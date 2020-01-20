#pragma once
#include<exception>
using namespace std;

class Fahrzeug;
class Weg;

class Fahrausnahme:
	public exception
{
public:
	Fahrausnahme()=default;
	Fahrausnahme(Fahrzeug& fahrzeug, Weg& weg);

	virtual void vBearbeiten()=0;

	virtual ~Fahrausnahme();
protected:
	Fahrzeug& p_pFahrzeug;
	Weg& p_pWeg;
};

