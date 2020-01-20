#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Streckenende.h"

Fahren::Fahren()
{
}
Fahren::Fahren(Weg& weg):
Verhalten(weg)
{}

double Fahren::dStrecke(Fahrzeug& fahrzeug, double dZeit)
{
	double dStrecke1 = fahrzeug.dGeschwindigkeit()*dZeit;
	double dStrecke2 = p_pWeg->getLaenge() - fahrzeug.getAbschnittStrecke();
	if (dStrecke2<0.01)
	{
		throw new Streckenende(fahrzeug, *p_pWeg);
	}
	
	if (dStrecke1 > dStrecke2) 
	{
		cout << "Wegende" << endl;
		return dStrecke2;
	}
	else
	{
		return dStrecke1;
	}
}

Fahren::~Fahren()
{
}
