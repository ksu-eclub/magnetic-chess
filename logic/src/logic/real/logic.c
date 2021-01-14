#include <stdio.h>
#include <stdbool.h>
#include <magchess/logic/logic.h>

board_t board;


// declare all pieces

piece_t pRook;
piece_t pKnight;
piece_t pBishop;
piece_t pKing;
piece_t pQueen;
piece_t pPawn;
piece_t empty;
piece_t wPawn;
piece_t wRook;
piece_t wKnight;
piece_t wBishop;
piece_t wQueen;
piece_t wKing;

void board_Converter ( board_t board, char *newBoard){
    int count = 0;
    for (int i = 7; i >= 0; i--){
        for (int j = 7; j >= 0; j--){
            if ((board.pieces[i][j].piece == pc_rook) && (board.pieces[i][j].color == cr_white)){
                newBoard[count] = 'R';
            }
            if ((board.pieces[i][j].piece == pc_rook) && (board.pieces[i][j].color == cr_purple)){
                newBoard[count] = 'r';
            }
            if ((board.pieces[i][j].piece == pc_knight) && (board.pieces[i][j].color == cr_white)){
                newBoard[count] = 'N';
            }
            if ((board.pieces[i][j].piece == pc_knight) && (board.pieces[i][j].color == cr_purple)){
                newBoard[count] = 'n';
            }
            if ((board.pieces[i][j].piece == pc_bishop) && (board.pieces[i][j].color == cr_white)){
                newBoard[count] = 'B';
            }
            if ((board.pieces[i][j].piece == pc_bishop) && (board.pieces[i][j].color == cr_purple)){
                newBoard[count] = 'b';
            } 
            if ((board.pieces[i][j].piece == pc_king) && (board.pieces[i][j].color == cr_white)){
                newBoard[count] = 'K';
            }
            if ((board.pieces[i][j].piece == pc_king) && (board.pieces[i][j].color == cr_purple)){
                newBoard[count] = 'k';
            }
            if ((board.pieces[i][j].piece == pc_queen) && (board.pieces[i][j].color == cr_white)){
                newBoard[count] = 'Q';
            }
            if ((board.pieces[i][j].piece == pc_queen) && (board.pieces[i][j].color == cr_purple)){
                newBoard[count] = 'q';
            }
            if ((board.pieces[i][j].piece == pc_pawn) && (board.pieces[i][j].color == cr_white)){
                newBoard[count] = 'P';
            }
            if ((board.pieces[i][j].piece == pc_pawn) && (board.pieces[i][j].color == cr_purple)){
                newBoard[count] = 'p';
            }
            if (board.pieces[i][j].piece == pc_empty){
                newBoard[count] = '-';
            }
            count++;

        }
    }
}



void reset_board(void) {
    puts("reset_board");
     
    //defines each piece
    pRook.piece = pc_rook;
    pRook.color = cr_purple;
    pRook.hasMoved = false;

    pKnight.piece = pc_knight;
    pKnight.color = cr_purple;

    pBishop.piece = pc_bishop;
    pBishop.color = cr_purple;

    pKing.piece = pc_king;
    pKing.color = cr_purple;

    pQueen.piece = pc_queen;
    pQueen.color = cr_purple;

    pPawn.piece = pc_pawn;
    pPawn.color = cr_purple;
    pPawn.hasMoved = false;

    empty.color = cr_none;
    empty.piece = pc_empty;

    wPawn.piece = pc_pawn;
    wPawn.color = cr_white;
    wPawn.hasMoved = false;

    wRook.piece = pc_rook;
    wRook.color = cr_white;
    wRook.hasMoved = false;

    wKnight.piece = pc_knight;
    wKnight.color = cr_white;

    wBishop.piece = pc_bishop;
    wBishop.color = cr_white;

    wQueen.piece = pc_queen;
    wQueen.color = cr_white;

    wKing.piece = pc_king;
    wKing.color = cr_white;


    //Stores each piece in the correct place on the board

    board.pieces[0][0] = wRook;
    board.pieces[0][1] = wKnight;
    board.pieces[0][2] = wBishop;
    board.pieces[0][3] = wKing;
    board.pieces[0][4] = wQueen;
    board.pieces[0][5] = wBishop;
    board.pieces[0][6] = wKnight;
    board.pieces[0][7] = wRook;
    for (int i = 0; i < 8; ++i){
        board.pieces[1][i] = pPawn;
    }
    for (int i = 2; i < 6; ++i){
        for (int j = 0; j < 8; ++j){
            board.pieces [i][j] = empty;
        }
    }
    for (int i = 0; i < 8; ++i){
        board.pieces [6][i] = wPawn;
    }
    board.pieces[7][0] = pRook;
    board.pieces[7][1] = pKnight;
    board.pieces[7][2] = pBishop;
    board.pieces[7][3] = pQueen;
    board.pieces[7][4] = pKing;
    board.pieces[7][5] = pBishop;
    board.pieces[7][6] = pKnight;
    board.pieces[7][7] = pRook;

    char convertedBoard [64];
    board_Converter (board, convertedBoard);
    on_change(board.turn, board.state, convertedBoard);
}

int get_moves(coordinate_t from, coordinate_t *tos, int tos_count) {
    puts("get_moves");
    int count = 0;

    on_selection(board.turn, board.state, from);
    
    // gets moves for rook
    if (board.pieces[from.y][from.x].piece == pc_rook){
        if ((from.y+1) < 8){
            for (int i = from.y+1; i < 8; ++i){
                //if occupied by friendly
                if (board.pieces[from.y][from.x].color == board.pieces[i][from.x].color){
                    break;
                }
                // if occupied by enemy
                else if (!(board.pieces[from.y][from.x].color == board.pieces[i][from.x].color) && !(board.pieces[i][from.x].color == cr_none)){
                    tos[count].y = i;
                    tos[count].x = from.x;
                    ++count;
                    break;
                }
                // if empty
                else{
                    tos[count].y = i;
                    tos[count].x = from.x; 
                }
                ++count;
            }
        }

        if ((from.y-1) >= 0){
            for (int i = from.y-1; i < 8; --i){
                //if occupied by friendly
                if (board.pieces[from.y][from.x].color == board.pieces[i][from.x].color){
                    break;
                }
                // if occupied by enemy
                else if (!(board.pieces[from.y][from.x].color == board.pieces[i][from.x].color) && !(board.pieces[i][from.x].color == cr_none)){
                    tos[count].y = i;
                    tos[count].x = from.x;
                    ++count;
                    break;
                }
                // if empty
                else{
                    tos[count].y = i;
                    tos[count].x = from.x; 
                }
                ++count;
            }
        }

        if ((from.x+1) < 8){
            for(int i = from.x+1; i < 8; ++i){
                // if occupied by friendly
                if(board.pieces[from.y][from.x].color == board.pieces[from.y][i].color){
                    break;
                }
                // if occupied by enemy
                else if(!(board.pieces[from.y][from.x].color == board.pieces[from.y][i].color) && !(board.pieces[from.y][i].color == cr_none)){
                    tos[count].y = from.y;
                    tos[count].x = i;
                    ++count;
                    break;
                }
                //if empty
                else{
                    tos[count].y = from.y;
                    tos[count].x = i;
                }
                ++count;
            }
        }

        if ((from.x-1) >= 0){
            for(int i = from.x-1; i < 8; --i){
                //if place is occupied by friendly
                if(board.pieces[from.y][from.x].color == board.pieces[from.y][i].color){
                    break;
                }
                //if occupied by enemy
                else if(!(board.pieces[from.y][from.x].color == board.pieces[from.y][i].color) && !(board.pieces[from.y][i].color == cr_none)){
                    tos[count].y = from.y;
                    tos[count].x = i;
                    ++count;
                    break;
                }
                // if empty
                else{
                    tos[count].y = from.y;
                    tos[count].x = i;
                }
                ++count;
            }
        }
        //tos_count = count;
    }

    // get moves for Knight
    if (board.pieces[from.y][from.x].piece == pc_knight){
        if (((from.y+2) < 8) && ((from.x-1) >= 0)){
           /* //checks if enemy is there
            if (!(board.pieces[from.y][from.x].color == board.pieces[from.y + 2][from.x - 1].color) && !(board.pieces[from.y + 2][from.x - 1].color == cr_none)){
                tos[count].y = from.y + 2;
                tos[count].x = from.x - 1;
                ++count;
            }
            // if empty
            else if (board.pieces[from.y + 2][from.x - 1].color == cr_none){
                tos[count].y = from.y + 2;
                tos[count].x = from.x - 1; 
                ++count;
            }
        } /*/

            if (board.pieces[from.y + 2][from.x - 1].color != board.pieces[from.y][from.x].color){
                tos[count].y = from.y + 2;
                tos[count].x = from.x - 1; 
                ++count;
            }
        }
        if (((from.y+2) < 8) && ((from.x+1) < 8)){
            if (board.pieces[from.y + 2][from.x + 1].color != board.pieces[from.y][from.x].color){
                tos[count].y = from.y + 2;
                tos[count].x = from.x + 1; 
                ++count;
            }
        }
        if (((from.y-2) >= 0) && ((from.x-1) >= 0)){
            if (board.pieces[from.y - 2][from.x - 1].color != board.pieces[from.y][from.x].color){
                tos[count].y = from.y - 2;
                tos[count].x = from.x - 1; 
                ++count;
            }
        }
        if (((from.y-2) >= 0) && ((from.x+1) < 8)){
            if (board.pieces[from.y - 2][from.x + 1].color != board.pieces[from.y][from.x].color){
                tos[count].y = from.y - 2;
                tos[count].x = from.x + 1; 
                ++count;
            }
        }
        if (((from.y+1) < 8) && ((from.x-2) >= 0)){
            if (board.pieces[from.y + 1][from.x - 2].color != board.pieces[from.y][from.x].color){
                tos[count].y = from.y + 1;
                tos[count].x = from.x - 2; 
                ++count;
            }
        }
        if (((from.y+1) < 8) && ((from.x+2) < 8)){
            if (board.pieces[from.y + 1][from.x + 2].color != board.pieces[from.y][from.x].color){
                tos[count].y = from.y + 1;
                tos[count].x = from.x + 2; 
                ++count;
            }
        }
        if (((from.y-1) >= 0) && ((from.x-2) >= 0)){
            if (board.pieces[from.y - 1][from.x - 2].color != board.pieces[from.y][from.x].color){
                tos[count].y = from.y - 1;
                tos[count].x = from.x - 2; 
                ++count;
            }
        }
        if (((from.y-1) >= 0) && ((from.x+2) < 8)){
            if (board.pieces[from.y - 1][from.x + 2].color != board.pieces[from.y][from.x].color){
                tos[count].y = from.y - 1;
                tos[count].x = from.x + 2; 
                ++count;
            }
        }
    }

    // Gets moves for white pawns
    if ((board.pieces[from.y][from.x].piece == pc_pawn) && (board.pieces[from.y][from.x].color == cr_white)){
         if((from.y+1) < 8){
            if ((board.pieces[from.y + 1][from.x].color == cr_none)){
                if (from.y + 1 == 7 ){

                }
                else{
                    tos[count].x = from.x;
                    tos[count].y = from.y + 1;
                    ++count;
                }
            }
        }
        if (((from.x + 1) < 8) && ((from.y + 1) < 8)){
            if (!(board.pieces[from.y][from.x].color == board.pieces[from.y+1][from.x+1].color) && !(board.pieces[from.y + 1][from.x + 1].color == cr_none)){
                tos[count].x = from.x + 1;
                tos[count].y = from.y + 1;
                ++count;
            }
        }
        if (((from.x - 1) < 8) && ((from.y + 1) < 8)){
            if (!(board.pieces[from.y][from.x].color == board.pieces[from.y+1][from.x-1].color) && !(board.pieces[from.y + 1][from.x - 1].color == cr_none)){
                tos[count].x = from.x - 1;
                tos[count].y = from.y + 1;
                ++count;
            }
        }
        if ((board.pieces[from.y][from.x].hasMoved == false) && (board.pieces[from.y + 1][from.x].color == cr_none) && (board.pieces[from.y + 2][from.x].color == cr_none)){
            tos[count].x = from.x;
            tos[count].y = from.y + 2;
            ++count;
        }
    }
    // Gets moves for purple pawns
    if ((board.pieces[from.y][from.x].piece == pc_pawn) && (board.pieces[from.y][from.x].color == cr_purple)){
        
        if((from.y-1) >= 0){
            if ((board.pieces[from.y - 1][from.x].color == cr_none)){
                if (from.y - 1 == 0){

                }
                else{
                    tos[count].x = from.x;
                    tos[count].y = from.y - 1;
                    ++count;
                }
            }
        }
        if (((from.x + 1) < 8) && ((from.y - 1) < 8)){
            if (!(board.pieces[from.y][from.x].color == board.pieces[from.y-1][from.x+1].color) && !(board.pieces[from.y - 1][from.x + 1].color == cr_none)){
                tos[count].x = from.x + 1;
                tos[count].y = from.y - 1;
                ++count;
            }
        }
        if (((from.x - 1) < 8) && ((from.y - 1) < 8)){
            if (!(board.pieces[from.y][from.x].color == board.pieces[from.y-1][from.x-1].color) && !(board.pieces[from.y - 1][from.x - 1].color == cr_none)){
                tos[count].x = from.x - 1;
                tos[count].y = from.y - 1;
                ++count;
            }
        }
        if ((board.pieces[from.y][from.x].hasMoved == false) && (board.pieces[from.y - 1][from.x].color == cr_none) && (board.pieces[from.y - 2][from.x].color == cr_none)){
            tos[count].x = from.x;
            tos[count].y = from.y - 2;
            ++count;
        }
    }

    // Get Moves for Bishop
    if (board.pieces[from.y][from.x].piece == pc_bishop){
        int j;
        int i;
        int z;
        for (i = 1, j = 1; (i < (8-from.x))  &&  (j < (8-from.y)); ++j, ++i){
            if ( !(board.pieces[from.y + j][from.x + i].color == board.pieces[from.y][from.x].color)){
                tos[count].x = from.x + i;
                tos[count].y = from.y + j;
                ++count;
            }
        }
        for (i = 1, j = from.y; (i < (8-from.x))  &&  (j > 0); --j, ++i){
            if ( !(board.pieces[from.y - i][from.x + i].color == board.pieces[from.y][from.x].color)){
                tos[count].x = from.x + i;
                tos[count].y = from.y - i;
                ++count;
            }
        }
        for (i = from.x, j = 1; (i > 0)  &&  (j < (8-from.y)); ++j, --i){
            if ( !(board.pieces[from.y + j][from.x - j].color == board.pieces[from.y][from.x].color)){
                tos[count].x = from.x - j;
                tos[count].y = from.y + j;
                ++count;
            }
        }
        for (i = from.x, j = from.y, z = 1; (i > 0)  &&  (j > 0); --j, --i, ++z){
            if ( !(board.pieces[from.y - z][from.x - z].color == board.pieces[from.y][from.x].color)){
                tos[count].x = from.x - z;
                tos[count].y = from.y - z;
                ++count;
            }
        }
    }

    //get Moves for Queen
    if (board.pieces[from.y][from.x].piece == pc_queen){
        if ((from.y+1) < 8){
            for (int i = from.y+1; i < 8; ++i){
                //if occupied by friendly
                if (board.pieces[from.y][from.x].color == board.pieces[i][from.x].color){
                    break;
                }
                // if occupied by enemy
                else if (!(board.pieces[from.y][from.x].color == board.pieces[i][from.x].color) && !(board.pieces[i][from.x].color == cr_none)){
                    tos[count].y = i;
                    tos[count].x = from.x;
                    ++count;
                    break;
                }
                // if empty
                else{
                    tos[count].y = i;
                    tos[count].x = from.x; 
                }
                ++count;
            }
        }

        if ((from.y-1) >= 0){
            for (int i = from.y-1; i < 8; --i){
                //if occupied by friendly
                if (board.pieces[from.y][from.x].color == board.pieces[i][from.x].color){
                    break;
                }
                // if occupied by enemy
                else if (!(board.pieces[from.y][from.x].color == board.pieces[i][from.x].color) && !(board.pieces[i][from.x].color == cr_none)){
                    tos[count].y = i;
                    tos[count].x = from.x;
                    ++count;
                    break;
                }
                // if empty
                else{
                    tos[count].y = i;
                    tos[count].x = from.x; 
                }
                ++count;
            }
        }

        if ((from.x+1) < 8){
            for(int i = from.x+1; i < 8; ++i){
                // if occupied by friendly
                if(board.pieces[from.y][from.x].color == board.pieces[from.y][i].color){
                    break;
                }
                // if occupied by enemy
                else if(!(board.pieces[from.y][from.x].color == board.pieces[from.y][i].color) && !(board.pieces[from.y][i].color == cr_none)){
                    tos[count].y = from.y;
                    tos[count].x = i;
                    ++count;
                    break;
                }
                //if empty
                else{
                    tos[count].y = from.y;
                    tos[count].x = i;
                }
                ++count;
            }
        }

        if ((from.x-1) >= 0){
            for(int i = from.x-1; i < 8; --i){
                //if place is occupied by friendly
                if(board.pieces[from.y][from.x].color == board.pieces[from.y][i].color){
                    break;
                }
                //if occupied by enemy
                else if(!(board.pieces[from.y][from.x].color == board.pieces[from.y][i].color) && !(board.pieces[from.y][i].color == cr_none)){
                    tos[count].y = from.y;
                    tos[count].x = i;
                    ++count;
                    break;
                }
                // if empty
                else{
                    tos[count].y = from.y;
                    tos[count].x = i;
                }
                ++count;
            }
        }
        int j;
        int i;
        int z;
        for (i = 1, j = 1; (i < (8-from.x))  &&  (j < (8-from.y)); ++j, ++i){
            if ( !(board.pieces[from.y + j][from.x + i].color == board.pieces[from.y][from.x].color)){
                tos[count].x = from.x + i;
                tos[count].y = from.y + j;
                ++count;
            }
        }
        for (i = 1, j = from.y; (i < (8-from.x))  &&  (j > 0); --j, ++i){
            if ( !(board.pieces[from.y - i][from.x + i].color == board.pieces[from.y][from.x].color)){
                tos[count].x = from.x + i;
                tos[count].y = from.y - i;
                ++count;
            }
        }
        for (i = from.x, j = 1; (i > 0)  &&  (j < (8-from.y)); ++j, --i){
            if ( !(board.pieces[from.y + j][from.x - j].color == board.pieces[from.y][from.x].color)){
                tos[count].x = from.x - j;
                tos[count].y = from.y + j;
                ++count;
            }
        }
        for (i = from.x, j = from.y, z = 1; (i > 0)  &&  (j > 0); --j, --i, ++z){
            if ( !(board.pieces[from.y - z][from.x - z].color == board.pieces[from.y][from.x].color)){
                tos[count].x = from.x - z;
                tos[count].y = from.y - z;
                ++count;
            }
        }
    }
    
    // Gets moves for King
    if (board.pieces[from.y][from.x].piece == pc_king){
        if (!(board.pieces[from.y][from.x].color == board.pieces[from.y][from.x+1].color)){
            tos[count].x = from.x + 1;
            tos[count].y = from.y;
            ++count;
        }
        if (!(board.pieces[from.y][from.x].color == board.pieces[from.y+1][from.x].color)){
            tos[count].x = from.x;
            tos[count].y = from.y + 1;
            ++count;
        }
        if (!(board.pieces[from.y][from.x].color == board.pieces[from.y][from.x-1].color)){
            tos[count].x = from.x - 1;
            tos[count].y = from.y;
            ++count;
        }
        if (!(board.pieces[from.y][from.x].color == board.pieces[from.y-1][from.x].color)){
            tos[count].x = from.x;
            tos[count].y = from.y - 1;
            ++count;
        }
        if (!(board.pieces[from.y][from.x].color == board.pieces[from.y+1][from.x+1].color)){
            tos[count].x = from.x + 1;
            tos[count].y = from.y + 1;
            ++count;
        }
        if (!(board.pieces[from.y][from.x].color == board.pieces[from.y+1][from.x-1].color)){
            tos[count].x = from.x - 1;
            tos[count].y = from.y + 1;
            ++count;
        }
        if (!(board.pieces[from.y][from.x].color == board.pieces[from.y-1][from.x+1].color)){
            tos[count].x = from.x + 1;
            tos[count].y = from.y - 1;
            ++count;
        }
        if (!(board.pieces[from.y][from.x].color == board.pieces[from.y-1][from.x-1].color)){
            tos[count].x = from.x - 1;
            tos[count].y = from.y - 1;
            ++count;
        }
    }

    return count;
    // TODO
    // if (count + 1 < tos_count) {
    //     tos[count].x = 0;
    //     tos[count].y = 0;
    //     ++count;
    // }
    // if (count + 1 < tos_count) {
    //     tos[count].x = 4;
    //     tos[count].y = 7;
    //     ++count;
    // }
    // return count;
}
 //
move_error_t move(coordinate_t from, coordinate_t to) {
    puts("move");
    if (board.pieces[to.y][to.x].color == board.pieces[from.y][from.x].color){
        return me_not_valid;
    }
    if (to.y > 7 || to.y < 0 || to.x > 7 || to.x < 0){
        return me_not_valid;
    }
    
    return me_none;
}

restore_error_t restore(piece_type_t type) {
    puts("restore");
    // TODO 
    return re_none;
}

