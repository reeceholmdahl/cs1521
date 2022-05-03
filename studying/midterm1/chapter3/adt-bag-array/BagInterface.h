/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  BagInterface class template definition.
 *
 *  Adapted from page 24-25 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 28 Jan 2021
 *
 *  @version 7.0 */

#ifndef BAG_INTERFACE_
#define BAG_INTERFACE_

#include <vector>

/** @class BagInterface BagInterface.h "BagInterface.h"
 *
 *  BagInterface abstract base class template. */
template <typename ItemType>
class BagInterface {
public:
   /** Virtual destructor. (See C++ Interlude 2.) */
   virtual ~BagInterface() {}

   /** Gets the current number of entries in this bag.
    *
    *  @return The integer number of entries currently in the bag. */
   virtual int getCurrentSize() const = 0;

   /** Sees whether this bag is empty.
    *
    *  @return True if the bag is empty, or false if not. */
   virtual bool isEmpty() const = 0;

   /** Adds a new entry to this bag.
    *
    *  @post If successful, newEntry is stored in the bag and the
    *        count of items in the bag has increased by 1.
    *
    *  @param newEntry The object to be added as a new entry.
    *
    *  @return True if addition was successful, or false if not. */
   virtual bool add(const ItemType& newEntry) = 0;

   /** Removes one occurrence of a given entry from this bag, if
    *  possible.
    *
    *  @post If successful, anEntry has been removed from the bag and
    *        the count of items in the bag has decreased by 1.
    *
    *  @param anEntry The value of the entry to be removed.
    *
    *  @return True if removal was successful, or false if not. */
   virtual bool remove(const ItemType& anEntry) = 0;

   /** Removes all entries from this bag.
    *
    *  @post This bag contains no items (thus the count is 0). */
   virtual void clear() = 0;


   /** Counts the number of times a given entry appears in bag.
    *
    *  @param anEntry The value of the entry to be counted.
    *
    *  @return The number of times anEntry appears in this bag. */
   virtual int getFrequencyOf(const ItemType& anEntry) const = 0;

   /** Tests whether this bag contains a given entry.
    *
    *  @param anEntry The value of the entry to locate.
    *
    *  @return True if this bag contains anEntry, or false
    *          otherwise. */
   virtual bool contains(const ItemType& anEntry) const = 0;

   /** Converts this bag into a vector.
    *
    *  @return A vector containing all the entries in this bag. */
   virtual std::vector<ItemType> toVector() const = 0;
};

#endif
