#include "Simulation.h"
#include "Simulationsobject.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Kreuzung.h"
#include <sstream>
#include "SimuClient.h"

extern double dGlobaleZeit;

Simulation::Simulation()
{

}

shared_ptr<Kreuzung> Simulation::getKreuzung(string sName) 
{
	if (kreuzungmap.find(sName) == kreuzungmap.end())
	{
		throw runtime_error("ERROR: Kreuzung " +sName+ " not found. line "+to_string(iZeile));
	}
	return kreuzungmap[sName]; 
}
//fertigt alle ihr bekannten Kreuzungen ab und stellt somit einen Simulationsschritt dar.
void Simulation::vSimulieren()
{
	list<shared_ptr<Kreuzung>>::iterator it;
	for (it = kreuzunglist.begin(); it != kreuzunglist.end(); it++)
	{
		(*it)->vSimulieren();
	}
}

void Simulation::vSimulieren(double dDauer, double dZeitschritt) 
{	
	for (dGlobaleZeit = dZeitschritt; dGlobaleZeit < dDauer;dGlobaleZeit += dZeitschritt) 
	{
		if (fabs(dGlobaleZeit - 6.6) < 0.01) 
		{
			cout << "wait..." << endl;
		}
		vSetzeZeit(dGlobaleZeit);
		vSimulieren();
		vSleep(10);
	}
	vBeendeGrafik();
}

void Simulation::vEinlesen(istream& is, bool bMitGrafik) 
{
	int Koordinaten[100]; 
	if (bMitGrafik) 
	{
		bInitialisiereGrafik(1000,1000);
		iZeile = 0;
		while (!is.eof())
		{
			string info;
			iZeile++;
			is >> info;

			try
			{
				if (info == "KREUZUNG")
				{
					int X, Y;
					shared_ptr<Kreuzung> pkr = make_shared<Kreuzung>();
					is >> *pkr >> X >> Y;
					string sName = pkr->getName();
					if (kreuzungmap.find(sName) == kreuzungmap.end())
					{
						kreuzunglist.push_back(pkr);
						kreuzungmap[sName] = pkr;
						cout << *pkr << endl;

						bZeichneKreuzung(X,Y);
					}
					else
					{
						throw runtime_error("ERROR: Kreuzung " + sName + " ist schon abgelegt. Line " + to_string(iZeile));
					}

				}
				else if (info == "PKW")
				{
					unique_ptr<PKW> ppkw = make_unique<PKW>();
					string sKreuzung;
					double dStartzeitpunkt;
					is >> *ppkw >> sKreuzung >> dStartzeitpunkt;
					try
					{
						if (getKreuzung(sKreuzung)->getWege().empty())
						{
							throw runtime_error("ERROR: Keine Wege von Kreuzung " + sKreuzung + " . Line " + to_string(iZeile));
						}
						getKreuzung(sKreuzung)->vAnnahme(move(ppkw), dStartzeitpunkt);
					}
					catch (exception & error)
					{
						cout << error.what() << endl;
						//throw;
					}
				}
				else if (info == "FAHRRAD")
				{
					unique_ptr<Fahrrad> pfahrrad = make_unique<Fahrrad>();
					string sKreuzung;
					double dStartzeitpunkt;
					is >> *pfahrrad >> sKreuzung >> dStartzeitpunkt;
					try
					{
						getKreuzung(sKreuzung)->vAnnahme(move(pfahrrad), dStartzeitpunkt);
					}
					catch (exception & error)
					{
						cout << error.what() << endl;
						//throw;
					}
				}
				else if (info == "STRASSE")
				{
					string NameQ;
					string NameZ;
					string NameW1;			//Name des Weges von der Quell- zur Zielkreuzung
					string NameW2;
					int iTempolimit;
					int  iUeberholverbot;
					Weg::Tempolimit tempolimit;
					double dLaenge;

					int numXY;
					is >> NameQ >> NameZ >> NameW1 >> NameW2 >> dLaenge >> iTempolimit >> iUeberholverbot >> numXY;
					
					
					for (int i = 0; i < numXY*2;i++) 
					{
						is >> Koordinaten[i];
					}
					bZeichneStrasse(NameW1,NameW2,dLaenge,numXY,Koordinaten);
					bool bUeberholverbot;
					try
					{
						switch (iUeberholverbot)
						{
						case 0:
							bUeberholverbot = false;
							break;
						case 1:
							bUeberholverbot = true;
							break;
						default:
							bUeberholverbot = true;
							throw runtime_error("ERROR: invalid Uberholverbot. Line " + to_string(iZeile));
							break;
						}
					}
					catch (exception & error)
					{
						cout << error.what() << endl;
					}

					try
					{
						switch (iTempolimit)
						{
						case 1:
							tempolimit = Weg::Tempolimit::Innerorts;
							break;
						case 2:
							tempolimit = Weg::Tempolimit::Landstrasse;
							break;
						case 3:
							tempolimit = Weg::Tempolimit::Autobahn;
							break;
						default:
							tempolimit = Weg::Tempolimit::Autobahn;
							throw runtime_error("ERROR: invalid Tempolimit. Line " + to_string(iZeile));
							break;
						}
					}
					catch (exception & error)
					{
						cout << error.what() << endl;
					}

					try
					{
						getKreuzung(NameQ)->vVerbinde(NameW1, NameW2, dLaenge, getKreuzung(NameQ), getKreuzung(NameZ), tempolimit, bUeberholverbot);
					}
					catch (exception & error)
					{
						cout << error.what() << endl;
					}

				}
				else
				{
					throw runtime_error("ERROR: " + info + " undefiniert. Line " + to_string(iZeile));
				}
			}
			catch (exception & error)
			{
				cout << error.what() << endl;
				//throw;
			}
		}
	}
	else 
	{
		vEinlesen_default(is);
	}

}

void Simulation::vEinlesen_default(istream& is)
{
	iZeile = 0;
	while (!is.eof())
	{
		string info;
		iZeile++;
		is >> info;

		try
		{
			if (info == "KREUZUNG")
			{
				shared_ptr<Kreuzung> pkr = make_shared<Kreuzung>();
				is >> *pkr;
				string sName = pkr->getName();
				if (kreuzungmap.find(sName) == kreuzungmap.end())
				{
					kreuzunglist.push_back(pkr);
					kreuzungmap[sName] = pkr;
					cout << *pkr << endl;
				}
				else
				{
					throw runtime_error("ERROR: Kreuzung " + sName + " ist schon abgelegt. Line " + to_string(iZeile));
				}

			}
			else if (info == "PKW")
			{
				unique_ptr<PKW> ppkw = make_unique<PKW>();
				string sKreuzung;
				double dStartzeitpunkt;
				is >> *ppkw >> sKreuzung >> dStartzeitpunkt;
				try
				{
					if (getKreuzung(sKreuzung)->getWege().empty())
					{
						throw runtime_error("ERROR: Keine Wege von Kreuzung " + sKreuzung + " . Line " + to_string(iZeile));
					}
					getKreuzung(sKreuzung)->vAnnahme(move(ppkw), dStartzeitpunkt);
				}
				catch (exception & error)
				{
					cout << error.what() << endl;
					//throw;
				}
			}
			else if (info == "FAHRRAD")
			{
				unique_ptr<Fahrrad> pfahrrad = make_unique<Fahrrad>();
				string sKreuzung;
				double dStartzeitpunkt;
				is >> *pfahrrad >> sKreuzung >> dStartzeitpunkt;
				try
				{
					getKreuzung(sKreuzung)->vAnnahme(move(pfahrrad), dStartzeitpunkt);
				}
				catch (exception & error)
				{
					cout << error.what() << endl;
					//throw;
				}
			}
			else if (info == "STRASSE")
			{
				string NameQ;
				string NameZ;
				string NameW1;			//Name des Weges von der Quell- zur Zielkreuzung
				string NameW2;
				int iTempolimit;
				int  iUeberholverbot;
				Weg::Tempolimit tempolimit;
				double dLaenge;
				is >> NameQ >> NameZ >> NameW1 >> NameW2 >> dLaenge >> iTempolimit >> iUeberholverbot;
				bool bUeberholverbot;
				try
				{
					switch (iUeberholverbot)
					{
					case 0:
						bUeberholverbot = false;
						break;
					case 1:
						bUeberholverbot = true;
						break;
					default:
						bUeberholverbot = true;
						throw runtime_error("ERROR: invalid Uberholverbot. Line " + to_string(iZeile));
						break;
					}
				}
				catch (exception & error)
				{
					cout << error.what() << endl;
				}

				try
				{
					switch (iTempolimit)
					{
					case 1:
						tempolimit = Weg::Tempolimit::Innerorts;
						break;
					case 2:
						tempolimit = Weg::Tempolimit::Landstrasse;
						break;
					case 3:
						tempolimit = Weg::Tempolimit::Autobahn;
						break;
					default:
						tempolimit = Weg::Tempolimit::Autobahn;
						throw runtime_error("ERROR: invalid Tempolimit. Line " + to_string(iZeile));
						break;
					}
				}
				catch (exception & error)
				{
					cout << error.what() << endl;
				}

				try
				{
					getKreuzung(NameQ)->vVerbinde(NameW1, NameW2, dLaenge, getKreuzung(NameQ), getKreuzung(NameZ), tempolimit, bUeberholverbot);
				}
				catch (exception & error)
				{
					cout << error.what() << endl;
				}

			}
			else
			{
				throw runtime_error("ERROR: " + info + " undefiniert. Line " + to_string(iZeile));
			}
		}
		catch (exception & error)
		{
			cout << error.what() << endl;
			//throw;
		}
	}
}



Simulation::~Simulation()
{
}
