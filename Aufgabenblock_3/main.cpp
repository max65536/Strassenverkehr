﻿#include<iostream>
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
#include "Kreuzung.h"
#include <fstream>
#include "Simulationsobject.h"
#include <string>
#include "Simulation.h"

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

	bInitialisiereGrafik(1000, 500); 
	int koordinaten[4] = { 700, 300, 100, 300 }; 
	string s2 = weg2->getName();
	const char* sWegname2 = s2.c_str();
	bZeichneStrasse(weg1->getName(), sWegname2, weg1->getLaenge(), 2, koordinaten);

	for (dGlobaleZeit =0; dGlobaleZeit < 3; dGlobaleZeit += 0.25){
		
		vSetzeZeit(dGlobaleZeit);

		cout << "GlobaleZeit:" << dGlobaleZeit << endl;
		//weg1->setVirtuelleSchranke(10000000000);
		weg1->vSimulieren();
		cout << "weg1 VirtuelleSchranke:" << weg1->getVirtuelleSchranke() << endl;
		weg1->vFahrzeuglistAusgeben();

		//weg2->setVirtuelleSchranke(10000000000);
		weg2->vSimulieren();
		cout << "weg2 VirtuelleSchranke:" << weg2->getVirtuelleSchranke() << endl;
		weg2->vFahrzeuglistAusgeben();
		cout << endl;
		
		vSleep(800);
	}
	vBeendeGrafik();
}

void vAufgabe_7(){
	cout << "Aufgabe 7: " << endl << endl;
	shared_ptr<Kreuzung> kr1 = make_shared<Kreuzung>("kr1", 10001);
	shared_ptr<Kreuzung> kr2 = make_shared<Kreuzung>("kr2", 10001);
	shared_ptr<Kreuzung> kr3 = make_shared<Kreuzung>("kr3");
	shared_ptr<Kreuzung> kr4 = make_shared<Kreuzung>("kr4");

	unique_ptr<Fahrzeug> f1 = make_unique<PKW>("F1", 45, 7, 800);
	unique_ptr<Fahrzeug> f2 = make_unique<PKW>("F2", 100, 5, 600);
	unique_ptr<Fahrzeug> f3 = make_unique<PKW>("F3", 200, 7, 600);
	unique_ptr<Fahrzeug> f4 = make_unique<Fahrrad>("Fahrrad1", 30);
	unique_ptr<Fahrzeug> f5 = make_unique<Fahrrad>("Fahrrad2", 20);

	bInitialisiereGrafik(1000, 1000);

	bZeichneKreuzung(680, 40);
	bZeichneKreuzung(680, 300);
	bZeichneKreuzung(680, 570);
	bZeichneKreuzung(320, 300);

	int strasse1[] = { 680, 40, 680, 300 };
	int strasse2[] = { 680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570 };
	int strasse3[] = { 680, 300, 680, 570 };
	int strasse4[] = { 680, 300, 320, 300 };
	int strasse5[] = { 680, 570, 500, 570, 350, 510, 320, 420, 320, 300 };
	int strasse6[] = { 320, 300, 170, 300, 70, 250, 80, 90, 200, 60, 320, 150, 320, 300 };

	bZeichneStrasse("W12", "W21", 40, 2, strasse1);
	bZeichneStrasse("W23a", "W32a", 115, 6, strasse2);
	bZeichneStrasse("W23b", "W32b", 40, 2, strasse3);
	bZeichneStrasse("W24", "W42", 55, 2, strasse4);
	bZeichneStrasse("W34", "W43", 85, 5, strasse5);
	bZeichneStrasse("W44a", "W44b", 130, 7, strasse6);

	kr1->vVerbinde("W12", "W21", 40, kr1, kr2, Weg::Tempolimit::Innerorts, true);
	kr2->vVerbinde("W23a", "W32a", 115, kr2, kr3, Weg::Tempolimit::Autobahn, false);
	kr2->vVerbinde("W23b", "W32b", 40, kr2, kr3, Weg::Tempolimit::Innerorts, true);
	kr2->vVerbinde("W24", "W42", 55, kr2, kr4, Weg::Tempolimit::Innerorts, true);
	kr3->vVerbinde("W34", "W43", 85, kr3, kr4, Weg::Tempolimit::Autobahn, false);
	kr4->vVerbinde("W44a", "W44b", 130, kr4, kr4, Weg::Tempolimit::Landstrasse, false);


	//int koordinaten[4] = { 700, 300, 100, 300 };
	//string s2 = weg2->getName();
	//const char* sWegname2 = s2.c_str();
	//bZeichneStrasse(weg1->getName(), sWegname2, weg1->getLaenge(), 2, koordinaten);
	Fahrzeug& sf1 = *f1;
	Fahrzeug& sf2 = *f2;
	Fahrzeug& sf3 = *f3;
	Fahrzeug& sf4 = *f4;

	
	kr2->vAnnahme(move(f2),1);
	kr1->vAnnahme(move(f3),0);
	kr1->vAnnahme(move(f4),0);
	kr1->vAnnahme(move(f1),0);

	for (dGlobaleZeit = 0; dGlobaleZeit <= 3; dGlobaleZeit += 0.25)
	{

		if (fabs(dGlobaleZeit- 1)<0.01)
		{
			cout << "wait..." << endl;
		}
		cout << "dZeit=" << dGlobaleZeit<< endl;
		vSetzeZeit(dGlobaleZeit);
		kr1->vSimulieren();
		//kr1->getWege().front()->vFahrzeuglistAusgeben();

		kr2->vSimulieren();
		//list<shared_ptr<Weg>> tmp=kr2->getWege();
		//list<shared_ptr<Weg>>::iterator it = tmp.begin();
		//it++;
		//(*it)->vFahrzeuglistAusgeben();

		kr3->vSimulieren();
		kr4->vSimulieren();

		Fahrzeug::vKopf();
		cout << sf1 << endl;
		cout << sf2 << endl;
		cout << sf3 << endl;
		cout << sf4 << endl;
		vSleep(200);
	}

	vBeendeGrafik();
}

void vAufgabe_8()
{
	cout << "Aufgabe 8: " << endl << endl;

	ifstream myfile("VO.dat");
	Fahrzeug f1;
	PKW p1;
	Fahrrad f2;
	Kreuzung kr1;
	Fahrzeug::vKopf();
	string data;
	myfile.exceptions(ios_base::eofbit | ios_base::failbit|ios_base::badbit);
	try
	{
		myfile >> p1;
		cout << p1 << endl;
		myfile >> f2;
		cout << f2 << endl;
		myfile >> kr1;
		cout << kr1 << endl;

	}
	catch (exception& error)
	{
		cout << error.what() << endl;
	}
}

void vAufgabe_9() 
{
	cout << "Aufgabe 9:" << endl;
	Simulation simu;
	ifstream myfile("SimuKopie.dat");
	try
	{
		simu.vEinlesen(myfile);
	}
	catch(exception& error)
	{
		cout << error.what() << endl;
	}

	simu.vSimulieren(3, 0.1);

}

void vAufgabe_9a()
{
	cout << "Aufgabe_9a:" << endl;
	Simulation simu;
	ifstream myfile("SimuDisplay.dat");
	try
	{
		simu.vEinlesen(myfile,true);
	}
	catch (exception & error)
	{
		cout << error.what() << endl;
	}
	simu.vSimulieren(10, 0.1);
}

void test(){
	//unique_ptr < Fahrzeug > f1 = make_unique<PKW>("F1", 100);
	//unique_ptr < Fahrzeug > f2 = move(f1);
	Kreuzung kr1("kr1", 100);
	Fahrzeug f1("s1");
	PKW p1("p1", 100, 10, 100);
	kr1.vTanken(p1);
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
	//vAufgabe_6();
	//vAufgabe_6a();
	//vAufgabe_7();
	//vAufgabe_8();
	//vAufgabe_9();
	vAufgabe_9a();
	//test();
	return 0;
}