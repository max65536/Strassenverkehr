#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <memory>

Losfahren::Losfahren(Fahrzeug& fahrzeug, Weg& weg):
Fahrausnahme(fahrzeug,weg)
{
}
void Losfahren::vBearbeiten()
{
	cout << p_pFahrzeug.getName() << " faehrt auf " << p_pWeg.getName() << " los um " << p_pFahrzeug.getZeit()<< "." << endl;
//	p_pWeg.pAbgabe(p_pFahrzeug);
	unique_ptr<Fahrzeug> pf = p_pWeg.pAbgabe(p_pFahrzeug);
	p_pWeg.vAnnahme(move(pf));
	
}

Losfahren::~Losfahren()
{
}
