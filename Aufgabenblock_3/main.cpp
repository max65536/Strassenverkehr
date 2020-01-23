#include<iostream>
#include<memory>
#include<vector>
#include<iomanip>
#include"Fahrzeug.h"
#include"PKW.h"
#include"Fahrrad.h"
#include"Weg.h"
#include "SimuClient.h"
#include "vertagt_liste.h"
#include <random>

using namespace std;

double dGlobaleZeit;

void vAufgabe_1(){
//	Fahrzeug f1;
//	Fahrzeug f2("black2");
//	Fahrzeug* f3 = new Fahrzeug("red3");
//	Fahrzeug* f4 = new Fahrzeug();
//
//	unique_ptr<Fahrzeug> f5 = make_unique<Fahrzeug>("white5");
//	unique_ptr<Fahrzeug> f6 = make_unique<Fahrzeug>("VW6");
//
//	shared_ptr<Fahrzeug>f7 = make_shared<Fahrzeug>("blue7");
//	shared_ptr<Fahrzeug>f8 = make_shared<Fahrzeug>("BMW8");
//	shared_ptr<Fahrzeug>f7s = f7;
//
//	cout << "f7.use_count() = " << f7.use_count() << endl;
//
////	unique_ptr<Fahrzeug> f5s = move(f5);
//
//	vector<unique_ptr<Fahrzeug>> v1;
//	
////	v1= { move(f5), move(f6) };
//	v1.push_back(move(f5));
//	v1.push_back(move(f6));
//	v1.clear();//delete f5,f6
//
//	vector<shared_ptr<Fahrzeug>> v2;
//	v2.push_back(f7);
//	v2.push_back(move(f8));
//	v2.clear();//delete f8
//
//	delete f3;
//	delete f4;
}//delete remained cars.

void vAufgabe_1a(){
	vector<unique_ptr<Fahrzeug>> Fahrzeugliste;
	string name;
	double maxgeschwindigkeit;
	for (int i = 0; i < 3; i++){
		cout << "Geben Sie einen Fahrzeugsname und die Maximalgeschwindigkeit:";
		cin >> name >> maxgeschwindigkeit;
		unique_ptr<Fahrzeug> fz = make_unique<Fahrzeug>(name,maxgeschwindigkeit);
		Fahrzeugliste.push_back(move(fz));
	}
	double dZeitschritt = 1;
	for (int i=0; i < 3; i++)
	{
		dGlobaleZeit += dZeitschritt;
		cout << "GlobaleZeit=" << dGlobaleZeit << endl;
		Fahrzeug::vKopf();
		for (int j = 0; j < 3; j++){
			Fahrzeugliste[j]->vSimulieren();
			Fahrzeugliste[j]->vAusgeben();
			cout << endl;
		}
		cout << endl;
	}
}
void vAufgabe_2(){
	vector<unique_ptr<Fahrzeug>> Fahrzeugliste;
	int PKWanzahl, Fahrradanzahl;
	string name;
	double maxgeschwindigkeit, verbrauch, tankvolume;
	int i;

	//cout << "PKWanzahl:";
	//cin >> PKWanzahl;

	//for (i = 0; i < PKWanzahl; i++){
	//	cout << "Geben Sie Fahrzeugsnamen, Maximalgeschwindigkeiten, Verbrauch und Tankvolumen:";
	//	cin >> name >> maxgeschwindigkeit >> verbrauch >> tankvolume;
	//	unique_ptr<Fahrzeug> fz = make_unique<PKW>(name, maxgeschwindigkeit, tankvolume);
	//	Fahrzeugliste.push_back(move(fz));
	//}
	//cout << "Fahrradanzahl:";
	//cin >> Fahrradanzahl;

	unique_ptr<Fahrzeug> fz = make_unique<PKW>("bmw", 600, 13,300);
	Fahrzeugliste.push_back(move(fz));
	fz = make_unique<PKW>("vw", 500, 20);
	Fahrzeugliste.push_back(move(fz));

	fz = make_unique<Fahrrad>("Rider", 100);
	Fahrzeugliste.push_back(move(fz));
	fz = make_unique<Fahrrad>("Light", 200);
	Fahrzeugliste.push_back(move(fz));

	int fSize = Fahrzeugliste.size();

	double dGesamtzeit=6.0;
	double dTankzeit = 4.0;
	for (dGlobaleZeit=0; dGlobaleZeit <= dGesamtzeit; dGlobaleZeit += 1){
		cout << "dGlobaleZeit=" << dGlobaleZeit<<endl;
		Fahrzeug::vKopf();
		for (i = 0; i < fSize; i++){

			Fahrzeugliste[i]->vSimulieren();
			Fahrzeugliste[i]->vAusgeben();
			cout << endl;
			if (dGlobaleZeit == dTankzeit && Fahrzeugliste[i]->check_type() == 1){
				Fahrzeugliste[i]->dTanken(-1);
			}
		}
		cout << endl;
	}
}

void vAufgabe_3()
{
	cout << "Aufgabenblock 1, Aufgabe 3: " << endl;

	Fahrzeug* aPKW=new PKW("PKW", 300, 10, 200.0);
	Fahrzeug* aFahrrad=new Fahrrad("Fahrrad", 50);

	dGlobaleZeit = 2;
	aPKW->vSimulieren();
	aFahrrad->vSimulieren();



	Fahrzeug::vKopf();
	cout << *aPKW << endl;
	cout << *aFahrrad << endl; 
	cout << endl;

	if (aPKW < aFahrrad){
		cout << "aFahrrad ist weiter" << endl;
	}else{
		cout << "PKW ist weiter" << endl;
	}

	Fahrrad f1("Rider", 100);

	Fahrzeug::vKopf();
	Fahrzeug newbike;
	newbike = f1;

	cout << f1 << endl;
	cout << newbike << endl;
	cout << endl;
}

void vAufgabe_4()
{
	cout << "Aufgabe 4: " << endl;
	unique_ptr<Weg> weg1 = make_unique<Weg>("Weg1", 200);
	unique_ptr<Fahrzeug> f1 = make_unique<PKW>("F1", 200, 7, 70);
	unique_ptr<Fahrzeug> f2 = make_unique<PKW>("F2", 300, 5, 60);
	unique_ptr<Fahrzeug> f3 = make_unique<PKW>("F3", 250, 7, 80);
}

void vAufgabe_5()
{
	cout << "Aufgabe 5: " << endl << endl;

	unique_ptr<Weg> weg1 = make_unique<Weg>("Weg1", 500);

	unique_ptr<Fahrzeug> f1 = make_unique<PKW>("F1", 200, 7, 70);
	unique_ptr<Fahrzeug> f2 = make_unique<PKW>("F2", 300, 5, 60);
	unique_ptr<Fahrzeug> f3 = make_unique<PKW>("F3", 250, 7, 80);
	weg1->vAnnahme(move(f1));
	weg1->vAnnahme(move(f2),1);
	weg1->vAnnahme(move(f3));

	Weg::vKopf();
	cout << *weg1 << endl;

	for (dGlobaleZeit = 0; dGlobaleZeit < 5; dGlobaleZeit += 0.3){
		cout << "GlobaleZeit:" << dGlobaleZeit << endl;
		weg1->vSimulieren();
		weg1->vFahrzeuglistAusgeben();
		cout << endl;
	}
}

void vAufgabe_6a()
{
	cout << "Aufgabe 6a: " << endl << endl;

	using namespace vertagt;
	VListe<int> vListe;
	typedef VListe<int>::iterator vListItInt;

	static std::mt19937 device(0);
	std::uniform_int_distribution<int> dist(1, 10);

	for (int i = 1; i <= 10; i++)
	{
		vListe.push_back(dist(device));
	}
	vListe.vAktualisieren();

	for (vListItInt it = vListe.begin(); it != vListe.end(); it++)
	{
		cout << (*it) << " ";
	}

	for (vListItInt it = vListe.begin(); it != vListe.end(); it++)
	{
		if ((*it) > 5)
		{
			vListe.erase(it);
		}
	}
	cout << endl;

	for (vListItInt it = vListe.begin(); it != vListe.end(); it++)
	{
		cout << (*it) <<" ";
	}
	cout << endl;

	vListe.vAktualisieren();

	for (vListItInt it = vListe.begin(); it != vListe.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;

	vListe.push_front(dist(device));
	vListe.push_back(dist(device));
	vListe.vAktualisieren();


	for (vListItInt it = vListe.begin(); it != vListe.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;

	//unique_ptr<Fahrzeug> f1 = make_unique<PKW>("asd",100);
	////unique_ptr<Fahrzeug> f1 = make_unique<int>(100);
	//vertagt::VListe<unique_ptr<Fahrzeug>> ppf;
	//ppf.begin();
	//ppf.push_back(move(f1));
}

void vAufgabe_6()
{
	cout << "Aufgabe 6: " << endl << endl;

	unique_ptr<Weg> weg1 = make_unique<Weg>("Weg1", 500, Weg::Autobahn);
	unique_ptr<Weg> weg2 = make_unique<Weg>("Weg2", 500, Weg::Innerorts);

	unique_ptr<Fahrzeug> f1 = make_unique<PKW>("F1", 90, 7, 10);
	unique_ptr<Fahrzeug> f2 = make_unique<PKW>("F2", 100, 5, 60);
	unique_ptr<Fahrzeug> f3 = make_unique<PKW>("F3", 200, 7, 100);
	unique_ptr<Fahrzeug> f4 = make_unique<Fahrrad>("Fahrrad1", 30);
	unique_ptr<Fahrzeug> f5 = make_unique<Fahrrad>("Fahrrad2", 20);

	weg1->vAnnahme(move(f1));
	weg1->vAnnahme(move(f2));
	weg1->vAnnahme(move(f3),0.9);
	//weg1->vAnnahme(move(f4));
	//weg1->vAnnahme(move(f5),2);



	unique_ptr<Fahrzeug> b1 = make_unique<PKW>("BMW1", 50, 3.6, 70);
	unique_ptr<Fahrzeug> b2 = make_unique<PKW>("BMW2", 300, 5, 60);
	unique_ptr<Fahrzeug> b3 = make_unique<Fahrrad>("Fahrrad3", 20);

	weg2->vAnnahme(move(b1));
	weg2->vAnnahme(move(b2),0.7);
	weg2->vAnnahme(move(b3));

	Weg::vKopf();
	cout << *weg1 << endl<<*weg2<< endl;

	bInitialisiereGrafik(800, 500); 
	int koordinaten[4] = { 700, 250, 100, 250 }; 
	string s2 = weg2->getName();
	const char* sWegname2 = s2.c_str();
	bZeichneStrasse(weg1->getName(), sWegname2, weg1->getLaenge(), 2, koordinaten);

	for (dGlobaleZeit =0; dGlobaleZeit < 3; dGlobaleZeit += 0.25){
		
		vSetzeZeit(dGlobaleZeit);

		cout << "GlobaleZeit:" << dGlobaleZeit << endl;
		weg1->setVirtuelleSchranke(10000000000);
		weg1->vSimulieren();
		cout << "weg1 VirtuelleSchranke:" << weg1->getVirtuelleSchranke() << endl;
		weg1->vFahrzeuglistAusgeben();

		weg2->setVirtuelleSchranke(10000000000);
		weg2->vSimulieren();
		cout << "weg2 VirtuelleSchranke:" << weg2->getVirtuelleSchranke() << endl;
		weg2->vFahrzeuglistAusgeben();
		cout << endl;
		
		vSleep(800);
	}
	vBeendeGrafik();
}

void test(){
	bInitialisiereGrafik(800, 500); 
	int koordinaten[4] = { 700, 250, 100, 250 }; 

	string s1 = "wegtest";
	const char* sWegname = s1.c_str();

	bZeichneStrasse("weg1", sWegname, 500, 2, koordinaten);

	for (dGlobaleZeit = 0; dGlobaleZeit < 5; dGlobaleZeit += 0.25){

		string s1 = "wegtest";
		const char* sWegname = s1.c_str();
		string s2 = "PKWtest";
		const char* fname = s2.c_str();
		double realPosition = dGlobaleZeit / 5;
		double dGeschwind = 100;
		double p_dTankinhalt = 100;
		bZeichnePKW(s2, sWegname, realPosition, dGeschwind, p_dTankinhalt);

		vSleep(800);
	}
	s1 = "weg4";
	sWegname = s1.c_str();
	int koordinaten2[4] = { 100, 100, 200, 250 };
	bZeichneStrasse("weg3", sWegname, 500, 2, koordinaten2);

	vBeendeGrafik();
}

int main(){
//	dGlobaleZeit = 0;
	cout << "Hello" << endl;
//	vAufgabe_1();
//	test();
//	vAufgabe_1a();
	//vAufgabe_2();
//	vAufgabe_3();
//	vAufgabe_4();
	//vAufgabe_5();
	vAufgabe_6();
	//vAufgabe_6a();
//	test();
	return 0;
}