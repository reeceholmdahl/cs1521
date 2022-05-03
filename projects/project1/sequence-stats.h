// My ID#: 5727889
#ifndef _SEQUENCE_STATS_H_
#define _SEQUENCE_STATS_H_
using namespace std;

class SequenceStats {
 private:
  int length;
  double sum;
  double lastElement;
  double least;
  double greatest;
  
 public:
  /** Creates a new object representing the statistics of a sequence.
      @post The object begins with an empty set. */
  SequenceStats();

  /** Adds a floating point number as an element to the sequence. Also evaluates statistics about
      said number to determine its rank among the set.

      @param[in] element The floating point number to add to the sequence.
      
      @post Added the element to the sequence, determined if its the greatest or least in the
      sequence, and indicated it as the last element of the sequence. */
  void addElement(double element);

  /** Clears the sequence by resetting all of the instance variables to 0.
      @post All instance variables are now 0. */
  void clear();

  /** Gets the length of the sequence.
      @return An integer indicating the length of the sequence. */
  int getLength();

  /** Gets the last element of the sequence.
      
      @pre The sequence has at least 1 element, otherwise returns 0.
      @return The floating point number at the end of the sequence. */
  double getLastElement();

  /** Gets the sum of the sequence.
      
      @pre The sequence has at least 1 element, otherwise returns 0.
      @return The floating point number representing the sum of the sequence. */
  double getSum();

  /** Gets the arithmetic mean of the sequence.
      
      @pre The sequence has at least 1 element, otherwise returns 0.
      @return The arithmetic mean/average of the sequence as a floating point number. */
  double getMean();

  /** Gets the lowest number of the sequence.

      @pre The sequence has at least 1 element, otherwise returns 0.
      @return The floating point number with the least value in the sequence. */
  double getMin();

  /** Gets the greatest number of the sequence.

      @pre The sequence has at least 1 element, otherwise returns 0.
      @return The floating point number with the greatest value in the sequence. */
  double getMax();
};

#endif // #ifndef _SEQUENCE_STATS_H_
