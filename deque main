#include "funcheader.h"

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    deque<studentas> mas;
    studentas tempas;
    deque<studentas> zino;
    deque<studentas> nezino;
    char uzkl = 'n', uzkl_2, uzkl_3, b;
    cout << "Jei norite, jog paskirstytu pagal medianos galutinio ivertinima, spauskit y. Kitu atveju programa paskirstys pagal pazymiu vidurkio galutini ivertinima: " << endl;
    cin >> b;
    cout << "Jei norite, jog programa pati sugeneruotu visus duomenis, spauskit y. Kitu atveju galesite pasirinkti ar norite, jog duomenis is failo nuskaitytu, ar patys juos ivesti: " << endl;
    cin >> uzkl_3;
    if (uzkl_3 == 'y' || uzkl_3 == 'Y')//V0.4
    {
        int x, n = 1000;
        int a = 1;
        cout << "Iveskite kiek norite jog sugeneruotu pazymiu" << endl;
        cin >> x;
        while (a == 1)//kiek pazymiu generuot
        {
            if (x <= 0 || isdigit(x))
            {
                cout << "Iveskite pazymiu kieki is naujo: " << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin >> x;
            }
            else break;
        }
        visiskas_generavimas(tempas, x, n);//generavimas i faila duomenu
        skaitymas_is_failo("gen_stud.txt", mas, tempas);
        if (b == 'y' || b == 'Y')//medianos rusiavimas
        {
            auto start = std::chrono::high_resolution_clock::now();
            sort(mas.begin(), mas.end(), rusiavimas_2);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            cout << "Failo rusiavimas pagal mediana uztruko: " << diff.count() << " s." << endl;
        }
        else//vidurkio rusiavimas
        {
            auto start = std::chrono::high_resolution_clock::now();
            sort(mas.begin(), mas.end(), rusiavimas_3);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            cout << "Failo rusiavimas pagal vidurki uztruko: " << diff.count() << " s." << endl;
        }
        skirstymas(zino, nezino, b, mas);
        spaus(zino, b, "Islaike_studentai.txt");
        spaus(nezino, b, "neislaike_studentai.txt");
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << "Visa programa uztruko: " << diff.count() << " s." << endl;
        cout << "Programa baige darba. Patikrinkite rezultatus failuose: Islaike_studentai ir neislaike_studentai" << endl;
    }
    else//V0.2
    {
        cout << "Jei norite, jog duomenis nuskaitytu is failo, spauskit y. Kitu atveju patys turesite ivesti duomenis apie studenta: " << endl;
        cin >> uzkl_2;
        if (uzkl_2 == 'y' || uzkl_2 == 'Y')
        {
            skaitymas_is_failo("studentai.txt", mas, tempas);
            if (b == 'y' || b == 'Y')//medianos rusiavimas
            {
                auto start = std::chrono::high_resolution_clock::now();
                sort(mas.begin(), mas.end(), rusiavimas_2);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = end - start;
                cout << "Failo rusiavimas pagal mediana uztruko: " << diff.count() << " s." << endl;
                skirstymas(zino, nezino, b, mas);
                cout << "Islaikiusiu ";
                spaus(zino, b, "Islaike_studentai.txt");
                cout << "Neislaikiusiu ";
                spaus(nezino, b, "neislaike_studentai.txt");
            }
            else//vidurkio rusiavimas
            {
                auto start = std::chrono::high_resolution_clock::now();
                sort(mas.begin(), mas.end(), rusiavimas_3);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = end - start;
                cout << "Failo rusiavimas pagal vidurki uztruko: " << diff.count() << " s." << endl;
                skirstymas(zino, nezino, b, mas);
                cout << "Islaikiusiu ";
                spaus(zino, b, "Islaike_studentai.txt");
                cout << "Neislaikiusiu ";
                spaus(nezino, b, "neislaike_studentai.txt");
            }
        }
        else//V0.1
        {
            do {
                ivedimas(tempas);
                galutinis(tempas);
                mediana(tempas);
                mas.push_back(tempas);
                tempas.pazymiai.clear();
                tempas.suma = 0;
                cout << "Baigti darba paspauskite n, testi - bet koks klavisas: ";
                cin >> uzkl;
            } while (uzkl != 'n' && uzkl != 'N');
        }
        sort(mas.begin(), mas.end(), rusiavimas);
        spausdinimas(mas);

    }
    for (auto& i : mas) i.pazymiai.clear();
    mas.clear();
    for (auto& i : zino) i.pazymiai.clear();
    zino.clear();
    for (auto& i : nezino) i.pazymiai.clear();
    nezino.clear();
}
