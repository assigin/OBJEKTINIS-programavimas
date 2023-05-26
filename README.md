# OBJEKTINIS programavimas
## V0.1

- Programa, kuri paskaičiuoja studento galutinį įvertinimą su mediana ir vidurkiu. (Pagal formulę)
- Pasirenkama, ar vartotojas įveda pažymius, ar juos atsitiktinai sugeneruoja.

## V0.2

- Pridėtas studento duomenų skaitymas iš failo.

## V0.3

- išskirstyta funkcijos ir struktūros į kitus failus.
- Įdėtas išimčių valdymas, jei būtų bandoma skaityti duomenis iš failo, kurio nėra.

## V0.4

- Programa gali sugeneruoti visus duomenis.
- Surūšiuoja studentus į du failus pagal galutinį balą.
- Surūšiuoja studentus failuose pagal vidurkį.
- matuojamas programos veikimo greitis.

| Failo generavimo lentelė||||||
|-------------------------|-----|-----|-----|-----|-----|
|laikas(s)|0,043|0,34|3,5|34,2|
|dydis| 1000 |10000|100000|1000000|10000000|

|Funkcijų atlikimo greičio lentelė||||||
|-------------------------|-----|-----|-----|-----|-----|
|dydis| 1000 |10000|100000|1000000|10000000|
|Rūšiavimas(s)|0,0053|0,065|0,65|6,9|
|Skirstymas(s)|0,0047|0,058|0,52|5,5|
|Išlaikiusiu vedimas į failą (s)|0,01|0,09|0,9|9|
|Neišlaikiusiu vedimas į failą (s)|0,0068|0,06|0,66|6,2|
|Visas programos veikimo laikas su failo generavimu (s)|0,0698|0.613|6,23|61.8|

Greitis buvo matuojamas paleidžiant programą penkis kartus, generuojant penkis pažymius kiekvienam studentui
