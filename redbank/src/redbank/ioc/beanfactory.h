#ifndef RED_BANK_BEAN_FACTORY_H
#define RED_BANK_BEAN_FACTORY_H

#include <redbank/platform.h>
#include <redbank/ioc/class.h>

#include <boost/shared_ptr.hpp>

namespace redbank {
namespace ioc {

using namespace boost;

enum ResourceType{
    xml,
    yaml
};


/**
*   BeanFactory是Ioc Framework的核心组件，该组件向IoC Container 的
*   用户提供对象创建和销毁的能力，Ioc Container管理所有创建对象的生命周期。
*   在对象不再被使用之后的某个时间又Ioc Container将销毁该对象。BeanFactory
*   是单例对象在系统运行的整个时期，任何进程中只有一个BeanFactory的对象。
*/
class BeanFactory{
public:
    /**
    *   调用该方法可以获得BeanFactoory的引用。
    */
    static BeanFactory& getInstance();
public:
    /**
    *   析构函数
    */
    ~BeanFactory()
    {
    }
public:

    /**
    *   该函数向IoC Container 添加资源，使得该IoC Container能够通过外部资源扩展
    *
    *   @param  resuorce    指定资源的配置文件路径
    *   @param  type        指定资源的配置文件使用的数据格式
    */
    void  addResuorce(const String& resource,ResourceType type);

    /**
    *   从Ioc Container中获取指定名称的对象，如果名称指定对象被指定为单例，重复
    *   重复使用该方法将得到同一个对象。该方法是模板方法调用是指定返回类型。
    *
    *   @param  objName 对象名称。
    */
    template<typename ReulteType>
    shared_ptr<ResultType> getObject(const String& objName);

    /**
    *   测试与对象名称关联的对象是否是单例对象。
    *
    *   @param  objName 对象名称。
    */
    bool isSingleton(const String& objName);

    /**
    *   测试容器是否提供指定名称的对象
    *
    *   @param  objName 对象名称。
    */
    bool contain(const String& objName);

    /**
    *   检索指定名称的对象的Class
    *
    *   @param  objName 对象名称。
    */
    shared_ptr<Class> getType(const String& objName);

private:
    BeanFactory();
    BeanFactory(const BeanFactory&);
    const BeanFactory& operator=(const BeanFactory&);

    class Impl;
    shared_ptr<Impl> impl;
};


}
}
#endif // RED_BANK_BEAN_FACTORY_H
