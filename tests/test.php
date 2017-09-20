<?php
use Volantus\BerryI2C\I2cInterface;

$i2cInterface = new I2CInterface(-1, 2);
var_dump($i2cInterface->getBus());
var_dump($i2cInterface->getAddress());
var_dump($i2cInterface->getFlags());

$i2cInterface->open();