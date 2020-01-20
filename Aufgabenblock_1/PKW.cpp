#include "PKW.h"



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
void PKW::vAusgabe(){
	Fahrzeug::vAusgabe();
	char buf[20];
	sprintf_s(buf, "%.2f/%.2f", p_dTankinhalt,p_dTankvolumen);
	cout << setw(20) << buf;
}
void PKW::vAusgabe(ostream& os){
	Fahrzeug::vAusgabe(os);
	char buf[20];
	sprintf_s(buf, "%.2f/%.2f", p_dTankinhalt, p_dTankvolumen);
	os << setw(20) << buf;
}


PKW::~PKW()
{
	cout << "geloeschter PKW: " << p_sName << " " << p_iID << " " << p_dVerbrauch << " " << p_dTankvolumen << endl;
}
