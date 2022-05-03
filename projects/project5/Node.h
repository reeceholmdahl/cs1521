/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  Header file for a node that uses smart pointers.
 *
 *  Adapted from page 296 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 10 Mar 2021
 *
 *  @version 7.0 */

#ifndef NODE_
#define NODE_

#include <memory>

/** @class Node Node.h "Node.h"
 *
 *  Specification of a smart pointer-based ADT node. */
template <typename ItemType>
class Node {
private:
   ItemType item;

   /** Default constructed to nullptr. */
   std::shared_ptr<Node<ItemType>> next;

public:
   /** Default constructor. */
   Node() = default;

   /** One- and two-arg constructor. */
   explicit Node(const ItemType& anItem,
                 std::shared_ptr<Node<ItemType>> nextNodePtr = nullptr);

#ifdef DTOR_TEST
   /** Destructor that outputs message when called. Note: Not declared
       virtual as this class should not be used as a base class. */
   ~Node();
#else
   /** Destructor. */
   ~Node() = default;
#endif

   /** Sets the item in this node.
    *
    * @pre None.
    *
    * @post The item in this node has been set to anItem.
    *
    * @param anItem The new item to put in this node. */
   void setItem(const ItemType& anItem);

   /** Sets the next pointer in this node.
    *
    * @pre None.
    *
    * @post The next pointer in this node has been set to
    *       nextNodePtr.
    *
    * @param nextNodePtr The new pointer that this node should point
    *        at. */
   void setNext(const std::shared_ptr<Node<ItemType>>& nextNodePtr);

   /** Gets the item in this node.
    *
    * @pre None.
    *
    * @post None.
    *
    * @return The item in this node. */
   ItemType getItem() const;

   /** Gets the next pointer in this node.
    *
    * @pre None.
    *
    * @post None.
    *
    * @return The next pointer in this node. */
   auto getNext() const;
};

#include "Node.cpp"

#endif
