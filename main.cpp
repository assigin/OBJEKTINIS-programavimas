#include "mylib.h"

struct studentas 
{
  string vardas, pavarde;
  int * pazymiai;
  int egzaminas;
  int darbu_sk;
  double suma=0;
  double gal;
  double med;
};

void ivedimas (studentas & temp)
{
  char kdr;
  int a=1;
  cout<<"Iveskite varda ir pavarde: ";cin>>temp.vardas>>temp.pavarde; 
  cout<<"Jei norite jog sugeneruotu skaicius automatiskai spauskite y, jei ne, tai bet koki kita klavisa"<<endl;
  cin>>kdr;
  if (kdr=='y' || kdr=='Y')
  {
    
    cout<<"Iveskite kiek norite jog sugeneruotu pazymiu"<<endl;
    cin>>temp.darbu_sk;
    while (a==1)
      {
        if (temp.darbu_sk<=0 || isdigit(temp.darbu_sk))
        {
          cout<<"Iveskite pazymiu kieki is naujo: "<<endl;
          cin.clear ();
          cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
          cin>>temp.darbu_sk;
        }
        else
        {
          temp.pazymiai=new int[temp.darbu_sk];
           mt19937 mt(1729);
           uniform_int_distribution<int>dist(1,10);
          for (int i=0;i<temp.darbu_sk;i++)
          {
           temp.pazymiai[i]=dist(mt);
           temp.suma=temp.suma+dist(mt);
          }
          break;
        }
      }
  }
else
  {
    temp.pazymiai=new int [1];
    int paz, i=0, sk=1;
    cout<<"Iveskite pazymius, o baige juos ivest, iveskite bet kokia raide: ";
    while (cin>>paz)
      {
        if (paz<1 || paz>10) cout<<"Rezultatas neatitinka reikalavimu, veskite rezultata intervale nuo 0 iki 10."<<endl;
        if(i==sk)
        {
          sk*=2;
          int* npaz=new int[sk];
          for (int j=0;j<i;j++)
            {
              npaz[j]=temp.pazymiai[j];
            }
          delete[]npaz;
          temp.pazymiai=npaz;
        }
        temp.pazymiai[i++]=paz;
      }
    temp.darbu_sk=i;
  }
  cout<<"Iveskite egzamina: ";
  cin>>temp.egzaminas;
    if(temp.egzaminas<=0 || temp.egzaminas>=10 || isdigit(temp.egzaminas))
      {
      while(a==1) 
        {
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

double galutinis (int* pazymiai, int darbu_sk)
{
  double suma=0;
  for (int i=0;i<darbu_sk;i++)
    {
      suma=suma+pazymiai[i];
    }
   return suma / darbu_sk;
}

double mediana (int* pazymiai, int darbu_sk)
{
  sort(pazymiai, pazymiai+darbu_sk);
  double vid;
  if (darbu_sk % 2 == 0) {
        return (pazymiai[darbu_sk / 2 - 1] + pazymiai[darbu_sk / 2]) / 2.0;
    }
    else {
        return pazymiai[darbu_sk / 2];
    }
}
int main() {
  const int did=1000;
  studentas mas[did];
  int nr=0, a=1;
  char x;
  while (a==1)
    {
      ivedimas[mas[nr]];
      nr++;
      cout<<"Iveskite n jei norite baigt ivedima studentu:"<<endl;
      cin>>x;
      if(x=='n'||x=='N') break;
      if(nr==did)
      {
        cout<<"pasiektas studentu limitas"<<endl;
        break;
      }
    }
  cout << "Vardas    Pavarde     Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "---------------------------------------------------------" << endl;
    for (int i = 0; i < nr; i++) {
        cout << mas[i].vardas << setw(15) << mas[i].pavarde << setw(5) << fixed << setprecision(2) << (galutinis(mas[i].pazymiai, mas[i].darbu_sk) * 0.4) + (mas[i].egzaminas * 0.6) << setw(20) << fixed << setprecision(2) << (mediana(mas[i].pazymiai, mas[i].darbu_sk) * 0.4) + (mas[i].egzaminas * 0.6) << endl;
        delete[] mas[i].pazymiai;
}
  return 0;
}
