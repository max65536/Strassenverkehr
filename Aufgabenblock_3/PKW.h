#pragma once
#include "Fahrzeug.h"
class PKW :
	public Fahrzeug
{
private:
	double p_dVerbrauch=0;
	double p_dTankvolumen=551;
	double p_dTankinhalt=275.5;

public:


	PKW();
	PKW(string sName);
	PKW(string sName, double dMaxGeschwindigkeit);
	PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen=551);

	virtual void vAusgeben() override;
	virtual double dTanken(double dMenge = 0) override;
	virtual void vSimulieren() override;
	virtual double dGeschwindigkeit() const override;
	virtual void vZeichnen(const Weg&) const override;

	virtual int check_type(){ return 1; };
	virtual ostream& vAusgeben(ostream& os) override;

	virtual istream& vEinlesen(istream& is) override;

	virtual ~PKW();


};

