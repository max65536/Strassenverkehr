#include "Fahrzeug.h"
#include"config.h"

int Fahrzeug::p_iMaxID = 0;

Fahrzeug::Fahrzeug():p_iID(++p_iMaxID){
		cout << "erzeugtes Fahrzeug: " << p_sName << " " << p_iID << endl;
	}

	//Instalisierungsliste
Fahrzeug::Fahrzeug(string name) :
		p_sName(name),
		p_iID(++p_iMaxID)
	{
		cout << "erzeugtes Fahrzeug: " << p_sName << " " << p_iID << endl;
	}
Fahrzeug::~Fahrzeug(){
		cout << "geloeschtes Fahrzeug: " << p_sName << " " << p_iID << endl;
	}
Fahrzeug::Fahrzeug(string name, double maxGeschwindigkeit):
		p_sName(name),
		p_dMaxGeschwindigkeit(maxGeschwindigkeit>0? maxGeschwindigkeit:0),
		p_iID(++p_iMaxID)
	{
		cout << "erzeugtes Fahrzeug: " << p_sName << " maxGeschwindigkeit=" << p_dMaxGeschwindigkeit << endl;
	}
void Fahrzeug::vAusgabe(){
	cout << setiosflags(ios::right)
		<< setw(6) << p_iID
		<< setw(10) << p_sName
		<< setw(20) << p_dMaxGeschwindigkeit
		<< setw(20) << p_dGesamtStrecke
		<< setw(25) << dGeschwindigkeit();
//		<< endl;
}
void Fahrzeug::vKopf(){
	cout << setiosflags(ios::left)
		<< setw(5) << "ID"
		<< setiosflags(ios::right)
		<< setw(10) << "Name"
		<< setw(30) << "MaxGeschwindigkeit(km/h)"
		<< setw(20) << "Gesamtstrecke(km)"
		<< setw(25) << "Geschwindigkeit(km/h)"
		<< setw(20) << "Tankinhalt(L)"
		<< endl;
	cout << setfill('-') << setw(110)<<"" << setfill(' ')<<endl;

}
void Fahrzeug::vSimulieren(){
	double dZeitraum = dGlobaleZeit - p_dZeit;
	p_dGesamtStrecke += dGeschwindigkeit() * dZeitraum;
	p_dGesamtZeit += dZeitraum;
	p_dZeit = dGlobaleZeit;
}

double Fahrzeug::dTanken(double dMenge){
	return 0;
}

void Fahrzeug::vAusgabe(ostream& os){
	os << setiosflags(ios::right)
		<< setw(6) << this->p_iID
		<< setw(10) << this->p_sName
		<< setw(20) << this->p_dMaxGeschwindigkeit
		<< setw(20) << this->p_dGesamtStrecke
		<< setw(25) << this->dGeschwindigkeit();
}

ostream& operator<<(ostream& os, Fahrzeug& fahrzeug){
	fahrzeug.vAusgabe(os);
//	os << "overload" << endl;
	return os;
}

bool Fahrzeug::operator<(const Fahrzeug& fahrzeug){
	return (p_dGesamtStrecke < fahrzeug.p_dGesamtStrecke);
}
Fahrzeug& Fahrzeug::operator =(const Fahrzeug &fahrzeug){
	p_sName = fahrzeug.p_sName;
	p_dGesamtStrecke = fahrzeug.p_dGesamtStrecke;
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
	p_dGesamtZeit = fahrzeug.p_dGesamtZeit;
	p_dZeit = fahrzeug.p_dZeit;
	return *this;
}


void Fahrzeug::test(){
	double x = dGlobaleZeit;

}