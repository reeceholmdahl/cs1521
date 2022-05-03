/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  Header file for a pointer-based implementation of the ADT list
 *  that uses smart pointers.
 *
 *  Adapted from pages 297-298 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 10 Mar 2021
 *
 *  @version 7.0 */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <memory>

#include "ListInterface.h"
#include "Node.h"

/** @class LinkedList LinkedList.h "LinkedList.h"
 *
 *  Specification of a smart pointer-based ADT list. */
template <typename ItemType>
class LinkedList : public ListInterface<ItemType> {
private:
   // Note: Automatically initialized to nullptr:
   std::shared_ptr<Node<ItemType>> headPtr;

   int itemCount = 0;

   /** Locates the node at the specified position in this list.
    *
    *  @pre 1 <= position <= itemCount
    *
    *  @post None.
    *
    *  @param position The desired position to locate.
    *
    *  @return A std::shared_ptr to the position-th node in this list.
    */
   auto getNodeAt(int position) const;

public:
   LinkedList() = default;

   LinkedList(const LinkedList<ItemType>& aList);

#ifdef DTOR_TEST
   virtual ~LinkedList();
#else
   virtual ~LinkedList() = default;
#endif

   virtual bool isEmpty() const;

   virtual int getLength() const;

   virtual bool insert(int newPosition,
                       const ItemType& newEntry);

   virtual bool remove(int position);

   virtual void clear();

   virtual ItemType getEntry(int position) const;

   virtual ItemType replace(int position,
                            const ItemType& newEntry);
};

#include "LinkedList.cpp"

#endif
