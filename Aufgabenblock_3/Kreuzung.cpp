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

void Kreuzung::vVerbinde(string sNameHinweg, string sNameRueckweg, double dWegLaenge, 
	weak_ptr<Kreuzung> pStartKreuzung, const weak_ptr<Kreuzung> pZielKreuzung,
	Weg::Tempolimit Geschwindigkeitslimit, bool bUeberholVerbot)
{
	shared_ptr<Weg> pHinweg = make_shared<Weg>(sNameHinweg,dWegLaenge, pZielKreuzung, Geschwindigkeitslimit, bUeberholVerbot);
	shared_ptr<Weg> pRueckweg = make_shared<Weg>(sNameRueckweg, dWegLaenge, pStartKreuzung, Geschwindigkeitslimit, bUeberholVerbot);
	pHinweg->setRueckweg(pRueckweg);
	pRueckweg->setRueckweg(pHinweg);

	pZielKreuzung.lock()->p_pWege.push_back(pRueckweg);
	p_pWege.push_back(pHinweg);

}

void Kreuzung::vAnnahme(unique_ptr<Fahrzeug> pFahrzeug,double dZeit) 
{
	vTanken(*pFahrzeug);
	p_pWege.front()->vAnnahme(move(pFahrzeug),dZeit);
}

void Kreuzung::vSimulieren() 
{
	list<shared_ptr<Weg>>::iterator it;
	for (it = p_pWege.begin();it != p_pWege.end();it++) {
		(*it)->vSimulieren();
	}
}

Weg& Kreuzung::pZufaelligerWeg(Weg& weg) 
{
	Weg& ruckweg = weg.getRueckweg();
	if (p_pWege.size() == 1)
	{
		return ruckweg;
	}
	int r = (rand() % p_pWege.size());
	list<shared_ptr<Weg>>::iterator it = p_pWege.begin();
	for (int i = 0; i < r; i++) 
	{
		it++;
	}
	if ((*it)->getName() == (ruckweg.getName())) 
	{
		return pZufaelligerWeg(ruckweg);
	}
	return *(*it);
}

Kreuzung::~Kreuzung() 
{
}