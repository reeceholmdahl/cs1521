/** @file
 *
 * @author Mike Dawson
 *
 * @author Steven J Holtz
 *
 * @note From "C++ Projects: Programming with Text-Based Games" */

#include <iostream>

#include "player.h"
#include "board.h"

const char Player::PIECES[NUM_PIECES] = {'X',
                                         'O'};

int Player::current(0);

Player::Player() {
   piece = PIECES[current];

   // current = (current + 1) % NUM_PIECES;
   ++current %= NUM_PIECES;
}

char Player::getPiece() const {
   return piece;
}

void Player::makeMove(Board* board) const {
   int move;

   do {
      std::cout << "Player "
                << getPiece()
                << ", where would you like to move (0-8): ";
      std::cin >> move;
   } while (!board->isLegalMove(move) );

   board->receiveMove(getPiece(), move);
}
