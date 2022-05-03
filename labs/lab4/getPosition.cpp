// My ID#: 5727889
template <typename ItemType>
int getPosition(const ListInterface<ItemType>& list, const ItemType& target) {

  // Length of list
  int size = list.getLength();

  // Iterate through length starting at 1 going to (inclusive) size.
  for (int i(1); i <= size; ++i) {

    // If the entry at this position is the target, return this position.
    if (list.getEntry(i) == target) {
      return i;
    }
  }

  // If it's made it here, there is no 'target' in 'list'; return a number higher than the size of the list to indicate so.
  return size + 1;
}
