// My ID: 5727889

#include <iostream>

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNode::BinaryNode(const ItemType& anItem, BinaryNodePtr leftPtr, BinaryNodePtr rightPtr) : item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr) {
}

#ifdef DTOR_TEST
template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNode::~BinaryNode() {
  std::cerr << "Destructor called on binary node." << std::endl;
}
#endif
