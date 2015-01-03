#include "PleasureCraft.h"
#include "Ship.h"

PleasureCraft::PleasureCraft()
{
    //ctor
}
PleasureCraft::PleasureCraft(std::string Name, Factory* f) : Ship(Name, f)
{

}
float PleasureCraft::failureProbability(){
	return 5;
}
bool PleasureCraft::accept(int dockId){
	return true;
}
int PleasureCraft::getPriority(){
	return 2;
}
