#include "negamax.h"

int MAX_DEPTH = 10;


board_t negamax(board_t board, int _depth, int player){
    ivec_t nexts = {0};
    int mv,v;
    board_t next_board = {}, mini_board = {}, best = {};
    if (_depth == MAX_DEPTH || board.winner != 0 || board.full == true){
        board.winner *= player;
        return board;
    }
    nexts = get_next_moves(board.state);
    if ((int)nexts.size() == 0){
        board.winner *= player;
        return board;
    }
    mv = -100;
    ivec_t::iterator i;
    for(i = nexts.begin(); i != nexts.end(); ++i){
        next_board = get_next_board(board,(*i));
        mini_board = negamax(next_board,_depth+1,next_board.next_player);
        if (mv < -mini_board.winner){
            mv = -mini_board.winner;
            best = mini_board;
        }
    }
    return best;
}
