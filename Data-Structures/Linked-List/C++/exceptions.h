#pragma once
#include <exception>

class EmptyList: public std::exception
{
public:
  virtual const char * what() const throw()
  {
    return "List is empty";
  }
};
