/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  Implementation file for a pointer-based implementation of the ADT
 *  list.
 *
 *  Adapted from pages 274-281 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 26 Feb 2021
 *
 *  @version 7.0 */

// #define NDEBUG

#include <string>
#include <new>

#include <cassert>

#include "PrecondViolatedExcep.h"

template <typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {

   itemCount = 0; // Initialize an empty list (by def of isEmpty).

   if (!aList.headPtr) {
      headPtr = nullptr;
   }
   else {
      NodePtr aListPtr(aList.headPtr);

      try {
         headPtr = new Node<ItemType>(aListPtr->getItem() );

         ++itemCount; // Increment after successful call to new

         NodePtr thisListPtr(headPtr);

         aListPtr = aListPtr->getNext();

         while (aListPtr) {
            thisListPtr->setNext(new Node<ItemType>(aListPtr->getItem()) );

            ++itemCount; // Increment after each successful call to new

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

template <typename ItemType>
LinkedList<ItemType>::~LinkedList() {

   clear();
}

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
            headPtr = new Node<ItemType>(newEntry,
                                         headPtr);
         }
         else {
            NodePtr prevPtr(getNodeAt(newPosition - 1) );

            prevPtr->setNext(new Node<ItemType>(newEntry,
                                                prevPtr->getNext()) );
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
      NodePtr nodeToDeletePtr(nullptr);

      if (position == 1) {
         nodeToDeletePtr = headPtr;
         headPtr = headPtr->getNext();
      }
      else {
         NodePtr prevPtr(getNodeAt(position - 1) );

         nodeToDeletePtr = prevPtr->getNext();

         prevPtr->setNext(nodeToDeletePtr->getNext() );
      }

      delete nodeToDeletePtr;

      --itemCount;

      return true;
   }

   return false;
}

template <typename ItemType>
void LinkedList<ItemType>::clear() {

   while (!isEmpty() ) {
      remove(1);
   }
}

template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {

   if (position >= 1 && position <= itemCount) {
      NodePtr nodePtr(getNodeAt(position) );

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
      NodePtr nodePtr(getNodeAt(position) );

      ItemType oldEntry(nodePtr->getItem() );

      nodePtr->setItem(newEntry);

      return oldEntry;
   }

   std::string message("LinkedList::replace() called with an empty ");
   message += "list or an invalid position.";

   throw PrecondViolatedExcep(message);
}

template <typename ItemType>
Node<ItemType>*
LinkedList<ItemType>::getNodeAt(int position) const {

   assert(position >= 1 && position <= itemCount);

   NodePtr curPtr(headPtr);

   for (int skip(1); skip < position; ++skip) {
      curPtr = curPtr->getNext();
   }

   return curPtr;
}
