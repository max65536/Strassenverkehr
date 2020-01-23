#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Streckenende.h"
#include<algorithm>

Fahren::Fahren()
{
}
Fahren::Fahren(Weg& weg):
Verhalten(weg)
{}

double Fahren::dStrecke(Fahrzeug& fahrzeug, double dZeit)
{
	if (dZeit == 0) return 0;
	double dVirtuelleStrecke = p_pWeg->getVirtuelleSchranke();
	double dZeitLaenge = fahrzeug.dGeschwindigkeit()*dZeit;
	double dAbschnittStrecke = fahrzeug.getAbschnittStrecke();
	double dRestLaenge = p_pWeg->getLaenge() - dAbschnittStrecke;
	double dVirtuelleRestLaenge= dVirtuelleStrecke - dAbschnittStrecke;

	if (dRestLaenge <0.01)
	{
		throw new Streckenende(fahrzeug, *p_pWeg);
		return 0;
	}
	double dFahrbarLaenge = min(min(dRestLaenge,dVirtuelleRestLaenge),dZeitLaenge);
	p_pWeg->setVirtuelleSchranke(dFahrbarLaenge+ dAbschnittStrecke);
	return dFahrbarLaenge;
	
}

Fahren::~Fahren()
{
}
