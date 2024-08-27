#include <iostream>

using namespace std;

void quick_sort(int niz[], int lijevi, int desni) {

    int i = lijevi, j = desni;
    //odredjivanje pivot elementa
    //u ovom slucaju uzima se srednji element za pivot
    int pivot = niz[(lijevi + desni) / 2];
    //podjela
    while(i <= j)
    {
        while (niz[i] < pivot)  { i++; }  //pomjera i dok ne nadje element niza koji je veci od pivota
        while (niz[j] > pivot)  { j--; }  //pomjera j dok ne nadje element niza koji je manji od pivota
        if (i <= j)
        {
            //mijenja dva elementa u nizu
            //tako da element lijevo postaje element manji od pivota, a desno veci od pivota
            swap(niz[i], niz[j]);
            i++;
            j--;
        }
    }
    //rekurzivno sortiranje dijelova niza
    if (lijevi < j)  { quick_sort(niz, lijevi, j); }
    if (i < desni)  { quick_sort(niz, i, desni); }
}// f

int main()
{
    int niz[10]{9,0,8,1,7,2,6,3,5,4};
    quick_sort(niz, 0, 9);
    for(int i = 0; i < sizeof(niz)/sizeof(niz[0]); i++)
    {
        cout << niz[i] << " ";
    }
}
