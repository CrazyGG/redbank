#ifndef MEMBER_H
#define MEMBER_H

#include <string>

#include "class.h"

using namespace std;

enum MemberType{
    INSTANCE_FIELD,
    INSTANCE_METHOD,
    CONSTRUCTOR,
    CLASS_FIELD,
    CLASS_METHOD
};

enum MemberModifer{
    PUBLIC,
    PROTECTED,
    PRIVATE
};


class Member{
public:
    Member(const string& name,Class* clazz,MemberType member_type,MemberModifer member_modifer,bool is_static)
        :name_(name),clazz_(clazz),member_type_(member_type),member_modifer_(member_modifer),is_static_(is_static)
    {
    }

    ~Member(){}
public:
    const string& getName()
    {
        return name_;
    }

    const Class* getClass(){
        return clazz_;
    }

    MemberType getType(){
        return member_type_;
    }

    bool isStatic(){
        return is_static_;
    }

    MemberModifer getModifer(){
        return member_modifer_;
    }

private:
    Class* clazz_;
    string name_;
    MemberType member_type_;
    MemberModifer member_modifer_;
    bool    is_static_;
};



#endif // MEMBER_H
