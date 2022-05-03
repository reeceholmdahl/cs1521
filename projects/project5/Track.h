#ifndef TRACK_
#define TRACK_

#include <memory>
#include <string>

#include "Disc.h"

class Disc;

class Track {
private:

  /** Initialized a weak pointer to the parent disc. */
  std::weak_ptr<Disc> parentDisc;

  /** The track number this track is in the parent disc. */
  int number;

  /** The name of this track. */
  std::string name;

  /** The name of the artist of this track. */
  std::string artist;

  /** The playtime in seconds of this track. */
  int playTime;

  /** The path/filename (location) where the track is stored in the system. */
  std::string location;

  /** Static utility method that reads in play time in the form 'minutes:seconds' and converts it to an int of seconds. */
  static int readPlayTime();
  
public:

  /** No default ctor. */
  Track() = delete;
  
  /** Ctor, associates this track with the disc of discPtr. */
  Track(std::shared_ptr<Disc> discPtr);

  /** Virtual dtor. */
  virtual ~Track();

  /** Reads in information about a track from stdin and yields a pointer to a new track object.
      @pre 'discPtr' is a shared pointer to a disc.
      @post None.

      @param[in] discPtr The pointer to the parent disc of this track.

      @return A shared pointer of the track newly created. */
  static std::shared_ptr<Track> getTrackFromUser(std::shared_ptr<Disc> discPtr);

  /** Prints information about this track to stdout. */
  virtual void printTrack() const;

  /** Gets the number of this track on the parent disc.
      @return Integer number of this track. */
  virtual int getNumber() const;

  /** Gets the play time in seconds of this track.
      @return Integer play time representing duration in seconds. */
  virtual int getPlayTime() const;
};

#endif // TRACK_
