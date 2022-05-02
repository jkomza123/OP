```

```

# Programa skirta studentų pažymių vidurkiui ir medianai apskaičiuoti.

### Apie programą.<br>

https://github.com/jkomza123/OP/blob/v1.0/vidurkisdeque.cpp naudojami deque tipo konteineriai.
https://github.com/jkomza123/OP/blob/v1.0/vidurkisvector.cpp naudojami vector tipo konteineriai.
https://github.com/jkomza123/OP/blob/v1.0/vidurkislist.cpp naudojami list tipo konteineriai.

### Įjungus programą Jums reikės:<br>

- Pasirinkti ar duomenys įkeliami iš failo ar vedami ranka.
- Suvesti kiek studentų duomenis norėsite įvesti.
- Suvesti studento vardą ir pavardę.
- Suvesti pažymius patiems arba parašius 11 pažymys bus sugeneruotas automatiškai.
- Baigus vesti vieno studento duomenis rašyti -1. Tada bus pereita prie kito studento arba pasibaigus programa pasibaigs.

Programa papildyta, kad rodytu klaidas, kurios nutinka įvedant duomenis iš failo.

(Pažymių vidurkis sudaromas vadovaujantis šia formule: galutinis = 0.4 * vidurkis + 0.6 * egzaminas)<br>
(Pažymių mediana sudaroma vadovaujantis šia formule: mediana = 0.4 * pažymių mediana + 0.6 * egzaminas)<br>

### Pasirinkus šiuos nustatymus matysite sudarytą lentelę su studentu pavardėmis, vardais ir pažymių vidurkiais ir medianomis.

- v0.1 Pradinė programos versija skaičiuojanti vidurkį pagal medianą ir pažymius.
- v0.2 Sukurta funkcija skaityti duomenis iš failo.
- v0.3 Sukurta funkcija, rodanti klaidas, nutinkančias programos eigoje.
- v0.4 Sukurtas funkcija, generuojanti atsitiktinių duomenų failą.
- v0.5 Sukurta versija su deque tipo konteineriais.
- v1.0 Optimizuota programa, veikianti sparčiau.

### Kaip įsirašyti programą?

-Įsirašykite mingw32 kompiliatorių.
-Įsijunkite cmd kaip administratorius ir nueikite į norimų konteinerių failo repozitoriją naudodami komandą CD.
-Rašykite mingw32-make run, jums susikurs .exe failas kurį galėsite paleisti savo kompiuteryje.
-Baigę darbą su programa rašykite mingw32-make clean.
