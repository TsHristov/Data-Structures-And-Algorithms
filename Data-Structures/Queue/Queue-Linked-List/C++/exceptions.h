#pragma once
#include <exception>

class EmptyQueue: public std::exception
{
public:
  virtual const char * what() const throw()
  {
    return "Queue is empty";
  }
};
