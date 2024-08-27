#include <iostream>

using namespace std;

void spoji(int niz[], int lijevi_lijevi, int lijevi_desni, int desni_lijevi, int desni_desni)
{
    int duzina = desni_desni - lijevi_lijevi + 1;
    int pomocni[duzina];

    int pom_lijeva = lijevi_lijevi;
    int pom_desna = desni_lijevi;

    for(int i = 0; i < duzina; ++i) {
        if (pom_lijeva > lijevi_desni)
        {
            pomocni[i] = niz[pom_desna++];
        }
        else if (pom_desna > desni_desni)  { pomocni[i] = niz[pom_lijeva++]; }
        else if (niz[pom_lijeva] <= niz[pom_desna])  { pomocni[i] = niz[pom_lijeva++]; }
        else  {pomocni[i] = niz[pom_desna++];}
    }

    for (int i=0; i < duzina; ++i)
        niz[lijevi_lijevi++] = pomocni[i];
}

void merge_sort(int niz[], int lijevi, int desni)
{
    if (lijevi >= desni)  { return; }  //uslov za prekid rekurzije
    else
    {
      int srednji = (lijevi + desni) / 2;   //odredjuje sredinu

      merge_sort(niz, lijevi, srednji);     //sortira rekurzivno lijevu polovicu niza
      merge_sort(niz, srednji + 1, desni);  //sortira rekurzivno desnu polovicu niza

      spoji(niz, lijevi, srednji, srednji + 1, desni);     //spaja sortirane polovice u jedan niz
    }
}

int main()
{
    int niz[10]{9,0,8,1,7,2,6,3,5,4};
    merge_sort(niz, 0, 9);
    for(int i = 0; i < sizeof(niz)/sizeof(niz[0]); i++)
    {
        cout << niz[i] << " ";
    }
}
