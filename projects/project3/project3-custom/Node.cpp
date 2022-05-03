template <typename Type>
Node<Type>::Node(const Type& value, Node<Type>* next) {
  setValue(value);
  setNext(next);
}

Type Node<Type>::getValue() const {
  return value;
}

Node<Type>* Node<Type>::getNext() const {
  return next;
}

void Node<Type>::setValue(const Type& newValue) {
  value = newValue;
}

void Node<Type>::setNext(Node<Type>* newNext) {
  next = newNext;
}
