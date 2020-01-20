#pragma once
#include "Fahrzeug.h"
class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(string name, double maxGeschwindigkeit);

	virtual double dGeschwindigkeit() override;
	virtual void vAusgabe() override;
	virtual void vSimulieren() override;

	virtual int check_type(){ return 2; };
//	virtual void vAusgabe(ostream& oStream) override;

	virtual ~Fahrrad();
};

