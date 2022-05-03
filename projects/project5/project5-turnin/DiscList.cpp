#include <memory>
#include <iostream>
#include <new>

#include "Disc.h"
#include "DiscList.h"
#include "LinkedList.h"

DiscList::DiscList() {
  try {
    discListPtr = std::make_unique<LinkedList<std::shared_ptr<Disc> > >();
  } catch (const std::bad_alloc&) {
    throw;
  }
}

DiscList::~DiscList() {
  std::cerr << "The DiscList destructor has been called." << std::endl;
}

bool DiscList::isEmpty() const {
  return discListPtr->isEmpty();
}

int DiscList::getNumberOfDiscs() const {
  return discListPtr->getLength();
}

bool DiscList::insertDisc(std::shared_ptr<Disc> discPtr) {
  int nextPos = discListPtr->getLength() + 1;

  bool success;
  try {
    success = discListPtr->insert(nextPos, discPtr);
  } catch (const std::bad_alloc&) {
    success = false;
    throw;
  }
  
  return success;
}

bool DiscList::removeDisc(std::shared_ptr<Disc> discPtr) {

  // Search discListPtr for 'discPtr' and if found, attempt to remove it.
  int pos = -1;
  for (int i(1); i <= discListPtr->getLength(); ++i) {
    if (discListPtr->getEntry(i) == discPtr) {
      pos = i;
      break;
    }
  }

  // Attempt to remove 'discPtr'
  if (pos >= 1 && pos <= getNumberOfDiscs() ) {
    return discListPtr->remove(pos);
  }

  // If we've made it here, 'discPtr' was not found in discListPtr
  return false;
}

std::shared_ptr<Disc> DiscList::retrieveDisc(int number) const {

  // If the number is within the range of acceptable values, return a pointer to a disc corresponding to 'number'
  if (number >= 1 && number <= getNumberOfDiscs() ) {
    return discListPtr->getEntry(number);
  }

  // If we've made it here, there isn't a pointer to a disc associated with 'number', return nullptr
  return nullptr;
}
