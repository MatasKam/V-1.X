#include "duomenys.h"
#include "Studentai.h"
int main()
{
	duomenys D;
	string vardas = "";
	string pavarde = "";
	string q;
	int egzp;
	int ilgis = 0;
	float galbal;
	float med;
	vector<int>ndp;
	vector<Studentai>gaidz;
	auto start = high_resolution_clock::now();
	
	ifstream klasiokai;
	klasiokai.open("studentai10.txt");
	ofstream mldc;
	mldc.open("kieti.txt");

	mldc << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(33) << "Galutinis balas (Vid.)" << setw(25) << "Galutinis (Med.)" << endl;
	mldc << setfill('-') << setw(90) << "-" << endl;

		if (klasiokai.is_open())
		{
			klasiokai >> vardas >> pavarde;
			while (q != "Egz.") // perskaito visus namu darbus kiek ju yra
			{
				klasiokai >> q;
				if (q == "Egz.") {//teko iterpt nes nezinia del ko while nesibaidavo
					break;
				}
				ilgis ++;
			}
			




			auto startt = high_resolution_clock::now();
			while (!klasiokai.eof())
			{
				klasiokai >> vardas >> pavarde;
				int xxx;
				for (int i = 1; i <= ilgis; i++)
				{
					klasiokai >> xxx;
					ndp.push_back(xxx);

				}
				klasiokai >> egzp;
				D.prarusiuok();
				galbal = (double)accumulate(ndp.begin(), ndp.end(), 0) / ndp.size() * 0.4 + egzp * 0.6;
				if (D.lyginis())
				{
					med = (double)ndp.size() / 2;
				}
				else
				{
					med = (double)(((ndp.size() - 1) / 2) + (ndp.size() / 2)) / 2.0;
				}
				D.dadek_med(med);
				ndp.clear();
				if (D.galball() < 5)
				{
					Studentai(vardas, pavarde, galbal, med);
					D.dadek_gaidziu(D);
				}
				else
				{
					mldc << setfill(' ') << setw(17) << vardas << setw(20) << pavarde << setw(14) << setprecision(2) << fixed << galbal << setw(31) << setprecision(2) << fixed << med << endl;
				}
			}

			duration<double> di = high_resolution_clock::now() - startt;
			cout << "skirstymas i viena grupe ir irasymas vienos grupe truko: " << di.count() << " " << endl;
			rasom(D.prasau_gaidziu());
			D.trynk_gaidziu();
			
		}
		
	mldc.close();
	klasiokai.close();

	duration<double> diff = high_resolution_clock::now() - start;
	cout << "viso failo skaitymas truko: " << diff.count() << endl;



	return 0;
}
