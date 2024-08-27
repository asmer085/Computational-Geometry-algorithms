#include<iostream>
#include <list>

using namespace std;

class Hash
{
    int velicina;  //Broj slotova u tabeli
    list<int> *tabela;
public:
    Hash(int velicina);
    void ubaci(int element);
    void izbrisi(int kljuc);
    //Hash funkcija koristi modul kao hash funkciju
    int hash_funkcija(int element)
    {
        return (element % velicina);
    }
    void ispisi_tabelu();
};

Hash::Hash(int velicina)
{
    this -> velicina = velicina;
    tabela = new list<int>[velicina];
}

void Hash::ubaci(int kljuc)
{
    int index = hash_funkcija(kljuc);
    tabela[index].push_back(kljuc);
}

void Hash::izbrisi(int kljuc)
{
    int index = hash_funkcija(kljuc);
    //pronalazak kljuca u listi
    list <int> :: iterator i;
    for (i = tabela[index].begin(); i != tabela[index].end(); i++)
    {
        if (*i == kljuc)  { break; }
    }
    //ako kljuc postoji u tabeli, brise se iz tabele
    if (i != tabela[index].end())  { tabela[index].erase(i); }

}

void Hash::ispisi_tabelu() {
    for (int i = 0; i < velicina; i++)
    {
        cout << "[" << i << "]";
        for (auto x : tabela[i])
        {
            cout << " o-> " << "(" << x << ")";
        }
        cout << endl;
    }
}

int main()
{

}
