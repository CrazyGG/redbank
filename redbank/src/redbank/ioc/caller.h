#ifndef RED_BANK_IOC_CALLER_H
#define RED_BANK_IOC_CALLER_H

#include <redbank/platform.h>
#include <redbank/ioc/parameters.h>

/**
*   核心接口用于包装class的一个方法的调用过程，该接口的具体实现由
*   工具自动生成。
*/

namespace redbank{
namespace ioc{


class Caller{
public://destructor
    virtual ~Caller()
    {}

public:// invoke

    /**
     *  该方法执行了类方法的调用过程。再方法中对类方法的参数进行解包，返回调用结果的包装器
     *  @param obj 指向与被调用方法关联的类的指针
     *  @param params 时间调用方法的参数包装器
     *  @return 返回调用结果
     */
    virtual Variant invoke(void* obj,const Parameters& params) = 0;
};

}
}

#endif // RED_BANK_IOC_CALLER_H
