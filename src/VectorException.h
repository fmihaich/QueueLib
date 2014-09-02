#ifndef VECTOREXCEPTION_H
#define	VECTOREXCEPTION_H

#include <exception>
#include <string>


class VectorException: public std::exception
{
  public:
      VectorException();      
      VectorException(const std::string & msg): message_(msg) {}
      ~VectorException() throw() {}
      const char* what() const throw() { return message_.c_str(); }
      
  private:
    std::string message_;
};

#endif	/* VECTOREXCEPTION_H */

