#include <iostream>
#include <fstream>

#include "LinkedSet.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/** Cleans all of the extraneous characters from both the beginning and the end of a string.
    @pre None.
    @post None.

    @param[in] dirty The uncleaned string.

    @return The cleaned up version of 'dirty'. */
string clean(const string& dirty);

/** Makes all of the characters in the string lower case.
    @pre None.
    @post None.

    @param[in] cased The string which could contain letters of any case.

    @return A new copy of 'cased' in all lower case. */
string toLower(const string& cased);

int main() {

  std::ifstream inFile;

  cout << "Enter the name of a dictionary file: ";

  string dictFile;
  cin >> dictFile;

  inFile.open(dictFile);

  // Once this while loop exits, the file was successfully opened
  while (!inFile) {
    cout << "Could not find the file \"" << dictFile << "\"." << endl;
    
    cout << "Try again, and enter the name of another dictionary file (or \"exit\" to quit): ";
    
    cin >> dictFile;

    // Loop control: if user enters "exit", then exit program
    if (toLower(dictFile) == "exit") {
      return EXIT_SUCCESS;
    }

    inFile.open(dictFile);
  }

  cout << endl;

  // Variables for the dictionary read
  LinkedSet<string> dictionary;
  string input;

  // Read each individual word from the dictionary in a loop
  while (true) {
    
    inFile >> input;

    // If the EOF character was found, break
    if (inFile.eof() ) {
      break;
    }

    // Since a dictionary is already cleaned and in lower case, just add the input
    dictionary.add(input);
  }

  // Close the dictionary file and prepare to spell check other files
  inFile.close();

  // Variables for other files to be spell checked
  string fileName;
  LinkedSet<string> toBeSpellChecked;

  // Main user loop: prompts user to enter a file name to spell check, then spell checks and repeats until prompted to exit
  while (true) {
    cout << "Enter the name of a file to spell check (or \"exit\" to quit): ";
    cin >> fileName;

    // Loop control: if user enters "exit", then exit program
    if (toLower(fileName) == "exit") {
      return EXIT_SUCCESS;
    }

    inFile.open(fileName);

    // If the file couldn't be opened, let the user know and return to loop. Otherwise, spell check
    if (!inFile) {
      cout << "Could not open the file \"" << fileName << "\", try again." << endl;
    } else {

      // Clear the set of words to be spell checked
      toBeSpellChecked.clear();

      // Read in files from the file to be spell checked
      string input;
      while (true) {
	inFile >> input;

	// If the EOF character was found, break
	if (inFile.eof() ) {
	  break;
	}

	// Clean and lower the case of the word read from inFile
	input = clean(toLower(input) );

	// Add the cleaned and lowered input to the to be spell checked set
	toBeSpellChecked.add(input);
      }

      // Take the difference from the set of words to be spell checked to the dictionary, yielding all of the incorrectly spelled words
      LinkedSet<string> misspelledWords = toBeSpellChecked.difference(dictionary);

      // Output control for mispelled words: if empty, indicate so. Otherwise, list all of the misspelled words.
      if (misspelledWords.isEmpty() ) {
	
	cout << "There are no misspelled words in this document." << endl;
      } else {

	cout << "The misspelled words are as follows:" << endl;

	// Create a vector of all of the misspelled words from the set, and print out each of them.
	std::vector<string> misspelled = misspelledWords.toVector();
	for (unsigned int i(0); i < misspelled.size(); ++i) {
	  if (i > 0) {
	    cout << ", ";
	  }
	  cout << misspelled[i];
	}
	cout << endl;
      }

      cout << endl;
    }

    // After this file has been spell checked, close it in preparation for the next check or the end of the program.
    inFile.close();
  }

  return EXIT_SUCCESS;
}

/* Implementation of method headers shown above */

string clean(const string& dirty) {
  // The characters to be removed from the beginning or end of the word
  string ext = "!@#$%^&*()_-+={}[]:;\"\'`<>,.?/|\\";
  
  string toClean(dirty);
  bool clean(false);
  
  while (!clean) {
    int first = toClean.find_first_of(ext);
    int last = toClean.find_last_of(ext);
    int lastIndex = toClean.length() - 1;

    // Loop control for cleaning the string. It can either have an invalid character at the beginning, end, both, or neither
    if (first == 0 && last == lastIndex) {

      // Remove the first and last character
      toClean = toClean.substr(1, lastIndex);
    } else if (first == 0) {

      // Remove the first character
      toClean = toClean.substr(1);
    } else if (last == lastIndex) {

      // Remove the last character
      toClean = toClean.substr(0, lastIndex);
    } else {

      // No invalid characters, the string is clean
      clean = true;
    }
  }
  
  return toClean;
}

string toLower(const string& cased) {
  int toLower = 'a' - 'A';
  string lower(cased);

  // Iterate through the string and find any uppercase letters, if found, increment that character by the distance to lower case
  for (unsigned int i(0); i < lower.length(); ++i) {
    if (lower[i] >= 'A' && lower[i] <= 'Z') {
      lower[i] += toLower;
    }
  }
  
  return lower;
}
