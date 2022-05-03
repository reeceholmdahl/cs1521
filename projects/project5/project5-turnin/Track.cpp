#include <memory>
#include <iostream>
#include <sstream>
#include <new>

#include "Track.h"
#include "Disc.h"

using std::cout;
using std::cin;
using std::endl;

Track::Track(std::shared_ptr<Disc> discPtr) {
  parentDisc = discPtr;
}

Track::~Track() {
  std::cerr << "Track \"" << name << "\" destructor called." << std::endl; 
}

int Track::readPlayTime() {

  std::string input;
  std::stringstream stream;
  
  int min;
  int sec;

  cout << "Enter the play time of this track with the format 'minutes:seconds': ";
  while (true) {
    getline(cin, input);

    bool invalid = false;

    int delims(0);
    for (char c : input) {
      if (c >= 48 && c <= 57)
	continue;
      else if (c == ':')
	++delims;
      else
	invalid = true;
    }

    invalid = invalid || (delims != 1);

    if (!invalid) {
      char delim;
      stream << input;

      stream >> min;
      stream >> delim;
      stream >> sec;

      if (delim == ':' && min >= 0 && sec >= 0 && sec <= 59)
	break;
    }

    stream.clear();
    input = "";
    cout << "Incorrect format. Please re-enter the play time in 'minutes:seconds': ";
  }
  
  return min * 60 + sec;
}

std::shared_ptr<Track> Track::getTrackFromUser(std::shared_ptr<Disc> discPtr) {

  // Make a new shared pointer to a track object.
  std::shared_ptr<Track> track;

  try {
    track = std::make_shared<Track>(discPtr);
  } catch (const std::bad_alloc&) {
    throw;
  }

  // Set the tracks number to the next available number in the disc
  track->number = discPtr->getNumberOfTracks() + 1;
  
  // Read name of track
  cout << "Enter the name of this track: ";
  getline(cin, track->name);

  // If multi artist, prompt, otherwise use the disc's artist
  std::string artist;
  if (discPtr->isMultiArtist() ) {
    cout << "Enter the name of this track's artist: ";
    getline(cin, artist);
  } else {
    artist = discPtr->getArtist();
  }
  track->artist = artist;

  // Read play time of track
  track->playTime = readPlayTime();
  
  // Read location of track in system
  cout << "Enter the location (path) of this track in the system: ";
  getline(cin, track->location);
  
  return track;
}

void Track::printTrack() const {

  // Lock weak pointer into a shared pointer locally in this method
  auto parentDisc = this->parentDisc.lock();
  
  // Print the track number and name
  cout << "--- '" << parentDisc->getTitle() << "' Track Number " << getNumber() << " ---" << endl
       << "Name: " << name << endl;

  // If the parent disc is multi artist, print the artist of this track
  if (parentDisc->isMultiArtist() )
    cout << "Artist: " << artist << endl;

  // Derive minutes and seconds from total seconds
  int duration = getPlayTime();
  int minutes = duration / 60;
  int seconds = duration % 60;

  // Print the play time and location in the system
  cout << "Play time: " << minutes << ":" << seconds << endl
       << "Location in system: " << location << endl;
}

int Track::getNumber() const {
  return number;
}

int Track::getPlayTime() const {
  return playTime;
}
