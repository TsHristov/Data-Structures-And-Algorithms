#include <exception>

class ValueNotPresent: public std::exception
{
public:
  virtual const char* what() const throw()
  {
    return "Value not available in the collection";
  }
};

class EmptyArray: public std::exception
{
public:
  virtual const char* what() const throw()
  {
    return "Array is empty";
  }
};
