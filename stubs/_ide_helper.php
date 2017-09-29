<?php
namespace Volantus\BerryI2C;

/**
 * Class I2cInterface
 *
 * @package Volantus\BerryI2C
 */
class I2cInterface
{
    /**
     * I2cInterface constructor.
     *
     * @param int $bus
     * @param int $address
     * @param int $flags
     *
     * @throws InvalidArgumentException
     * @throws GpioInitException
     */
    public function __construct(int $bus, int $address, int $flags = 0)
    {
    }

    /**
     * Opens the I2C device
     *
     * @throws InvalidArgumentException
     */
    public function open()
    {
    }

    /**
     * This closes the I2C device associated
     */
    public function close()
    {
    }

    /**
     * @return int
     */
    public function getBus(): int
    {
    }

    /**
     * @return int
     */
    public function getAddress(): int
    {
    }

    /**
     * @return int
     */
    public function getFlags(): int
    {
    }
}

/**
 * Class InvalidArgumentException
 *
 * @package Volantus\BerryI2C
 */
class InvalidArgumentException extends \Exception
{
}

/**
 * Class GpioInitException
 *
 * @package Volantus\BerryI2C
 */
class GpioInitException extends \Exception
{
}