#include "Simulationsobject.h"

int Simulationsobject::p_iMaxID = 0;
Simulationsobject::Simulationsobject()
{
}

Simulationsobject::Simulationsobject(string name):
	p_sName(name),
	p_iID(++p_iMaxID)
{}



void Simulationsobject::vAusgeben()
{
	cout << setiosflags(ios::right)
		<< setw(6) << p_iID
		<< setw(10) << p_sName
		<<':';
}

ostream& Simulationsobject::vAusgeben(ostream& os)
{
	os << setiosflags(ios::right)
		<< setw(6) << p_iID
		<< setw(10) << p_sName
		<< ':';
	return os;
}

ostream& operator<<(ostream& oStream, Simulationsobject& simulationsobject)
{
	simulationsobject.vAusgeben(oStream);
	//	os << "overload" << endl;
	return oStream;
}

Simulationsobject::~Simulationsobject()
{
	cout << "geloeschtes object: " << p_sName << " " << p_iID <<" "<< p_dZeit<< endl;
}
