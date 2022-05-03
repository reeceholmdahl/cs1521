// My ID: 5727889

/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  Implementation file for an array-based implementation of the ADT
 *  list.
 *
 *  Adapted from pages 268-272 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 4 Mar 2021
 *
 *  @version 7.0 */

#include <string>
#include <utility>

#include "PrecondViolatedExcep.h"

template <typename ItemType>
bool ArrayList<ItemType>::isEmpty() const {

   return !itemCount;
}

template <typename ItemType>
int ArrayList<ItemType>::getLength() const {

   return itemCount;
}

template <typename ItemType>
bool ArrayList<ItemType>::insert(int newPosition,
                                 const ItemType& newEntry) {

   if (newPosition >= 1 && newPosition <= itemCount + 1 &&
       itemCount < DEFAULT_CAPACITY) {
      // Make room for 'newEntry' by shifting all entries at positions
      // >= 'newPosition' toward the end of the array:
      for (int pos(itemCount); pos >= newPosition; --pos) {
         items[pos] = items[pos - 1];
      }

      // Insert new entry:
      items[newPosition - 1] = newEntry;

      ++itemCount;

      return true;
   }

   return false;
}

template <typename ItemType>
bool ArrayList<ItemType>::remove(int position) {

   if (position >= 1 && position <= itemCount) {
      // Remove entry by shifting all entries after the one at
      // position toward the beginning of the array:
      for (int pos(position); pos < itemCount; ++pos) {
         items[pos - 1] = items[pos];
      }
      --itemCount;

      return true;
   }

   return false;
}

template <typename ItemType>
void ArrayList<ItemType>::clear() {

   itemCount = 0;
}

template <typename ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {

   if (position >= 1 && position <= itemCount) {
      return items[position - 1];
   }

   std::string message("ArrayList::getEntry() called with an empty ");
   message += "list or an invalid position.";

   throw PrecondViolatedExcep(message);
}

template <typename ItemType>
ItemType ArrayList<ItemType>::replace(int position,
                                      const ItemType& newEntry) {

   if (position >= 1 && position <= itemCount) {
      ItemType oldEntry(items[position - 1]);

      items[position - 1] = newEntry;

      return oldEntry;
   }

   std::string message("ArrayList::replace() called with an empty ");
   message += "list or an invalid position.";

   throw PrecondViolatedExcep(message);
}

template <typename ItemType>
void ArrayList<ItemType>::sort() {
  
  // Sorted array: [0, unsorted), Unsorted array [unsorted, itemCount - 1]
  for (int unsorted(1); unsorted < itemCount; ++unsorted) {

    // The item to insert at the searched location
    ItemType toInsert(items[unsorted]);

    // Location in the sorted array starting at rightmost index
    int loc(unsorted);
    while (loc > 0 && items[loc - 1] > toInsert) {

      // Shift item at [loc - 1] to the right 1
      items[loc] = items[loc - 1];
      
      loc--;
    }

    // At this point, loc is at the right spot to insert the item
    items[loc] = toInsert;
  }
}

