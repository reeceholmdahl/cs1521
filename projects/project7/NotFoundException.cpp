// My ID: 5727889

#include <stdexcept>
#include <string>

#include "NotFoundException.h"

NotFoundException::NotFoundException(const std::string& message) : std::domain_error(message) {
}
