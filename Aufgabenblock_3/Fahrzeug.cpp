#include "Fahrzeug.h"
#include "Fahren.h"
#include "Parken.h"

//
Fahrzeug::Fahrzeug(){
		
	}

	//Instalisierungsliste
Fahrzeug::Fahrzeug(string name) :
	Simulationsobject(name)
	{
		cout << "erzeugtes Fahrzeug: " << p_sName << " " << p_iID << endl;
	}
Fahrzeug::~Fahrzeug(){
		cout << "geloeschtes Fahrzeug: " << p_sName << " " << p_iID << endl;
	}
Fahrzeug::Fahrzeug(string name, double maxGeschwindigkeit):
		Simulationsobject(name),
		p_dMaxGeschwindigkeit(maxGeschwindigkeit>0? maxGeschwindigkeit:0)
	{
		cout << "erzeugtes Fahrzeug: " << p_sName << " maxGeschwindigkeit=" << p_dMaxGeschwindigkeit << endl;
	}
void Fahrzeug::vAusgeben(){
	Simulationsobject::vAusgeben();
	cout << setw(20) << p_dMaxGeschwindigkeit
		<< setw(20) << p_dAbschnittStrecke
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
		<< setw(20) << "AbschnittStrecke(km)"
		<< setw(20) << "Gesamtstrecke(km)"
		<< setw(25) << "Geschwindigkeit(km/h)"
		<< setw(20) << "Tankinhalt(L)"
		<< endl;
	cout << setfill('-') << setw(130)<<"" << setfill(' ')<<endl;

}
//void Fahrzeug::vSimulieren(){
//	double dZeitraum = dGlobaleZeit - p_dZeit;
//	p_dGesamtStrecke += dGeschwindigkeit() * dZeitraum;
//	p_dAbschnittStrecke += dGeschwindigkeit() * dZeitraum;
//	p_dGesamtZeit += dZeitraum;
//	p_dZeit = dGlobaleZeit;
//
//}

void Fahrzeug::vSimulieren(){
	double dZeitraum = fabs(dGlobaleZeit - p_dZeit);

	//if (typeid(*p_pVerhalten)==typeid(Parken)){
	//	return;
	//}

	double dGeradeGefahreneStrecke = p_pVerhalten->dStrecke(*this, dZeitraum);
	p_dGesamtStrecke += dGeradeGefahreneStrecke;   //dGeschwindigkeit() * (dGlobaleZeit - p_dZeit);
	p_dAbschnittStrecke += dGeradeGefahreneStrecke;
	p_dGesamtZeit += dZeitraum;
	p_dZeit = dGlobaleZeit;

}

double Fahrzeug::dTanken(double dMenge){
	return 0;
}

void Fahrzeug::vNeueStrecke(Weg& weg){
	if (p_pVerhalten)
	{
		delete p_pVerhalten;
	}
	p_pVerhalten=new Fahren(weg);
}
void Fahrzeug::vNeueStrecke(Weg& weg, double dStartzeitpunkt){
	if (p_pVerhalten)
	{
		delete p_pVerhalten;
	}
	p_pVerhalten = new Parken(weg, dStartzeitpunkt);
}
double Fahrzeug::getAbschnittStrecke(){
	return p_dAbschnittStrecke;
}


ostream& Fahrzeug::vAusgeben(ostream& os){
	Simulationsobject::vAusgeben(os) << setw(20) << this->p_dMaxGeschwindigkeit
		<< setw(20) << this->p_dGesamtStrecke
		<< setw(25) << this->dGeschwindigkeit();
	return os;
}

ostream& operator<<(ostream& os, Fahrzeug& fahrzeug){
	fahrzeug.vAusgeben(os);
//	os << "overload" << endl;
	return os;
}

bool Fahrzeug::operator<(const Fahrzeug& fahrzeug){
	return (p_dGesamtStrecke < fahrzeug.p_dGesamtStrecke);
}
Fahrzeug& Fahrzeug::operator =(const Fahrzeug &fahrzeug){
	p_sName = fahrzeug.p_sName;
	p_dGesamtStrecke = fahrzeug.p_dGesamtStrecke;
	p_dAbschnittStrecke = fahrzeug.p_dAbschnittStrecke;
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
	p_dGesamtZeit = fahrzeug.p_dGesamtZeit;
	p_dZeit = fahrzeug.p_dZeit;
	return *this;
}


void Fahrzeug::test(){
	double x = dGlobaleZeit;

}