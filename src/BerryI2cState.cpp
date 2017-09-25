#include <pigpio.h>
#include "BerryI2cState.hpp"

int BerryI2cState::pigpioInitRc;

void BerryI2cState::initDependencies()
{
    pigpioInitRc = gpioInitialise();
}

void BerryI2cState::cleanDependencies()
{
    gpioTerminate();
}

int BerryI2cState::getPigpioInitRc()
{
    return pigpioInitRc;
}

