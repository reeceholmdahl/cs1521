// My ID#: 5727889

/** @file
    @course CS1521
    @section 9
    @term Spring 2021
    
    ReceiptBagInterface class template definition.
    
    Adapted from page 24-25 in Carrano 7e.
    
    @author Frank M. Carrano
    @author Timothy Henry
    @author Steve Holtz
    @author Reece Holmdahl
    
    @date 9 Feb 2021
    
    @version 7.0 */

#ifndef RECEIPT_BAG_INTERFACE_
#define RECEIPT_BAG_INTERFACE_

#include <vector>

/** @class ReceiptBagInterface ReceiptBagInterface.h "ReceiptBagInterface.h"
 *
 *  ReceiptBagInterface abstract base class template. */
template <typename ItemType>
class ReceiptBagInterface {
public:
   /** Virtual destructor. */
   virtual ~ReceiptBagInterface() {}

   /** Gets the current number of entries in this bag.

       @return The integer number of entries currently in the bag. */
   virtual int getCurrentSize() const = 0;

   /** Checks whether or not this bag is empty.

       @return True if the bag is empty, or false if not. */
   virtual bool isEmpty() const = 0;

   /** Puts 'newEntry' in this bag and yields a receipt to retrieve it later.

       @pre For the method to work as intended there must be room in the bag.
       @post If successful, 'newEntry' is stored in the bag and the count of items in the bag has increased by 1.

       @param[in] newEntry The object to be put in this bag.

       @return The integer receipt associated with the item put in the bag if successful, -1 if unsuccessful. */
   virtual int put(const ItemType& newEntry) = 0;

  /** Takes out the item which corresponds to 'receipt', if possible.

      @pre 'receipt' must be at least 0 and there must be an item which corresponds to 'receipt'.
      @post If successful, the item which corresponds to 'receipt' has been taken out of the bag and the count of items in the bag has decreased by 1.

      @param[in] receipt The integer receipt of item.

      @return If successful, a copy of the item removed from the bag is returned, otherwise an invalid_argument error is thrown. */
   virtual ItemType takeOut(int receipt) = 0;

   /** Deletes all entries in this bag.

       @post This bag contains no items. */
   virtual void clear() = 0;

   /** Counts the number of times a given entry appears in bag.

       @param[in] anEntry The entry which will have its frequency checked.

       @return The number of times 'anEntry' appears in this bag. */
   virtual int getFrequencyOf(const ItemType& anEntry) const = 0;

   /** Checks whether or not this bag contains a given entry.

       @param[in] anEntry The entry to check.

       @return True if this bag contains 'anEntry', or false otherwise. */
   virtual bool contains(const ItemType& anEntry) const = 0;

   /** Converts this bag into a vector.

       @return A vector containing all the entries in this bag. */
   virtual std::vector<ItemType> toVector() const = 0;
};

#endif
