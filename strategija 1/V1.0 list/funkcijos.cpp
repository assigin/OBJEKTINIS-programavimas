#include "v05LIST.h"

bool isnumber(string str) //check if string is number;
{
    for(int i = 0; i < str.length(); i++)
    {
        if(!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

bool equality(studentas &x, studentas &y)
{
    if(x.pavarde == y.pavarde) 
    {
        return x.pavarde < y.pavarde;
    } else return x.vardas < y.vardas;
}


bool grading(studentas &x, studentas &y)
{
    return x.lygin > y.lygin;
}

void mediana(studentas &temp, int n) //mediana search function;
{
    temp.paz.sort();
    float mid1, mid2;
    list<int>::iterator it = temp.paz.begin();
    if(n == 2*(n/2))
    {
        advance(it, n/2-1);
        mid1 = *it;
        advance(it, n/2);
        mid2 = *it;
        temp.med = (mid1+mid2)/2;
    } 
    else 
    {
        advance(it, n/2);
        mid1 = *it;
        temp.med = mid1;
    }
}

void pild(studentas& temp) //function to insert data by hand;
{
    cout << "Iveskite varda ir pavarde: "; cin >> temp.vardas >> temp.pavarde;
    char pas;
    cout << "Jei norite atsitiktinai sugeneruoti pažymius ir egzamino rezultatą, įveskite (k), jei duomenis įvesite pats, įveskite (s): " << endl;
    do
    {
        cin >> pas;
    } while (pas != 's' && pas != 'S' && pas != 'k' && pas != 'K' );

    string check;
    if (pas == 's' || pas == 'S')
    {
        cout << "Iveskite pazymius (norint nebevesti pažymiu rašykite: '0' ): ";
        while(true)
        {
            cin >> check;
            if(!isnumber(check)) 
            {
                cout << "Iveskite SKAICIU [1; 10] be simboliu ar raidziu. Į intervalą nepatenkantys skaičiai nebus apdorojami" << endl;
                continue;
            }

            int check_nd = stoi(check);
        
            if(check_nd == 0)
            {
                if(temp.paz.size() == 0)
                {
                    temp.paz.push_back(check_nd);
                    break;
                } else break;
            } else if(check_nd > 0 && check_nd <=10)
                    {
                        temp.paz.push_back(check_nd);
                    } else if(check_nd < 0 || check_nd > 10)
                        {
                            cout << "Iveskite SKAICIU intervale [1; 10]: " << endl;
                            continue;
                        }
        }

        cout << "Iveskite egzamino paz.: ";
        while(true)
        {
            cin >> check;
            if(!isnumber(check)) 
            {
                cout << "Iveskite SKAICIU [1; 10] be simboliu ar raidziu. Į intervalą nepatenkantys skaičiai nebus abdorojami" << endl;
                continue;
            }

            int check_nd = stoi(check);
            if(check_nd > 0 && check_nd <=10)
                {
                    temp.egz = check_nd;
                } else if(check_nd < 0 || check_nd > 10)
                        {
                            cout << "Iveskite SKAICIU intervale: [1; 10]" << endl;
                            continue;
                        }
            break;
        }

    } else if(pas == 'k' || pas == 'K')
        { 
            cout << "Generuojami pažymiai: " << endl;
            srand(time(0));
            int a = (rand()%10)+1; //generating amount of random numbers
            for (int i = 0; i < a; i++)
            {
                int c = (rand()%10)+1; //generating random numbers;
                cout << c << " ";
                temp.paz.push_back(c);
            }
            cout << endl;
            cout << "Generuojamas egzamino pažymys: " << endl;
            int c = (rand()%10)+1; //generating random exam grade;
            cout << c << endl;
            temp.egz = c;
        } 
}

void eil_po_eil(string read_vardas, studentas& temp, list<studentas> &mas, double &laikas) //read data from file;
{
    string eil, zod, skaic;
    int times;
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    ifstream open_f; //(read_vardas)
    try
    {
        open_f.open(read_vardas);
        if(open_f.fail())
        throw read_vardas;
    }
    catch(string pvd)
    {
        cout << "Nerastas failas: " << pvd << endl;
        cout << "Paleiskite programa is naujo pasitikrine, ar egzistuoja toks failas Jūsų direktorijoje.." << endl;
        exit(0);
    }
 
    getline(open_f, eil);
    times = count(eil.begin(), eil.end(), 'N'); //counting a number of homework;
    while (open_f)
    { 
      if (!open_f.eof()) 
        {
            open_f >> temp.vardas >> temp.pavarde;
            for(int i = 0; i < times; i++)
            {
                int a;
                open_f >> a;
                temp.paz.push_back(a);
            }
            int a;
            open_f >> a; 
            temp.egz = a;
            mas.push_back(temp);
            temp.paz.resize(0);
        }   else break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    cout << "Failo nuskaitymas užtruko: "<< diff.count() << " s." << endl;   
    laikas += diff.count();
}

void generate(string pavadinimas, int size)
{
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    ofstream fs (pavadinimas);
    srand(time(0));
    int pazym_sk = (rand()%20)+1; //generating random homework grades number. NOW ITS [1; 20];
    //(start) Creating top line (vardas pavarde ND* Egz.);
    fs  << left << setw(16) << "Vardas"  << left << setw(14) << "Pavarde" << left << setw(20) << " ";
    for(int i = 1; i <= pazym_sk; i++)
    {
        fs << left << setw(10) << ("ND" + std::to_string(i));
    }
    fs << left << setw(10) << "Egz." << endl;
    //(finish) Creating top line (vardas pavarde ND* Egz.);

    //Generating student names and grades;
    for(int i = 1; i <= size; i++)
    {
        fs  << left << setw(16) << ("Vardas" + std::to_string(i))  << left << setw(14) << ("Pavarde" + std::to_string(i)) << left << setw(20) << " ";
        
        for(int j = 0; j < pazym_sk; j++)
        {
            fs << left << setw(10) << (rand()%10)+1; //generating random grades;
        }
        fs << left << setw(10) << (rand()%10)+1 << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    cout << "Failo generavimas užtruko: "<< diff.count() << " s." << endl; 
}

void skirstymas(list<studentas> &mas, char ats, list<studentas> &mldc, list<studentas> &blgj, double &laikas) //sorting students to good and bad ones;
{
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    mas.sort(grading);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    laikas += diff.count();
    cout << "Failo rūšiavimas didėjimo tvarką užtruko: " << diff.count() << " s." << endl;

    start = std::chrono::high_resolution_clock::now(); 
    
    for(auto &k : mas)
    {
        list<int>::iterator it = k.paz.begin();
        //bereikalingas darbas:
        for(int i = 0; i < k.paz.size(); i++)
        {
            advance(it, i);
            k.gal += *it;
        } 
        // baigiasi čia.
        //gal greičiau buvo skirstyti taip: Sortinam pagrindini faila. Sukuriame viena papildoma vektoriu kaip pvz.: mldc. ir jei galutinis didesnis uz 5, metam mokini i mldc vektoriu. Maziau reiketu sortint. galimai sutaupom laiko;
        if (ats == 'G' || ats == 'g')
        {
            double kint = (0.4*k.gal/(double)k.paz.size() +  k.egz*0.6);
            k.lygin = kint;
            if(kint < 5)
            {
                blgj.push_back(k);
            } else 
                {
                    mldc.push_back(k);
                }
    
        }

        if(ats == 'M' || ats == 'm')
        {
            mediana(k, k.paz.size());
            double kint = (0.4*k.med + k.egz*0.6);
            k.lygin = kint;
            if(kint < 5)
            {
                blgj.push_back(k);
            } else 
                {
                    mldc.push_back(k);
                }
        }        
    }

    end = std::chrono::high_resolution_clock::now();
    diff = end-start; // Skirtumas (s)
    cout << "Failo suskirstymas į vargšus ir šaunuolius užtruko: "<< diff.count() << " s." << endl;
    laikas += diff.count();


}

void spausd(list<studentas> &mas, char ats, string file_name, double &laikas) //printing data to file;
{
    ofstream fr (file_name);
    fr << "------------------------------------------------------------------------------" <<endl;
    fr << left << setw(16) << "Vardas"  << left << setw(25) << "Pavardė " << left << setw(20)  << "Galutinis(Vid.)/Galutinis(Med.)"<<  endl;
    fr << "------------------------------------------------------------------------------" <<endl;
    string skirt = " - ";
    for(auto &k : mas)
    {
        if (ats == 'G' || ats == 'g')
        {
            char eilut[100];
            sprintf(eilut, "%-16s%-25s%-20.2lf%-5s\n", k.vardas.c_str(), k.pavarde.c_str(), k.lygin, skirt.c_str());
            fr << eilut;
        }

        if(ats == 'M' || ats == 'm')
        {
            char eilut[100];
            sprintf(eilut, "%-16s%-25s%-5s%-20.2lf\n", k.vardas.c_str(), k.pavarde.c_str(), skirt.c_str(), k.lygin);
            fr << eilut;
        }
    }
}