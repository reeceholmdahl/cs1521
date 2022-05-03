/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  Implementation file for a pointer-based implementation of the ADT
 *  list that uses smart pointers.
 *
 *  Adapted from pages 298-300 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 10 Mar 2021
 *
 *  @version 7.0 */

//#define NDEBUG

#include <string>
#include <new>
#include <memory>

#include <cassert>

#include "PrecondViolatedExcep.h"

template <typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {

   itemCount = aList.itemCount;

   if (aList.headPtr) {
      auto aListPtr(aList.headPtr);

      try {
         headPtr = std::make_shared<Node<ItemType>>(aListPtr->getItem() );

         auto thisListPtr(headPtr);

         aListPtr = aListPtr->getNext();

         while (aListPtr) {
            thisListPtr->setNext(
               std::make_shared<Node<ItemType>>(aListPtr->getItem())
                                 );

            thisListPtr = thisListPtr->getNext();
            aListPtr = aListPtr->getNext();
         }
      }
      catch (const std::bad_alloc&) {
         clear();
         throw;
      }
   }
}

#ifdef DTOR_TEST

#include <iostream>

template <typename ItemType>
LinkedList<ItemType>::~LinkedList() {

   std::cerr << "LinkedList destructor called on:\n"
             << "\theadPtr: "
             << headPtr
             << "\n"
             << "\titemCount: "
             << itemCount
             << std::endl;
}

#endif

template <typename ItemType>
bool LinkedList<ItemType>::isEmpty() const {

   return !itemCount;
}

template <typename ItemType>
int LinkedList<ItemType>::getLength() const {

   return itemCount;
}

template <typename ItemType>
bool LinkedList<ItemType>::insert(int newPosition,
                                  const ItemType& newEntry) {

   if (newPosition >= 1 && newPosition <= itemCount + 1) {
      try {
         if (newPosition == 1) {
            headPtr = std::make_shared<Node<ItemType>>(newEntry,
                                                       headPtr);
         }
         else {
            auto prevPtr(getNodeAt(newPosition - 1) );

            prevPtr->setNext(
               std::make_shared<Node<ItemType>>(newEntry,
                                                prevPtr->getNext())
                             );
         }

         ++itemCount;

         return true;
      }
      catch (const std::bad_alloc&) {
         return false;
      }
   }

   return false;
}

template <typename ItemType>
bool LinkedList<ItemType>::remove(int position) {

   if (position >= 1 && position <= itemCount) {
      if (position == 1) {
         headPtr = headPtr->getNext();
      }
      else {
         auto prevPtr(getNodeAt(position - 1) );

         auto curPtr(prevPtr->getNext() );

         prevPtr->setNext(curPtr->getNext() );
      }

      --itemCount;

      return true;
   }

   return false;
}

template <typename ItemType>
void LinkedList<ItemType>::clear() {

   headPtr = nullptr; // or headPtr.reset();
   itemCount = 0;
}

template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {

   if (position >= 1 && position <= itemCount) {
      auto nodePtr(getNodeAt(position) );

      return nodePtr->getItem();
   }

   std::string message("LinkedList::getEntry() called with an empty ");
   message += "list or an invalid position.";

   throw PrecondViolatedExcep(message);
}

template <typename ItemType>
ItemType LinkedList<ItemType>::replace(int position,
                                       const ItemType& newEntry) {

   if (position >= 1 && position <= itemCount) {
      auto nodePtr(getNodeAt(position) );

      ItemType oldEntry(nodePtr->getItem() );

      nodePtr->setItem(newEntry);

      return oldEntry;
   }

   std::string message("LinkedList::setEntry() called with an empty ");
   message += "list or an invalid position.";

   throw PrecondViolatedExcep(message);
}

template <typename ItemType>
auto LinkedList<ItemType>::getNodeAt(int position) const {

   assert(position >= 1 && position <= itemCount);

   auto curPtr(headPtr);

   for (int skip(1); skip < position; ++skip) {
      curPtr = curPtr->getNext();
   }

   return curPtr;
}
