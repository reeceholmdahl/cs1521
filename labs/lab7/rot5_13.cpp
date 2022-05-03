#include "rot5_13.h"

void rot5_rot13(char& ch) {

  if ((ch >= 'A' && ch <= 'Z') ) {
    // If in the lower half of the alphabet, increment the character by 13, otherwise decrement by 13
    ch += (ch - 13 < 'A') ? 13 : -13;
  } else if ((ch >= 'a' && ch <= 'z') ) {
    // If in the lower half of the alphabet, increment the character by 13, otherwise decrement by 13
    ch += (ch - 13 < 'a') ? 13 : -13;
  } else if (ch >= '0' && ch <= '9') {
    // If in the lower half of the number range, increment by 5, otherwise decrement by 5
    ch += (ch - 5 < '0') ? 5 : -5;
  }
}
