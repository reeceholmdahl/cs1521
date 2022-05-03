#include <iostream>
#include <utility>

template <typename T>
void quickSort(T* array, int size) {
  std::cout << "Size: " << size << std::endl;
  std::cout << "Array address: " << array << std::endl;
  quickSort(array, 0, size - 1);
}

template <typename T>
void quickSort(T* array, int first, int last) {

  if (last - first + 1 >= QUICK_SORT_MIN_SIZE) {

    // Partitions array[first...last] about a pivot p and returns the index of that pivot when complete
    int pivotIndex = partition(array, first, last);

    // Sort subarrays S_1 and S_2
    quickSort(array, first, pivotIndex - 1); // S_1
    quickSort(array, pivotIndex + 1, last); // S_2
    
  } else if (first < last) {
    insertionSort(array, first, last);
  }
}

template <typename T>
int partition(T* array, int first, int last) {
  
  // Check this
  int mid = first + (last - first) / 2;

  // Sort first, mid, and last for median-of-three
  sortFirstMidLast(array, first, mid, last);

  // Swap pivot index (middle of median-of-three) with array[last-1]
  std::swap(array[mid], array[last - 1]); // Now the unsorted portion of array is array[first+1...last-2]

  int pivotIndex = last - 1;
  T pivot = array[pivotIndex];

  int indexFromLeft = first + 1;
  int indexFromRight = last - 2;

  bool done = false;
  while (!done) {

    while (array[indexFromLeft] < pivot) {
      ++indexFromLeft;
    }

    while (array[indexFromRight] > pivot) {
      --indexFromRight;
    }

    if (indexFromLeft < indexFromRight) {
      std::swap(array[indexFromLeft], array[indexFromRight]);
      ++indexFromLeft;
      --indexFromRight;
    } else {
      done = true;
    }
  }

  // Check, may not work
  std::swap(pivot, array[indexFromLeft]);
  
  pivotIndex = indexFromLeft;

  return pivotIndex;
}

template <typename T>
void sortFirstMidLast(T* array, int first, int mid, int last) {
  if (array[first] > array[mid])
    std::swap(array[first], array[mid]);

  if (array[mid] > array[last])
    std::swap(array[mid], array[last]);

  if (array[first] > array[mid])
    std::swap(array[first], array[mid]);
}

template <typename T>
  void insertionSort(T* array, int first, int last) {

  for (int unsorted(first + 1); unsorted <= last; ++unsorted) {
    T nextItem(array[unsorted]);
    int loc = unsorted;

    while (loc > first && array[loc - 1] > nextItem) {
      array[loc] = array[loc - 1];
      --loc;
    }
    
    array[loc] = nextItem;
  }
}
