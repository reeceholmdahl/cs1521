// My ID: 5727889
#ifndef DIVISION_BY_ZERO_EXCEP_
#define DIVISION_BY_ZERO_EXCEP_

#include <stdexcept>
#include <string>

class DivisionByZeroExcep : public std::logic_error {
 public:

  /** Explicit constructor specifying the 'what' of the exception. */
  explicit DivisionByZeroExcep(const std::string& message = "")
    : std::logic_error(message) {
  }

  /** Virtual destructor */
  virtual ~DivisionByZeroExcep() noexcept = default;
};

#endif // DIVISION_BY_ZERO_EXCEP_
