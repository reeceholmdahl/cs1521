// My ID#: 5727889
// Using linked list implementation
//#define USE_ARRAY_LIST
 
#include <iostream>

#ifdef USE_ARRAY_LIST
#include "ArrayList.h"
#else
#include "LinkedList.h"
#endif
 
#include "getPosition.h"
 
int main() {
 
#ifdef USE_ARRAY_LIST
   ArrayList<int> list;
#else
   LinkedList<int> list;
#endif

   list.insert(1, 9);
   list.insert(2, 5);
   list.insert(1, 0);
   list.insert(2, 3);
   list.insert(4, 2);
 
   int position(0);
   int value(0);

   while (std::cin >> value) {
 
      if ((position = getPosition(list, value)) <= list.getLength() ) {
         std::cout << "list["
                   << position
                   << "] = "
                   << value
                   << "."
                  << std::endl;
      }
      else {
         std::cout << "The list does NOT contain "
                   << value
                   << "."
                   << std::endl;
      }
   }
 
   return EXIT_SUCCESS;
}
