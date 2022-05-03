// My ID#: 5727889

/** @file
    @course CS1521
    @section 9
    @term Spring 2021
    
    Header file for an array-based implementation of the ADT bag with receipt functionality.
    
    Adapted from page 100 in Carrano 7e.
    
    @author Frank M. Carrano
    @author Timothy Henry
    @author Steve Holtz
    @author Reece Holmdahl
    
    @date 9 Feb 2021
    
    @version 7.0 */

#ifndef RECEIPT_ARRAY_BAG_
#define RECEIPT_ARRAY_BAG_

#include <vector>

#include "ReceiptBagInterface.h"

/** @class ReceiptArrayBag ReceiptArrayBag.h "ReceiptArrayBag.h"
 *
 *  Specification of an array-based ADT bag implemented with receipt functionality for addition and removal from the bag. */
template <typename ItemType>
class ReceiptArrayBag : public ReceiptBagInterface<ItemType> {
private:

  /** Data structure containing and item and its corresponding receipt */
  struct itemInfo {
    ItemType item;
    int receipt = -1;
  };
  
  /** Maximum capacity of this bag. */
  static const int DEFAULT_CAPACITY = 6;

  /** Data storage. */
  itemInfo items[DEFAULT_CAPACITY];

  /** Number of items in this bag. */
  int itemCount = 0;

  /** Maximum capacity of this bag. */
  int maxItems = DEFAULT_CAPACITY;
  
public:
  /** Default constructor. */
  ReceiptArrayBag() = default;

  /** Virtual destructor. */
  virtual ~ReceiptArrayBag() = default;

  virtual int getCurrentSize() const;

  virtual bool isEmpty() const;

  virtual int put(const ItemType& newEntry);

  virtual ItemType takeOut(int receipt);

  virtual void clear();

  virtual int getFrequencyOf(const ItemType& anEntry) const;

  virtual bool contains(const ItemType& anEntry) const;

  virtual std::vector<ItemType> toVector() const;
};

#include "ReceiptArrayBag.cpp"

#endif
