#include <string>
#include <sstream>
#include <cmath>

#include "polynomial.h"

Polynomial::Polynomial(const Polynomial& in) {

   expCoef = in.expCoef;
}

Polynomial::Polynomial(Polynomial&& in) {

   expCoef = std::move(in.expCoef);
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {

   if (this != &rhs) {
      decltype(expCoef) temp(rhs.expCoef);
      expCoef.clear();
      expCoef = temp;
   }

   return *this;
}

Polynomial& Polynomial::operator=(Polynomial&& rhs) {

   if (this != &rhs) {
      expCoef.clear();
      expCoef.swap(rhs.expCoef);
   }

   return *this;
}

unsigned Polynomial::degree() const {

   auto last(expCoef.crbegin() );

   return last->first;
}

int Polynomial::coefficient(unsigned exponent) const {

   unsigned coef(0);

   if (expCoef.count(exponent) > 0) {
      coef = expCoef.at(exponent);
   }

   return coef;
}

void Polynomial::setCoefficient(int newCoefficient,
                                unsigned exponent) {

   if (newCoefficient != 0) {
      expCoef[exponent] = newCoefficient;
   }
   else if (expCoef.count(exponent) != 0) {
      expCoef.erase(exponent);
   }
}

std::string Polynomial::print() const {

   std::ostringstream outStr;

   auto iter(expCoef.crbegin() );

   for (; iter != expCoef.crend(); ++iter) {
      if (iter->second == 1 && iter->first == 0 && iter != expCoef.crbegin() ) {
         outStr << "+ 1"; // Plus 1
      }
      else if (iter->second == 1 && iter->first == 0) {
         outStr << "1";
      }
      else if (iter->second == -1 && iter->first == 0 && iter != expCoef.crbegin() ) {
         outStr << "- 1"; // Minus 1
      }
      else if (iter->second == -1 && iter->first == 0) {
         outStr << "-1";
      }
      else if (iter->second == -1 && iter == expCoef.crbegin() ) {
         outStr << "-"; // Negative sign
      }
      else if (iter->second == -1) {
         outStr << "- "; // Minus operator
      }
      else if (iter->second < -1 && iter == expCoef.crbegin() ) {
         outStr << "-"
                << std::abs(iter->second); // Minus coefficient
      }
      else if (iter->second < -1) {
         outStr << "- "
                << std::abs(iter->second); // Minus coefficient
      }
      else if (iter->second == 1 && iter == expCoef.crbegin() ) {
         ; // Do nothing
      }
      else if (iter->second == 1) {
         outStr << "+ "; // Plus operator
      }
      else {
         outStr << "+ "
                << iter->second; // Plus coefficient
      }
      if (iter->first != 0) {
         outStr << "x^"
                << iter->first
                << " ";
      }
   }

   return outStr.str();
}
