#ifndef RED_BANK_BEAN_FACTORY_H
#define RED_BANK_BEAN_FACTORY_H

#include <redbank/platform.h>
#include <redbank/ioc/class.h>


namespace redbank {
namespace ioc {

enum ResourceType{
    xml,
    yaml
};


/**
*	BeanFactory是Ioc Framework的核心接口，该接口向IoC Container 的
*用户提供对象创建和销毁的能力，BeanFactory将会管理所有已被她创建的对象。
*用户在不再使用对象时可以直接丢弃对象的引用，或者显示的销毁不再使用的
*对象。不再使用的并且没有
*
*/
class BeanFactory{
public:
    static BeanFactory& getInstance();
public:
    ~BeanFactory()
    {}
public:

    void  addResuorce(const string& resource,ResourceType type);

    template<typename ReulteType>
    shared_ptr<ResultType> getBean(const string& beanName);

    bool isSingleton(const string& beanName);

    bool contain(const string& beanName);

    shared_ptr<Class> getType(const string& beanName);

private:

    BeanFactory();
    BeanFactory(const BeanFactory&);
    const BeanFactory& operator=(const BeanFactory&);

    //
    class Impl;
    shared_ptr<Impl> impl;
};


}
}
#endif // RED_BANK_BEAN_FACTORY_H