/** @file
 *
 * @author Mike Dawson
 *
 * @author Steven J Holtz
 *
 * @note From "C++ Projects: Programming with Text-Based Games" */

#include <iostream>
#include <cstdlib>

#include "game.h"

int main() {
   Game* ticTacToe(new Game);

   ticTacToe->displayInstructions();

   char playAgain;

   do {
      ticTacToe->play();
      std::cout << "\nPlay again (y/n)? ";
      std::cin >> playAgain;
   } while (playAgain != 'n');

   return EXIT_SUCCESS;
}
