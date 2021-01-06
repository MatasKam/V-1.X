#pragma once
#include "biblioteka.h"
#include "Dll.h"

class duomenys {
private:
	string vardas = "";
	string pavarde = "";
	int egzp;
	int ilgis;
	float galbal;
	float med;

	vector<int>ndp;
	vector < duomenys> gaidz;
	vector < duomenys> mldc;

//protected:
	
public:
	void dadek_vardas(const string var) { vardas = var; }
	void dadek_pavarde(const string pavar) { pavarde = pavar; }
	void dadek_egzp(const int egz) { egzp = egz; }
	void dadek_ilgis(const int il) { ilgis = il; cout << ilgis << endl; }
	void dadek_galbal(const float gal) { galbal = gal; }
	void dadek_med(const float me) { med = me; }
	string vardass() const { return vardas; }
	string pavardee() const { return pavarde; }
	int egzpp() const { return egzp; }
	int ilgiss() const { return ilgis; }
	float galball() const { return galbal; }
	float medd() const { return med; }

	vector < duomenys> prasau_gaidziu() { return gaidz; }
	void dadek_gaidziu(duomenys x) { gaidz.push_back(x); };
	void trynk_gaidziu() { gaidz.clear(); };

	int prasau_ndp(int s) { return ndp[s]; }
	int prasau_ndp_size() { return ndp.size(); }
	void dadek_ndp(int n) { ndp.push_back(n); };
	void trynk_ndp() { ndp.clear(); };

	void prarusiuok() { sort(ndp.begin(), ndp.end()); }
	void suskaiciuok_galbal() { galbal = (double)accumulate(ndp.begin(), ndp.end(), 0) / ndp.size() * 0.4 + egzp * 0.6; }
	bool lyginis() const { return ndp.size() % 2 != 0; }


};
class duomvald : public duomenys {
public:
	void dadek_vardas(const string var) {
		duomenys::dadek_vardas(var);
	}
	void dadek_pavarde(const string pavar) {
		duomenys::dadek_pavarde(pavar);
	}
	void dadek_egzp(const int egz) {
		duomenys::dadek_egzp(egz);
	}
	void dadek_ilgis(const int il) {
		duomenys::dadek_ilgis(il);
	}
	void dadek_galbal(const float gal) {
		duomenys::dadek_galbal(gal);
	}
	void dadek_med(const float me) {
		duomenys::dadek_med(me);
	}
};
void rasom(vector<duomenys>);
