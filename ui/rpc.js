"use strict";

(function() {
    var with_rpc = {
        "reset_board": function() {

        },
        "get_moves": function(from, callback) {

        },
        "move": function(from, to, callback) {

        },
        "restore": function(type, callback) {

        },
        "init": function() {
            console.error("RPC methods are not implemented!");
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
