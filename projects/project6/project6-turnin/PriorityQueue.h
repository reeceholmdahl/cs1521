/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  Header file for a sorted list-based implementation of the ADT
 *  priority queue.
 *
 *  Adapted from page 431 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 16 Mar 2021
 *
 *  @version 7.0 */

#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

#include <memory>

#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"

/** @class PriorityQueue PriorityQueue.h "PriorityQueue.h"
 *
 *  Specification of a sorted list-based ADT priority queue. */
template <typename ItemType>
class PriorityQueue : public PriorityQueueInterface<ItemType> {
private:
   std::unique_ptr<LinkedSortedList<ItemType>> sListPtr;

public:
   PriorityQueue();

   PriorityQueue(const PriorityQueue<ItemType>& pq);

   ~PriorityQueue() override = default;

   bool isEmpty() const override;

   bool enqueue(const ItemType& newEntry) override;

   bool dequeue() override;

   ItemType peekFront() const override;
};

#include "PriorityQueue.cpp"

#endif
