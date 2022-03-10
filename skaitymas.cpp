#include "skaitymas.h"

int b,paz=0;

void pirmaeil(std::string read_vardas) {
    std::string eil;
    std::ifstream open_f(read_vardas);
    std::getline(open_f, eil);
    int ilg = eil.size();
        for (int i = 1; i < ilg; i++) {

            if (eil[i - 1] == ' ' && eil[i] != ' ') paz++;
        }
        paz = paz - 2;
        std::cout << paz;
}
void skaidymas(std::vector <std::string> splited);
void eil_po_eil(std::string read_vardas, std::string write_vardas) {
    std::string eil;
    //----------------------------------------------------------------------
    std::ifstream open_f(read_vardas);
    std::vector<std::string> splited;
    while (open_f) {
        if (!open_f.eof()) {
            std::getline(open_f, eil);
            splited.push_back(eil);
            b++;
        }
        else break;
    }
    skaidymas(splited);
    open_f.close();
    std::ofstream out_f(write_vardas);
    for (std::string a : splited) out_f << a;
    out_f.close();
    splited.resize(0);
}

void skaidymas(std::vector <std::string> splited) {
    std::string eil;
    for (int i = 0; i < b; i++) {
        eil = splited[i];
        std::vector<std::string> eildalys = split (eil, ' ');

        Mokinys mok = Mokinys();
        mok.vardas = eilDalys[0];
        mok.pavarde = eilDalys[1];

        for (int i = 0; i < kiek; i++)
        {
            mok.paz[i] = std::stoi(eilDalys[2 + i]);
        }

        mok.egz = std::stod(eilDalys[kiek + 2]);


        mokiniai.push_back(mok);
        //cout<<mokiniai.vardas;
        splited.push_back(eil);
    }
}