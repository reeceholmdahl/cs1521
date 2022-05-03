// My ID: 5727889

#ifndef NOT_FOUND_EXCEPTION_
#define NOT_FOUND_EXCEPTION_

#include <stdexcept>
#include <string>

class NotFoundException : public std::domain_error {
public:
  
  explicit NotFoundException(const std::string& message = "");

  virtual ~NotFoundException() noexcept = default;
};

#endif // NOT_FOUND_EXCEPTION_
