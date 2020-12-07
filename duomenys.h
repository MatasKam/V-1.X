#pragma once
#include "biblioteka.h"

class duomenys {
private:
	string vardas = "";
	string pavarde = "";
	int egzp;
	int ilgis=0;
	float galbal;
	float med;

	vector<int>ndp;
	vector < duomenys> gaidz;
	vector < duomenys> mldc;

public:
	void dadek_vardas(const string var) { vardas = var; }
	string vardass() const { return vardas; }
	void dadek_pavarde(const string pavar) { pavarde = pavar; }
	string pavardee() const { return pavarde; }
	void dadek_egzp(const int egz) { egzp = egz; }
	int egzpp() const { return egzp; }
	void dadek_ilgis(const int il) { ilgis = il; }
	int ilgiss() const { return ilgis; }
	void dadek_galbal(const float gal) { galbal = gal; }
	float galball() const { return galbal; }
	void dadek_med(const float me) { med = me; }
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
void rasom(vector<duomenys>);