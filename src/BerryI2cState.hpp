class BerryI2cState
{
private:
    static int pigpioInitRc;

public:
    static void initDependencies();
    static void cleanDependencies();
    static int getPigpioInitRc();
};