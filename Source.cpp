#include "duomenys.h"
#include "Studentai.h"
int main()
{
	string vardas = "";
	string pavarde = "";
	string q;
	int egzp;
	int ilgis = 0;
	float galbal;
	float med;


	auto start = high_resolution_clock::now();
	duomenys D;

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
				D.dadek_ilgis(ilgis);
			}





			auto startt = high_resolution_clock::now();
			while (!klasiokai.eof())
			{
				klasiokai >> vardas >> pavarde;
				D.dadek_vardas(vardas);
				D.dadek_pavarde(pavarde);
				int xxx;
				for (int i = 1; i <= D.ilgiss(); i++)
				{
					klasiokai >> xxx;
					D.dadek_ndp(xxx);

				}
				klasiokai >> egzp;
				D.dadek_egzp(egzp);
				D.prarusiuok();
				D.suskaiciuok_galbal();
				if (D.lyginis())
				{
					med = (double)D.prasau_ndp(D.prasau_ndp_size() / 2);
				}
				else
				{
					med = (double)(D.prasau_ndp((D.prasau_ndp_size() - 1) / 2) + D.prasau_ndp(D.prasau_ndp_size() / 2)) / 2.0;
				}
				D.dadek_med(med);
				D.trynk_ndp();
				if (D.galball() < 5)
				{
					Studentai(vardas, pavarde, galbal, med);
					D.dadek_gaidziu(D);
				}
				else
				{
					mldc << setfill(' ') << setw(17) << D.vardass() << setw(20) << D.pavardee() << setw(14) << setprecision(2) << fixed << D.galball() << setw(31) << setprecision(2) << fixed << D.medd() << endl;
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
