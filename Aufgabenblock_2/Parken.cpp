#include "Parken.h"
#include "Losfahren.h"
#include "Fahrzeug.h"

extern double dGlobaleZeit;

Parken::Parken()
{
}

Parken::Parken(Weg& weg, double dStartzeitpunkt):
Verhalten(weg),
p_dStartzeitpunkt(dStartzeitpunkt)
{}

double Parken::dStrecke(Fahrzeug& fahrzeug, double dZeit)
{
	if (dGlobaleZeit > p_dStartzeitpunkt)
	{
		fahrzeug.setZeit(p_dStartzeitpunkt);
		throw new Losfahren(fahrzeug, *p_pWeg);
	}
	else
	{
		return 0;
	}
}

Parken::~Parken()
{
}
