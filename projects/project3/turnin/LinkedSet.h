/** @file
 
    @course CS1521
    @section 9
    @term Spring 2021
 
    Header file for a linked implementation of the ADT set.
 
    Adapted from page 139 in Carrano 7e.

    @author Frank M. Carrano
    @author Timothy Henry
    @author Steve Holtz
    @author Reece Holmdahl (5727889)
 
    @date 20 Feb 2021
 
    @version 7.0 */

#ifndef LINKED_SET_
#define LINKED_SET_

#include <vector>

#include "SetInterface.h"
#include "Node.h"

/** @class LinkedSet LinkedSet.h "LinkedSet.h"
    Specification of a pointer-based ADT set. */
template <typename ItemType>
class LinkedSet : public SetInterface<ItemType> {
private:
  
  /** Define nested data type 'NodePtr'. Create a more "friendly" type name for a pointer-to-a-node-of-ItemType. */
  using NodePtr = Node<ItemType>*;

  /** Pointer to first node in this LinkedSet's linked chain.
      Default initialized to 'nullptr', which is an empty linked chain. */
  NodePtr headPtr = nullptr;

  /** Number of items in this set. An empty set has no (zero) items. */
  int itemCount = 0;

  /** Gets a pointer to the node containing the target in this set.
      @pre None.
      @post None.
   
      @param target The 'ItemType' value to find.
   
      @return A pointer to the node that contains the given 'target' or 'nullptr' if this set does not contain 'target'. */
  NodePtr getPointerTo(const ItemType& target) const;

public:
  
  /** Default constructor. */
  LinkedSet() = default;

  /** Copy constructor. */
  LinkedSet(const LinkedSet<ItemType>& aSet);

  virtual ~LinkedSet();

  virtual int getCurrentSize() const;

  virtual bool isEmpty() const;

  virtual bool add(const ItemType& newEntry);

  virtual bool remove(const ItemType& anEntry);

  virtual void clear();

  virtual int getFrequencyOf(const ItemType& anEntry) const;

  virtual bool contains(const ItemType& anEntry) const;

  virtual std::vector<ItemType> toVector() const;

  /** Creates a new set containing all of the items in this set that are not in 'set2'.
      @param[in] set2 The LinkedSet of the same item type to take the difference with.
      
      @return The LinkedSet of the same item type representing the difference between this set and 'set2'. */
  virtual LinkedSet<ItemType> difference(const LinkedSet<ItemType>& set2) const;
};

#include "LinkedSet.cpp"

#endif
