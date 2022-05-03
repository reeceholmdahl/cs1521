#ifndef DISC_LIST_
#define DISC_LIST_

#include <memory>

#include "LinkedList.h"
#include "Disc.h"

class DiscList {
private:

  /** Pointer to a list of pointers of discs. */
  std::unique_ptr<LinkedList<std::shared_ptr<Disc> > > discListPtr;
  
public:

  /** Default ctor. */
  DiscList();

  /** Virtual dtor. */
  virtual ~DiscList();

  /** Checks if the disc list is empty; contains no discs.
      @return True if there are no discs in the disc list, false otherwise. */
  virtual bool isEmpty() const;

  /** Gets the number of discs in the disc list. 
      @return The integer number of discs. */
  virtual int getNumberOfDiscs() const;

  /** Inserts a disc into the disc list.
      @pre 'discPtr' is a pointer to a valid disc object.
      @post If successful, this disc list contains one more disc.

      @param[in] discPtr A pointer to the disc object to insert.

      @return True if the disc was added successfully, false otherwise. */
  virtual bool insertDisc(std::shared_ptr<Disc> discPtr);

  /** Removes a disc from the disc list.
      @pre This disc list contains 'discPtr'. 
      @post If successful, this disc list no longer contains 'discPtr'.

      @param[in] discPtr A pointer to a the disc object to remove.

      @return True if the disc was removed successfully, false otherwise. */
  virtual bool removeDisc(std::shared_ptr<Disc> discPtr);

  /** Retrieves a disc from the disc list by means of its number.
      @pre A disc associated with the number is in this disc list.
      @post None.

      @param number The number of the disc to retrieve from the disc list.

      @return If successful, a pointer to the disc object associated with 'number' in the list. Otherwise, nullptr. */
  virtual std::shared_ptr<Disc> retrieveDisc(int number) const;
};

#endif // DISC_LIST_
