#include <iostream>

using namespace std;

template<class Tip>

class Stablo
{
private:
    struct Cvor
    {
        Cvor *lijevi, *desni;
        Tip vrijednost;
        int visina;

        Cvor(Tip vrijednost) : vrijednost{vrijednost}, visina{0}, lijevi{nullptr}, desni{nullptr} {}
    };

    Cvor* korijen;

    //Umetanje elementa
    void Umetni(Cvor*& pok, Tip vrijednost);
    //Balansiranje stabla
    void Balansiraj(Cvor*& pok);
    int Visina(Cvor* pok) const { return (pok != nullptr) ? pok -> visina : -1;}

    //Rotacione funkcije za balansiranje
    void rotirajLijevo(Cvor*& pok);
    void rotirajDesno(Cvor*& pok);
    void duploRotirajLijevo(Cvor*& pok);
    void duploRotirajDesno(Cvor*& pok);

    //Briasanje elementa
    void Brisi(Tip vrijednost, Cvor*& pok);

    //Trazenje najmanjeg elementa
    Tip minimum(Cvor* pok)
    {
        while(pok -> lijevi != nullptr)  { pok = pok -> lijevi; }
        return pok -> vrijednost;
    }

    void inOrder(Cvor* pok, void (*akcija)(Tip&));
    void inOrderVisine(Cvor* pok);
public:
    Stablo() : korijen{nullptr} {}

    //funkcije koje pozivaju privatne funkcije
    void Umetni(Tip vrijednost) { Umetni(korijen, vrijednost); }
    void Brisi(Tip vrijednost) { Brisi(vrijednost, korijen); }

    //inOrder ispisivanje
    void inOrder(void (*akcija)(Tip&)) { inOrder(korijen, akcija); }
    void inOrderVisine() { inOrderVisine(korijen); }

};

/************************************************************************************/

//Funkcija za umetanje novog elementa
template<class Tip>
void Stablo<Tip>::Umetni(Cvor*& pok, Tip vrijednost)
{
    if(pok == nullptr)  { pok = new Cvor(vrijednost); }
    else if(vrijednost < pok -> vrijednost)  { Umetni(pok -> lijevi, vrijednost); }
    else  { Umetni(pok -> desni, vrijednost); }

    //Balansira stablo ako nije balansirano poslije umetanja
    Balansiraj(pok);
}

/************************************************************************************/

//Ispisuje sve elemente od najmanjeg ka najvecem
template<class Tip>
void Stablo<Tip>::inOrder(typename Stablo<Tip>::Cvor* pok, void (*akcija)(Tip&))
{
    if(pok == nullptr) { return; }

    inOrder(pok -> lijevi, akcija);
    akcija(pok -> vrijednost);
    inOrder(pok -> desni, akcija);
}

/************************************************************************************/

//Ispisuje visine svakog elementa (od najmanjeg ka najveceg elementa)
template<class Tip>
void Stablo<Tip>::inOrderVisine(typename Stablo<Tip>::Cvor* pok)
{
    if(pok == nullptr) { return; }

    inOrderVisine(pok -> lijevi);
    cout << pok -> visina << " ";
    inOrderVisine(pok -> desni);
}

/************************************************************************************/

//Funkcija za balansiranje stabla
template<class Tip>
void Stablo<Tip>::Balansiraj(typename Stablo<Tip>::Cvor*& pok)
{
    if(pok == nullptr) { return; }

        //LIJEVO
    if(Visina(pok -> lijevi) - Visina(pok -> desni) > 1)
    {
            //->LIJEVO
        if(Visina(pok -> lijevi -> lijevi) >= Visina(pok -> lijevi -> desni))
        {
            rotirajLijevo(pok);
        }
            //->DESNO
        else
        {
            duploRotirajLijevo(pok);
        }
    }//end if

        //DESNO
    else if(Visina(pok -> desni) - Visina(pok -> lijevi) > 1)
    {
            //->LIJEVO
        if(Visina(pok -> desni -> desni) >= Visina(pok -> desni -> lijevi))
        {
            rotirajDesno(pok);
        }
            //->DESNO
        else
        {
            duploRotirajDesno(pok);
        }
    }//end else

    pok -> visina = max(Visina(pok -> lijevi), Visina(pok -> desni)) + 1;
}

/************************************************************************************/
//Funkcije rotiranja koje koristima za balansiranje stabla

template<class Tip>
void Stablo<Tip>::rotirajLijevo(typename Stablo<Tip>::Cvor*& pok)
{
    Cvor* pok1 = pok -> lijevi;
    pok -> lijevi = pok1 -> desni;
    pok1 -> desni = pok;

    pok -> visina = max(Visina(pok -> lijevi), Visina(pok -> desni)) + 1;
    pok1 -> visina = max(Visina(pok1 -> lijevi), Visina(pok)) + 1;

    pok = pok1;
}

/************************************************************************************/

template<class Tip>
void Stablo<Tip>::rotirajDesno(typename Stablo<Tip>::Cvor*& pok)
{
    Cvor* pok1 = pok -> desni;
    pok -> desni = pok1 -> lijevi;
    pok1 -> lijevi = pok;

    pok -> visina = max(Visina(pok -> lijevi), Visina(pok -> desni)) + 1;
    pok1 -> visina = max(Visina(pok1 -> desni), Visina(pok)) + 1;

    pok = pok1;
}

/************************************************************************************/

template<class Tip>
void Stablo<Tip>::duploRotirajLijevo(typename Stablo<Tip>::Cvor*& pok)
{
    rotirajDesno(pok -> lijevi);
    rotirajLijevo(pok);
}

/************************************************************************************/

template<class Tip>
void Stablo<Tip>::duploRotirajDesno(typename Stablo<Tip>::Cvor*& pok)
{
    rotirajLijevo(pok -> desni);
    rotirajDesno(pok);
}

/************************************************************************************/

//Funkcija za brisanje elementa
template<class Tip>
void Stablo<Tip>::Brisi(Tip vrijednost, typename Stablo<Tip>::Cvor*& pok)
{
    if(pok == nullptr) return;

    if(vrijednost < pok -> vrijednost)
    {
        Brisi(vrijednost, pok -> lijevi);
    }
    else if(vrijednost > pok -> vrijednost)
    {
        Brisi(vrijednost, pok -> desni);
    }

        //Nasli smo cvor sa ppba djeteta
    else if(pok -> lijevi != nullptr && pok -> desni != nullptr)
    {
        pok -> vrijednost = minimum(pok -> desni);
        Brisi(pok -> vrijednost, pok -> desni);
    }//end else if
    else
    {
        Cvor* zaBrisanje = pok;
        pok = (pok -> lijevi != nullptr) ? pok -> lijevi : pok -> desni;
        delete zaBrisanje;
    }//end else

    //Balansiramo ako nije balansirano poslije brijsanja
    Balansiraj(pok);
}

/************************************************************************************/
/************************************************************************************/

void print(int& a)
{
    cout << a << " ";
}

/************************************************************************************/
/************************************************************************************/

int main()
{

}
