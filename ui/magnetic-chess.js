/* 
Magnetic Chess
User Interface Code
*/

// debug information

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

// Alert boxes will eventually be replaced with HTML modal pop-ups.
// Dummy function for unimplemented UI elements

function notImplemented() {
    alert("This doesn't work yet! :P");
}

// Displays information about this project

function getAbout() {
    alert("E-Club Magnetic Chess by Zach Deibert, Jim Gant, Rich Garris, Nick Gerhold, and Dane Thompson.");
}

// Moves the pawn element to different locations on screen by modifying CSS properties -- dev tool, used for finding positions

function movePawnDirect() {
    // collect input values
    var x = document.getElementById("x-input").value;
    var y = document.getElementById("y-input").value;
    // update x alignment
    document.getElementById("pawn1").style.right = x;
    // update y alignment
    document.getElementById("pawn1").style.top = y;
}

// The code in movePawn() needs to be broken out into multiple functions. This will happen eventually.

function movePawn() {
    // collect input values                                                                                            
    var x = document.getElementById("x-input").value;
    var y = document.getElementById("y-input").value;
    var errorFlag = false;
    
    // these switch statements check the input values and move the piece accordingly
    // update x position
    switch(x) {
        case "a":
            document.getElementById("pawn1").style.right = "40.8%";
            break;
        case "b":
            document.getElementById("pawn1").style.right = "35.7%";
            break;
        case "c":
            document.getElementById("pawn1").style.right = "30.8%";
            break;
        case "d":
            document.getElementById("pawn1").style.right = "25.8%";
            break;
        case "e":
            document.getElementById("pawn1").style.right = "20.9%";
            break;
        case "f":
            document.getElementById("pawn1").style.right = "16%";
            break;
        case "g":
            document.getElementById("pawn1").style.right = "11%";
            break;
        case "h":
            document.getElementById("pawn1").style.right = "6.1%";
            break;
        default:
            errorFlag = true;
            break;
    }

    // update y position
    switch(y) {
        case "1":
            document.getElementById("pawn1").style.top = "80%";
            break;
        case "2":
            document.getElementById("pawn1").style.top = "72%";
            break;
        case "3":
            document.getElementById("pawn1").style.top = "64%";
            break;
        case "4":
            document.getElementById("pawn1").style.top = "56%";
            break;
        case "5":
            document.getElementById("pawn1").style.top = "47.5%";
            break;
        case "6":
            document.getElementById("pawn1").style.top = "39.5%";
            break;
        case "7":
            document.getElementById("pawn1").style.top = "31%";
            break;
        case "8":
            document.getElementById("pawn1").style.top = "23%";
            break;
        default:
            errorFlag = true;
            break;
    }
    
    // clear inputs
    document.getElementById("x-input").value = null;
    document.getElementById("y-input").value = null;

    // check if an input error occurred
    if (errorFlag == true) {
        document.getElementById("debug").innerHTML =  "Invalid entry. Please use valid alphanumeric characters.";
    } else {
        document.getElementById("debug").innerHTML =  "Piece successfully moved to " . x . y;
    }

}
