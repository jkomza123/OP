#include "skaitymas.h"

int b,sk;

void pirmaeil(std::string read_vardas, std::string write_vardas) {
    std::string eil;
    std::ifstream open_f(read_vardas);
    std::getline(open_f, eil);
}
void skaidymas(std::string &eil, const char delim, std::vector <std::string> splited);
void eil_po_eil(std::string read_vardas, std::string write_vardas) {
    const char delim = ' ';
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
    open_f.close();
    std::ofstream out_f(write_vardas);
    for (std::string a : splited) out_f << a;
    out_f.close();
    splited.resize(0);
}

void skaidymas(std::string& eil, const char delim, std::vector <std::string> splited) {
    for (int i = 0; i < b; i++) {
        eil = splited[i];
        std::stringstream s(eil);
        int l = eil.size();
    }
}