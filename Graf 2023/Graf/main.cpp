#include <iostream>
#include "graf.h"
using namespace std;

int main() {

  /*Graf G(9);
  //G.dodajGranu(7,2);
  //G.dodajGranu(0,7);
  G.dodajGranu(4,2);
  //G.dodajGranu(2,5);
  G.dodajGranu(8,6);
  G.dodajGranu(4,8);
  G.dodajGranu(8,3);
  //G.dodajGranu(6,1);
  G.dodajGranu(0,1);
  G.dodajGranu(7,1);
  G.dodajGranu(8,5);*/




  /*auto udaljenosti = G.udaljenosti(7);
  for(auto d:udaljenosti)
    cout<<d<<" ";*/

  /*auto put = G.najkraciPut(0,8);
  for(auto cvor: put)
    cout<<cvor<<" ";*/

  //G.DFS();
  //G.DFSVremena(6);

  //Usmjereni graf
  Graf G(5, true);
  G.dodajGranu(0,1);
  G.dodajGranu(3,1);
  G.dodajGranu(0,3);
  G.dodajGranu(4,1);
  G.dodajGranu(0,2);
  G.dodajGranu(4,2);
  G.dodajGranu(4,0);

  auto rezultat = G.TopoloskoSortiranje();
  for(auto el: rezultat)
    cout<<el<<" ";
}
