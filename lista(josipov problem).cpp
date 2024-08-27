#include <iostream>

using namespace std;

struct Cvor
{
    int vrijednost;
    Cvor *sljedeci;
    Cvor(int vrijednost) : vrijednost(vrijednost), sljedeci(nullptr) {}
};

int josipov_problem(int interval, int ukupan_broj)
{
    Cvor *head = new Cvor(1);
    Cvor *pomocni = head;
    for(int i = 2; i <= ukupan_broj; i++)
    {
        pomocni -> sljedeci = new Cvor(i);
        pomocni = pomocni -> sljedeci;
    }
    pomocni -> sljedeci = head;

    Cvor *trenutni = head;
    Cvor *prethodni = head;
    while (trenutni -> sljedeci != trenutni)
    {
        int brojac = 1;
        while(brojac != interval)
        {
            prethodni = trenutni;
            trenutni = trenutni -> sljedeci;
            brojac++;
        }

        prethodni -> sljedeci = trenutni -> sljedeci;
        trenutni = prethodni -> sljedeci;
    }

    return trenutni -> vrijednost;
}

int main()
{
    int n = 5, m = 3;
    cout << josipov_problem(m, n);
}
