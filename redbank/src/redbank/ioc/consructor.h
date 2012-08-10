#ifndef CONSRUCTOR_H
#define CONSRUCTOR_H

#include <redbank/platform.h>
#include <redbank/ioc/member.h>
#include <redbank/ioc/parameters.h>

namespace redbank {
namespace ioc{

class Constructor : public Member{
public:
    virtual ~Constructor()
    {
    }

public:
    virtual String& getSign() = 0;

    virtual void* newInstance(const Parameters& params = Parameters()) = 0;
};

}
}



#endif // CONSRUCTOR_H
