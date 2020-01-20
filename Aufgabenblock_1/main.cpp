#include<iostream>
#include<memory>
#include<vector>
#include<iomanip>
#include"Fahrzeug.h"
#include"PKW.h"
#include"Fahrrad.h"

#include"Testclass.h"

using namespace std;

double dGlobaleZeit;

void vAufgabe_1(){
	Fahrzeug f1;
	Fahrzeug f2("black2");
	Fahrzeug* f3 = new Fahrzeug("red3");
	Fahrzeug* f4 = new Fahrzeug();

	unique_ptr<Fahrzeug> f5 = make_unique<Fahrzeug>("white5");
	unique_ptr<Fahrzeug> f6 = make_unique<Fahrzeug>("VW6");

	shared_ptr<Fahrzeug>f7 = make_shared<Fahrzeug>("blue7");
	shared_ptr<Fahrzeug>f8 = make_shared<Fahrzeug>("BMW8");
	shared_ptr<Fahrzeug>f7s = f7;

	cout << "f7.use_count() = " << f7.use_count() << endl;

//	unique_ptr<Fahrzeug> f5s = move(f5);

	vector<unique_ptr<Fahrzeug>> v1;
	
//	v1= { move(f5), move(f6) };
	v1.push_back(move(f5));
	v1.push_back(move(f6));
	v1.clear();//delete f5,f6

	vector<shared_ptr<Fahrzeug>> v2;
	v2.push_back(f7);
	v2.push_back(move(f8));
	v2.clear();//delete f8

	delete f3;
	delete f4;
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
			Fahrzeugliste[j]->vAusgabe();
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
			Fahrzeugliste[i]->vAusgabe();
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

void test(){
	//std::cout << std::hex << std::setiosflags(std::ios::showbase);
	//std::cout << 100 << std::endl;
	//std::cout << 100 << std::endl;
	//std::cout << std::resetiosflags(std::ios::showbase) << 100 << std::endl;
	//Fahrzeug ftest("testCar", 300);
	//Fahrzeug::vKopf();
	//ftest.vAusgabe();
	//char b[20];
	//cout << endl;
	//sprintf_s(b, "abc%.2f connect",1.2);
	//cout << b <<endl;
	cout << (int)2.6 << endl;
}

int main(){
//	dGlobaleZeit = 0;
	cout << "Hello" << endl;
	vAufgabe_1();
//	test();
	vAufgabe_1a();
	vAufgabe_2();
	vAufgabe_3();
	return 0;
}