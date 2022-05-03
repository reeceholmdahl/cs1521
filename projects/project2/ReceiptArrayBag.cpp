// My ID#: 5727889

/** @file
    @course CS1521
    @section 9
    @term Spring 2021
    
    Implementation file for the class ReceiptArrayBag.
    
    Adapted from pages 101-111 in Carrano 7e.
    
    @author Frank M. Carrano
    @author Timothy Henry
    @author Steve Holtz
    @author Reece Holmdahl
    
    @date 9 Feb 2021
    
    @version 7.0 */

#include <vector>
#include <sstream>
#include <stdexcept>

template <typename ItemType>
int ReceiptArrayBag<ItemType>::getCurrentSize() const {
  
  return itemCount;
}

template <typename ItemType>
bool ReceiptArrayBag<ItemType>::isEmpty() const {
  
  return !itemCount;
}

template <typename ItemType>
int ReceiptArrayBag<ItemType>::put(const ItemType& newEntry) {

  bool hasRoomToAdd(itemCount < maxItems);
  int receipt = -1;
  
  if (hasRoomToAdd) {
    
    // itemInfo here hasn't been given a receipt yet
    if (items[itemCount].receipt == -1) {
      
      // Initialize receipt for this itemInfo
      items[itemCount].receipt = itemCount;
    }

    // Set the item at the add position to the new entry
    items[itemCount].item = newEntry;

    // Since there's room to add, set the return argument to this receipt
    receipt = items[itemCount].receipt;

    // Increment 'itemCount'
    ++itemCount;
  }

  // -1 if none, receipt otherwise
  return receipt;
}

template <typename ItemType>
ItemType ReceiptArrayBag<ItemType>::takeOut(int receipt) {

  // Search 'items' array for an itemInfo structure with its receipt matching 'receipt'
  for (int index(0); index < itemCount; ++index) {
    if (items[index].receipt == receipt) {
      // Grab itemInfo from 'items' array where the receipt matches
      itemInfo copy = items[index];

      // Decrement 'itemCount' and move last item in array to where this item was removed from
      --itemCount;
      items[index] = items[itemCount];

      // Make the item in 'items[itemCount+1]' (just past the end of the bag's external length) have the receipt we just removed; making it available
      items[itemCount].receipt = copy.receipt;

      // Return a copy of the item removed
      return copy.item;
    }
  }

  // If the method has made it this far, 'receipt' has no match within this bag; make and throw an invalid argument exception

  // Making a clear error message that is traceable, giving the client the faulty receipt integer
  std::stringstream errorMsg;
  errorMsg << "This bag does not contain the receipt: " << receipt;
  
  throw std::invalid_argument(errorMsg.str());
}

template <typename ItemType>
void ReceiptArrayBag<ItemType>::clear() {
  
  itemCount = 0;
}

template <typename ItemType>
bool ReceiptArrayBag<ItemType>::contains(const ItemType& anEntry) const {

  // Search the 'items' array for the itemInfo structure containing 'anEntry' and return true if found
  for (int index(0); index < itemCount; ++index) {
    
    if (items[index].item == anEntry) {
      return true;
    }
  }

  // If method has made it this far, no 'anEntry' was found; return false
  return false;
}

template <typename ItemType>
int ReceiptArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {

  // Variable for integer amount of times 'anEntry' has been found
  int amount(0);

  // Search the 'items' array for 'anEntry' and increment it each time it's found
  for (int index(0); index < itemCount; ++index) {
    
    if (items[index].item == anEntry) {
      ++amount;
    }
  }

  // Return amount of times 'anEntry' was found within this bag
  return amount;
}

template <typename ItemType>
std::vector<ItemType> ReceiptArrayBag<ItemType>::toVector() const {

  std::vector<ItemType> bagContents;

  // Add the item for every itemInfo structure in the 'items' array to the vector
  for (int i(0); i < itemCount; ++i) {
    bagContents.push_back(items[i].item);
  }

  // Return the vector filled with this bag's contents.
  return bagContents;
}
