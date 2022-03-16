#include "funkcijos.h"

int paz=0;
std::vector<data> mokiniai;

//GENERAVIMAS

void generavimas(int s, int pz) {
    std::ofstream out_f("studentai.txt");
    for (int i = 0; i <= s; i++) {
        out_f << "Vardas" << i << ' ' << "Pavarde" << i << ' ';
        for (int j = 0; j < pz; j++) {
            out_f << rand() % 11 << ' ';
        }
        out_f << rand() % 11 << '\n';
    }
    out_f.close();
}

//VEDAMA IS FAILO

void failotikrinimas() {
    struct nera : public std::exception {
        const char* what() const throw () {
            return " Klaida";
        }
    };
    try
    {   
        std::string eil;
        std::ifstream open_f("studentai.txt");
        std::getline(open_f, eil);
       // open_f.exceptions(std::ifstream::eofbit);
        open_f.open("studentai.txt");
        if (open_f.is_open()) {
            cout << "*Failas atidarytas ir programa pradeda duomenu apdorojima*" << std::endl;
        }
        else if (!open_f.is_open()) {
            throw nera();
        }
        if (open_f.eof())
        {
            cout << "*Failas tuscias*" << std::endl;
        }
    }
    catch (nera& e)
    {
        cout << "*Failo nera arba netinkamas failo formatas*" << e.what() << std::endl;
        _exit(1);
    }
}
void pirmaeil(std::string read_vardas) {

    std::string eil;
    std::ifstream open_f(read_vardas);
    std::getline(open_f, eil);
    int ilg = eil.size();
        for (int i = 1; i < ilg; i++) {

            if (eil[i - 1] == ' ' && eil[i] != ' ') paz++;
        }
        paz = paz - 2;
}
void skaidymas(std::vector <std::string> splited);
void eil_po_eil(std::string read_vardas, std::string write_vardas,int &b) {
    std::string eil;
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
    /*std::ofstream out_f(write_vardas);
    for (std::string a : splited) out_f << a;
    out_f.close();*/
    skaidymas(splited,b);
    
}

void skaidymas(std::vector <std::string> splited,int b) {
    std::string eil;
    for (int i = 1; i < b-1; i++) {
        eil = splited[i];
        std::vector<std::string> eildalys = split (eil, ' ');
        //cout << i <<std:: endl;
        data mok = data();
        mok.n = paz;
        mok.vardas = eildalys[0];
        mok.pavarde = eildalys[1];
        //cout << mok.vardas << " " << mok.pavarde << " ";
        for (int j = 0; j < paz + 1; j++)
        {
            mok.paz.push_back(j);
            std::stringstream value(eildalys[j + 2]);
            if (j < paz) {
                value >> mok.paz[j];
                mok.rezult = mok.rezult + mok.paz[j];
            }
            else value >> mok.egz;
        }
        mokiniai.push_back(mok);
    }
    isvestis(mokiniai, paz);
}
std::vector<std::string> split(std::string eil, char delimiter)
{
    std::vector<std::string> result;
    size_t start;
    size_t end = 0;

    while ((start = eil.find_first_not_of(delimiter, end)) != std::string::npos)
    {
        end = eil.find(delimiter, start);
        result.push_back(eil.substr(start, end - start));
    }

    return result;
}
void isvestis(std::vector<data>& mok, int paz)
{   
    std::ofstream out_v("vargsiukai.txt");
    std::ofstream out_m("moksliukai.txt");
    out_v<<std::setw(20) << "Vardas" <<std:: setw(20) << "Pavarde" <<std:: setw(20) << "Galutinis (Vid.)" <<std:: setw(20) << "Galutinis (Med.)" <<'\n';
    out_v << "----------------------------------------------------------------------------------------" <<std:: endl;
    out_m << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << '\n';
    out_m << "----------------------------------------------------------------------------------------" << std::endl;
    int i = 0;
    std::sort(mok.begin(), mok.end(), [](const data&d1,const data&d2) {
        return d1.vardas < d2.vardas;
        });
    for (data& m : mok)
    {
        rikiavimas(mok, i, paz);
        mok[i].rezult = mok[i].rezult / mok[i].n * 0.4 + 0.6 * mok[i].egz;
        if (mok[i].rezult<5) out_v << std::setw(20) << mok[i].vardas << std::setw(20) << mok[i].pavarde << std::setprecision(3) << std::setw(10) << mok[i].rezult << std::setprecision(3) << std::setw(25) << mok[i].med << '\n';
        else if (mok[i].rezult >= 5) out_m << std::setw(20) << mok[i].vardas << std::setw(20) << mok[i].pavarde << std::setprecision(3) << std::setw(10) << mok[i].rezult << std::setprecision(3) << std::setw(25) << mok[i].med << '\n';
        i++;
    }
    out_v.close();
    out_m.close();
}
void rikiavimas(std::vector<data>& mok, int a, int paz)
{
    int laikinas;
    for (int i = 0; i < mok[a].n; i++) {
        for (int j = i + 1; j < mok[a].n; j++)
        {
            if (mok[a].paz[i] > mok[a].paz[j])
            {
                laikinas = mok[a].paz[i];
                mok[a].paz[i] = mok[a].paz[j];
                mok[a].paz[j] = laikinas;
            }
        }
        if (mok[a].n % 2 == 0) {
            mok[a].med = (mok[a].paz[mok[a].n / 2] + mok[a].paz[(mok[a].n / 2) - 1]) * 0.5;
        }
        else mok[a].med = mok[a].paz[mok[a].n / 2];
    }
}
//VEDAMA RANKA
void ivestis(data& temp) {
    int p;
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    for (int i = 0; i < 1000000; i++) {
        if (i == 0) cout << "______________________________________________________________________" << std::endl;
        if (i == 0) cout << "Jei norite, kad pazymys butu sugeneruotas automatiskai, rasykite '11'." << std::endl;
        if (i == 0) cout << "______________________________________________________________________" << std::endl;
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
        else i = 10000000;

    }
    cout << "______________________________________________________________________" << std::endl;
    cout << "Jei norite, kad pazymys butu sugeneruotas automatiskai, rasykite '11'." << std::endl;
    cout << "______________________________________________________________________" << std::endl;
    cout << "Iveskite egzamino iverti: ";
    cin >> p;
    if (p > 10) temp.egz = rand() % 11;
    else temp.egz = p;
}
void isved(data& temp) {
    cout << std::setw(20) << temp.vardas << std::setw(20) << temp.pavarde;
    for (int i = 0; i < temp.n; i++) temp.rezult += temp.paz[i];
    if (temp.n > 0) {
        temp.rezult = temp.rezult / temp.n * 0.4 + 0.6 * temp.egz;
        cout << std::setprecision(3) << std::setw(10) << temp.rezult << std::setprecision(3) << std::setw(25) << temp.med << std::endl;
    }
    else cout << std::setprecision(3) << std::setw(10) << temp.egz << std::setprecision(3) << std::setw(25) << temp.egz << std::endl;
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