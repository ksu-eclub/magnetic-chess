const grpc = require("./chess_service_grpc_web_pb");
const pb = require("./chess_service_pb");
const empty = require("google-protobuf/google/protobuf/empty_pb.js");

window.grpc = grpc;
window.pb = pb;
window.Empty = empty.Empty;
