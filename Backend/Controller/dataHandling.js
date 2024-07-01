// const dataModel = require("../Models/dataSent")
const dataModel = require("../Models/logs")

const handlePost = async (req, res)=>
{
    try{
        const {level, tamper} = req.body;
        console.log("New Data......");
        console.log(req.body);
        const savedData = await dataModel.create({tamper, level})
        console.log(savedData)
        const result = {
            succces: true,
            message: "Data has been sent Successfully.."
        }
        return res.json(result)
    }
    catch(err)
    {
        console.log(err.message)
        return res.send(err.message)
    }
}

const testTheServer = async (req, res) =>
{
    try{
        const result = {
            success: true,
            message: "Test worked"
        }

        return res.json(result)
    }
    catch(err)
    {
        console.log(err.message)
        return res.send(err.message)

    }
}
module.exports ={
    handlePost,
    testTheServer
}