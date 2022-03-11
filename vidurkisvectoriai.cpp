#include "funkcijos.h"



int main()
{   
    int p,b=0;
    cout << "Ar norite ivesti patys, ar duomenis ivesti is failo?" << std::endl;
    cout << "Spauskite 0 jei norite ivesti patys, 1 jei norite ivesti is failo." << std::endl;
    cin >> p;
    if (p == 0) {
        cout << "Kiek studentu norite ivesti?" << std::endl;
        cin >> b;
        data* mas = new data[b];
        for (data* a = mas; a < mas + b; a++) {
            ivestis(*a);
        }
        for (data* a = mas; a < mas + b; a++) {
            isdest(*a);
        }
        cout << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Med (Vid.)" << std::endl;
        cout << "______________________________________________________________________________" << std::endl;
        for (data* a = mas; a < mas + b; a++) {
            isved(*a);
        }

        delete[] mas;
    }
    if (p == 1) {
        pirmaeil("studentai.txt");
        eil_po_eil("studentai.txt", "studentai_copy.txt",b);
    }
}

