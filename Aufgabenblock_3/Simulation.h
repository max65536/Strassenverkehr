#pragma once
#include <memory>
#include <list>
#include <string>
#include <iostream>
#include<map>
class Kreuzung;
using namespace std;

class Simulation
{
public:
	Simulation();
	void vEinlesen_default(istream&);
	void vEinlesen(istream&, bool bMitGrafik=false);
	void vSimulieren();
	void vSimulieren(double dDauer, double dZeitschritt);
	virtual ~Simulation();

	shared_ptr<Kreuzung> getKreuzung(string sName);

private:
	list<shared_ptr<Kreuzung>> kreuzunglist;
	map<string, shared_ptr<Kreuzung>> kreuzungmap;
	int iZeile;

};

