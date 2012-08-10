#ifndef METHOD_H
#define METHOD_H

#include "member.h"
#include "caller.h"

class Variant;
class Variants;

class Method : public Member {
public://structor

    Method(const string& name,Class* clazz,MemberType member_type,MemberModifer member_modifer,bool is_static,Caller* caller):
        Member(name,clazz,member_type,member_modifer,is_static),caller_(caller)
    {}

    ~Method()
    {}

public:
    /**
     *  @override
     */
    Variant invoke(void* obj,const Variants& params){
        return caller_->invoke(obj,params);
    }
private:
    Caller* caller_;
};

#endif // METHOD_H
