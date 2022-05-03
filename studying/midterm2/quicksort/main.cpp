#include <iostream>
#include <stdlib.h>

#include "quicksort.h"

#define PRINT_ARRAY

int main() {

  srand(time(0) );
  
  int size = 500;
  
  int* test = new int[size];

  for (int i(0); i < size; ++i) {
    test[i] = rand() % size;
    
#ifdef PRINT_ARRAY
    std::cout << "test[" << i << "] = " << test[i] << std::endl;
#endif // PRINT_ARRAY
  }
    
  quickSort(test, size);

  std::cout << "\n---AFTER SORT---\n" << std::endl;
  
  for (int i(0); i < size; ++i) {
    std::cout << "test[" << i << "] = " << test[i] << std::endl;
  }

  delete test;
  test = nullptr;
  
  return EXIT_SUCCESS;
       }
