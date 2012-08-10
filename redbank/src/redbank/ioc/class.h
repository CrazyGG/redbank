#ifndef RED_BANK_IOC_CLASS_H
#define RED_BANK_IOC_CLASS_H

#include <redbank/platform.h>

#include <redbank/ioc/field.h>
#include <redbank/ioc/method.h>
#include <redbank/ioc/consructor.h>
#include <redbank/ioc/destructor.h>
#include <redbank/ioc/instanctialexception.h>
#include <redbank/ioc/nosuchmethodexception.h>

#include <map>
#include <vector>

namespace redbank {
namespace ioc{

class Class{
public:
    Class(const String& name,const map<String,Method*>& method_map,const map<String,field*>& field_map,map<String,Constructor*>& constructor_map,const Destructor& destructor)
        :name_(name),method_map_(method_map),field_map_(field_map),constructor_map_(constructor_map),destructor_(destructor)
    {}

    ~Class()
    {}

public:

    void* newInstance(const Parameters params = Parameters()){
        const String& constructor_sign = params.getMethodSign();
        void* obj = 0;
        try{
            const Constructor* constructor = constructor_map_[constructor_sign];
            if(!constructor){
                throw NoSuchMethodException("no such method");
            }
            obj = constructor.newInstance(params);
        }catch(exception& e){
            throw InstantialException(e);
        }
        return obj;
    }

    const String& getName(){
        return name_;
    }

    Method* getMethod(const String& method_sign){
        return method_map_[method_sign];
    }

    const vector<Method*>& allMethod(){

    }

    Field* getField(const String& field_name){
        return field_map_[field_name];
    }

    const vector<Field*>& allField(){

    }

private:
    String name_;
    map<String,Method*>& method_map_;
    map<String,Field*>&  field_map_;
    map<String,Constructor*>& constructor_map_;
    Destructor& destructor_;
};

}
}

#endif // RED_BANK_IOC_CLASS_H
