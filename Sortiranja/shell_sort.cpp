#include <iostream>

using namespace std;

int shell_sort(int niz[], int duzina)
{
    //odredjuje opadajuci niz brojeva po kojima ce se niz sortirat
    for (int broj = duzina / 2; broj > 0; broj /= 2)
    {
        for (int i = broj; i < duzina; i++)
        {
            int pomocna = niz[i];

            int j;
            for (j = i; j >= broj && niz[j - broj] > pomocna; j -= broj)
            {
                niz[j] = niz[j - broj];
            }
            niz[j] = pomocna;
        }
    }
}// f

int main()
{
    int niz[10]{9,0,8,1,7,2,6,3,5,4};
    shell_sort(niz, sizeof(niz)/sizeof(niz[0]));
    for(int i = 0; i < sizeof(niz)/sizeof(niz[0]); i++)
    {
        cout << niz[i] << " ";
    }
}
