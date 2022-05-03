#ifndef CUSTOM_QUICKSORT_
#define CUSTOM_QUICKSORT_

const int QUICK_SORT_MIN_SIZE = 4;

template <typename T>
void quickSort(T* array, int size);

template <typename T>
void quickSort(T* array, int first, int last);

/** Returns pivot index after partitioning array[first...last] about pivot p. */
template <typename T>
int partition(T* array, int first, int last);

template <typename T>
void sortFirstMidLast(T* array, int first, int mid, int last);

template <typename T>
void insertionSort(T* array, int first, int last);

#include "quicksort.cpp"

#endif // CUSTOM_QUICKSORT
