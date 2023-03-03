#include "funcheader.h"

int main() {
  vector<studentas> mas;
  studentas tempas;
  char uzkl='n', uzkl_2;
  cout<<"Jei norite jog duomenis nuskaitytu is failo, spauskit y. Kitu atveju patys turesite ivesti duomenis apie studenta: "<<endl;
  cin>>uzkl_2;
    if (uzkl_2=='y' || uzkl_2=='Y')
    {
       skaitymas_is_failo("studentai.txt" ,mas, tempas);
      
    }
  else 
  {
  do{
    ivedimas(tempas);
    galutinis (tempas);
    mediana(tempas);
    mas.push_back(tempas);
    tempas.pazymiai.clear();
    tempas.suma=0;
      cout<<"Baigti darba paspauskite n, testi - bet koks klavisas: ";
    cin>>uzkl;
    }
  while (uzkl!='n' && uzkl!='N');
  }
  sort(mas.begin(), mas.end(), rusiavimas);
 spausdinimas(mas);
  for (auto &i : mas) i.pazymiai.clear();
  mas.clear();
}
