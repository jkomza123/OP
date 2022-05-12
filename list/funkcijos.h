#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cctype>
#include <thread>
#include <list>
#include <iterator>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::vector;


struct data {
    string vardas, pavarde;
    std::vector <int> paz;
    int egz = 0;
    double rezult = 0;
    double med;
    int n = 0;
};

void ivestis(data& temp);
void isved(data& temp);
void isdest(data& temp);

void failotikrinimas();
void eil_po_eil(std::string, std::string, int &b);
void skaidymas(std::list <std::string> splited,int b);
void pirmaeil(std::string read_vardas);
void israsymas(int b);
vector <std::string> split(std::string eil, char delimiter);
vector<data> sortabc(std::list<data> mok);
void isvestis(std::list<data>& mok, int paz, std::list<data>& vargsiukai, std::list<data>& moksliukai);
void rikiavimas(std::list<data>& mok, int a, int paz);
void dalijimas(std::list<data>& mok, int paz, std::list<data>& vargsiukai, std::list<data>& moksliukai);

void generavimas(int s,int pz);