#include <iostream>

using std::cout;
using std::endl;

/** Computes the product of the first 'n' numbers in the array.
    @param[in] array The array to calculate product from.
    @param[in] n The amount elements to multiply.
    @param[in] first The first index of the array slice.
    @param[in] last The last index (inclusive) of the array slice.
    @pre 'array' has at least 'n' elements between [first, last]. 'first' <= 'last'.
    @post None.
    @return The product of the first n elements of 'array' as a double. */
double arrayProduct(const double array[], int n, int first, int last) {
  cout << "Entering arrayProduct: 'n': " << n
       << " 'first': " << first
       << " 'last': " << last << endl;

  double send;
  if (n == 0 || first > last) {
    send = 1;
  } else {
    send = array[first] * arrayProduct(array, n - 1, first + 1, last);
  }
  cout << "Leaving arrayProduct: 'n': " << n
       << " 'first': " << first
       << " 'last': " << last
       << " Returning: " << send << endl;
  return send;
}

int main() {

  double* testArr = new double[40];

  for (int i(0); i < 40; ++i) {
    // test what i is during calls
    //cout << "value of i: " << i << endl;

    testArr[i] = 2;
    if (!testArr[i]) {
      testArr[i] = 1;
    }
    cout << "testArr[" << i << "]: " << testArr[i] << endl;
  }

  int n = 5;
  int first = 0;
  int last = 39;
  double result = arrayProduct(testArr, n, first, last);
  cout << "Array product 'array': testArr 'n': " << n
       << " 'first': " << first
       << " 'last': " << last
       << " Result: " << result;

  // Clear free store
  delete testArr;
  testArr = nullptr;
  
  return EXIT_SUCCESS;
}
