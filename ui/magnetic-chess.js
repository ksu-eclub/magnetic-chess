function update_board(board) {
    var div = document.getElementById("debug");
    if (div) {
        div.innerText += board + "\n";
    }
}
