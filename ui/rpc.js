"use strict";

(function() {
    var with_rpc = {
        "reset_board": function() {
            rpcService.resetBoard(new Empty(), {}, function(err, res) {
                if (err) {
                    console.error(err);
                }
            });
        },
        "get_moves": function(from, callback) {
            var tile = new Coordinate();
            tile.setX(from[0]);
            tile.setY(from[1]);
            var req = new GetMovesRequest();
            req.setTile(tile);
            rpcService.getMoves(req, {}, function(err, res) {
                if (err) {
                    console.error(err);
                } else {
                    callback(res.getDestinationsList().map(x => [ x.getX(), x.getY() ]));
                }
            });
        },
        "move": function(from, to, callback) {
            var f = new Coordinate();
            f.setX(from[0]);
            f.setY(from[1]);
            var t = new Coordinate();
            t.setX(to[0]);
            t.setY(to[1]);
            var req = new MoveRequest();
            req.setFrom(f);
            req.setTo(t);
            rpcService.move(req, {}, function(err, res) {
                if (err) {
                    console.error(err);
                } else {
                    callback(res.getError());
                }
            });
        },
        "restore": function(type, callback) {
            var req = new RestorePieceRequest();
            req.setType(type);
            rpcService.restorePiece(req, {}, function(err, res) {
                if (err) {
                    console.error(err);
                } else {
                    callback(res.getError());
                }
            });
        },
        "init": function() {
            window.ChessServiceClient = window.grpc.ChessServiceClient;
            [
                "Coordinate",
                "GetMovesRequest",
                "GetMovesResponse",
                "MoveRequest",
                "MoveResponse",
                "RestorePieceRequest",
                "RestorePieceResponse",
                "GameState"
            ].forEach(f => window[f] = window.pb[f]);
            window.rpcService = new ChessServiceClient("http://localhost:8080");
            var streamFunc = function() {
                console.log("[RPC] Opening stream");
                var dataCount = 0;
                var stream = rpcService.streamBoard(new Empty(), {});
                stream.on("data", function(res) {
                    ++dataCount;
                    console.log(res);
                });
                stream.on("error", function(err) {
                    if (dataCount > 0 && err.code === 2) {
                        streamFunc();
                    } else {
                        console.error(err);
                    }
                });
                stream.on("end", streamFunc);
            };
            streamFunc();
        }
    };
    var without_rpc = {
        "reset_board": function() {
            console.log("[RPC] reset_board");
        },
        "get_moves": function(from, callback) {
            console.log("[RPC] get_moves (" + from[0] + ", " + from[1] + ")");
            moves = [];
            if (from[0] > 0) {
                moves.push([from[0]-1, from[1]]);
            }
            if (from[0] < 7) {
                moves.push([from[0]+1, from[1]]);
            }
            if (from[1] > 0) {
                moves.push([from[0], from[1]-1]);
            }
            if (from[1] < 7) {
                moves.push([from[0], from[1]+1]);
            }
            callback(moves);
        },
        "move": function(from, to, callback) {
            console.log("[RPC] move (" + from[0] + ", " + from[1] + ") -> (" + to[0] + ", " + to[1] + ")");
            callback(0);
        },
        "restore": function(type, callback) {
            console.log("[RPC] restore (" + type + ")");
            callback(0);
        },
        "init": function() {}
    };

    var methods;
    if (window.pb && window.grpc) {
        methods = with_rpc;
    } else {
        console.warn("Running without RPC capabilities");
        methods = without_rpc;
    }

    window.reset_board = methods.reset_board;
    window.get_moves = methods.get_moves;
    window.move = methods.move;
    window.restore = methods.restore;
    methods.init();
})();
