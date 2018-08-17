#ifndef EMPTY_EXCEPTION_H
#define EMPTY_EXCEPTION_H

#include <exception>

struct EmptyException : public std::exception {
  const char* what () const throw () {
    return "Empty!";
  }
};

#endif
