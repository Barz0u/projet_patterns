#include "FishingBoat.h"
#include "Ship.h"
#include <windows.h>

FishingBoat::FishingBoat()
{
    //ctor
}
FishingBoat::FishingBoat(std::string Name, Factory* f): Ship(Name , f)
{

}
float FishingBoat::failureProbability(){
	int random =0;
	while(random<9)
		{random = rand()%100;}
	return random;
}
bool FishingBoat::accept(int dockId){
	if(dockId % 2 != 0)
		{return true;}
	else
	{return false;}
}
int FishingBoat::getPriority(){
	return 4;
}
