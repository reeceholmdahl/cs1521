// My ID: 5727889
#include <iostream>
#include <memory>
#include <sstream>
#include <new>

#include "DiscList.h"
#include "Disc.h"
#include "Track.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

/** Prints the main menu and requests input for further action. Returns a char to indicate result */
char mainMenu();

/** Asks user to press enter to return to resume flow of control */
void returnPrompt(const std::string& message);

/** Requests input of an integer and won't exit until a proper integer is given. */
int validateInt();

int main() {

  // Disc list object
  try {
    DiscList discList;
    
    // Main user experience loop
    bool exit = false;
    while (!exit) {
      char option = mainMenu();

      std::shared_ptr<Disc> disc;
    
      switch (option) {
      case 'A':
	cin.ignore(1000, '\n');
	discList.insertDisc(Disc::getDiscFromUser() );
	break;
      
      case 'R':

	cout << "Enter the number of the disc to remove from the system: ";
	int toRemove;
	toRemove = validateInt();

	if (toRemove >= 1 && toRemove <= discList.getNumberOfDiscs() ) {
	  disc = discList.retrieveDisc(toRemove);
	}

	if (discList.removeDisc(disc) ) {
	  cout << "Successfully removed '" << disc->getTitle() << "' (disc " << toRemove << ") from the system." << endl;
	} else {
	  cout << "Could not remove disc " << toRemove << " from the system, it could not be found." << endl;
	}

	cout << endl;

	returnPrompt("Press enter to return to the main menu. ");

	cout << endl;
      
	break;
      
      case 'P':
      
	cout << "Enter the number of the disc to print: ";
	int toPrint;
	toPrint = validateInt();

	cout << endl;
      
	if (toPrint >= 1 && toPrint <= discList.getNumberOfDiscs()) {
	  discList.retrieveDisc(toPrint)->printDisc();
	} else {
	  cout << "There is no disc that corresponds to '" << toPrint << "'." << endl;
	}

	cout << endl;

	returnPrompt("Press enter to return to the main menu. ");

	cout << endl;
      
	break;

	/** Lists the discs in a numbered, non verbose way. */
      case 'L':
      
	// Print header
	cout << endl << "|--- All Discs in the System ---|" << endl;
  
	for (int i(1); i <= discList.getNumberOfDiscs(); ++i) {
	  disc = discList.retrieveDisc(i);
	  cout << i << ": '" << disc->getTitle() << "' by " << disc->getArtist() << endl;
	}
      
	// Prompt for user to return to main menu
	returnPrompt("Press enter to return to the main menu. ");
	cout << endl;
      
	break;
      case 'Q':
	exit = true;
	break;
      }
    }
  } catch (const std::bad_alloc&) {
    std::cerr << "ERROR: Memory allocation failed." << endl;
  }
  
  return EXIT_SUCCESS;
}

char mainMenu() {
  cout << "|----- Music Storage Program -----|" << endl
       << "(A)dd a new disc." << endl
       << "(R)emove a disc." << endl
       << "(P)rint a disc." << endl
       << "(L)ist discs." << endl
       << "(Q)uit." << endl
       << "> ";

  int toUpper = 'A' - 'a';

  char option;
  while (true) {
    cin >> option;

    if (option >= 'a' && option <= 'z')
      option += toUpper;

    switch (option) {
    case 'A':
    case 'R':
    case 'P':
    case 'L':
    case 'Q':
      return option;

    default:
      break;
    }
    
    cout << "Incorrect option, please enter again." << endl << "> ";
  }
}

void returnPrompt(const std::string& message) {
  cout << endl << message;
  
  char c;
  cin.ignore(1000, '\n');
  cin.get(c);
}

int validateInt() {
  cin.ignore(1000, '\n');
  int i;
  bool valid = false;
  std::stringstream stream;
  std::string input;
  while (!valid) {
    getline(cin, input);
    stream << input;

    valid = true;
    for (char c : input) {
      if (c < '0' || c > '9') {
	valid = false;
	break;
      }
    }
    
    if (valid) {
      stream >> i;
      break;
}

	cout << "Not a valid integer, please enter again: ";
    
    input = "";
    stream.clear();
  }

  return i;
}
