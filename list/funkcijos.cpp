#include "funkcijos.h"

int paz=0;
size_t mokslsk = 0;
size_t vargsk = 0;
std::list<data> mokiniai;
std::list<data> vargsiukai;
std::list<data> moksliukai;
//GENERAVIMAS

void generavimas(int s, int pz) {
    std::stringstream my_buffer;
    auto start =std::chrono::high_resolution_clock::now();
    for (int i = 0; i <= s; i++) {
        my_buffer << "Vardas" << i << ' ' << "Pavarde" << i << ' ';
        for (int j = 0; j < pz; j++) {
            my_buffer << rand() % 11 << ' ';
        }
        my_buffer << rand() % 11 << '\n';
    }
    std::ofstream out_f("studentai.txt");
    out_f << my_buffer.str();
    out_f.close();
    my_buffer.clear();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    double t = (duration.count());
    cout <<"FAILO SUKURIMAS IR UZDARYMAS - " << t/1000 <<" s" << '\n';
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
void skaidymas(std::list <std::string> splited);
void eil_po_eil(std::string read_vardas, std::string write_vardas,int &b) {
    auto start = std::chrono::high_resolution_clock::now();
    std::string eil;
    std::ifstream open_f(read_vardas);
    std::list<std::string> splited;
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
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    double t = (duration.count());
    cout << "FAILO NUSKAITYMAS - " << t/1000<<" s" << '\n';
    skaidymas(splited,b);
    
}

void skaidymas(std::list <std::string> splited,int b) {
    std::string eil;
    auto it = splited.begin();
    for (int i = 1; i < b-1; i++) {
        eil = *it;
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
        std::advance(it,1);
    }
    dalijimas(mokiniai, paz, vargsiukai, moksliukai);
    isvestis(mokiniai, paz,vargsiukai,moksliukai);
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
void dalijimas(std::list<data>& mok, int paz, std::list<data>& vargsiukai, std::list<data>& moksliukai) {
    auto start = std::chrono::high_resolution_clock::now();
    int i = 0;
    std::sort(mok.begin(), mok.end()) {
        return d1.vardas < d2.vardas;
        });
    for (data& m : mok) {
        m.rezult = m.rezult / m.n * 0.4 + 0.6 * m.egz;
        if (m.rezult < 5) {
            vargsiukai.push_back(m);
            vargsk++;
        }
        else {
            mok.push_back(m);
            mokslsk++;
        }
        i++;
    }
    //for (int i = 0; i < mokslsk + vargsk; i++) mok.pop_front();
    auto mid = mok.begin();
    std::advance(mid, mokslsk + vargsk);
    mok.erase(mok.begin(),mid);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    double t = (duration.count());
    cout << "STUDENTU RUSIAVIMAS - " << t/1000 << " s" << '\n';
}
void isvestis(std::list<data>& mok, int paz, std::list<data>& vargsiukai, std::list<data>& moksliukai)
{   
    std::stringstream vargsai;
    std::stringstream mokslai;
    auto start = std::chrono::high_resolution_clock::now();
    vargsai << std::setw(20) << "Vardas" <<std:: setw(20) << "Pavarde" <<std:: setw(20) << "Galutinis (Vid.)" <<std:: setw(20) << "Galutinis (Med.)" <<'\n';
    vargsai << "----------------------------------------------------------------------------------------" <<std:: endl;
    mokslai << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << '\n';
    mokslai << "----------------------------------------------------------------------------------------" << std::endl;
    int i = 0;
    
    for (data& m : vargsiukai)
    {
        rikiavimas(vargsiukai, i, paz);
        vargsai << std::setw(20) << m.vardas << std::setw(20) << m.pavarde  << std::setw(10) <<std::fixed<< std::setprecision(2) << m.rezult << std::setw(25) <<std::fixed<< std::setprecision(2) << m.med << '\n';
        i++;
    }
    i = 0;
    for (data& m : mok)
    {
       rikiavimas(mok, i, paz);
       mokslai << std::setw(20) << m.vardas << std::setw(20) << m.pavarde << std::setw(10) << std::fixed << std::setprecision(2) << m.rezult << std::setw(25) << std::fixed << std::setprecision(2) << m.med << '\n';
       i++;
    }
    std::ofstream out_v("vargsiukai.txt");
    std::ofstream out_m("moksliukai.txt");
    out_v << vargsai.str();
    out_m << mokslai.str();
    out_v.close();
    out_m.close();
    mokiniai.clear();
    vargsiukai.clear();
    moksliukai.clear();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    double t = (duration.count());
    cout << "STUDENTU ISVEDIMAS - " << t/1000 <<" s" << '\n';
}
void rikiavimas(std::list<data>& mok, int a, int paz)
{   
   // auto b = mok.begin();
    //std::advance(b, a);
    int laikinas;
    //std::vector<int> c = b->paz;
    //std::sort(std::begin(c), std::end(c),[](int a, int b) { return a < b; });
    auto it = mok.begin();
    std::advance(it, a);
    //int mokinys = *it;
    for (int i = 0; i < paz;i++) {
        for (int j=0;j < paz;j++)
        {
            if (it->paz[i] > it->paz[j])
            {
                laikinas = it->paz[i];
                it->paz[i] = it->paz[j];
                it->paz[j] = laikinas;
            }
        }
        if (it->n % 2 == 0) {
             it->med = (it->paz[it->n / 2] + it->paz[(it->n / 2) - 1]) * 0.5;
        }
        else  it->med =  it->paz[it->n / 2];
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