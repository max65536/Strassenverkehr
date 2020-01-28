#include "Simulationsobject.h"

int Simulationsobject::p_iMaxID = 0;
Simulationsobject::Simulationsobject():p_iID(++p_iMaxID),p_sName("")
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

istream& Simulationsobject::vEinlesen(istream& iStream) {

	iStream >> p_sName;
	if (p_sName == "")
	{
		throw runtime_error("leerer Name");
	}
	return iStream;
}

ostream& operator<<(ostream& oStream, Simulationsobject& simulationsobject)
{
	simulationsobject.vAusgeben(oStream);
	//	os << "overload" << endl;
	return oStream;
}


istream& operator>>(istream& iStream, Simulationsobject& simulationsobject)
{
	simulationsobject.vEinlesen(iStream);
	return iStream;
}

Simulationsobject::~Simulationsobject()
{
	cout << "geloeschtes object: " << p_sName << " " << p_iID <<" "<< p_dZeit<< endl;
}
