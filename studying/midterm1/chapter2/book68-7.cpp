#include <iostream>

using std::cout;
using std::endl;

int productArray(const int array[], int first, int last) {

  cout << "Entering, first: " << first << " last: " << last << endl;
  
  int stepValue;
  if (first >= last) {
    stepValue = 1;
  } else {
    stepValue = array[first] * productArray(array, first + 1, last);
  }

  cout << "Leaving, first: " << first << " last: " << last << " return: " << stepValue << endl;
  return stepValue;
}

int main() {

  // Setup array
  int count = 20;
  int* arr = new int[count];

  // Fill array
  for (int i(0); i < count; ++i) {
    arr[i] = i + 1;
    cout << "arr[" << i << "] == " << i << endl;
  }

  // Print results
  int first = 0;
  int last = 5;
  int result = productArray(arr, first, last);
  cout << "productArray(arr, " << first << ", " << last << ") == " << result << endl;

  // Free memory
  delete arr;
  arr = nullptr;
  
  return EXIT_SUCCESS;
}
