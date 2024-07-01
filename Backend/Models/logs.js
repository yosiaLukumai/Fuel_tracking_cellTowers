const mongoose = require("mongoose")

const data = mongoose.Schema({
    tamper: {
        type: Boolean,
        required: true
    },
    level: {
        type: Number,
        required: true
    }
  
}, {
    timestamps: true
})



     

module.exports = mongoose.model("data", data)