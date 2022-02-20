
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::string;

struct data {
    string vardas, pavarde;
    int paz[3], egz;
    double rezult=0;
};

void ivestis(data& temp);
void isved(data& temp);
int main()
{
    data* mas = new data[2];
    for (data* a = mas; a < mas + 2; a++) {
    ivestis(*a);
}   
    cout << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::endl;
    cout << "______________________________________________________________________________" << std::endl;
    for (data* a = mas; a < mas + 2; a++) {
        isved(*a);
    }

    delete[] mas;
}
void ivestis(data& temp) {
    int n=3;
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    //cout << "Kiek pazymiu turi studentas: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Iveskite " << i + 1 << "-a(-i) pazymi: ";
        cin >> temp.paz[i];
    }
    cout << "Iveskite egzamino iverti: ";
    cin >> temp.egz;
}
void isved(data& temp) {
    cout << std::setw(20) << temp.vardas << std::setw(20) << temp.pavarde;
    for (int i = 0; i < 3; i++) temp.rezult += temp.paz[i];
    temp.rezult = temp.rezult / 3 * 0.4 + 0.6 * temp.egz;
    cout << std::setprecision(3) << std::setw(10)  <<temp.rezult<< std::endl;
}
