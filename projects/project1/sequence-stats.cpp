// My ID#: 5727889
#include <iostream>
#include "sequence-stats.h"

SequenceStats::SequenceStats() {
  // Initializes object with all values set to 0, as per clear() method
  clear();
}

void SequenceStats::addElement(double element) {
  // Add the data point to the sum; sum
  sum += element;

  // Set the last element (most recently added) of the sequence to the parameter
  lastElement = element;
  length++;

  // If data point < min, make it new min
  if (element < least) {
    least = element;
  }

  // If data point > max, make it new max
  if (element > greatest) {
    greatest = element;
  }

  // On first data point make it the min and the max
  if (length == 1) {
    least = greatest = element;
  }
}

void SequenceStats::clear() {
  sum = length = least = greatest = 0;
}

int SequenceStats::getLength() {
  return length;
}

double SequenceStats::getLastElement() {
  return lastElement;
}

double SequenceStats::getSum() {
  return sum;
}

double SequenceStats::getMean() {
  return (length == 0) ? 0 : sum / length;
}

double SequenceStats::getMin() {
  return least;
}

double SequenceStats::getMax() {
  return greatest;
}
