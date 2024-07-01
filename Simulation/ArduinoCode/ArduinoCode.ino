#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#define Trig_Pin 12
#define Echo_Pin 11
bool triggered = false;
String stringToPy = "";
SoftwareSerial virtualPort(9, 10);
long duration, distance;
long thredshold = 24;
LiquidCrystal lcd(8, 7, 6, 5, 4, 3);
bool thereWarning1 = false;
bool thereWarning2 = false;



void UpdateScreen(String text, uint8_t row, uint8_t column) {
  lcd.setCursor(column, row);
  lcd.print(text);
}

void welcomeScreen() {
  lcd.setCursor(0, 0);
  lcd.print("-FUEL TRACKING-");
  lcd.setCursor(0, 1);
  lcd.print(" =MONITOR SYS=");
}


void setup() {
  Serial.begin(9600);
  virtualPort.begin(9600);
  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("-FUEL TRACKING-");
  lcd.setCursor(0, 1);
  lcd.print(" =MONITOR SYS=");
  delay(500);
  attachInterrupt(digitalPinToInterrupt(2), signalTamper, FALLING);
}

void signalTamper() {
  Serial.println("-------------------------------------");
  triggered = true;
}

void LevelTracking() {
  digitalWrite(Trig_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_Pin, LOW);
  duration = pulseIn(Echo_Pin, HIGH);
  distance = ((duration / 2) * 0.0343) + 1;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}

void loop() {
  LevelTracking();
  delay(1000);

  if (triggered) {
    UpdateScreen("    TAMPERING   ", 0, 0);
    UpdateScreen("   ==WARNING== ", 1, 0);
    thereWarning1 = true;
    delay(2000);
  } else {
    thereWarning1 = false;
  }

  if (distance <= thredshold) {
    UpdateScreen("   LOW LEVEL    ", 0, 0);
    UpdateScreen("   ==WARNING== ", 1, 0);
    delay(1000);
    thereWarning2 = true;
  } else {
    thereWarning2 = false;
  }
  if (!thereWarning1 && !thereWarning2) {
    welcomeScreen();
  }

  if (triggered) {
    stringToPy.concat(triggered + "xx");
    triggered = false;
  } else {
    stringToPy.concat(String(triggered) + "xx");
  }

  // attaching the level
  stringToPy.concat(String(distance) + "xx");
  virtualPort.println(stringToPy);
  stringToPy = "";
}
