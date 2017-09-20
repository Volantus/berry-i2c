#include <phpcpp.h>
#include "I2CInterface.hpp"

extern "C" {
    /**
     *  @return void*   a pointer to an address that is understood by PHP
     */
    PHPCPP_EXPORT void *get_module() 
    {
        static Php::Extension extension("berry-i2c", "0.1");
        Php::Class<I2CInterface> i2cInterface("I2CInterface");
        i2cInterface.method<&I2CInterface::__construct> ("__construct", {
            Php::ByVal("bus", Php::Type::Numeric, true),
            Php::ByVal("address", Php::Type::Numeric, true),
            Php::ByVal("flags", Php::Type::Numeric, false),
        });
        i2cInterface.method<&I2CInterface::getBus> ("getBus");
        i2cInterface.method<&I2CInterface::getAddress> ("getAddress");
        i2cInterface.method<&I2CInterface::getFlags> ("getFlags");
        i2cInterface.method<&I2CInterface::open> ("open");

        extension.add(std::move(i2cInterface));

        return extension;
    }
}