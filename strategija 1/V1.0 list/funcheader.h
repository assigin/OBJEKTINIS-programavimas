#ifndef V05LIST_H_INCLUDED
#define V05LIST_H_INCLUDED

#include "Mylib.h"

struct studentas //struct
{
    string vardas, pavarde;
    list<int> paz;
    double egz;
    double gal = 0;
    double med;
    double lygin;
};

bool isnumber(string str); //check if string is number;
bool equality(studentas &x, studentas &y); //bool for sorting by name;
bool grading(studentas &x, studentas &y); //bool for sorting by grades;
void mediana(studentas &temp, int n); //mediana search function;
void pild(studentas& temp); //function to insert data by hand;
void eil_po_eil(string read_vardas, studentas& temp, list<studentas> &mas, double &laikas); //read data from file;
void generate(string pavadinimas, int size); //function for student file generating;
void skirstymas(list<studentas> &mas, char ats, list<studentas> &mldc, list<studentas> &blgj, double &laikas); //sorting students to good and bad ones;
void spausd(list<studentas> &mas, char ats, string file_name, double &laikas); //printing data to file;


#endif