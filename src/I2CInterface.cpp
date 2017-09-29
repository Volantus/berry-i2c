#include <phpcpp.h>
#include <stdint.h>
#include <pigpio.h>
#include "BerryI2cState.hpp"
#include "BerryI2cExceptions.hpp"
#include "I2CInterface.hpp"

void I2CInterface::__construct(Php::Parameters &params)
{
    int _bus = params[0];
    int _address = params[1];
    int _flags = 0;
    if (params.size() > 2) {
        _flags = params[2];
    }
    handle = -1;

    if (_bus < 0) {BerryI2cExceptions::InvalidArgumentException("No negative values allowed for <bus> parameter"); return;}
    if (_address < 0) {BerryI2cExceptions::InvalidArgumentException("No negative values allowed for <address> parameter"); return;}
    if (_flags < 0) {BerryI2cExceptions::InvalidArgumentException("No negative values allowed for <flags> parameter"); return;}

    bus = _bus;
    address = _address;
    flags = _flags;

    if (BerryI2cState::getPigpioInitRc() < 0) {
        std::string message = "Pigpio initialization failed with RC=";
        message = message + std::to_string(BerryI2cState::getPigpioInitRc());
        BerryI2cExceptions::GpioInitFailureException(message.c_str());
        return;
    }
}

void I2CInterface::open()
{
    int rc = i2cOpen(bus, address, flags);

    if (rc > 0) {
        handle = rc;
    } else if (rc == PI_BAD_I2C_BUS) {
        BerryI2cExceptions::InvalidArgumentException("i2cOpen failed => bad i2c bus");
        return;
    } else if (rc == PI_BAD_I2C_ADDR) {
        BerryI2cExceptions::InvalidArgumentException("i2cOpen failed => bad i2c address");
        return;
    } else if (rc == PI_BAD_FLAGS) {
        BerryI2cExceptions::InvalidArgumentException("i2cOpen failed => bad i2c flags");
        return;
    } else if (rc == PI_NO_HANDLE) {
        throw Php::Exception("i2cOpen failed => no handle available");
    } else {
        throw Php::Exception("i2cOpen failed => opening failed for unknown reason");
    }
}

void I2CInterface::close()
{
    if (handle == -1) {
        BerryI2cExceptions::LogicException("Unable to close an unestablished device connection");
        return;
    }  

    int expectedRc = handle;
    int rc = i2cClose(handle);
    handle = -1;

    if (rc != expectedRc) {
        std::string message = "i2cClose failed as RC " + std::to_string(rc) + " does not match expected handle " + std::to_string(expectedRc);
        throw Php::Exception(message);
    }
}

Php::Value I2CInterface::getBus() const { return (int16_t) bus; }
Php::Value I2CInterface::getAddress() const { return (int16_t) address; }
Php::Value I2CInterface::getFlags() const { return (int16_t) flags; }
