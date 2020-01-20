#pragma once
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;


extern double dGlobaleZeit;

class Fahrzeug
{
private:
	static int p_iMaxID;
protected:
	string p_sName = "";
	const int p_iID = 0;
	double p_dMaxGeschwindigkeit=0;
	double p_dGesamtStrecke=0;
	double p_dGesamtZeit=0;
	double p_dZeit=0;
public:
	Fahrzeug();
	Fahrzeug(string name);
	Fahrzeug(string name, double maxGeschwindigkeit);
	Fahrzeug(const Fahrzeug &fahrzeug) = delete;

	static void vKopf();
	virtual void vAusgabe();

	virtual void vSimulieren();

	virtual double dTanken(double dMenge);

	virtual double dGeschwindigkeit(){ return p_dMaxGeschwindigkeit; };

	virtual int check_type(){ return 0; };

	virtual void vAusgabe(ostream& oStream);

	bool operator <(const Fahrzeug& fahrzeug);
	Fahrzeug& operator =(const Fahrzeug& fahrzeug);


	void test();

	virtual ~Fahrzeug();
};

ostream& operator<<(ostream& oStream, Fahrzeug& fahrzeug);
