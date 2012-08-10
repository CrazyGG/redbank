#ifndef FIELD_H
#define FIELD_H

#include "member.h"
#include "caller.h"

class Variant;
class Variants;

class Field : public Member{
public:// structor

    Field(const string& name,Class* clazz,MemberType member_type,MemberModifer member_modifer,bool is_static,const Caller* set_caller,const Caller* get_caller)
        :Member(name,clazz,member_type,member_modifer,is_static),set_caller_(set_caller),get_caller_(get_caller)
    {
    }

    ~Field()
    {}
public:
    void set(void* obj,const Variants& params)
    {
        set_caller_->invoke(obj,params);
    }

    Variant get(void* obj)
    {
        return get_caller_->invoke(obj,Variants());
    }
private:
    Caller* set_caller_;
    Caller* get_caller_;
};

#endif // FIELD_H
