function update_board(board) {
    var div = document.getElementById("debug");
    if (div) {
        div.innerText += "Board: " + board + "\n";
    }
}

function update_state(state) {
    var div = document.getElementById("debug");
    if (div) {
        div.innerText += "State: " + state + "\n";
    }
}
