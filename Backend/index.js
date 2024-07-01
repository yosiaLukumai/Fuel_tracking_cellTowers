const express = require('express');
const cors = require('cors')
const db = require("./db/db");
require("dotenv").config();
db.connectDb()

const app = express();
app.use(cors())

// let load the json

app.use(express.urlencoded({extended: true}))
app.use(express.json())

// loading the routes
const routesForData = require("./routes/postDataRoutes")
const clientRoutes = require('./routes/clientroutes')
routesForData.sendData(app)
clientRoutes.clientRoutes(app)



app.get("/", (req, res)=>
{
    res.send('okk')
})

let port = process.env.PORT
console.log("Port: ", port);
app.listen(port, ()=>
{
    console.log(`app has been aired on port ${port}`)
})
