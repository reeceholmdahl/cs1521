#include <iostream>

#include "ArrayList.h"
#include "LinkedList.h"

void displayList(ListInterface<int>* listPtr) {

   if (!listPtr) {
      return;
   }

   std::cout << "The list contains "
             << listPtr->getLength()
             << " items:"
             << std::endl;

   for (int pos(1); pos <= listPtr->getLength(); ++pos) {
      std::cout << "list["
                << pos
                << "] = "
                << listPtr->getEntry(pos)
                << "\n";
   }

   std::cout << std::endl;
}

void fillList(ListInterface<int>* listPtr) {

   if (!listPtr) {
      return;
   }

   listPtr->insert(1, 2);
   listPtr->insert(2, 7);
   listPtr->insert(3, 9);
   listPtr->insert(4, 6);
   listPtr->insert(5, 8);
   listPtr->insert(5, 0);
   listPtr->insert(4, 3);
   listPtr->insert(3, 5);
   listPtr->insert(2, 1);
   listPtr->insert(1, 4);
}

int main() {

   ListInterface<int>* listPtr(nullptr);

   char userChoice;

   std::cout << "Enter 'A' the test the array-based list"
             << std::endl
             << "or 'L' to test the linked-chain based list"
             << std::endl
             << "or 'Q' to quit\n"
             << std::endl
             << "Choice: ";

   std::cin >> userChoice;

   while (userChoice != 'Q' && userChoice != 'q') {
      if (userChoice == 'A' || userChoice == 'a') {
         listPtr = new ArrayList<int>();
         std::cout << "Testing with ArrayList ..."
                   << std::endl;
      }
      else {
         listPtr = new LinkedList<int>();
         std::cout << "Testing with LinkedList ..."
                   << std::endl;
      }

      // Fill the list with a permutation of 0-9:
      fillList(listPtr);

      // Display the initial (unsorted) list:
      displayList(listPtr);

      std::cout << "Sorting the list ... ";
      listPtr->sort();
      std::cout << "Done.\n"
                << std::endl;

      // Display the sorted list:
      displayList(listPtr);

      delete listPtr;
      listPtr = nullptr;

      std::cout << "All done with that test!"
                << std::endl
                << std::endl;

      std::cout << "Enter 'A' the test the array-based list"
                << std::endl
                << "or 'L' to test the linked-chain based list"
                << std::endl
                << "or 'Q' to quit\n"
                << std::endl
                << "Choice: ";

      std::cin >> userChoice;
   }

   return EXIT_SUCCESS;
}
