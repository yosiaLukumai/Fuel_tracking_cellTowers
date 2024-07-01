const express = require('express')
const router = express.Router();
const clientController = require("../Controller/client")

const clientRoutes = (app)=>
{
    
    router.get("/getdata", clientController.RenderHomePage)
    return app.use("/api/backend/fuel", router)
} 


module.exports = {
    clientRoutes
}