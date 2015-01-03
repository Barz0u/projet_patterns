#include "StrongHull.h"

StrongHull::StrongHull()
{
    m_solidity = 4;
}

StrongHull::~StrongHull()
{
    //dtor
}

bool StrongHull::operator < (const Hull& a) const
{
    if (this->getSolidity() < a.getSolidity())
        return true;
    else
        return false;
}
