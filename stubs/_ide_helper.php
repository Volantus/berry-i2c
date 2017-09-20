<?php
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