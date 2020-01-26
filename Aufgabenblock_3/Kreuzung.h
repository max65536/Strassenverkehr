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

	void vVerbinde(string sNameHinweg, string sNameRueckweg, double dWegLaenge, 
		weak_ptr<Kreuzung> pStartKreuzung, const weak_ptr<Kreuzung> pZielKreuzung,
		Weg::Tempolimit geschwBegrenz = Weg::Tempolimit::Autobahn, bool bUeberholVerbot = true);
	void vTanken(Fahrzeug&);
	void vAnnahme(unique_ptr<Fahrzeug>,double dZeit);
	void vSimulieren();
	Weg& pZufaelligerWeg(Weg& pWeg);
	double getTankstellen() { return p_dTankstelle; }

	virtual ~Kreuzung();

private:
	double p_dTankstelle;
	list<shared_ptr<Weg>> p_pWege;


};

