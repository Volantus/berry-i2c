#include <stdexcept>
#include <phpcpp.h>
#include "BerryI2cExceptions.hpp"

zend_class_entry* BerryI2cExceptions::_invalidArgumentException;

void BerryI2cExceptions::prepare()
{
    registerException("Volantus\\BerryI2C\\InvalidArgumentException", &_invalidArgumentException);
}

void BerryI2cExceptions::registerException(const char* name, zend_class_entry **memberClassEntry)
{
    zend_class_entry classEntry;
    INIT_CLASS_ENTRY(classEntry, name, NULL);
    *memberClassEntry = zend_register_internal_class_ex(&classEntry, zend_exception_get_default());
}

void BerryI2cExceptions::InvalidArgumentException(const char* message)
{
    zend_throw_exception_ex(_invalidArgumentException, 0, message, __FILE__, __LINE__);
}