/* Implement parameterized constructor */
template <typename Type>
Node<Type>::Node(const Type& p_value, Node<Type>* p_next) : value(p_value), next(p_next) {
}

/* Implement destructor */
template <typename Type>
Node<Type>::~Node() {
} // STUB

/* Implement getValue */
template <typename Type>
Type& Node<Type>::getValue() {
  return value;
}

/* Implement getNext */
template <typename Type>
Node<Type>* Node<Type>::getNext() const {
  return next;
}

/* Implement setValue */
template <typename Type>
void Node<Type>::setValue(const Type& newValue) {
  value = newValue;
}

/* Implement setNext */
template <typename Type>
void Node<Type>::setNext(Node<Type>* newNext) {
  next = newNext;
}
