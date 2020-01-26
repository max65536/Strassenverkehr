#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Kreuzung.h"

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
	fahrzeuglist->vAktualisieren();
	Kreuzung& kreuzung = p_pWeg.getKreuzung();
	Weg& neuweg = kreuzung.pZufaelligerWeg(p_pWeg);
	kreuzung.vTanken(p_pFahrzeug);
	unique_ptr<Fahrzeug> pFahrzeug(&p_pFahrzeug);
	neuweg.vAnnahme(move(pFahrzeug));

	cout << setw(10) << "ZEIT" << ":" << dGlobaleZeit << endl
		<< setw(10) << "KREUZUNG" << ":" << kreuzung.getName() << " " << kreuzung.getTankstellen() << endl
		<< setw(10) << "WECHSEL" << ":" << p_pWeg.getName() << " -> " << neuweg.getName() << endl
		<< setw(10) << "FAHRZEUG" << ":" << pFahrzeug->getName() << endl;
}

Streckenende::~Streckenende()
{
}
