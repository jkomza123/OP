
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::string;

struct data {
    string vardas, pavarde;
    int paz[100], egz;
    double rezult=0;
    double med;
    int n=0;
};

void ivestis(data& temp);
void isved(data& temp);
void isdest(data&);
int main()
{
    data* mas = new data[2];
    for (data* a = mas; a < mas + 2; a++) {
    ivestis(*a);
}   
    for (data* a = mas; a < mas + 2; a++) {
        isdest(*a);
    }
    cout << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Med (Vid.)"<< std::endl;
    cout << "______________________________________________________________________________" << std::endl;
    for (data* a = mas; a < mas + 2; a++) {
        isved(*a);
    }

    delete[] mas;
}
void ivestis(data& temp) {
    int p;
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    //cout << "Kiek pazymiu turi studentas: "; cin >> n;
    for (int i = 0; i < 100; i++) {
        if (i == 0) cout << "______________________________________________________________________" << std::endl;
        if (i == 0) cout << "Jei norite, kad pazymys butu sugeneruotas automatiskai, rasykite '11'." << std::endl;
        if (i == 0) cout << "______________________________________________________________________" << std::endl;
        if (i == 1)cout << "__________________________________________" << std::endl;
        if (i == 1)cout << "Jei tai paskutinis pazymys, rasykite '-1'." << std::endl;
        if (i == 1)cout << "__________________________________________" << std::endl;
        cout << "Iveskite " << i + 1 << "-a(-i) pazymi: ";
        cin >> p;
        if (!cin) cout << "veskite is naujo" <<std::endl;
        if (p > 10) {
            temp.paz[i] = rand() % 11;
            temp.n++;
        }
        else if (p >= 0&&p<=10) {
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
    temp.rezult = temp.rezult / temp.n * 0.4 + 0.6 * temp.egz;
    cout << std::setprecision(3) << std::setw(10)  <<temp.rezult<< std::setprecision(3)<< std::setw(25) << temp.med<< std::endl;
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
