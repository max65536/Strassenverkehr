#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<memory>
#include"Simulationsobject.h"

using namespace std;


extern double dGlobaleZeit;

class Verhalten;
class Weg;
class Fahren;
class Parken;

class Fahrzeug:public Simulationsobject
{
protected:
	double p_dMaxGeschwindigkeit=0;
	double p_dGesamtStrecke=0;
	double p_dGesamtZeit=0;

	Verhalten *p_pVerhalten;
//	shared_ptr<Verhalten> p_pVerhalten;

	double p_dAbschnittStrecke=0;
public:
	Fahrzeug();
	Fahrzeug(string name);
	Fahrzeug(string name, double maxGeschwindigkeit);
	Fahrzeug(const Fahrzeug &fahrzeug) = delete;

	static void vKopf();
	virtual void vAusgeben();

	virtual void vSimulieren();

	virtual double dTanken(double dMenge);

	virtual double dGeschwindigkeit() const { return p_dMaxGeschwindigkeit; }

	void vNeueStrecke(Weg&);
	void vNeueStrecke(Weg& weg, double dStartzeitpunkt);
	double getAbschnittStrecke();
	void setZeit(double dZeit){ p_dZeit = dZeit; }
	double getZeit(){ return p_dZeit; }
	virtual void vZeichnen(const Weg&)const {};

	virtual int check_type(){ return 0; };

	virtual ostream& vAusgeben(ostream& oStream);

	bool operator <(const Fahrzeug& fahrzeug);
	Fahrzeug& operator =(const Fahrzeug& fahrzeug);
	
	void setAbschnittStrecke(double dAbschnittStrecke) { p_dAbschnittStrecke = dAbschnittStrecke; };

	void test();

	virtual istream& vEinlesen(istream&) override;

	virtual ~Fahrzeug();
};

ostream& operator<<(ostream& oStream, Fahrzeug& fahrzeug);
