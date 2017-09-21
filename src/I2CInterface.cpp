#include <phpcpp.h>
#include <stdint.h>
#include <pigpio.h>
#include "BerryI2cState.hpp"
#include "I2CInterface.hpp"

void I2CInterface::__construct(Php::Parameters &params)
{
    int _bus = params[0];
    int _address = params[1];
    int _flags = params[2];

    bus = _bus;
    address = _address;
    flags = _flags;
}

void I2CInterface::open()
{
}

Php::Value I2CInterface::getBus() const { return (int16_t) bus; }
Php::Value I2CInterface::getAddress() const { return (int16_t) address; }
Php::Value I2CInterface::getFlags() const { return (int16_t) flags; }
