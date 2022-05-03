#ifndef ORDERED_LINKED_LIST_
#define ORDERED_LINKED_LIST_

#include "node.hpp"

template <typename T>
class OrderedLinkedList : public LinkedList<T> {
private:

  using nodePtr = Node<T>*;

  nodePtr head;

  int size;
public:

  /* Default constructor NOT synthesized */
  OrderedLinkedList();

  /* Copy constructor */
  OrderedLinkedList(const LinkedList& list);

  /* Virtual destructor */
  ~OrderedLinkedList();
};

#endif // ORDERED_LINKED_LIST_
