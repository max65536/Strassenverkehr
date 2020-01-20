#pragma once

#include "Verhalten.h"
class Weg;
class Fahrzeug;

class Fahren :
	public Verhalten
{
public:
	Fahren();
	Fahren(Weg&);

	virtual double dStrecke(Fahrzeug& fahrzeug, double dZeit) override;

	~Fahren();
};

