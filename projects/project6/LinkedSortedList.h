/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  Header file for a pointer-based implementation of the ADT sorted
 *  list.
 *
 *  Adapted from pages 373-374 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 16 Mar 2021
 *
 *  @version 7.0 */

#ifndef LINKED_SORTED_LIST_
#define LINKED_SORTED_LIST_

#include <memory>

#include "SortedListInterface.h"
#include "Node.h"

/** @class LinkedSortedList LinkedSortedList.h "LinkedSortedList.h"
 *
 *  Specification of a pointer-based ADT sorted list. */
template <typename ItemType>
class LinkedSortedList : public SortedListInterface<ItemType> {
private:
   using NodePtr = std::shared_ptr<Node<ItemType>>;

   NodePtr headPtr;

   int itemCount = 0;

   /** Locates the node that is before the node that does or should
    *  contain the given entry.
    *
    * @pre None.
    *
    * @post None.
    *
    * @param anEntry The entry to find.
    *
    * @return Either a pointer to the node before the node that
    *         contains or should contain the given entry, or nullptr
    *         if no prior node exists. */
   auto getNodeBefore(const ItemType& anEntry) const;

   auto getNodeAt(int position) const;

   /** Copy the chain of nodes pointed to by origChainPtr.
    *
    * @pre None.
    *
    * @post None.
    *
    * @param origChainPtr A pointer to the chain of nodes to copy.
    *
    * @return A pointer to a copy of the nodes pointed to by
    *         origChainPtr.
    *
    * @throws std::bad_alloc When memory allocation fails.
    */
   auto copyChain(const NodePtr& origChainPtr);

public:
   LinkedSortedList() = default;

   LinkedSortedList(const LinkedSortedList<ItemType>& aList);

   ~LinkedSortedList() override = default;

   bool isEmpty() const override;

   int getLength() const override;

   bool insertSorted(const ItemType& newEntry) override;

   bool removeSorted(const ItemType& anEntry) override;

   bool remove(int position) override;

   void clear() override;

   ItemType getEntry(int position) const override;

   int getPosition(const ItemType& newEntry) const override;
};

#include "LinkedSortedList.cpp"

#endif
