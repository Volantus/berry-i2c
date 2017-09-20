class I2CInterface : public Php::Base
{
private:
    /**
     *  An I2C bus number
     *  @var    unsigned
     */
    unsigned bus = 0;

    /**
     *  The address of a device on the I2C bus.
     *  @var    unsigned 0-0x7F
     */
    unsigned address = 0;

    /**
     *  Flags which modify an I2C open command. None are currently defined.
     *  @var    unsigned 0-0x7F
     */
    unsigned flags = 0;

public:
    I2CInterface() = default;
    virtual ~I2CInterface() = default;

    void __construct(Php::Parameters &params);

    Php::Value getBus() const;
    Php::Value getAddress() const;
    Php::Value getFlags() const;

    void open();
};