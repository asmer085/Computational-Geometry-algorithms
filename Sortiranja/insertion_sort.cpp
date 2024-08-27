#include <iostream>

using namespace std;

void insertion_sort(int niz[], int duzina)
{
    for (int i = 1; i < duzina; i++)
    {
        int pomocna = niz[i];
        int j = i-1;

        //ubacuje pomocnu u lijevi dio niza
        //tako da lijevi dio niza ostane sortiran
        while (j >= 0 && niz[j] > pomocna)
        {
            niz[j + 1] = niz[j];
            j--;
        }
        niz[j + 1] = pomocna;
    }
}// f

int main()
{
    int niz[10]{9,0,8,1,7,2,6,3,5,4};
    insertion_sort(niz, sizeof(niz)/sizeof(niz[0]));
    for(int i = 0; i < sizeof(niz)/sizeof(niz[0]); i++)
    {
        cout << niz[i] << " ";
    }
}


