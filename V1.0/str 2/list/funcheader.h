#pragma once
#include "lib.h"

struct studentas
{
	string vardas, pavarde;
	list<int> pazymiai;
	int egzaminas;
	double vid;
	double med;
	int suma = 0;
};

void ivedimas(studentas& temp);
void galutinis(studentas& temp);
void mediana(studentas& temp);
void skaitymas_is_failo(string read_vardas, list<studentas>& mas, studentas& temp);
void spausdinimas(list<studentas> mas);
bool rusiavimas(studentas& pirm, studentas& kit);
void visiskas_generavimas(studentas& temp, int& x, int& n);
bool rusiavimas_2(studentas& pirm, studentas& kit);
bool rusiavimas_3(studentas& pirm, studentas& kit);
void spaus(list<studentas>& mas, char b, string file_name);
void skirstymas(list<studentas>& mas, list<studentas>& nezino, char& b);
bool patikra_med1(studentas& pirm);
bool patikra_vid1(studentas& pirm);
bool patikra_med2(studentas& pirm);
bool patikra_vid2(studentas& pirm);