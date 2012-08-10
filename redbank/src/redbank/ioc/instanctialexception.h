#ifndef INSTANCTIALEXCEPTION_H
#define INSTANCTIALEXCEPTION_H
#include <exception>

class InstantialException : public std::exception{
public:
    InstantialException(const exception& e):what_str_(e.what())
    {}

    InstantialException(const char* what_str):what_str_(what_str)
    {}

    ~InstantialException()
    {}
public:
    const char* what() const throw(){
        return what_str_.cstr();
    }
private:
    string what_str_;
};

#endif // INSTANCTIALEXCEPTION_H
