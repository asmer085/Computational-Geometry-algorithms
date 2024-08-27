#include <iostream>

using namespace std;

void selection_sort(int niz[], int duzina)
{
    int index_najmanjeg;

    for(int i = 0; i < duzina - 1; i++)
    {
        index_najmanjeg = i;
        //prolazi kroz niz i trazi index elementa koji je manji od
        //elementa niza sa indexom i
        for(int j = i + 1; j < duzina; j++)
        {
            //ukoliko postoji takav element novi najmanji index postaje
            //index tog elementa
            if(niz[j] < niz[index_najmanjeg])  { index_najmanjeg = j; }
        }
        //mijenja trenutni element sa najmanjim u ostatku niza
        swap(niz[i], niz[index_najmanjeg]);
    }
}// f

int main()
{
    int niz[10]{9,0,8,1,7,2,6,3,5,4};
    selection_sort(niz, sizeof(niz)/sizeof(niz[0]));
    for(int i = 0; i < sizeof(niz)/sizeof(niz[0]); i++)
    {
        cout << niz[i] << " ";
    }
}
