#ifndef DESTRUCTOR_H
#define DESTRUCTOR_H

#include <redbank/ioc/member.h>

namespace redbank {
namespace ioc {

class Destructor : public Member
{
public:
    virtual ~Destructor()
    {
    }

public:
    virtual const String& getSign() = 0;

    virtual void destroy() = 0;
};


}
}



#endif // DESTRUCTOR_H
