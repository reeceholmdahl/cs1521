// My ID#: 5727889
using namespace std;
#include <iostream>
#include "stdlib.h"
#include "sequence-stats.h"

// Sequence Stats tester object
SequenceStats *seqStats = new SequenceStats();

/** Tests a double array with the Sequence Stats class and prints data about the array.
    @pre seq is a double array of any length, and length is the exact length of the array.

    @param[in] seq The double array to generate statistics on.
    @param[in] length The length of the passed array. */
void tester(const double seq[], const int length) {
  // Add data point to test for each value in seq parameter and print array
  cout << "Sequence: ";
  if (length == 0) cout << "empty sequence";
  for (int i = 0; i < length; i++) {
    cout << seq[i];
    if (i < length - 1) cout << ", ";
    seqStats->addElement(seq[i]);
  }

  // Output test statistics with respect to seq parameter
  cout << endl << "Length, N: " << seqStats->getLength() << endl;
  cout << "Sum: " << seqStats->getSum() << endl;
  cout << "Arithmetic mean: " << seqStats->getMean() << endl;
  cout << "Smallest data point: " << seqStats->getMin() << endl;
  cout << "Greatest data point: " << seqStats->getMax() << endl;
  cout << "Last element: " << seqStats->getLastElement() << endl << endl;

  // Clear after done for next test
  seqStats->clear();
}
  
int main() {
  // Testing certain sequences as per testing requirements
  cout << "a. Empty sequence" << endl;
  tester({}, 0);

  cout << "b. Single value sequence" << endl;
  double b[1] = {9};
  tester(b, 1);

  cout << "c. Increasing sequence" << endl;
  double c[6] = {-5.4, -2.7, -1, 1.5, 3.6, 9.8};
  tester(c, 6);

  cout << "d. Decreasing sequence" << endl;
  double d[9] = {10, 9, 8, 6.4, 3.2, -1, -2.4, -4.8, -13};
  tester(d, 9);

  cout << "e. Random sequence" << endl;
  srand(time(0));
  double ran[10] = {};
  for (int i = 0; i < 10; i++) {
    ran[i] = (rand() % 1000) * 1.0 / 100;
  }
  tester(ran, 10);

  cout << "f. Constant sequence" << endl;
  double f[5] = {-3.5, -3.5, -3.5, -3.5, -3.5};
  tester(f, 5);

  cout << "g1. Fibonacci sequence N=10" << endl;
  double g1[10] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55};
  tester(g1, 10);
  
  cout << "g2. Sequence that sums to 0" << endl;
  double g2[6] = {-10, -6, -2, 2, 6, 10};
  tester(g2, 6);

  cout << "g3. Sequence of squares N=7" << endl;
  double g3[7] = {1, 4, 9, 16, 25, 36, 49};
  tester(g3, 7);

  cout << "g4. Sequence of cubes N=5" << endl;
  double g4[5] = {1, 8, 27, 64, 125};
  tester(g4, 5);

  cout << "g5. Digits of pi" << endl;
  double g5[11] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  tester(g5, 11);
  
  return 0;
}
