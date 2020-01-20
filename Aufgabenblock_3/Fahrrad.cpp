#include "Fahrrad.h"
#include"Weg.h"
#include "SimuClient.h"
#include <math.h>

Fahrrad::Fahrrad() :
Fahrzeug()
{}
Fahrrad::Fahrrad(string sName, double dMaxGeschwindigkeit):
Fahrzeug(sName, dMaxGeschwindigkeit)
{
}

double Fahrrad::dGeschwindigkeit()const{
	int iPow=(int)(p_dGesamtStrecke / 20);
	double dGeschwindigkeit = p_dMaxGeschwindigkeit*pow(0.9,iPow);
	if (dGeschwindigkeit < 12) dGeschwindigkeit = 12;
	return dGeschwindigkeit;
}
void Fahrrad::vSimulieren(){
	Fahrzeug::vSimulieren();
}
void Fahrrad::vAusgeben(){
	Fahrzeug::vAusgeben();
}

void Fahrrad::vZeichnen(const Weg& weg) const
{
	double dGeschwind = dGeschwindigkeit();
	double dLaenge = weg.getLaenge();
	double realPosition = p_dAbschnittStrecke / dLaenge;
	string tmp = weg.getName();
	const char *sWegname = tmp.c_str();
//	string tem = weg.getName();
	bZeichneFahrrad(p_sName, sWegname, realPosition, dGeschwind);
}


Fahrrad::~Fahrrad()
{
}
