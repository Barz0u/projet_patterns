#include "MilitaryShip.h"
#include "Ship.h"

MilitaryShip::MilitaryShip()
{
    //ctor
}
MilitaryShip::MilitaryShip(std::string Name, Factory* f) : Ship( Name, f)
{

}
float MilitaryShip::failureProbability(){
	return 50;
}
bool MilitaryShip::accept(int dockId){
	if(dockId >= 20)
		{return true;}
	else
	{return false;}
}
int MilitaryShip::getPriority(){
	return 10;
}
