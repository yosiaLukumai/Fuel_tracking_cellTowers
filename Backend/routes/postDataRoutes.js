const express = require('express')
const router = express.Router();
const controller = require("../Controller/dataHandling")

const sendData = (app) =>
{
    router.post('/data', controller.handlePost)
    router.get("/test", controller.testTheServer)
    return app.use("/api/backend/fuel", router)
}


module.exports = {
    sendData
}