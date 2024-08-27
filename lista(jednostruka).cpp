#include <iostream>

using namespace std;

struct Cvor
{
    int vrijednost;
    Cvor* sljedeci;
    Cvor(int n) : vrijednost(n), sljedeci(nullptr) {}
};

class Lista
{
private:
    int duzina;
    Cvor* head;
    Cvor* tail;
public:
    Lista() : duzina(0), head(nullptr), tail(nullptr) {}
    int get_duzina() { return duzina; };
    void dodaj_element(int vrijednost);
    void ispis_liste();
    void dodaj_na_pocetak(int vrijednost);
    void dodaj_na_kraj(int vrijednost);
    void izbrisi_vrijednost(int n);
    void izbrisi_cvor(Cvor* brisanje);
    void zamjeni_element(int x, int y);
    void inverz();
};

void Lista::dodaj_element(int vrijednost)
{
    Cvor *pomocni = new Cvor(vrijednost);
    if(head == nullptr)
    {

        head = pomocni;
        tail = pomocni;
    }
    else
    {
        tail -> sljedeci = pomocni;
        tail = tail -> sljedeci;
    }
    duzina++;
}

void Lista::ispis_liste()
{
    Cvor* trenutni = head;
    if(duzina == 0)  { cout << "Lista je prazna" << endl; return; }
    while(trenutni != nullptr)
    {
        cout << trenutni -> vrijednost << endl;
        trenutni = trenutni -> sljedeci;
    }
    cout << "Duzina liste: " << duzina << endl;
}

void Lista::dodaj_na_pocetak(int vrijednost)
{
    Cvor* pomocni = new Cvor(vrijednost);
    pomocni -> sljedeci = head;
    head = pomocni;
    duzina++;
}

void Lista::izbrisi_vrijednost(int n)
{
    if(head -> vrijednost == n)
    {
        Cvor* pomocni = head;
        head = pomocni -> sljedeci;
        delete pomocni;
        duzina--;
        return;
    }
    else
    {
        Cvor *trenutni = head -> sljedeci;
        Cvor *prije = head;
        while(trenutni != nullptr)
        {
            if(trenutni -> vrijednost == n)
            {
                prije -> sljedeci = trenutni -> sljedeci;
                delete trenutni;
            }
            trenutni = trenutni -> sljedeci;
            prije = prije -> sljedeci;
        }
    }
    duzina--;
}

void Lista::izbrisi_cvor(Cvor* brisanje)
{
    Cvor* trenutni = head;
    while(trenutni != nullptr)
    {
        if(trenutni = brisanje)
        {
            Cvor* zamjena = brisanje -> sljedeci;
            brisanje -> sljedeci = zamjena -> sljedeci;
            delete zamjena;
        }
    }
}

void Lista::zamjeni_element(int x, int y)
{
    if(x == y) { cout << "Unijeti elementi su isti" << endl; }

    Cvor* trenutnaX = head;
    while(trenutnaX != nullptr && trenutnaX -> sljedeci -> vrijednost != x)
    {
        trenutnaX = trenutnaX -> sljedeci;
    }

    Cvor* trenutnaY = head;
    while(trenutnaY != nullptr && trenutnaY -> sljedeci -> vrijednost != y)
    {
        trenutnaY = trenutnaY -> sljedeci;
    }

    if(trenutnaX == nullptr || trenutnaY == nullptr)  { return; }

    Cvor* pomocniX = trenutnaX -> sljedeci;
    Cvor* pomocniY = trenutnaY -> sljedeci;
    Cvor* pomocni = pomocniX -> sljedeci;
    pomocniX -> sljedeci = pomocniY -> sljedeci;
    trenutnaY -> sljedeci = pomocniX;
    pomocniY -> sljedeci = pomocni;
    trenutnaX -> sljedeci = pomocniY;

}

void Lista::inverz()
{
    Cvor* prethodni = nullptr;
    Cvor* trenutni = head;
    Cvor* sljedeci = nullptr;

    while(trenutni != nullptr)
    {
        sljedeci = trenutni -> sljedeci;
        trenutni -> sljedeci = prethodni;
        prethodni = trenutni;
        trenutni = sljedeci;
    }
    head = prethodni;
}
/**************************** main ****************************/

int main()
{

}
