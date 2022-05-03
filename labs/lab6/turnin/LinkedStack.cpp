/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  Implementation file for a pointer-based implementation of the ADT
 *  stack.
 *
 *  Adapted from pages 246-8 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holt
 *  @author Reece Holmdahl (5727889)
 *
 *  @date 18 Feb 2021
 *
 *  @version 7.0 */

// #define NDEBUG

#include <memory>
#include <new>

#include <cassert>

template <typename ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack) {

   if (!aStack.topPtr) {
      topPtr = nullptr;
   }
   else {
     auto origChainPtr(aStack.topPtr);

     try {
       topPtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem() );

       auto newChainPtr(topPtr);

       origChainPtr = origChainPtr->getNext();

       while (origChainPtr) {
	 newChainPtr->setNext(std::make_shared<Node<ItemType>>(origChainPtr->getItem()) );

	 newChainPtr = newChainPtr->getNext();
	 origChainPtr = origChainPtr->getNext();
       }
      }
      catch (const std::bad_alloc&) {
         while (!isEmpty() ) {
            pop();
         }
         throw;
      }
   }
}

template <typename ItemType>
LinkedStack<ItemType>::~LinkedStack() {

   while (!isEmpty() ) {
      pop();
   }
}

template <typename ItemType>
bool LinkedStack<ItemType>::isEmpty() const {

   return !topPtr;
}

template <typename ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem) {

   try {
     topPtr = std::make_shared<Node<ItemType>>(newItem, topPtr);
   }
   catch (const std::bad_alloc&) {
      return false;
   }

   return true;
}

template <typename ItemType>
bool LinkedStack<ItemType>::pop() {

   if (!isEmpty() ) {
     topPtr = topPtr->getNext();

     return true;
   }

   return false;
}

template <typename ItemType>
ItemType LinkedStack<ItemType>::peek() const {

   assert(!isEmpty() );

   return topPtr->getItem();
}
