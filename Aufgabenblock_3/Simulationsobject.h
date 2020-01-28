#pragma once
#include <string>
#include<iostream>
#include<iomanip>
using namespace std;
class Simulationsobject
{
private:
	static int p_iMaxID;
public:
	virtual void vSimulieren() = 0;
	virtual void vAusgeben();
	virtual ostream& vAusgeben(ostream& oStream);

	string getName() const	{return p_sName;	}

	Simulationsobject();
	Simulationsobject(string name);
	virtual ~Simulationsobject();

	virtual istream& vEinlesen(istream&);

protected:
	string p_sName="";
	const int p_iID = 0;
	double p_dZeit = 0;

};

ostream& operator<<(ostream& oStream, Simulationsobject& simulationsobject);
istream& operator>>(istream& iStream, Simulationsobject& simulationsobject);

