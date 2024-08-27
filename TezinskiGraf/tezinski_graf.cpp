#include "tezinski_graf.h"
#include <climits>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

TezinskiGraf::TezinskiGraf(int broj_cvorova, bool usmjeren):n(broj_cvorova), usmjeren(usmjeren) {
    lista_susjedstva.resize(n);
}

void TezinskiGraf::dodajGranu(int i, int j, double tezina) {
    lista_susjedstva[i].push_back({j,tezina});
    if(!usmjeren)
        lista_susjedstva[j].push_back({i,tezina});
}

vector<double> TezinskiGraf::Dijkstra(int pocetni) {
    vector<double> udaljenosti(n, INT_MAX);
    udaljenosti[pocetni] = 0;
    vector<bool> obradjeni(n, false);
    obradjeni[pocetni] = true;
    int trenutni = pocetni;

    for(int iter = 0; iter < n - 1; iter++) {
        for(auto el: lista_susjedstva[trenutni])
            if(udaljenosti[trenutni] + el.second < udaljenosti[el.first])
               udaljenosti[el.first] = udaljenosti[trenutni] + el.second;

        double minimum = INT_MAX;
        int indeks_minimuma;
        for(int i = 0; i < n; i++)
            if(!obradjeni[i] && udaljenosti[i] < minimum) {
                minimum = udaljenosti[i];
                indeks_minimuma = i;
            }
        obradjeni[indeks_minimuma] = true;
        trenutni = indeks_minimuma;

    }
    return udaljenosti;
}

vector<double> TezinskiGraf::DijkstraBrzo(int pocetni) {
    vector<double> udaljenosti(n, INT_MAX);
    udaljenosti[pocetni] = 0;
    int trenutni = pocetni;
    set<pair<double,int>> stablo;

    for(int iter = 0; iter < n - 1; iter++) {
        for(auto el: lista_susjedstva[trenutni])
            if(udaljenosti[trenutni] + el.second < udaljenosti[el.first]) {
                if(stablo.find({udaljenosti[el.first], el.first}) != stablo.end())
                    stablo.erase({udaljenosti[el.first], el.first});
                udaljenosti[el.first] = udaljenosti[trenutni] + el.second;
                stablo.insert({udaljenosti[el.first], el.first});
            }

        pair<double,int> minimum = *stablo.begin();
        stablo.erase(stablo.begin());
        trenutni = minimum.second;


    }
    return udaljenosti;
}

pair<bool, vector<double>> TezinskiGraf::BelmanFord(int pocetni) {

    vector<double> udaljenosti(n,INT_MAX);
    udaljenosti[pocetni] = 0;

    for(int iteracija = 1; iteracija < n; iteracija++) {

        for(int i = 0; i < n; i++) {
            if(udaljenosti[i] != INT_MAX) {
                for(auto el: lista_susjedstva[i]) {
                    if(udaljenosti[i] + el.second < udaljenosti[el.first])
                        udaljenosti[el.first] = udaljenosti[i] + el.second;
                }
            }
        }
    }

    bool postoji_negativan_ciklus = false;
    for(int i = 0; i < n; i++) {
            if(udaljenosti[i] != INT_MAX) {
                for(auto el: lista_susjedstva[i]) {
                    if(udaljenosti[i] + el.second < udaljenosti[el.first]) {
                        postoji_negativan_ciklus = true;
                        break;
                    }
                }
            }
            if(postoji_negativan_ciklus) break;
    }

    return {postoji_negativan_ciklus, udaljenosti};
}

pair<double, vector<pair<int,int>>> TezinskiGraf::MSTPrim() {
    int pocetni = 0;
    pair<double, vector<pair<int,int>>> MST{0, vector<pair<int,int>>()};
    vector<double> potencijali(n, INT_MAX);
    vector<bool> obradjeni(n, false);
    vector<int> prethodnik(n, -1);
    potencijali[pocetni] = 0;
    obradjeni[pocetni] = true;
    int trenutni = pocetni;
    set<pair<double,int>> s;

    for(int iter = 0; iter < n - 1; iter++) {
        for(auto el: lista_susjedstva[trenutni])
            if(!obradjeni[el.first] && el.second < potencijali[el.first]) {
                prethodnik[el.first] = trenutni;
                if(s.find({potencijali[el.first], el.first}) != s.end())
                    s.erase({potencijali[el.first], el.first});
                potencijali[el.first] = el.second;
                s.insert({potencijali[el.first], el.first});
            }

        pair<double,int> minimum = *s.begin();
        s.erase(s.begin());
        obradjeni[minimum.second] = true;
        MST.first += minimum.first;
        MST.second.push_back({prethodnik[minimum.second], minimum.second});
        trenutni = minimum.second;


    }
    return MST;

}

pair<double, vector<pair<int,int>>> TezinskiGraf::MSTKruskal() {
    pair<double, vector<pair<int,int>>> MST{0, vector<pair<int,int>>()};
    vector<pair<double, pair<int,int>>> grane;
    for(int i = 0; i < n; i++)
        for(auto el: lista_susjedstva[i])
            if(i < el.first)
                grane.push_back({el.second, {i, el.first}});

    sort(grane.begin(), grane.end());
    DisjunktniSkupovi ds(n);

    for(auto grana: grane) {
        int i = grana.second.first;
        int j = grana.second.second;
        if(ds.Nadji(i) != ds.Nadji(j)) {
            ds.Spoji(i, j);
            MST.first += grana.first;
            MST.second.push_back(grana.second);
        }
        if(MST.second.size() == n - 1)
            break;
    }


    return MST;

}

double TezinskiGraf::maksimalanProtok(int pocetni, int krajnji) {
    //najprije pravimo matricu udaljenosti pomocnog grafa i popunjavamo je nulama
    vector<vector<double>> matricaUdaljenosti(n);
    for(int i = 0; i < n; i++)
        matricaUdaljenosti[i].resize(n);

    //sada pravimo listu susjedstva pomocnog grafa
    //bitno je samo da li postoji grana (ne i njen kapacitet)
    //moramo pamtiti i da li je ta grana u originalnom grafu (true ako jeste)
    vector<list<pair<int,bool>>> susjedi(n);
    for(int i=0;i<n;i++)
        for(auto it = lista_susjedstva[i].begin();it!=lista_susjedstva[i].end();it++) {
            susjedi[i].push_back({it->first,true});
            susjedi[it->first].push_back({i,false});
            matricaUdaljenosti[i][it->first] = it->second;
            //na pocetku samo postoji grana od i do it->first koja je jednaka kapacitetu
            //grana u suprotnom smjeru zasad ostaje na 0
        }

    double maksimalan_protok = 0;
    //sada trazimo puteve od pocetnog do krajnjeg u pomocnom grafu
    //kada vise ne bude puteva onda prekidamo petlju
    while(true) {
        //koristimo BFS
        queue<int> red;
        red.push(pocetni);
        //za svaki cvor pamtimo ko ga je pronasao kako bi rekonstruisali put
        //-1 znaci da nije pronadjen, a -2 da se radi o pocetnom cvoru
        //pored toga pamtimo da li ta grana po kojoj je pronadjen pripada originalnom grafu
        vector<pair<int,bool>> ko_ga_je_nasao(n,{-1,false});
        ko_ga_je_nasao[pocetni].first = -2;
        while(!red.empty()) {
            int trenutni = red.front();
            red.pop();
            for(auto it = susjedi[trenutni].begin();it!=susjedi[trenutni].end();it++) {
                //moguce je da u pomocnom grafu postoji grana ali ako je njena tezina 0 to znaci da je u sustini nema
                if(matricaUdaljenosti[trenutni][it->first] == 0)
                    continue;

                if(ko_ga_je_nasao[it->first].first == -1) {
                    red.push(it->first);
                    ko_ga_je_nasao[it->first] = {trenutni,it->second};
                }
            }
            //ako smo vec nasli krajnji nema potrebe dalje traziti
            if(ko_ga_je_nasao[krajnji].first != -1)
                break;
        }
        //ako nema puta znaci da smo nasli najveci protok
        if(ko_ga_je_nasao[krajnji].first == -1)
            break;
        //sada treba rekonstruisati put
        //u putu cuvamo grane i za svaku granu pamtimo da li grana pripada originalnom grafu
        vector<pair<pair<int,int>,bool>> put;
        //usput ćemo i vidjeti koja je najmanja grana na tom putu
        double duzina_najmanje_grane = INT_MAX;
        int trenutni = krajnji;
        do {
            put.push_back({{ko_ga_je_nasao[trenutni].first,trenutni},ko_ga_je_nasao[trenutni].second});
            if(matricaUdaljenosti[ko_ga_je_nasao[trenutni].first][trenutni] < duzina_najmanje_grane)
                duzina_najmanje_grane = matricaUdaljenosti[ko_ga_je_nasao[trenutni].first][trenutni];

            trenutni = ko_ga_je_nasao[trenutni].first;
        } while(trenutni != pocetni);
        //povecavamo protok za vrijednost najmanje grane
        maksimalan_protok += duzina_najmanje_grane;
        //modifikujemo graf
        for(int i = 0;i<put.size();i++) {
            cout<<"("<<put[i].first.first<<","<<put[i].first.second<<")";
            if(put[i].second) {
                matricaUdaljenosti[put[i].first.first][put[i].first.second] -= duzina_najmanje_grane;
                matricaUdaljenosti[put[i].first.second][put[i].first.first] += duzina_najmanje_grane;
            }
            else {
                matricaUdaljenosti[put[i].first.first][put[i].first.second] += duzina_najmanje_grane;
                matricaUdaljenosti[put[i].first.second][put[i].first.first] -= duzina_najmanje_grane;
            }
        }
        cout<<endl;
    }
    return maksimalan_protok;
}

