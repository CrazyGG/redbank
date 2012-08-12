#ifndef RED_BANK_IOC_CALLER_H
#define RED_BANK_IOC_CALLER_H


/**
\file caller.h
IoC容器核心接口
*/
#include <redbank/platform.h>
#include <redbank/ioc/parameters.h>



namespace redbank{
namespace ioc{

/**
\brief IoC 容器的核心接口，封装方法的调用过程。

在IoC容器中，Caller封装了方法的调用过程，Caller的子类建有IoC编译器实现。
IoC编译器为指定的类生成多个Caller的子类，每个Caller的子类执行一个方法的实际调用过程。

sample:

\code
    class MyClass {
    public:
        void sayHello(const std::string& name)
        {
            std::cout << name << " Hello" << std::endl;
        }
    }

    class MyClass_sayHello_Caller : public Caller{
    public:
        typedef void (MyClass::*InvokedFunction)(const std::string&);
    public:
        MyClass_sayHello_Caller():function_(&MyClass::sayHello)
        {}

        virtual ~MyClass_sayHello_Caller()
        {}

    public:
        virtual Variant invoke(void* obj,const Parameters& params)
        {
            try{
                MyClass* my_class = static_cast<MyClass>(obj);


            }catch(...){
            }
        }
    private:
        InvokedFunction function_;
    }
\endcode
*/
class Caller{
public://destructor
    /**
    \brief 析构函数
    */
    virtual ~Caller()
    {}

public:// invoke

    /**
    \brief 封装类方法的调用过程。

    封装方法的执行过程，返回执行结果
     *  @param obj 指向与被调用方法关联的类的指针
     *  @param params 时间调用方法的参数包装器
     *  @return 返回调用结果
     */
    virtual Variant invoke(void* obj,const Parameters& params) = 0;
};

}
}

#endif // RED_BANK_IOC_CALLER_H
