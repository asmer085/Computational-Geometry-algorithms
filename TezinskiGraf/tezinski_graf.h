#ifndef TEZINSKI_GRAF_H
#define TEZINSKI_GRAF_H

#include <vector>
#include <list>
#include <utility>
using namespace std;

class TezinskiGraf {
    int n;
    bool usmjeren;
    vector<list<pair<int,double>>> lista_susjedstva;

public:
    TezinskiGraf(int broj_cvorova, bool usmjeren = false);
    void dodajGranu(int i, int j, double tezina);
    vector<double> Dijkstra(int pocetni);
    vector<double> DijkstraBrzo(int pocetni);
    pair<bool, vector<double>> BelmanFord(int pocetni);
    pair<double, vector<pair<int,int>>> MSTPrim();
    pair<double, vector<pair<int,int>>> MSTKruskal();
    double maksimalanProtok(int pocetni, int krajnji);
};

class DisjunktniSkupovi {

    int n;
    vector<int> roditelj;

    public:
    DisjunktniSkupovi(int broj_cvorova):n(broj_cvorova) {
        for(int i = 0; i < n; i++)
            roditelj.push_back(i);
    }

    int Nadji(int cvor) {
        if(roditelj[cvor] == cvor)
            return cvor;
        roditelj[cvor] = Nadji(roditelj[cvor]);
        return roditelj[cvor];
    }

    void Spoji(int i, int j) {
        roditelj[roditelj[i]] = roditelj[j];
    }


};

#endif // TEZINSKI_GRAF_H
