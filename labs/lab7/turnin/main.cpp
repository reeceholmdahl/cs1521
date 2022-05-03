// My ID: 5727889

#include <iostream>
#include <algorithm>

#include "rot5_13.h"

const std::string UP = "\x1b[A";

int main() {

  while (true) {

    std::cout << "\n(Ctrl-D or enter nothing to exit)"
	      << UP << "\rEnter a string to encrypt: ";

    std::string in;
    getline(std::cin, in);

    // EOF or empty input
    if (std::cin.eof() ) {
      std::cout << std::endl;
      break;
    } else if (in == "") {
      break;
    }

    // Print original
    std::cout << "\n\nOriginal: " << in << std::endl;

    // For each loop on copy of original
    for_each(in.begin(), in.end(), rot5_rot13);

    std::cout << "Encrypted: " << in << "\n" << std::endl;
  }

  std::cout << std::endl;

  return EXIT_SUCCESS;
}
