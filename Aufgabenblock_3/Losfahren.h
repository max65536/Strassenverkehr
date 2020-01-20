#pragma once
#include "Fahrausnahme.h"
class Losfahren :
	public Fahrausnahme
{
public:
	Losfahren();
	Losfahren(Fahrzeug& fahrzeug, Weg& weg);
	virtual void vBearbeiten();
	virtual ~Losfahren();
};

