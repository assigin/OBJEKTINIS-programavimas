#include "funcheader.h"


void galutinis (studentas &temp)
{
  temp.vid=0.6*temp.egzaminas+0.4*(1.0*temp.suma/temp.pazymiai.size());
}
void mediana (studentas &temp)
{
  sort(temp.pazymiai.begin(),temp.pazymiai.end());
  double vid;
  vid=temp.pazymiai.size()/2;
  double mediana;
  mediana=temp.pazymiai.size()%2==0? ((temp.med=temp.pazymiai[vid-1]+temp.pazymiai[vid])/2):temp.med=temp.pazymiai[vid];
  temp.med=0.6*temp.egzaminas+0.4*temp.med;
}
void ivedimas (studentas &temp)
{
  char kdr;
  int x;
  int a=1;
  cout<<"Iveskite varda ir pavarde: ";cin>>temp.vardas>>temp.pavarde; 
  cout<<"Jei norite jog sugeneruotu skaicius automatiskai spauskite y, jei ne, tai bet koki kita klavisa"<<endl;
  cin>>kdr;
  if (kdr=='y' || kdr=='Y')
  {
    cout<<"Iveskite kiek norite jog sugeneruotu pazymiu"<<endl;
    cin>>x;
    while (a==1)
      {
        if (x<=0 || isdigit(x))
        {
          cout<<"Iveskite pazymiu kieki is naujo: "<<endl;
          cin.clear ();
          cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
          cin>>x;
        }
        else
        {
           mt19937 mt(1729);
           uniform_int_distribution<int>dist(1,10);
          for (int i=0;i<x;i++)
          {
           temp.pazymiai.push_back(dist(mt));
           temp.suma=temp.suma+dist(mt);
          }
          break;
        }
      }
  }
  else
  {
  cout<<"Iveskite pazymius, o baige juos ivest, iveskite bet kokia raide: ";
  while (cin>>x)
    {
      if (x>=0 && x<=10)
      {
      temp.pazymiai.push_back(x);
      temp.suma=temp.suma+x;
      }
      else cout<<"Rezultatas neatitinka reikalavimu, veskite rezultata intervale nuo 0 iki 10."<<endl;
    }
  cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  cout<<"Iveskite egzamina: ";
  cin>>temp.egzaminas;
    if(temp.egzaminas<=0 || temp.egzaminas>=10 || isdigit(temp.egzaminas)){
      while(a==1){
        if(temp.egzaminas<=0 || temp.egzaminas>10 || isdigit(temp.egzaminas)){
          cout<<"Iveskite egzamino bala is naujo intervale nuo 1 iki 10: "<<endl;
          cin.clear ();
          cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
          cin>>temp.egzaminas;
        }
        else
          break;
      }
    }
}  
void skaitymas_is_failo (string read_vardas, vector<studentas> &mas, studentas &temp) 
{
  string eil, zdz;
  int sk, x;
  ifstream open_f;
  try
    {
      open_f.open(read_vardas);
      if(open_f.fail())throw read_vardas;
    }
    catch (string pav)
    {
      cout<<"Nera tokio failo: "<<pav<<endl;
      cout<<"Patikrinkite ar toks failas egzistuoja."<<endl;
    }
  getline(open_f, eil);
  sk=count(eil.begin(), eil.end(),'D');
  while (open_f)
    {
       if (!open_f.eof())
       {
         open_f>>temp.vardas>>temp.pavarde;
         for(int i=0;i<sk;i++)
           {
             open_f>>x;
             temp.pazymiai.push_back(x);
             temp.suma=temp.suma+x;
           }
         open_f>>temp.egzaminas;
         galutinis (temp);
         mediana(temp);
         mas.push_back(temp);
         temp.pazymiai.clear();
         temp.suma=0;
       }
      else break;
    }
}
void spausdinimas (vector<studentas> mas)
{
  ofstream rf("rezultatai.txt");
  rf << "Vardas"<<setw(15)<<"Pavarde"<<setw(10)<<" Galutinis (Vid.) / Galutinis (Med.)" << endl;
  for(auto &i :mas)
    {
      rf<<i.vardas<<setw(15)<<i.pavarde<<setw(15)<<setprecision(2)<<i.vid<<setw(10)<<setprecision(2)<<i.med<<endl;
    }
  cout<<"Programa baige darba. Patikrinkite rezultatai.txt faila jog pamatytumet juos."<<endl;
}
bool rusiavimas (studentas &pirm, studentas &kit)
{
  if(pirm.vardas==kit.vardas)
  {
    return pirm.vardas<kit.vardas;
  }
  else return pirm.pavarde<kit.pavarde;
}
