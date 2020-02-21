const path = require("path");

module.exports = {
    "mode": "development",
    "entry": "client.js",
    "output": {
        "path": path.resolve(__dirname, ".."),
        "filename": "rpc-gen.js"
    },
    "devtool": "source-map",
    "target": "web"
};
