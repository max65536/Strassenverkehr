#include "Fahrrad.h"
#include <math.h>

Fahrrad::Fahrrad() :
Fahrzeug()
{}
Fahrrad::Fahrrad(string sName, double dMaxGeschwindigkeit):
Fahrzeug(sName, dMaxGeschwindigkeit)
{
}

double Fahrrad::dGeschwindigkeit(){
	int iPow=(int)(p_dGesamtStrecke / 20);
	double dGeschwindigkeit = p_dMaxGeschwindigkeit*pow(0.9,iPow);
	if (dGeschwindigkeit < 12) dGeschwindigkeit = 12;
	return dGeschwindigkeit;
}
void Fahrrad::vSimulieren(){
	Fahrzeug::vSimulieren();
}
void Fahrrad::vAusgabe(){
	Fahrzeug::vAusgabe();
}


Fahrrad::~Fahrrad()
{
}
