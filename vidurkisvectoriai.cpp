#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>

using std::cout;
using std::cin;
using std::string;

struct data {
    string vardas, pavarde;
    std::vector <int> paz;
    int egz;
    double rezult=0;
    double med;
    int n=0;
};

void ivestis(data& temp);
void isved(data& temp);
void isdest(data& temp);

int main()
{
    int b;
    cout << "Kiek studentu norite ivesti?" <<std::endl;
    cin >> b;
    data* mas = new data[b];
    for (data* a = mas; a < mas + b; a++) {
    ivestis(*a);
}
    for (data* a = mas; a < mas + b; a++) {
        isdest(*a);
    }
    cout << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Med (Vid.)"<< std::endl;
    cout << "______________________________________________________________________________" << std::endl;
    for (data* a = mas; a < mas + b; a++) {
        isved(*a);
    }

    delete[] mas;
}
void ivestis(data& temp) {
    int p;
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    for (int i = 0; i < 100; i++) {
        if (i == 0) cout << "______________________________________________________________________" << std::endl;
        if (i == 0) cout << "Jei norite, kad pazymys butu sugeneruotas automatiskai, rasykite '11'." << std::endl;
        if (i == 0) cout << "______________________________________________________________________" << std::endl;
        //if (i == 0)cout << "___________________________________________" << std::endl;
        if (i == 0)cout << "Jei norite uzbaigti ivedima, rasykite '-1'." << std::endl;
        if (i == 0)cout << "___________________________________________" << std::endl;
        cout << "Iveskite " << i + 1 << "-a(-i) pazymi: ";
        cin >> p;
            if (p > 10) {
                temp.paz.push_back(i);
                temp.paz[i] = rand() % 11;
                temp.n++;
            }
            else if (p >= 0 && p <= 10) {
                temp.paz.push_back(i);
                temp.paz[i] = p;
                temp.n++;
            }
            else i = 1000;

}
    cout << "______________________________________________________________________" << std::endl;
    cout << "Jei norite, kad pazymys butu sugeneruotas automatiskai, rasykite '11'." << std::endl;
    cout << "______________________________________________________________________" << std::endl;
    cout << "Iveskite egzamino iverti: ";
    cin >> p;
    if (p > 10) temp.egz= rand() % 11;
    else temp.egz = p;
}
void isved(data& temp) {
    cout << std::setw(20) << temp.vardas << std::setw(20) << temp.pavarde;
    for (int i = 0; i < temp.n; i++) temp.rezult += temp.paz[i];
    if (temp.n > 0) {
        temp.rezult = temp.rezult / temp.n * 0.4 + 0.6 * temp.egz;
        cout << std::setprecision(3) << std::setw(10) << temp.rezult << std::setprecision(3) << std::setw(25) << temp.med << std::endl;
    }
    else cout << std::setprecision(3) << std::setw(10) << temp.egz << std::setprecision(3) << std::setw(25) << temp.egz <<std:: endl;
}
void isdest(data& temp) {
    for (int i = 0; i < temp.n; i++) {
        for (int j = i + 1; j < temp.n; j++) {
            if (temp.paz[i] > temp.paz[j])
            {
                std::swap(temp.paz[i], temp.paz[j]);
            }
        }
    }
    if (temp.n % 2 == 0) {
        temp.med = (temp.paz[temp.n / 2] + temp.paz[(temp.n / 2) - 1]) * 0.5;
    }
    else temp.med = temp.paz[temp.n / 2];
}
