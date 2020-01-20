#pragma once
#include "Fahrausnahme.h"
class Streckenende :
	public Fahrausnahme
{
public:
	Streckenende();
	Streckenende(Fahrzeug& fahrzeug, Weg& weg);
	virtual void vBearbeiten();
	~Streckenende();
};

