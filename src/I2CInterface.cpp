#include <phpcpp.h>
#include <stdint.h>
#include <pigpio.h>
#include "BerryI2cState.hpp"
#include "I2CInterface.hpp"

void I2CInterface::__construct(Php::Parameters &params)
{
    int _bus = params[0];
    int _address = params[1];
    int _flags = 0;
    if (params.size() > 2) {
        _flags = params[2];
    }

    if (_bus < 0) {throw Php::Exception("No negative values allowed for <bus> parameter");}
    if (_address < 0) {throw Php::Exception("No negative values allowed for <address> parameter");}
    if (_flags < 0) {throw Php::Exception("No negative values allowed for <flags> parameter");}

    bus = _bus;
    address = _address;
    flags = _flags;

    if (BerryI2cState::getPigpioInitRc() < 0) {
        std::string message = "Pigpio initialization failed with RC=";
        message = message + std::to_string(BerryI2cState::getPigpioInitRc());
        throw Php::Exception(message);
    }
}

void I2CInterface::open()
{
    handle = i2cOpen(bus, address, flags);
}

Php::Value I2CInterface::getBus() const { return (int16_t) bus; }
Php::Value I2CInterface::getAddress() const { return (int16_t) address; }
Php::Value I2CInterface::getFlags() const { return (int16_t) flags; }
