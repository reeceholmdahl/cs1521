#include <iostream>
#include "polynomial.h"

using std::cout;
using std::endl;

/** Creates and returns a polynomial object with coefficients as per the parameters. If the coefficients array is empty, it simply creates a default polynomial.
    @param[in] coefficients An integer array reference containing (ordered highest to lowest by degree) the coefficients of the polynomial to create.
    @param[in] length The length of the coefficients array.
    @pre the parameter 'length' corresponds with the lenght of the coefficients array.
    @return A polynomial that corresponds to the coefficients array. */
Polynomial makePoly(const int coefficients[], const int length) {
  Polynomial poly;

  // Iterate through the array and assign coefficients to polynomial object
  for (int i = 0; i < length; i++) {
    int coeff = coefficients[length - 1 - i];
    poly.setCoefficient(coeff, i);
  }

  return poly;
}

/** Gets the coefficient of the highest degree of the passed polynomial.
    @param[in] poly The polynomial that this function will act upon.
    @pre The polynomial must have at least one non-zero coefficient.
    @return An integer that represents the coefficient of the highest degree of the polynomial. */
int highestDegreeCoeff(const Polynomial &poly) {
  return poly.coefficient(poly.degree());
}

/** Increases the coefficient of the supplied exponent by value for the passed polynomial object.
    @param[in, out] poly The polynomial to act upon.
    @param[in] exp The exponent at which the coefficient will be modified.
    @param[in] value The value to change the coefficient by.
    @post The polynomial object will have the coefficient at the exponent 'exp' changed by 'value.'
    @return The reference to the polynomial object passed in with modifications as per this contract. */
Polynomial increaseCoeff(Polynomial &poly, const unsigned exp, const int value) {
  // Calculate the new coefficient of the exponent
  int newCoeff = poly.coefficient(exp) + value;
  // Set the coefficient of the exponent to the new calculated one
  poly.setCoefficient(newCoeff, exp);
  return poly;
}

/** Computes the sum of the two passed polynomial objects and returns it as a new polynomial object.
    @param[in] poly1
    @param[in] poly2
    @pre Both polynomial objects passed as parameters must have at least one non-zero coefficient.
    @post There exists a polynomial object that is the sum of the two passed polynomial objects.
    @return A polynomial object that has values such that it is the sum of the two passed polynomial objects. */
Polynomial addPolynomials(const Polynomial &poly1, const Polynomial &poly2) {
  int d1 = poly1.degree();
  int d2 = poly2.degree();

  // Get the higher degree of the two
  int degree = d1 > d2 ? d1 : d2;

  // Make the sum polynomial object
  Polynomial sum;

  // Add the two polynomial objects via for loop size >degree
  for (int i = 0; i <= degree; i++) {
    int coeff = poly1.coefficient(i) + poly2.coefficient(i);
    sum.setCoefficient(coeff, i);
  }
  
  return sum;
}

int main() {
  // Testing

  // Make polynomials for testing
  int p1c[5] = {3, 0, 2, 0, 1};
  Polynomial p1 = makePoly(p1c, 5);

  int p2c[3] = {5, 1, 10};
  Polynomial p2 = makePoly(p2c, 3);
  increaseCoeff(p2, 3, 2); // Increase x^3 exponent coeff by 2

  Polynomial empty;

  int p3c[7] = {1, 2, 3, 4, 5, 6, 7};
  Polynomial p3 = makePoly(p3c, 7);

  int p4c[5] = {-2, 2, 1, 5, 3};
  Polynomial p4 = makePoly(p4c, 5);

  // Test functionality

  // Initial polynomials
  cout << "Initial polynomials" << endl;
  cout << "P1: " << p1.print() << endl;
  cout << "P2: " << p2.print() << endl;
  cout << "P3: " << p3.print() << endl;
  cout << "P4: " << p4.print() << endl;
  cout << "Empty poly: " << empty.print() << endl << endl;

  cout << "Highest degree coefficient P3 " << highestDegreeCoeff(p3) << endl;
  cout << "Highest degree coefficient P2 " << highestDegreeCoeff(p2) << endl << endl;

  Polynomial sumP1P4 = addPolynomials(p1, p4);

  cout << "P4: Increasing exponent 4 by 2" << endl;
  cout << "P1: Increasing epxonent 4 by 1" << endl;
  cout << "Empty: Increasing exponent 1 by 5" << endl << endl;
  increaseCoeff(p4, 4, 2);
  increaseCoeff(p1, 4, 1);
  increaseCoeff(empty, 1, 5);

  cout << "Final polynomials" << endl;
  cout << "P1: " << p1.print() << endl;
  cout << "P2: " << p2.print() << endl;
  cout << "P3: " << p3.print() << endl;
  cout << "P4: " << p4.print() << endl;
  cout << "Empty poly: " << empty.print() << endl;
  cout << "Sum P1+P4 " << sumP1P4.print() << endl;
}
