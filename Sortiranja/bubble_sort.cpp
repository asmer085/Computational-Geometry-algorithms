#include <iostream>

using namespace std;

void bubble_sort(int niz[], int duzina)
{
    for(int i = 0 ; i < duzina; i++)
    {
        for(int j = i + 1; j < duzina; j++)
        {
            //mijenja pozicije dva elementa ukoliko je element
            //na j poziciji u nizu manji od elementa na i poziciji
            if(niz[i] > niz[j])  { swap(niz[i], niz[j]); }
        }
    }
}// f

int main()
{
    int niz[10]{9,0,8,1,7,2,6,3,5,4};
    bubble_sort(niz, sizeof(niz)/sizeof(niz[0]));
    for(int i = 0; i < sizeof(niz)/sizeof(niz[0]); i++)
    {
        cout << niz[i] << " ";
    }
}
