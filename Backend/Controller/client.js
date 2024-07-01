const dataModel = require("../Models/logs")

const RenderHomePage = async (req, res ) =>
{
    try{
        const data = await dataModel.findOne().sort({ createdAt: -1 })
        return res.json(data)
        
    }
    catch(err)
    {
        console.log(err.message)
        return res.send(err.message)
    }
}

module.exports = {
    RenderHomePage
}