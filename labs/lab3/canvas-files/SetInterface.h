/** @file
 
    @course CS1521
    @section 9
    @term Spring 2021
 
    SetInterface class template definition adapted from BagInterface.

    Adapted from page 24-25 in Carrano 7e.
 
    @author Frank M. Carrano
    @author Timothy Henry
    @author Steve Holtz
    @author Reece Holmdahl (5727889)
 
    @date 13 Feb 2021
    
    @version 7.0 */

#ifndef SET_INTERFACE_
#define SET_INTERFACE_

#include <vector>

/** @class SetInterface SetInterface.h "SetInterface.h"
    SetInterface abstract base class template. */
template <typename ItemType>
class SetInterface {
public:
  
  /** Virtual destructor. */
  virtual ~SetInterface() {}

  /** Gets the current number of elements in this set.
      @return The integer number of elements currently in the set. */
  virtual int getCurrentSize() const = 0;

  /** Checks whether this set is the empty set.
      @return True if the set contains no elements, or false if otherwise. */
  virtual bool isEmpty() const = 0;

  /** Adds a new element to this set.
      @pre There must not already be an instance of newElement within the set.

      @post If successful, newElement is an element of the set and the size of the set has increased by 1.

      @param[in] newElement The object to be added as a new element.

      @return True if the addition was successful, or false is not. */
  virtual bool add(const ItemType& newElement) = 0;

  /** Removes an element from this set if possible.
      @pre There must be an instance of anElement within the set.

      @post If successful, anElement was removed from the set and the size of the set has decreased by 1.

      @param[in] anElement The value of the element to be removed.

      @return True if the removal was successful, or false if not. */
  virtual bool remove(const ItemType& anElement) = 0;

  /** Removes all elements from this set. It becomes the empty set.
      @post This set contains no elements and its size is 0. */
  virtual void clear() = 0;

  /** Counts the number of times a given element appears in the set.
      @param[in] anElement The value of the element to be counted.

      @return The number of times anElement appears in the set.*/
  virtual int getFrequencyOf(const ItemType& anElement) const = 0;

  /** Checks whether this set contains a given element.
      @param[in] anElement The value of the element to locate.

      @return True if this set contains anElement, or false if not. */
  virtual bool contains(const ItemType& anElement) const = 0;

  /** Converts this set into a vector.
      @return A vector containing each element of this set. */
  virtual std::vector<ItemType> toVector() const = 0;
};

#endif // SET_INTERFACE_
