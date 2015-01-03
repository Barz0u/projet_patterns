#ifndef BIGSHIPFACTORY_H
#define BIGSHIPFACTORY_H
#include "Factory.h"

class BigShipFactory : public Factory
{
    public:
        BigShipFactory();
        ~BigShipFactory();
        Engine* createEngine();
        Hull* createHull();
    protected:
    private:
};

#endif // BIGSHIPFACTORY_H
