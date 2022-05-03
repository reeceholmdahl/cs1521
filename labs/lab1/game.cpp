/** @file
 *
 * @author Mike Dawson
 *
 * @author Steven J Holtz
 *
 * @note From "C++ Projects: Programming with Text-Based Games" */

#include <iostream>

#include "game.h"

Game::Game()
   : currentPlayer(FIRST) {
   // Allocate a Board from the heap.
   board = new Board;

   // Allocate an array of pointers to Players.
   players = new Player*[NUM_PLAYERS];

   // Allocate each element in the players array to a new Player.
   players[FIRST] = new Player;
   players[SECOND] = new Player;
}

Game::~Game() {
   delete board;
   delete players[FIRST];
   delete players[SECOND];
   delete [] players;
}

bool Game::isPlaying() const {
   return !board->isFull() &&
      !board->isWinner(players[FIRST]->getPiece() ) &&
      !board->isWinner(players[SECOND]->getPiece() );
}

bool Game::isTie() const {
   return board->isFull() &&
      !board->isWinner(players[FIRST]->getPiece() ) &&
      !board->isWinner(players[SECOND]->getPiece() );
}

void Game::displayInstructions() const {
   std::cout << "\n\tWelcome to Tic-Tac-Toe!!!\n\n"
             << "Make your move by entering 0-8.  The number\n"
             << "corresponds to a board position:\n\n"
             << "\t0 | 1 | 2\n"
             << "\t--+---+--\n"
             << "\t3 | 4 | 5\n"
             << "\t--+---+--\n"
             << "\t6 | 7 | 8\n\n"
             << "Prepare for battle!!!\n"
             << std::endl;
}

void Game::nextPlayer() {
   // currentPlayer = (currentPlayer + 1) % NUM_PLAYERS;
   ++currentPlayer %= NUM_PLAYERS;
}

void Game::announceWinner() const {
   std::cout << "The battle has come to an end."
             << std::endl;

   if (isTie() ) {
      std::cout << "Sadly, there is no victor."
                << std::endl;
   }
   else {
      std::cout << "The winner is Player ";
      if (board->isWinner(players[FIRST]->getPiece()) ) {
         std::cout << players[FIRST]->getPiece();
      }
      else {
         std::cout << players[SECOND]->getPiece();
      }
      std::cout << "!"
                << std::endl;
   }
}

void Game::play() {
   currentPlayer = FIRST;

   board->reset();

   while (isPlaying() ) {
      board->display();
      players[currentPlayer]->makeMove(board);
      nextPlayer();
   }

   board->display();

   announceWinner();
}
