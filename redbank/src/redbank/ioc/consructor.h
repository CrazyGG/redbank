#ifndef CONSRUCTOR_H
#define CONSRUCTOR_H

#include <redbank/ioc/member.h>
#include <redbank/ioc/parameters.h>

namespace redbank {
namespace ioc{

class Constructor : public Member{
public:
    void* newInstance(const Parameters& params = Parameters());
};

}
}



#endif // CONSRUCTOR_H
