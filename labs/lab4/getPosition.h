// My ID#: 5727889
#ifndef GET_POSITION_
#define GET_POSITION_

#include "ListInterface.h"

/** Gets the position of the target in the passed list.
    @pre 'target' is in 'list'.
    @post None.

    @param[in] list The list to search.
    @param[in] target The target to search for in 'list'.

    @return If successful, the position in 'list' where 'target' can be found. Otherwise, the length of the list + 1. */
template <typename ItemType>
int getPosition(const ListInterface<ItemType>& list, const ItemType& target);

#include "getPosition.cpp"

#endif // GET_POSITION_
