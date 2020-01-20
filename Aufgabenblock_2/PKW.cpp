#include "PKW.h"
#include "Weg.h"
#include "Verhalten.h"
#include "SimuClient.h"


PKW::PKW()
{
	cout << "neuer PKW: " << p_sName << " " << p_iID << " " << p_dVerbrauch << "/" << p_dTankvolumen << endl;
}
PKW::PKW(string sName):
Fahrzeug(sName)
{
	cout << "neuer PKW: " << p_sName << " " << p_iID << " " << p_dVerbrauch << "/" << p_dTankvolumen << endl;
}
PKW::PKW(string sName, double dMaxGeschwindigkeit) :
Fahrzeug(sName, dMaxGeschwindigkeit)
{
	cout << "neuer PKW: " << p_sName << " " << p_iID << " " << p_dVerbrauch << "/" << p_dTankvolumen << endl;
}
PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen) :
Fahrzeug(sName, dMaxGeschwindigkeit),
	p_dVerbrauch(dVerbrauch),
	p_dTankvolumen(dTankvolumen),
	p_dTankinhalt(dTankvolumen / 2)
{
	cout << "neuer PKW: " << p_sName << " " << p_iID << " " << p_dVerbrauch << " " << p_dTankvolumen << endl;
}
double PKW::dTanken(double dMenge){
	if (dMenge <= 0 || dMenge>(p_dTankvolumen - p_dTankinhalt)){
		dMenge = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
		return dMenge;
	}
	p_dTankinhalt += dMenge;
	return dMenge;
}

double PKW::dGeschwindigkeit()const{
	if (!p_pVerhalten){
		return 0;
	}

	double dTempoLimit = p_pVerhalten->getWeg()->getTempolimit();
	if (dTempoLimit < p_dMaxGeschwindigkeit) return dTempoLimit; else return p_dMaxGeschwindigkeit;
}

void PKW::vSimulieren(){
	if (p_dTankinhalt <= 0){
		p_dZeit = dGlobaleZeit;
		return;
	}
	double tmp = p_dGesamtStrecke;
	Fahrzeug::vSimulieren();
	
	p_dTankinhalt -= p_dVerbrauch / 100 * (p_dGesamtStrecke - tmp);
	if (p_dTankinhalt < 0) p_dTankinhalt = 0;
	
}
void PKW::vAusgeben(){
	Fahrzeug::vAusgeben();
	char buf[20];
	sprintf_s(buf, "%.2f/%.2f", p_dTankinhalt,p_dTankvolumen);
	cout << setw(20) << buf;
}
ostream& PKW::vAusgeben(ostream& os){
	Fahrzeug::vAusgeben(os);
	char buf[20];
	sprintf_s(buf, "%.2f/%.2f", p_dTankinhalt, p_dTankvolumen);
	os << setw(20) << buf;
	return os;
}

void PKW::vZeichnen(const Weg &weg)const{
	double dGeschwind = dGeschwindigkeit();
	double dLaenge = weg.getLaenge();
	double realPosition = p_dAbschnittStrecke / dLaenge;
	string tmp = weg.getName();
	const char *sWegname = tmp.c_str();
	bZeichnePKW(p_sName, sWegname, realPosition, dGeschwind, p_dTankinhalt);
}

PKW::~PKW()
{
	cout << "geloeschter PKW: " << p_sName << " " << p_iID << " " << p_dVerbrauch << " " << p_dTankvolumen << endl;
}
