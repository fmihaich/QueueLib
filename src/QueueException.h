#ifndef QUEUEEXCEPTION_H
#define	QUEUEEXCEPTION_H

#include <exception>
#include <string>


class QueueException: public std::exception
{
  public:
      QueueException();      
      QueueException(const std::string & msg): message_(msg) {}
      ~QueueException() throw() {}
      const char* what() const throw() { return message_.c_str(); }
      
  private:
    std::string message_;
};

#endif	/* QUEUEEXCEPTION_H */

