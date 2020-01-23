#include "Kreuzung.h"
#include "Fahrzeug.h"

Kreuzung::Kreuzung(string sName, double dTankstelle) :
	p_dTankstelle(dTankstelle),
	Simulationsobject(sName)
{
}

void Kreuzung::vTanken(Fahrzeug& fahrzeug) 
{
	if (p_dTankstelle > 0) 
	{
		p_dTankstelle -= fahrzeug.dTanken(-1);
	}
}

void Kreuzung::vVerbinde(string sNameHinweg, string sNameRueckweg, double dWegLaenge, Kreuzung* kreuzung,
	Weg::Tempolimit geschwBegrenz = Weg::Tempolimit::Autobahn, bool bUeberholVerbot = true) 
{
}

Kreuzung::~Kreuzung() 
{
}