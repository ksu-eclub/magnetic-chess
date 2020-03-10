#include <stdio.h>
#include "logic.h"

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



void reset_board(void) {
    puts("reset_board");
     
    //defines each piece
    pRook.piece = pc_rook;
    pRook.color = cr_purple;

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

    empty.color = cr_none;

    wPawn.piece = pc_pawn;
    wPawn.color = cr_white;

    wRook.piece = pc_rook;
    wRook.color = cr_white;

    wKnight.piece = pc_knight;
    wKnight.color = cr_white;

    wBishop.piece = pc_bishop;
    wBishop.color = cr_white;

    wQueen.piece = pc_queen;
    wQueen.color = cr_white;

    wKing.piece = pc_king;
    wKing.color = cr_white;

    //Stores each piece in the correct place on the board

    board.pieces[0][0] = pRook;
    board.pieces[0][1] = pKnight;
    board.pieces[0][2] = pBishop;
    board.pieces[0][3] = pKing;
    board.pieces[0][4] = pQueen;
    board.pieces[0][5] = pBishop;
    board.pieces[0][6] = pKnight;
    board.pieces[0][7] = pRook;
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
}

int get_moves(coordinate_t from, coordinate_t *tos, int tos_count) {
    puts("get_moves");
    int count = 0;
    
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

        if ((from.y-1) > 0){
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

        if ((from.x-1) > 0){
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
    }

    // get moves for Knight
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
