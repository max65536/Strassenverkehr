#pragma once
#include<list>
#include <memory>
#include <string>
#include "Simulationsobject.h"
#include "Fahrzeug.h"
#include "vertagt_liste.h"
using namespace std;

class Fahrzeug;
class Kreuzung;

typedef vertagt::VListe<unique_ptr<Fahrzeug>>::iterator vIterator;

class Weg :
	public Simulationsobject
{
public:
	enum Tempolimit { Innerorts = 50, Landstrasse = 100, Autobahn = 1000000 };
	double getTempolimit();
	static void vKopf();
	virtual void vSimulieren() override;
	virtual void vAusgeben() override;
	virtual ostream& vAusgeben(ostream& os) override;
	void vFahrzeuglistAusgeben();
	vertagt::VListe<unique_ptr<Fahrzeug>>* getList(){ return &p_pFahrzeuge; }
//	list<Fahrzeug*> getList(){ return p_pFahrzeuge; }

	//Fahrende
	void vAnnahme(unique_ptr<Fahrzeug> pFahrzeug);
	//Parkende
	void vAnnahme(unique_ptr<Fahrzeug> pFahrzeug, double dStartzeitpunkt);

	unique_ptr<Fahrzeug> pAbgabe(Fahrzeug& pFahrzeug);

	Weg();
	Weg(string name, double laenge, Tempolimit Geschwindigkeitslimit = Autobahn, bool bUeberholverbot = true);
	Weg(string name, double laenge, weak_ptr<Kreuzung> pKreuzung ,Tempolimit Geschwindigkeitslimit = Autobahn, bool bUeberholverbot = true);
	double getLaenge() const { return p_dLanenge; };

	~Weg();

	double getVirtuelleSchranke();
	void setVirtuelleSchranke(double dVirtuelleSchranke);
	void setRueckweg(weak_ptr<Weg> pRueckweg);
	Weg& getRueckweg();
	Kreuzung& getKreuzung();
	virtual istream& vEinlesen(istream&) override;

private:
	double p_dLanenge;
	Tempolimit p_eTempolimit;
//	vertagt::VListe<unique_ptr<Fahrzeug>> p_pFahrzeuge;
//	list<unique_ptr<Fahrzeug>> p_pFahrzeuge;
//	list<Fahrzeug*> p_pFahrzeuge;
	vertagt::VListe<unique_ptr<Fahrzeug>> p_pFahrzeuge;

	bool p_bUeberholverbot;
	double p_dVirtuelleSchranke=10000000000;
	weak_ptr<Weg> p_pRueckWeg;
	const weak_ptr<Kreuzung> p_pKreuzung;
};

ostream& operator<<(ostream& oStream, Weg& weg);