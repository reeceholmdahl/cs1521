/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  Header file for an array-based implementation of the ADT list.
 *
 *  Adapted from pages 267-268 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 4 Mar 2021
 *
 *  @version 7.0 */

#ifndef ARRAY_LIST_
#define ARRAY_LIST_

#include "ListInterface.h"

/** @class ArrayList ArrayList.h "ArrayList.h"
 *
 *  Specification of an array-based ADT list. */
template <typename ItemType>
class ArrayList : public ListInterface<ItemType> {
private:
   static const int DEFAULT_CAPACITY = 15;

   int itemCount = 0;

   ItemType items[DEFAULT_CAPACITY];

   // void merge(int, int, int);
   // void mergeSort(int, int);

public:
   ArrayList() = default;

   virtual ~ArrayList() = default;

   virtual bool isEmpty() const;

   virtual int getLength() const;

   virtual bool insert(int newPosition,
                       const ItemType& newEntry);

   virtual bool remove(int position);

   virtual void clear();

   virtual ItemType getEntry(int position) const;

   virtual ItemType replace(int position,
                            const ItemType& newEntry);

   virtual void sort();
};

#include "ArrayList.cpp"

#endif
