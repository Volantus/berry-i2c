#include <Zend/zend.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_API.h>

class BerryI2cExceptions
{
private:
    static zend_class_entry* _invalidArgumentException;
    static void registerException(const char* name, zend_class_entry **memberClassEntry);

public:
    static void prepare();
    static void InvalidArgumentException(const char* message);
};