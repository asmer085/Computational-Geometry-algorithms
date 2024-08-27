#include <iostream>

using namespace std;

// funkcija sto vraca maksimalnu vrijednost u nizu
int daj_maksimum(int niz[], int duzina)
{
    int maks = niz[0];
    for(int i = 1; i < duzina; i++)
    {
        if (niz[i] > maks)
        maks = niz[i];
    }
    return maks;
}

// funkcija koja koristi counting sort
void count_sort(int niz[], int duzina, int exp)
{
    int pomocni[duzina];
    int count[10] = {0};

    // broj ponavljanja
    for(int i = 0; i < duzina; i++)
    {
        count[ (niz[i] / exp) % 10 ]++;
    }
    //Pomjeranje pozicija tako da odgovara izlaznom nizu
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    //Konstrukcija izlaznog niza
    for (int i = duzina - 1; i >= 0; i--)
    {
        pomocni[count[ (niz[i] / exp) % 10 ] - 1] = niz[i];
        count[ (niz[i] / exp) % 10 ]--;
    }
    //kopiranje pomocnog niza u ulazni niz
    for (int i = 0; i < duzina; i++)
    {
        niz[i] = pomocni[i];
    }
}

//glavna funkcija za radix sortiranje
void radix_sort(int niz[], int duzina)
{
    //Pronalazak maksimalnog elementa
    //kako bi se pronasao maksimalni broj cifara
    int maks = daj_maksimum(niz, duzina);

    //radi count sort za svaku cifru
    for (int exp = 1; maks / exp > 0; exp *= 10)
        count_sort(niz, duzina, exp);
}// f

int main()
{
    int niz[10]{9,0,8,1,7,2,6,3,5,4};
    radix_sort(niz, sizeof(niz)/sizeof(niz[0]));
    for(int i = 0; i < sizeof(niz)/sizeof(niz[0]); i++)
    {
        cout << niz[i] << " ";
    }
}
