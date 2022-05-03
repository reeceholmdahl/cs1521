#ifndef POLYNOMIAL_
#define POLYNOMIAL_

#include <string>
#include <map>

class Polynomial {
public:
   /** Gets the degree of this polynomial.
    *
    * The degree (or order) of a polynomial is the highest exponent
    * found on a term with a nonzero coefficient.
    *
    * @return The degree of this polynomial.
    */
   unsigned degree() const;

   /** Gets the coefficient of the term with 'exponent' power.
    *
    * If there is no term with power 'exponent', then zero is
    * returned, as zero times a term is zero (and that term is not
    * shown when it is written down).
    *
    * @param exponent The exponent of the term to get the coefficient
    *                 for.
    *
    * @return The coefficient for the term with 'exponent' power.
    */
   int coefficient(unsigned exponent) const;

   /** Set the coefficient for the term with 'exponent' power to
    * 'newCoefficient'.
    *
    * Note that if a term's coefficient is set to zero, then that term
    * is removed from the polynomial (as it no long has a meaningful
    * value).
    *
    * @param newCoefficient The new coefficient for the term with
    *                       'exponent' power.
    *
    * @param exponent The exponent of the term to change the
    *                 coefficient of to 'newCoefficient'.
    */
   void setCoefficient(int newCoefficient,
                       unsigned exponent);

   /** Print polynomial.
    *
    * @return Converts this polynomial to a string and returns it.
    */
   std::string print() const;

   /** Constructor. */
   Polynomial() = default;

   /** Copy constructor. */
   Polynomial(const Polynomial&);

   /** Move constructor. */
   Polynomial(Polynomial&&);

   /** Destructor. */
   ~Polynomial() = default;

   /** Copy assignment operator. */
   Polynomial& operator=(const Polynomial&);

   /** Move assignment operator. */
   Polynomial& operator=(Polynomial&&);

private:
   std::map<unsigned, int> expCoef;
};

#endif
