#include "v05LIST.h"

int main()
{   
    list<studentas> mas;
    studentas tempas;
    list<studentas> mldc;
    list<studentas> blgj;
    
    double laikas = 0;
    char rink;
    cout << "Jei norite:" << endl;
    do
    {
        cout << "nuskaityti duomenis iš failo, įveskite (f). " << endl;
        cout << "įvesti duomenis ranka, įveskite (r). " << endl;
        cout << "sugeneruoti duomenų failą (s). " << endl;
        cin >> rink; 
    } while (rink != 'r' && rink != 'R' && rink != 'f' && rink != 'F' && rink != 's' && rink != 'S');
    
    
    if(rink == 'r' || rink == 'R')
    {
        char uzkl = 'n';
        do{
            pild(tempas);
            mas.push_back(tempas);
            tempas.paz.clear();
            cout << "------------------------------------------------------------------------------" <<endl;
            cout << "Baigti darba spausk n, testi - bet koks klavisas: " << endl;
            cout << "------------------------------------------------------------------------------" <<endl;
            cin >> uzkl;
        }while (uzkl!='n' && uzkl!='N');  
    } else if(rink == 'f' || rink == 'F')
            {
                eil_po_eil("sarasas10000000.txt", tempas, mas, laikas);
            } else if (rink == 's' || rink == 'S')
                {
                    int size;
                    cout << "Įveskite norimo sąrašo dydį: "; cin >> size;
                    generate("sarasas10000000.txt", size);
                    cout << "Duomenų failas sugeneruotas! Pasitikrinkite savo folderį!";
                    exit(0);
                }

    
    char ats;  
    do
    {
        cout << "Galutinį pažymį(Vidurkis), rašykite (G)" << endl;
        cout << "Galutinį pažymį(Mediana), rašykite (M)" << endl;
        cin >> ats;
        cout << endl;
    } while (ats != 'g' && ats != 'G' && ats != 'm' && ats != 'M');
    //sort(mas.begin(), mas.end(), equality); //data sorting by name/lastname;  If "equality" function returns "False", it let's us know, that the "First" argument shouldn't be placed before "Second" argument, arguments would be swaped;
    mas.sort(equality);
    skirstymas(mas, ats, mldc, blgj, laikas);
    spausd(mldc, ats, "stiprus.txt", laikas); //printing data to file;
    spausd(blgj, ats, "apsileide.txt", laikas); //printing data to file;
    cout << "Programos trukmės laikas: " << laikas << "s. \n";

    for(auto &i : mas) i.paz.clear();
    mas.clear();
    for(auto &i : mldc) i.paz.clear();
    mldc.clear();
    for(auto &i : blgj) i.paz.clear();
    blgj.clear();

    cout << "Pasitikrinkite savo rezultatų failą!" << endl;
}