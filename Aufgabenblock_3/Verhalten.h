#pragma once
#include <memory>

class Fahrzeug;
class Weg;

class Verhalten
{
public:
	Verhalten();
	Verhalten(Weg& weg);

	virtual double dStrecke(Fahrzeug& fahrzeug, double dZeit) =0;
	virtual Weg* getWeg(){ return p_pWeg; }

	virtual ~Verhalten();
protected:
	Weg* p_pWeg;
};

