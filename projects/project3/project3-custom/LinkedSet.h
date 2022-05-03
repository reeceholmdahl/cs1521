#ifndef LINKED_SET_
#define LINKED_SET_

#include "SetInterface.h"
#include "Node.h"

template <typename ItemType>
class LinkedSet : public SetInterface<ItemType> {
private:

  /** Type alias for a pointer to a node of ItemType */
  using NodePtr = Node<ItemType>*;

  /** Head pointer of the linked chain */
  NodePtr headPtr = nullptr;

  /** Count of elements in this set; number of nodes in the linked chain */
  int size = 0;

  // make specs
  NodePtr getPointerTo(const ItemType& target) const;
  
public:

  /** Default constructor */
  LinkedSet() = default;

  /** Explicit copy constructor */
  LinkedSet(const LinkedSet<ItemType>& otherSet);

  /** Virtual destructor, not default */
  virtual ~LinkedSet();

  virtual int getCurrentSize() const;

  virtual bool isEmpty() const;

  virtual bool add(const ItemType& newElement);

  virtual bool remove(const ItemType& anElement);

  virtual void clear();

  virtual int getFrequencyOf(const ItemType& anElement) const;

  virtual bool contains(const ItemType& anElement) const;

  virtual std::vector<ItemType> toVector() const;

  /** Creates a new set containing all of the items in this set that are not in 'set2'.
      @param[in] set2 The LinkedSet of the same item type to take the difference with.
      
      @return The LinkedSet of the same item type representing the difference between this set and 'set2'. */
  virtual LinkedSet<ItemType> difference(const LinkedSet<ItemType>& set2) const;
}

#include "LinkedSet.cpp"

#endif // LINKED_SET_
