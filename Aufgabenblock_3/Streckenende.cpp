#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Kreuzung.h"
#include <string>

Streckenende::Streckenende(Fahrzeug& fahrzeug, Weg& weg):
Fahrausnahme(fahrzeug,weg)
{
}

void Streckenende::vBearbeiten()
{
	cout << p_pFahrzeug.getName() << " faehrt auf dem Wegende von " << p_pWeg.getName() << endl;
	vertagt::VListe<unique_ptr<Fahrzeug>>* fahrzeuglist = p_pWeg.getList();

	Kreuzung& kreuzung = p_pWeg.getKreuzung();
	Weg& neuweg = kreuzung.pZufaelligerWeg(p_pWeg);

	vIterator it;
	for (it = fahrzeuglist->begin(); it != fahrzeuglist->end(); it++)
	{
		if ((*it).get() == &p_pFahrzeug)
		{
			fahrzeuglist->erase(it);
			kreuzung.vTanken(p_pFahrzeug);
			neuweg.vAnnahme(move(*it));
			break;
		}
	}
	
	fahrzeuglist->vAktualisieren();
	cout << "ZEIT     " << ":" << dGlobaleZeit << endl;
	cout << "KREUZUNG " << ":" << kreuzung.getName() << " " << kreuzung.getTankstellen() << endl;
	cout << "WECHSEL  " << ":" << p_pWeg.getName() << " -> " << neuweg.getName() << endl;
	cout << "FAHRZEUG " << ":" << p_pFahrzeug.getName() << endl;
}

Streckenende::~Streckenende()
{
}
