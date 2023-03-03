#include "lib.h"

struct studentas 
{
  string vardas, pavarde;
  vector<int> pazymiai;
  int egzaminas;
  double vid;
  double med;
  int suma=0;
};

void ivedimas (studentas &temp);
void galutinis (studentas &temp);
void mediana (studentas &temp);
void skaitymas_is_failo (string read_vardas, vector<studentas> &mas, studentas &temp);
void spausdinimas (vector<studentas> mas);
bool rusiavimas (studentas &pirm, studentas &kit);
