#pragma once
#include<iostream>
#include "Verhalten.h"

class Weg;

class Parken :
	public Verhalten
{
public:
	Parken();
	Parken(Weg& weg, double dStartzeitpunkt);

	virtual double dStrecke(Fahrzeug& farzeug, double dZeit) override;

	~Parken();
private:
	double p_dStartzeitpunkt;
};

