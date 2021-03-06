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
#include <algorithm>
#include <cctype>  

using std::cout;
using std::cin;
using std::string;
using std::vector;


struct data {
    string vardas, pavarde;
    std::vector <int> paz;
    int egz;
    double rezult = 0;
    double med;
    int n = 0;
};

void ivestis(data& temp);
void isved(data& temp);
void isdest(data& temp);

void failotikrinimas();
void eil_po_eil(std::string, std::string, int &b);
void skaidymas(std::vector <std::string> splited,int b);
void pirmaeil(std::string read_vardas);
void israsymas(int b);
vector <std::string> split(std::string eil, char delimiter);
vector<data> sortabc(std::vector<data> mok);
void isvestis(std::vector<data>& mok, int paz);
void rikiavimas(std::vector<data>& mok, int a, int paz);