#include <iostream>
#include <map>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <windows.h>
#include "instance.h"
#include "Ship.h"
#include "PassengerShip.h"
#include "PleasureCraft.h"
#include "MilitaryShip.h"
#include "FishingBoat.h"
#include "Harbor.h"
#include "SmallShipFactory.h"
#include "BigShipFactory.h"

using namespace std;

instance::instance()
{
}

instance::~instance()
{
}

Ship* instance::createShip()
{
	BigShipFactory* BigFacto = new BigShipFactory();
	SmallShipFactory* SmallFacto = new SmallShipFactory();
    int random = rand()%100;
    if(random<25)
    {return new PassengerShip("Passenger",SmallFacto);}
    else if(random>25 && random <50)
    {return new FishingBoat("Fishing",BigFacto);}
    else if(random>50 && random<75)
    {return new MilitaryShip("Military",BigFacto);}
    else if(random<75)
    {return new PleasureCraft("Pleasure",SmallFacto);}
    else
    {return new PleasureCraft("Pleasure",SmallFacto);}
}

void instance::addToWaitList(Ship* Boat) // Ajoute l'élement a la file
{_waitList.push(Boat);}

void instance::cycle()
{
		int Pg=30;
		int random = rand()%100;
		coord* coordEntrance;
		Ship* Boat=NULL;
		Harbor* Port = Harbor::getInstance();//Harbor est un singleton, on récupere l'instance qui existe deja
		Port->addQuais();
		while(1)
		{
		Pg=30;
		random = rand()%100;
		if(random < Pg)	// Si ma proba de creation est validée
		{
			cout<<"Un bateau sauvage apparait"<<endl;
			Boat = createShip();	//Je créé mon bateau
			cout<<Boat->getName()<<endl;
			coordEntrance = Port->getInitialPosition(); // Je recup les position d'entrée de mon port
			if(Port->isThereAShip(coordEntrance)==false)//Si pas de bateau sur l'entrée
			{
				if(Port->findFreeReservation() != -1)
				{
					Port->addReservation(Port->findFreeReservation(),Boat);
					Port->addShip(Boat);
				}
				else
				{
					cout<<"Toutes les reservations sont prises, placement en file d'attente"<<endl;}
					addToWaitList(Boat);
				}
			else
			{
				cout<<"La case d'entrée est prise, placement en file d'attente"<<endl;
				addToWaitList(Boat);
			}
		}
		else //if(_waitList.empty()==false)
		{
			cout<<"Pas de bateau pour ce cycle"<<endl;
			/*if(Port->isThereAShip(coordEntrance)==false )//Si pas de bateau sur l'entrée
			{
				if(Port->findFreeReservation() != -1)
				{
					Port->addReservation(Port->findFreeReservation(),_waitList.front());
					Port->addShip(_waitList.front());
					_waitList.pop();
				}
				else{}
			}*/
		}
		Port->moveBoatsToQuais();
		//Port->afficheMatrix();
		Port->dessineMatrix();
		cout<<" "<<endl;
		cout<<" "<<endl;
		Sleep(1000);
	}
}
