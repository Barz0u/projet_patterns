#include "PassengerShip.h"
#include "Ship.h"

PassengerShip::PassengerShip()
{
    //ctor
}

PassengerShip::PassengerShip(std::string Name, Factory* f) : Ship( Name, f)
{

}
float PassengerShip::failureProbability(){
	return 20;
}
bool PassengerShip::accept(int dockId){
	if(dockId <= 10)
		{return true;}
	else
	{return false;}
}
int PassengerShip::getPriority(){
	return 7;
}
