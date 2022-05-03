#ifndef NODE_
#define NODE_

template <typename Type>
class Node {
private:

  /* The item in this node */
  Type value;

  /* The pointer to the next node */
  Node<Type>* next;
public:

  /* Default constructor */
  Node<Type>() = default;

  /* Parameterized constructor */
  Node<Type>(const Type& p_value, Node<Type>* p_next = nullptr);

  /* Virtual destructor NOT declared default */

  virtual ~Node<Type>();

  /* Get the value contained within this node */
  Type& getValue();

  /* Get the next node */
  Node<Type>* getNext() const;

  /* Set the value contained within this node */
  void setValue(const Type& newValue);

  /* Set the pointer to the next node */
  void setNext(Node<Type>* newNext);
};

#include "node.cpp"

#endif // NODE_
