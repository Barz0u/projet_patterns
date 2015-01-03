#include "WeakHull.h"

WeakHull::WeakHull()
{
    m_solidity = 1;
}

WeakHull::~WeakHull()
{
    //dtor
}

bool WeakHull::operator < (const Hull& a) const
{
    if (this->getSolidity() < a.getSolidity())
        return true;
    else
        return false;
}
