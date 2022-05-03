// My ID#: 5727889
#include <iostream>
#include <vector>

#include "ArraySet.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
void printSet(const SetInterface<T>& set) {

  cout << "Printing set." << endl;
  
  const vector<T> v = set.toVector();

  int size(v.size());

  if (!size) {
    
    cout << "The set is empty." << endl;
  } else {

    for (int index(0); index < size; ++index) {
      cout << "Element: " << v[index] << endl;
    }
  }

  cout << endl;
}

template <typename T>
void testAdd(SetInterface<T>& set, const T& addition, bool expectedResult) {
  cout << "Attempting to add " << addition
       << " to the set (should be " << expectedResult
       << "): " << set.add(addition) << endl;
}

int main() {

  ArraySet<string> set1;
  ArraySet<string> set2;
  ArraySet<string> diff;

  cout << "1: ArraySet doesn't allow duplicates:" << endl;

  // Show results set1, set2, and their difference
  cout << "Set1:" << endl;
  printSet(set1);

  testAdd(set1, string("hey!"), true);
  testAdd(set1, string("hello!"), true);
  testAdd(set1, string("hey!"), false);

  cout << "\nSet1:" << endl;
  printSet(set1);
  set1.clear();

  cout << "2: Both LHS and RHS are empty:" << endl;
  
  // Show results set1, set2, and their difference
  cout << "Set1:" << endl;
  printSet(set1);

  cout << "Set2:" << endl;
  printSet(set2);
  
  diff = set1.difference(set2);

  cout << "Difference Set1 to Set2:" << endl;
  printSet(diff);

  cout << "3: LHS is empty, RHS has items:" << endl;

  // Add some stuff to RHS
  set2.add("hello");
  set2.add("goodbye");
  set2.add("bonjour");

  // Show results set1, set2, and their difference
  cout << "Set1:" << endl;
  printSet(set1);

  cout << "Set2:" << endl;
  printSet(set2);
  
  diff = set1.difference(set2);

  cout << "Difference Set1 to Set2:" << endl;
  printSet(diff);

  cout << "4: RHS is empty, LHS has items:" << endl;
  
  // Clear RHS and add some stuff to LHS
  set2.clear();
  set1.add("twist");
  set1.add("fred");
  set1.add("johnny5");

  // Show results set1, set2, and their difference
  cout << "Set1:" << endl;
  printSet(set1);

  cout << "Set2:" << endl;
  printSet(set2);
  
  diff = set1.difference(set2);

  cout << "Difference Set1 to Set2:" << endl;
  printSet(diff);

  cout << "5: LHS and RHS have items without intersection:" << endl;

  // LHS already has stuff, add some stuff not in LHS to RHS
  set2.add("hello");
  set2.add("goodbye");
  set2.add("bonjour");

  // Show results set1, set2, and their difference
  cout << "Set1:" << endl;
  printSet(set1);

  cout << "Set2:" << endl;
  printSet(set2);
  
  diff = set1.difference(set2);

  cout << "Difference Set1 to Set2:" << endl;
  printSet(diff);

  cout << "6: LHS and RHS have items with partial intersection:" << endl;

  // Add something LHS has to RHS
  set2.add("twist");

  // Show results set1, set2, and their difference
  cout << "Set1:" << endl;
  printSet(set1);

  cout << "Set2:" << endl;
  printSet(set2);
  
  diff = set1.difference(set2);

  cout << "Difference Set1 to Set2:" << endl;
  printSet(diff);

  cout << "7: LHS and RHS have complete intersection:" << endl;

  // Make LHS and RHS identical
  set1.clear();
  set2.clear();
  set1.add("testing");
  set2.add("testing");
  set1.add("identical");
  set2.add("identical");
  set1.add("sets");
  set2.add("sets");

  // Show results set1, set2, and their difference
  cout << "Set1:" << endl;
  printSet(set1);

  cout << "Set2:" << endl;
  printSet(set2);
  
  diff = set1.difference(set2);

  cout << "Difference Set1 to Set2:" << endl;
  printSet(diff);

  cout << "(additional) 8: LHS has every element in RHS plus more:" << endl;

  // Add some extra stuff to LHS
  set1.add("extra");
  set1.add("stuff");

  // Show results set1, set2, and their difference
  cout << "Set1:" << endl;
  printSet(set1);

  cout << "Set2:" << endl;
  printSet(set2);
  
  diff = set1.difference(set2);

  cout << "Difference Set1 to Set2:" << endl;
  printSet(diff);

  cout << "(additional) 9: RHS has every element in LHS plus more:" << endl;

  // Show results set1, set2, and their difference
  cout << "Set1:" << endl;
  printSet(set1);

  cout << "Set2:" << endl;
  printSet(set2);
  
  diff = set2.difference(set1);

  cout << "Difference Set2 to Set1 (switched operands):" << endl;
  printSet(diff);
  
  return EXIT_SUCCESS;
}
