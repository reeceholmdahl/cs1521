#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <vector>

#include "node.hpp"

using std::vector;

template <typename Type>
class LinkedList {
private:

  /* Type alias to make things a little easier */
  using nodePtr = Node<Type>*;

  /* Head of the list */
  nodePtr head;

  /* Size of the list */
  int size;

public:

  /* Default constructor? */
  LinkedList();

  /* Copy constructor */
  LinkedList(const LinkedList& list);

  /* Virtual destructor */
  virtual ~LinkedList();

  /* Adds an item to the list */
  void add(const Type& item);

  /* Removes the first occurrence of an item from the list */
  bool remove(const Type& item);

  /* Gets size of list */
  int getSize() const;

  /* Array style access overload */
  Type& operator [] (int index) const;

  /* Show elements as a vector */
  vector<Type> toVector() const;
};

#include "linked-list.cpp"

#endif // LINKED_LIST_
