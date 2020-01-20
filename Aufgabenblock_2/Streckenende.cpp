#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"

Streckenende::Streckenende(Fahrzeug& fahrzeug, Weg& weg):
Fahrausnahme(fahrzeug,weg)
{
}

void Streckenende::vBearbeiten()
{
	cout << p_pFahrzeug.getName() << " faehrt auf dem Wegende von " << p_pWeg.getName() << endl;
	vertagt::VListe<unique_ptr<Fahrzeug>>* fahrzeuglist = p_pWeg.getList();
	for (vIterator it = fahrzeuglist->begin(); it != fahrzeuglist->end(); it++)
	{
		if ((*it).get() == &p_pFahrzeug)
		{
			fahrzeuglist->erase(it);
		}
	}
}

Streckenende::~Streckenende()
{
}
