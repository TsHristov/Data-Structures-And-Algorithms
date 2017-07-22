#include <exception>

class EmptyArray: public std::exception
{
public:
  virtual const char* what() const throw()
  {
    return "Array is empty";
  }
};
