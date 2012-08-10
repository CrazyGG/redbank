#ifndef RED_BANK_NO_SUCH_METHOD_EXCEPTION_H
#define RED_BANK_NO_SUCH_METHOD_EXCEPTION_H

#include <exception>
#include <string>

namespace redbank {
namespace ioc {

using namespace std;

class NoSuchMethodException : public exception{
public:
    NoSuchMethodException(exception& e):what_str_(e.what())
    {}

    NoSuchMethodException(const char* what_str):what_str_(what_str)
    {}

    ~NoSuchMethodException()
    {}
public:
    const char* what(){
        return what_str_.c_str();
    }
private :
    string what_str_;
};

}
}
#endif // RED_BANK_NO_SUCH_METHOD_EXCEPTION_H
