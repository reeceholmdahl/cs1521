/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  PriorityQueueInterface class template definition.
 *
 *  Not in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 10 Mar 2021
 *
 *  @version 7.0 */

#ifndef PRIORITY_QUEUE_INTERFACE_
#define PRIORITY_QUEUE_INTERFACE_

/** @class PriorityQueueInterface PriorityQueueInterface.h "PriorityQueueInterface.h"
 *
 *  Definition of PriorityQueueInterface class template. */
template <typename ItemType>
class PriorityQueueInterface {
public:
   /** Virtual destructor . */
   virtual ~PriorityQueueInterface() = default;

   /** Sees whether this queue is empty.
     *
     *  @return True if the queue is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Adds a new entry to this priority queue.
     *
     *  @pre The template parameter type, ItemType, *must* implement a
     *       full range of relational operator overloads: <, >, <=,
     *       >=, ==, and !=.
     *
     *  @post If successful, newEntry is stored at its correct
     *        position in this priority queue.
     *
     *  @param newEntry The object to be added as a new entry.
     *
     *  @return True if addition was successful, or false if not. */
    virtual bool enqueue(const ItemType& newEntry) = 0;

    /** Removes the front of this priority queue.
     *
     *  @post If successful, the front of this priority queue has been
     *        removed.
     *
     *  @return True if removal was successful, or false if not. */
    virtual bool dequeue() = 0;

    /** Retrieves the front of this priority queue.
     *
     *  @pre This priority queue is not empty.
     *
     *  @post None.
     *
     *  @throws PrecondViolatedExcep If the precondition is violated.
     *
     *  @return The front entry in this priority queue. */
   virtual ItemType peekFront() const = 0;
};

#endif
