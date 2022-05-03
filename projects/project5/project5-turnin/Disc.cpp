#include <memory>
#include <iostream>
#include <string>
#include <sstream>
#include <new>

#include "Track.h"
#include "Disc.h"

using std::cout;
using std::cin;
using std::endl;

Disc::Disc() {

  try {
    trackListPtr = std::make_unique<LinkedList<std::shared_ptr<Track> > >();
  } catch (std::bad_alloc&) {
    std::cerr << "ERROR: Memory allocation failed." << endl;
    throw;
  }
}

Disc::~Disc() {
  std::cerr << "Disc \"" << title << "\" destructor called." << std::endl;
}

bool Disc::yesOrNo() {

  std::string input;
  while (true) {
    getline(cin, input);

    if (input == "Y" || input == "y") {
      return true;
    } else if (input == "N" || input == "n") {
      return false;
    } else {
      input = "";
      cout << "Incorrect input. Please enter (Y/n): ";
    }
  }
}

bool Disc::isEmpty() const {
  return trackListPtr->isEmpty();
}

int Disc::getNumberOfTracks() const {
  return trackListPtr->getLength();
}

bool Disc::insertTrack(std::shared_ptr<Track> trackPtr) {

  // catch bad alloc and return success or not
  bool success;
  try {
    success = trackListPtr->insert(trackPtr->getNumber(), trackPtr);
  } catch (const std::bad_alloc&) {
    success = false;
    throw;
  }
  
  return success;
}

std::shared_ptr<Track> Disc::retrieveTrackByNumber(int number) const {

  if (number > 0 && number <= getNumberOfTracks() )
    return trackListPtr->getEntry(number);
  
  return nullptr;
}

std::string Disc::getArtist() const {
  return artist;
}

std::string Disc::getTitle() const {
  return title;
}

bool Disc::isMultiArtist() const {
  return multiArtist;
}

std::shared_ptr<Disc> Disc::getDiscFromUser() {

  // Make a new shared pointer to a disc object
  std::shared_ptr<Disc> disc;
  try {
    disc = std::make_shared<Disc>();
  } catch (const std::bad_alloc&) {
    throw;
    return nullptr;
  }

  // Read title of the disc
  cout << "Enter the title of this disc: ";
  getline(cin, disc->title);

  // Read if this disc is multiple artist
  cout << "Is this disc by mutliple artists? (Y/n): ";

  // (Y/n) input validation
  disc->multiArtist = yesOrNo();

  // Read in the artist of this disc
  std::string artist;
  if (disc->isMultiArtist() ) {
    artist = "Various Artists";
  } else {
    cout << "Enter the name of this disc's artist: ";
    getline(cin, artist);
  }
  disc->artist = artist;

  // Read in the release year of this disc
  cout << "Enter the year this disc was released: ";

  // Year input validation
  std::string input;
  while (true) {
    getline(cin, input);
    
    bool badInput = false;
    for (char c : input) {
      if (c < 48 || c > 57)
	badInput = true;
    }
    
    badInput = badInput || (input.length() != 4);
    
    if (!badInput) {
      disc->year = input;
      break;
    }

    cout << "Incorrect format. Please enter the year as a 4 digit number: ";
    input = "";
  }

  // Read in genre of the disc
  cout << "Enter the genre of this disc: ";
  getline(cin, disc->genre);

  // Read in tracks
  while (true) {
    cout << "\nWould you like to add a track to this disc? (Y/n): ";
    bool addTrack = yesOrNo();

    if (addTrack) {
      try {
	auto newTrack = Track::getTrackFromUser(disc);
	disc->insertTrack(newTrack);
	disc->addToTotalPlayTime(newTrack->getPlayTime() );
      } catch (const std::bad_alloc&) {
	throw;
      }
    } else {
      cout << endl;
      break;
    }
  }
  
  return disc;
}

void Disc::printDisc() const {

  // Print disc header of title and artist
  cout << "----- '" << getTitle() << "' by ";

  // Print artist, and by various artists if multiple
  if (isMultiArtist() ) {
    cout << "Various Artists";
  } else {
    cout << getArtist();
  }
  cout << " -----" << endl;

  // Print release year, genre, and number of tracks
  cout << "Year released: " << year << endl
       << "Genre: " << genre << endl
       << "Number of tracks: " << getNumberOfTracks() << endl;

  // Print the total play time of this disc
  int minutes = playTime / 60;
  int seconds = playTime % 60;
  cout << "Total play time: " << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << endl;

  // Print out all of the tracks under this disc
  for (int i(1); i <= trackListPtr->getLength(); ++i) {
    cout << endl;
    trackListPtr->getEntry(i)->printTrack();
  }
}

void Disc::addToTotalPlayTime(int seconds) {
  playTime += seconds;
}
