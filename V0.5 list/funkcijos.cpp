#include "funcheader.h"


void galutinis(studentas& temp)
{
    temp.vid = 0.6 * temp.egzaminas + 0.4 * ((1.0 * temp.suma) / temp.pazymiai.size());
}
void mediana(studentas& temp)
{
   // sort(temp.pazymiai.begin(), temp.pazymiai.end());
    temp.pazymiai.sort();
    double vid1, vid2;
    list<int>::iterator it = temp.pazymiai.begin();
    advance(it, temp.pazymiai.size() / 2 - 1);
    vid1 = *it;
    advance(it, temp.pazymiai.size() / 2);
    vid2 = *it;
    temp.med = 0.6 * temp.egzaminas + 0.4 * ((vid1+vid2)/2);
}
void ivedimas(studentas& temp)
{
    char kdr;
    int x;
    int a = 1;
    cout << "Iveskite varda ir pavarde: "; cin >> temp.vardas >> temp.pavarde;
    cout << "Jei norite jog sugeneruotu skaicius automatiskai spauskite y, jei ne, tai bet koki kita klavisa" << endl;
    cin >> kdr;
    if (kdr == 'y' || kdr == 'Y')
    {
        cout << "Iveskite kiek norite jog sugeneruotu pazymiu" << endl;
        cin >> x;
        while (a == 1)
        {
            if (x <= 0 || isdigit(x))
            {
                cout << "Iveskite pazymiu kieki is naujo: " << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin >> x;
            }
            else
            {
                random_device rd;
                mt19937 mt(rd());
                uniform_int_distribution<int>dist(1, 10);
                for (int i = 0; i < x; i++)
                {
                    temp.pazymiai.push_back(dist(mt));
                    temp.suma = temp.suma + dist(mt);
                }
                break;
            }
        }
    }
    else
    {
        cout << "Iveskite pazymius, o baige juos ivest, iveskite bet kokia raide: ";
        while (cin >> x)
        {
            if (x >= 0 && x <= 10)
            {
                temp.pazymiai.push_back(x);
                temp.suma = temp.suma + x;
            }
            else cout << "Rezultatas neatitinka reikalavimu, veskite rezultata intervale nuo 0 iki 10." << endl;
        }
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "Iveskite egzamina: ";
    cin >> temp.egzaminas;
    if (temp.egzaminas <= 0 || temp.egzaminas >= 10 || isdigit(temp.egzaminas)) {
        while (a == 1) {
            if (temp.egzaminas <= 0 || temp.egzaminas > 10 || isdigit(temp.egzaminas)) {
                cout << "Iveskite egzamino bala is naujo intervale nuo 1 iki 10: " << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin >> temp.egzaminas;
            }
            else
                break;
        }
    }
}
void skaitymas_is_failo(string read_vardas, list<studentas>& mas, studentas& temp)
{
    string eil, zdz;
    int sk, x, a;
    ifstream open_f;
    try
    {
        open_f.open(read_vardas);
        if (open_f.fail())throw read_vardas;
    }
    catch (string pav)
    {
        cout << "Nera tokio failo: " << pav << endl;
        cout << "Patikrinkite ar toks failas egzistuoja." << endl;
    }
    getline(open_f, eil);
    sk = count(eil.begin(), eil.end(), 'D');
    while (open_f)
    {
        if (!open_f.eof())
        {
            open_f >> temp.vardas >> temp.pavarde;
            for (int i = 0; i < sk; i++)
            {
                open_f >> x;
                temp.pazymiai.push_back(x);
                temp.suma = temp.suma + x;
            }
            open_f >> a;
            temp.egzaminas = a;
            galutinis(temp);
            mediana(temp);
            mas.push_back(temp);
            temp.pazymiai.clear();
            temp.suma = 0;
        }
        else break;
    }
}
void spausdinimas(list<studentas> mas)
{
    ofstream rf("rezultatai.txt");
    rf << "Vardas" << setw(15) << "Pavarde" << setw(10) << " Galutinis (Vid.) / Galutinis (Med.)" << endl;
    for (auto& i : mas)
    {
        rf << i.vardas << setw(15) << i.pavarde << setw(15) << setprecision(2) << i.vid << setw(10) << setprecision(2) << i.med << endl;
    }
    cout << "Programa baige darba. Patikrinkite rezultatai.txt faila jog pamatytumet juos." << endl;
}
bool rusiavimas(studentas& pirm, studentas& kit)
{
    if (pirm.vardas == kit.vardas)
    {
        return pirm.vardas < kit.vardas;
    }
    else return pirm.pavarde < kit.pavarde;
}
void visiskas_generavimas(studentas& temp, int& x, int& n)
{
    auto start = std::chrono::high_resolution_clock::now();
    int pazymiai, egzaminas;
    ofstream rf("gen_stud.txt");
    rf << "Vardas" << setw(12) << "Pavarde ";
    for (int i = 0; i < x; i++)
    {
        rf << "ND " + to_string(i + 1);
    }
    rf << "Egzaminas" << endl;
    for (int i = 0; i < n; i++)
    {
        string vardas = "Vardas", pavarde = "Pavarde";
        vardas += to_string(i + 1);
        pavarde += to_string(i + 1);
        rf << vardas << setfill(' ') << setw(18) << pavarde << setfill(' ') << setw(18);
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int>dist(1, 10);
        for (int j = 0; j < x; j++)
        {
            pazymiai = (dist(mt));
            rf << " " << pazymiai;
        }
        egzaminas = dist(mt);
        rf << " " << egzaminas << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo generavimas uztruko: " << diff.count() << " s." << endl;
}
bool rusiavimas_2(studentas& pirm, studentas& kit)
{
    if (pirm.med == kit.med)
    {
        return pirm.med < kit.med;
    }
    else return kit.med < pirm.med;
}
bool rusiavimas_3(studentas& pirm, studentas& kit)
{
    if (pirm.vid == kit.vid)
    {
        return pirm.vid < kit.vid;
    }
    else return kit.vid < pirm.vid;
}
void spaus(list<studentas>& mas, char b, string file_name)
{
    auto start = std::chrono::high_resolution_clock::now();
    ofstream rf(file_name);
    if (b == 'y' || b == 'Y')//mediana
    {
        rf << "Vardas" << setw(15) << "Pavarde" << setw(10) << "Galutinis (Med.)" << endl;
        for (auto i : mas)
        {
            rf << i.vardas << setw(15) << i.pavarde << setw(15) << setprecision(2) << i.med << setw(10) << endl;
        }
    }
    else//vidurkis
    {
        rf << "Vardas" << setw(15) << "Pavarde" << setw(10) << "Galutinis (Vid.)" << endl;
        for (auto i : mas)
        {
            rf << i.vardas << setw(15) << i.pavarde << setw(15) << setprecision(2) << i.vid << setw(10) << endl;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo atspausdinimas i failus uztruko: " << diff.count() << " s." << endl;
}
void skirstymas(list<studentas>& zino, list<studentas>& nezino, char& b, list<studentas>& mas)
{
    auto start = std::chrono::high_resolution_clock::now();
    if (b == 'y' || b == 'Y')// skirstymas pagal mediana
    {
        for (auto& i : mas)
        {
            if (i.med >= 5)
            {
                zino.push_back(i);
            }
            else
            {
                nezino.push_back(i);
            }
        }
    }
    else//skirstymas pagal vidurki
    {
        for (auto i : mas)
        {
            if (i.vid >= 5)
            {
                zino.push_back(i);
            }
            else
            {
                nezino.push_back(i);
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo skirstymas i dvi grupes uztruko: " << diff.count() << " s." << endl;
}