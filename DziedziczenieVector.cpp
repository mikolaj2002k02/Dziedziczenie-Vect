#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class towar
{
    int numer_id();
    int cena();
    int wartosc_firmy();
    string nazwa_gry();
    string nazwa_firmy();
    string kolekcja_gier();
    string kolekcja_firm();
public:
    void wprowadz();
    void wypisz();
};

//...... tu body funkcji:

class gra : public towar
{
    int numer_id;
    string cena, nazwa_gry;
public:
    void wypisz_gra()
    {
        cout << "numer id gry: " "  " << numer_id << endl;
        cout << "nazwa gry: " "  " << nazwa_gry << endl;
        cout << "cena gry: " "  " << cena << endl;
        wypisz();
    }
    void wprowadz()
    {
    }
};
class firma : public towar
{
    int numer_id, wartosc_firmy;
    string nazwa_firmy;
public:
    void wypisz_firma()
    {
        cout << "numer id firmy: " << numer_id << endl;
        cout << "nazwa firmy: " << nazwa_firmy << endl;
        cout << "wartosc firmy: " << wartosc_firmy << endl;
        wypisz();

    }
    void wprowadz()
    {
    }
};

class klasa
{
    vector <struct towar> spis;

public:
    void wprowadz();
    void wypisz();
    void zapiszDoPliku(const char*);
    //              void wczytajZPliku(const char *);                
};


void klasa::wprowadz()
{
    int ilosctowaru;
    struct towar wprowadzany;
    cout << "Ilosc uczniow: ";
    cin >> ilosctowaru;
    for (int i = 0; i < ilosctowaru; i++)
    {
        cout << "Id_Gry Nazwa Cena Id_Firmy Nazwa Wartosc: ";
        cin >> wprowadzany.numer_id
            >> wprowadzany.nazwa_gry
            >> wprowadzany.cena
            >> wprowadzany.wartosc_firmy
            >> wprowadzany.nazwa_firmy;
        spis.push_back(wprowadzany); //TU WSTAW do tablicy nowy rekord
    }
}

void klasa::wypisz()
{
    for (vector<struct towar>::iterator it = spis.begin(); it != spis.end(); ++it)
    {
        cout << it->numer_id << " "
            << it->nazwa_gry << " "
            << it->cena << ""
            << it->wartosc_firmy << ""
            << it->nazwa_firmy << "\n";
    }
}

void klasa::zapiszDoPliku(const char* nazwa)
{
    ofstream plik;
    plik.open(nazwa);
    for (vector<struct towar>::iterator it = spis.begin(); it != spis.end(); ++it)
    {
        plik << it->numer_id << " "
            << it->nazwa_gry << " "
            << it->cena << ""
            << it->wartosc_firmy << ""
            << it->nazwa_firmy << "\n";
    }
    plik.close();
}


int main()
{
    klasa T1;
    T1.wprowadz();
    T1.wypisz();
    T1.zapiszDoPliku("c:\\do.txt");
    gra g1;
    g1.wprowadz();
    g1.wypisz_gra();
    firma f1;
    f1.wprowadz();
    f1.wypisz_firma();


    return 0;
};
