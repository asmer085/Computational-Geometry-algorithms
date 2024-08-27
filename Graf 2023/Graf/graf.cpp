#include "graf.h"
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

void Graf::dodajGranu(int i, int j) {
  lista_susjedstva[i].push_back(j);
  if(!usmjeren) lista_susjedstva[j].push_back(i);
}

void Graf::ispisi() {
  for(int i = 0; i < n; i++) {
    cout<<i<<": ";
    for(auto el : lista_susjedstva[i]) {
        cout<<el<<" ";
    }
    cout<<endl;
  }

}

void Graf::BFS(int pocetni) {
  vector<bool> posjecen(n, false);
  posjecen[pocetni] = true;
  queue<int> red;
  red.push(pocetni);
  while(!red.empty()) {
    int trenutni = red.front();
    cout<<"Posjecujem "<<trenutni<<endl;
    red.pop();
    for(auto el:lista_susjedstva[trenutni]) {
       if(!posjecen[el]) {
          posjecen[el] = true;
          red.push(el);
       }
    }
  }
  /*for(int i = 0; i < broj_cvorova; i++) {
    cout<<i<<" "<<posjecen[i]<<endl;
  }*/

}

vector<int> Graf::najkraciPut(int pocetni, int krajnji) {
  vector<int> udaljenost(n, -1);
  vector<int> prethodnik(n, -1);
  udaljenost[pocetni] = 0;
  prethodnik[pocetni] = -2;
  queue<int> red;
  red.push(pocetni);
  while(!red.empty()) {
    int trenutni = red.front();
    red.pop();
    for(auto el:lista_susjedstva[trenutni]) {
       if(udaljenost[el] == -1) {
          udaljenost[el] = udaljenost[trenutni] + 1;
          prethodnik[el] = trenutni;
          red.push(el);
       }
    }
    if(udaljenost[krajnji] != -1)
        break;
  }
  //pronaci put
  vector<int> put;
  int trenutni = krajnji;
  put.push_back(krajnji);
  do {
    trenutni = prethodnik[trenutni];
    put.push_back(trenutni);
  } while(trenutni != pocetni);

  reverse(put.begin(), put.end());
  return put;
}

void Graf::DFS() {
  vector<bool> posjecen(n, false);
  for(int el = 0; el < n; el++)
    if(!posjecen[el])
     DFSRek(el, posjecen);

}

void Graf::DFSRek(int trenutni, vector<bool> &posjecen) {
  posjecen[trenutni] = true;
  cout<<trenutni<<endl;
  for(auto el: lista_susjedstva[trenutni])
    if(!posjecen[el])
        DFSRek(el, posjecen);
}

void Graf::DFSVremena(int pocetni) {
  vector<bool> posjecen(n, false);
  int time = 0;
  DFSVremenaRek(pocetni, posjecen, time);
}

void Graf::DFSVremenaRek(int trenutni, vector<bool> &posjecen, int &time) {
  posjecen[trenutni] = true;
  cout<<time<<" Posjecujem "<<trenutni<<endl;
  time++;
  for(auto el: lista_susjedstva[trenutni])
    if(!posjecen[el])
        DFSVremenaRek(el, posjecen, time);
  cout<<time<<" Zavrsavam "<<trenutni<<endl;
  time++;
}

list<int> Graf::TopoloskoSortiranje() {
  vector<bool> posjecen(n, false);
  list<int> rezultat;
  for(int el = 0; el < n; el++)
    if(!posjecen[el])
     TopoloskoSortiranjeRek(el, posjecen, rezultat);
  return rezultat;
}

void Graf::TopoloskoSortiranjeRek(int trenutni, vector<bool> &posjecen, list<int> &rezultat) {
  posjecen[trenutni] = true;
  for(auto el: lista_susjedstva[trenutni])
    if(!posjecen[el])
      TopoloskoSortiranjeRek(el, posjecen, rezultat);
  rezultat.push_front(trenutni);
}
