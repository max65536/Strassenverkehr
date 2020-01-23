#pragma once
#include"Simulationsobject.h"
#include<memory>
#include<list>
#include"Weg.h"
class Kreuzung :public Simulationsobject
{
public:
	Kreuzung()=default;
	Kreuzung(string sName, double dTankstellenKapazitaet = 0);

	void vVerbinde(string sNameHinweg, string sNameRueckweg, double dWegLaenge, Kreuzung* kreuzung,
		Weg::Tempolimit geschwBegrenz = Weg::Tempolimit::Autobahn, bool bUeberholVerbot = true);
	void vTanken(Fahrzeug&);
	void vAnnahme(unique_ptr<Fahrzeug>,double dZeit);
	void vSimulieren();
	Weg& ptZufaelligerWeg(Weg& pWeg);

	virtual ~Kreuzung();

private:
	double p_dTankstelle;
	list<weak_ptr<Weg>> p_pWege;


};

