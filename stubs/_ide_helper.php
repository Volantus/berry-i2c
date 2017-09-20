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
     */
    public function __construct(int $bus, int $address, int $flags = 0)
    {
    }

    /**
     * Opens the I²C connection
     */
    public function open()
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