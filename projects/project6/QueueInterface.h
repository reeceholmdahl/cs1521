/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  QueueInterface class template definition.
 *
 *  Adapted from page 396 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 10 Mar 2021
 *
 *  @version 7.0 */

#ifndef QUEUE_INTERFACE_
#define QUEUE_INTERFACE_

/** @class QueueInterface QueueInterface.h "QueueInterface.h"
 *
 *  Definition of QueueInterface class template. */
template <typename ItemType>
class QueueInterface {
public:
   /** Virtual destructor. */
   virtual ~QueueInterface() = default;

   /** Sees whether this queue is empty.
     *
     *  @return True if the queue is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Adds a new entry to the back of this queue.
     *
     *  @post If successful, newEntry is stored at the back of this
     *        queue.
     *
     *  @param newEntry The object to be added as a new entry.
     *
     *  @return True if addition was successful, or false if not. */
    virtual bool enqueue(const ItemType& newEntry) = 0;

    /** Removes the front of this queue.
     *
     *  @post If successful, the front of this queue has been
     *        removed.
     *
     *  @return True if removal was successful, or false if not. */
    virtual bool dequeue() = 0;

    /** Retrieves the front of this queue.
     *
     *  @pre This queue is not empty.
     *
     *  @post None.
     *
     *  @throws PrecondViolatedExcep If precondition is violated.
     *
     *  @return The front entry in this queue. */
   virtual ItemType peekFront() const = 0;
};

#endif
