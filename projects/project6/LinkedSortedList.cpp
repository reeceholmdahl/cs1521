/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  Implementation file for a pointer-based implementation of the ADT
 *  sorted list.
 *
 *  Adapted from pages 374-377 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 16 Mar 2021
 *
 *  @version 7.0 */

// #define NDEBUG

#include <string>
#include <new>
#include <memory>

#include <cassert>

#include "PrecondViolatedExcep.h"

template <typename ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList) {

   try {
      headPtr = copyChain(aList.headPtr);

      itemCount = aList.itemCount;
   }
   catch (const std::bad_alloc&) {
      clear();
      throw;
   }
}

template <typename ItemType>
auto LinkedSortedList<ItemType>::copyChain(const NodePtr& origChainPtr) {

   NodePtr copiedChainPtr;

   if (!origChainPtr) {
      return copiedChainPtr;
   }

   copiedChainPtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem() );

   copiedChainPtr->setNext(copyChain(origChainPtr->getNext()) );

   return copiedChainPtr;
}

template <typename ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const {

   return !itemCount;
}

template <typename ItemType>
int LinkedSortedList<ItemType>::getLength() const {

   return itemCount;
}

template <typename ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry) {

   try {
      auto prevPtr(getNodeBefore(newEntry) );

      if (isEmpty() || !prevPtr) {
         headPtr = std::make_shared<Node<ItemType>>(newEntry,
                                                    headPtr);
      }
      else {
         prevPtr->setNext(
            std::make_shared<Node<ItemType>>(newEntry,
                                             prevPtr->getNext())
                          );
      }

      ++itemCount;
   }
   catch (const std::bad_alloc&) {
      return false;
   }

   return true;
}

template <typename ItemType>
auto LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const {

   auto curPtr(headPtr);
   NodePtr prevPtr;

   // >
   while (curPtr && anEntry <= curPtr->getItem() ) {
     prevPtr = curPtr;
     curPtr = curPtr->getNext();
   }

   return prevPtr;
}

template <typename ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry) {

   int position(getPosition(anEntry) );

   if (position > 0) {
      return remove(position);
   }

   return false;
}

template <typename ItemType>
bool LinkedSortedList<ItemType>::remove(int position) {

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
void LinkedSortedList<ItemType>::clear() {

   headPtr = nullptr;
   itemCount = 0;
}

template <typename ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const {

   if (position >= 1 && position <= itemCount) {
      auto nodePtr(getNodeAt(position) );

      return nodePtr->getItem();
   }

   std::string message("LinkedSortedList::getEntry() called with an empty ");
   message += "list or an invalid position.";

   throw PrecondViolatedExcep(message);
}

template <typename ItemType>
auto LinkedSortedList<ItemType>::getNodeAt(int position) const {

   assert(position >= 1 && position <= itemCount);

   auto curPtr(headPtr);

   for (int skip(1); skip < position; ++skip) {
      curPtr = curPtr->getNext();
   }

   return curPtr;
}

template <typename ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& anEntry) const {

   int pos(1);
   auto curPtr(headPtr);
   bool foundIt(false);

   while (!foundIt && curPtr && anEntry >= curPtr->getItem() ) {
      if (curPtr->getItem() == anEntry) {
         foundIt = true;
      }
      else {
         curPtr = curPtr->getNext();
         ++pos;
      }
   }

   if (!foundIt) {
      pos = -pos;
   }

   return pos;
}
