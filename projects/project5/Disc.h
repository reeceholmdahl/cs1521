#ifndef DISC_
#define DISC_

#include <memory>
#include <string>

#include "LinkedList.h"
#include "Track.h"

class Track;

class Disc {
private:

  /** The name of the artist(s) of this disc. */
  std::string artist;

  /** The title of this disc. */
  std::string title;

  /** If this disc is made by multiple artists or not. */
  bool multiArtist;

  /** The total play time in seconds of this disc. */
  int playTime = 0;

  /** The year the disc was created. */
  std::string year;

  /** The disc's genre. */
  std::string genre;

  /** A pointer to a list of pointers of track objects; all the tracks of this disc. */
  std::unique_ptr<LinkedList<std::shared_ptr<Track> > > trackListPtr;

  /** Modularized (Y/n) validation.
      @return True if the Y/y is entered through stdin, or false if N/n is entered through stdin. */
  static bool yesOrNo();
  
public:

  /** Default ctor. */
  Disc();

  /** Virtual dtor. */
  virtual ~Disc();

  /** Checks if the disc is empty; contains no tracks.
      @return True if there are no tracks on this disc, false otherwise. */
  virtual bool isEmpty() const;

  /** Gets the number of tracks on this disc. 
      @return The integer number of tracks. */
  virtual int getNumberOfTracks() const;

  /** Inserts a track on to this disc.
      @pre 'trackPtr' is a pointer to a valid track object.
      @post This disc contains one more track and its play time has been increased by the amount on 'trackPtr'.

      @param[in] trackPtr A pointer to the track object to insert.

      @return True if the track was added successfully, false otherwise. */
  virtual bool insertTrack(std::shared_ptr<Track> trackPtr);

  /** Retrieves a track from this disc using its number.
      @pre This disc must contain a track with the number 'number'.

      @param number The number of the track to retrieve.

      @return A pointer to the track retrieved. */
  virtual std::shared_ptr<Track> retrieveTrackByNumber(int number) const;

  /** Gets the artist(s) of this disc. 
      @return String containing the artist(s) of this disc. If there are multiple, they are comma separated. */
  virtual std::string getArtist() const;

  /** Gets the title of this disc.
      @return String title of this disc. */
  virtual std::string getTitle() const;

  /** Checks if this disc is made by multiple artists. 
      @return True if it is made by multiple artists, false otherwise. */
  virtual bool isMultiArtist() const;

  /** Reads in data from stdin about a disc and yields a pointer to a new disc object.
      @return A pointer to a new disc object representing the information entered. */
  static std::shared_ptr<Disc> getDiscFromUser();

  /** Outputs information about this disc to stdout. */
  virtual void printDisc() const;

  /** Adds time to the total play time of this disc, in seconds.
      @param seconds The amount of seconds to add to the play time of this disc. */
  virtual void addToTotalPlayTime(int seconds);
};

#endif // DISC_
