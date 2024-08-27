#include <iostream>

using namespace std;

struct Cvor
{
    int vrijednost;
    Cvor* lijevi;
    Cvor* desni;
    Cvor(int n) : vrijednost(n), lijevi(nullptr), desni(nullptr) {}
};

class Stablo
{
private:
    Cvor* korijen;
    int broj_elemenata;

    void dodaj_element(int element, Cvor* trenutni);
    bool postoji_element(Cvor *trenutni, int element);
    void inorder(Cvor* trenutni);
    void preorder(Cvor* trenutni);
    void postorder(Cvor* trenutni);
    int visina_stabla(Cvor* trenutni);
    int suma_stabla(Cvor* trenutni);
    int proizvod_stabla(Cvor* trenutni);
    int najmanji_element(Cvor* trenutni);
    int najveci_element(Cvor* trenutni);
    int broj_potpunih_cvorova(Cvor* trenutni);
    int broj_listova(Cvor* trenutni);
    int minimalna_dubina(Cvor* trenutni);

public:
    Stablo() : korijen(nullptr), broj_elemenata(0) {}

    int get_broj_elemenata() { return broj_elemenata; }
    void dodaj_element(int element);
    bool postoji_element(int element);

    void inorder();
    void preorder();
    void postorder();

    int visina_stabla();
    int suma_stabla();
    int proizvod_stabla();
    int najmanji_element();
    int najveci_element();
    int broj_potpunih_cvorova();
    int broj_listova();
    int minimalna_dubina();
};

void Stablo::dodaj_element(int element)
{
    if(korijen == nullptr)
    {
        korijen = new Cvor(element);
        broj_elemenata++;
        return;
    }
    else  { dodaj_element(element, korijen); }
    broj_elemenata++;
}

void Stablo::dodaj_element(int element, Cvor* trenutni)
{
    if(element <= trenutni -> vrijednost)
    {
        if(trenutni -> lijevi == nullptr)
        {
            trenutni -> lijevi = new Cvor(element);
        }
        else  { dodaj_element(element, trenutni -> lijevi); }
    }

    if(element > trenutni -> vrijednost)
    {
        if(trenutni -> desni == nullptr)
        {
            trenutni -> desni = new Cvor(element);
        }
        else  {dodaj_element(element, trenutni -> desni); }
    }
}

void Stablo::inorder()
{
    if(korijen == nullptr)  { return; }
    else  { inorder(korijen); }
}

void Stablo::inorder(Cvor* trenutni)
{
    if(trenutni == nullptr)  { return; }
    inorder(trenutni -> lijevi);
    cout << trenutni -> vrijednost << " ";
    inorder(trenutni -> desni);
}

void Stablo::preorder()
{
    if(korijen == nullptr)  { return; }
    else  { preorder(korijen); }
}

void Stablo::preorder(Cvor* trenutni)
{
    if(trenutni == nullptr)  { return; }
    cout << trenutni -> vrijednost << " ";
    preorder(trenutni -> lijevi);
    preorder(trenutni -> desni);
}

void Stablo::postorder()
{
    if(korijen == nullptr)  { return; }
    else  { postorder(korijen); }
}

void Stablo::postorder(Cvor* trenutni)
{
    if(trenutni == nullptr)  { return; }
    postorder(trenutni -> lijevi);
    postorder(trenutni -> desni);
    cout << trenutni -> vrijednost << " ";
}

int Stablo::visina_stabla()
{
    if(korijen == nullptr)  { return -1; }
    visina_stabla(korijen);
}

int Stablo::visina_stabla(Cvor* trenutni)
{
    if(trenutni == nullptr)  { return 0; }
    int visina_lijevog = visina_stabla(trenutni -> lijevi);
    int visina_desnog = visina_stabla(trenutni -> desni);
    if(visina_lijevog >= visina_desnog)
    {
        return 1 + visina_lijevog;
    }
    else
    {
        return 1 + visina_desnog;
    }
}

int Stablo::suma_stabla()
{
    if(korijen == nullptr)  { return 0; }
    else { return suma_stabla(korijen); }
}

int Stablo::suma_stabla(Cvor* trenutni)
{
    if(trenutni == nullptr)  { return 0; }
    else  { return suma_stabla(trenutni -> lijevi) +
                   suma_stabla(trenutni -> desni) +
                   trenutni -> vrijednost;
          }
}

int Stablo::proizvod_stabla()
{
    if(korijen == nullptr)  { return 0; }
    else { return proizvod_stabla(korijen); }
}

int Stablo::proizvod_stabla(Cvor* trenutni)
{
    if(trenutni == nullptr)  { return 1; }
    else  { return proizvod_stabla(trenutni -> lijevi) *
                   proizvod_stabla(trenutni -> desni) *
                   trenutni -> vrijednost;
          }
}

int Stablo::najmanji_element()
{
    if(korijen == nullptr)  { return -1; }
    else  { return najmanji_element(korijen); }
}

int Stablo::najmanji_element(Cvor* trenutni)
{
    if(trenutni -> lijevi == nullptr)  { return trenutni -> vrijednost; }
    else  { return najmanji_element(trenutni -> lijevi); }
}

int Stablo::najveci_element()
{
    if(korijen == nullptr)  { return -1; }
    else  { return najveci_element(korijen); }
}

int Stablo::najveci_element(Cvor* trenutni)
{
    if(trenutni -> desni == nullptr)  { return trenutni -> vrijednost; }
    else  { return najveci_element(trenutni -> desni); }
}

int Stablo::broj_potpunih_cvorova()
{
    if(korijen == nullptr)  { return 0; }
    else  { return broj_potpunih_cvorova(korijen); }
}

int Stablo::broj_potpunih_cvorova(Cvor* trenutni)
{
    if(trenutni -> lijevi == nullptr || trenutni -> desni == nullptr)  { return 0; }
    else  { return 1 +
            broj_potpunih_cvorova(trenutni -> lijevi) +
            broj_potpunih_cvorova(trenutni -> desni);
          }
}

int Stablo::broj_listova()
{
    if(korijen == nullptr)  { return 0; }
    else  { return broj_listova(korijen); }
}

int Stablo::broj_listova(Cvor* trenutni)
{
    if(trenutni == nullptr)  { return 0; }
    if(trenutni -> lijevi == nullptr && trenutni -> desni == nullptr)  { return 1; }
    else  {
            return
            broj_listova(trenutni -> lijevi) +
            broj_listova(trenutni -> desni);
          }
}

int Stablo::minimalna_dubina()
{
    if(korijen == nullptr)  { return 0; }
    else  { return minimalna_dubina(korijen); }
}

int Stablo::minimalna_dubina(Cvor* trenutni)
{
    if(trenutni -> lijevi == nullptr && trenutni -> desni == nullptr)  { return 1; }
    if(trenutni -> lijevi == nullptr && trenutni -> desni != nullptr)
    {
        return minimalna_dubina(trenutni -> desni) + 1;
    }
    if(trenutni -> lijevi != nullptr && trenutni -> desni == nullptr)
    {
        return minimalna_dubina(trenutni -> lijevi) + 1;
    }
    else  { return min(minimalna_dubina(trenutni -> lijevi), minimalna_dubina(trenutni -> desni)) + 1; }
}

bool Stablo::postoji_element(int element)
{
    if(korijen == nullptr)  { return false; }
    else  { return postoji_element(korijen, element); }
}
bool Stablo::postoji_element(Cvor *trenutni, int element)
{
    if(trenutni == nullptr)  { return false; }
    if(trenutni -> vrijednost == element)  { return true; }
    if(trenutni -> vrijednost >= element)  { return postoji_element(trenutni -> lijevi, element); }
    if(trenutni -> vrijednost < element)  { return postoji_element(trenutni -> desni, element); }
}

int main()
{

}
