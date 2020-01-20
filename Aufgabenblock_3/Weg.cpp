#include "Weg.h"
#include "Fahrausnahme.h"
#include "SimuClient.h"

Weg::Weg()
{
}

Weg::Weg(string name, double laenge, Tempolimit Geschwindigkeitslimit ,bool bUeberholverbot) :
	Simulationsobject(name),
	p_dLanenge(laenge),
	p_eTempolimit(Geschwindigkeitslimit),
	p_bUeberholverbot(bUeberholverbot)
{}

double Weg::getTempolimit()
{
	return p_eTempolimit;
}

void Weg::vSimulieren()
{
	p_pFahrzeuge.vAktualisieren();
	vIterator tmp;
	for (vIterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); )
	{
		try
		{
			(*it)->vSimulieren();
			(*it)->vZeichnen(*this);
			it++;
		}
		catch (Fahrausnahme *pFahrausnahme)
		{
			it++;
			pFahrausnahme->vBearbeiten();
//			p_pFahrzeuge.vAktualisieren();
		}
	}
	p_pFahrzeuge.vAktualisieren();
}

void Weg::vAnnahme(unique_ptr<Fahrzeug> pFahrzeug){
	pFahrzeug->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(move(pFahrzeug));
	p_pFahrzeuge.vAktualisieren();
}
void Weg::vAnnahme(unique_ptr<Fahrzeug> pFahrzeug, double dStartzeitpunkt){
	pFahrzeug->vNeueStrecke(*this, dStartzeitpunkt);
	p_pFahrzeuge.push_front(move(pFahrzeug));
}
unique_ptr<Fahrzeug> Weg::pAbgabe(Fahrzeug& pFahrzeug){
	for (vIterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		if ((*it).get() == &pFahrzeug)
		{
			unique_ptr<Fahrzeug> tmp = move(*it);
			p_pFahrzeuge.erase(it);
			return tmp;
		}
	}
//	return nullptr;
}

void Weg::vKopf()
{
	cout << setiosflags(ios::left)
		<< setw(5) << "ID"
		<< setiosflags(ios::right)
		<< setw(10) << "Name"
		<< setw(30) << "Laenge"
		<< setw(20) << "Fahrzeuge"
		<< endl;
	cout << setfill('-') << setw(80) << "" << setfill(' ') << endl;
}

void Weg::vAusgeben()
{
	p_pFahrzeuge.vAktualisieren();
	Simulationsobject::vAusgeben();
	cout << setw(30) << p_dLanenge<<"  (";
	for (vIterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		cout << (*it)->getName()<<' ';
	}
	cout << ')' << endl;
}

ostream& Weg::vAusgeben(ostream& os){
	p_pFahrzeuge.vAktualisieren();
	Simulationsobject::vAusgeben(os) << setw(30) << p_dLanenge << "  (";
	for (vIterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		os << (*it)->getName() << ' ';
	}
	os << ')' << endl;
	return os;
}

void Weg::vFahrzeuglistAusgeben(){
	p_pFahrzeuge.vAktualisieren();
	Fahrzeug::vKopf();
	for (vIterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		(*it)->vAusgeben();
		cout << endl;
	}
}
//
//void Weg::vGraphAusgeben(){
//	for (auto &fahrzeug : p_pFahrzeuge)
//	{
//		if (typeid(fahrzeug)==typeid(PKW)){
//			bZeichnePKW()
//		}
//	}
//}

ostream& operator<<(ostream& os, Weg& weg)
{
	weg.vAusgeben(os);
	return os;
}


Weg::~Weg()
{
}
