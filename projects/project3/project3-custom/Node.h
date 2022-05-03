#ifndef NODE_
#define NODE_

template <typename Type>
class Node {
private:
  Type value;
  Node<Type>* next = nullptr;
public:

  /** Default constructor */
  Node() = default;
  
  /** Parameterized constructor with next defaulting to nullptr */
  Node(const Type& value, Node<Type>* next = nullptr);

  /** Virtual destructor, default */
  virtual ~Node() = default;

  // make specs
  Type getValue() const;

  // make specs
  Node<Type>* getNext() const;

  // make specs
  void setValue(const Type& newValue);

  void setNext(Node<Type>* newNext);
}

#include "Node.cpp"

#endif // NODE_
