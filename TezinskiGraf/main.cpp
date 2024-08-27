#include <iostream>
#include "tezinski_graf.h"
using namespace std;


int main() {
    /*TezinskiGraf G(9, true);
    G.dodajGranu(0,1,4);
    G.dodajGranu(0,7,8);
    G.dodajGranu(1,7,3);
    G.dodajGranu(7,8,7);
    G.dodajGranu(1,2,7);
    G.dodajGranu(7,6,1);
    G.dodajGranu(2,8,2);
    G.dodajGranu(8,6,6);
    G.dodajGranu(2,3,7);
    G.dodajGranu(2,5,4);
    G.dodajGranu(6,5,2);
    G.dodajGranu(3,5,14);
    G.dodajGranu(3,4,9);
    G.dodajGranu(5,4,10);
    auto udaljenosti = G.Dijkstra(0);
    for(int i = 0; i < udaljenosti.size(); i++)
        cout<<"("<<i<<","<<udaljenosti[i]<<") ";
    cout<<endl;
    auto udaljenosti_brzo = G.DijkstraBrzo(0);
    for(int i = 0; i < udaljenosti_brzo.size(); i++)
        cout<<"("<<i<<","<<udaljenosti_brzo[i]<<") ";*/

    /*TezinskiGraf G(5,true);
    G.dodajGranu(0,1,6);
    G.dodajGranu(0,4,7);
    G.dodajGranu(1,2,5);
    G.dodajGranu(1,3,-4);
    G.dodajGranu(1,4,8);
    G.dodajGranu(2,1,-2);
    G.dodajGranu(3,2,7);
    G.dodajGranu(3,0,2);
    G.dodajGranu(4,2,-3);
    G.dodajGranu(4,3,9);

    auto par = G.BelmanFord(0);
    if(!par.first) {
        for(int i = 0; i < 5; i++)
            cout<<"("<<i<<","<<par.second[i]<<") ";
    }
    else cout<<"U grafu postoji ciklus negativne duzine";*/

  /*TezinskiGraf G(9);
  G.dodajGranu(0,1,4);
  G.dodajGranu(0,3,8);
  G.dodajGranu(1,3,11);
  G.dodajGranu(1,2,8);
  G.dodajGranu(3,5,1);
  G.dodajGranu(3,8,7);
  G.dodajGranu(5,8,6);
  G.dodajGranu(5,6,2);
  G.dodajGranu(2,8,2);
  G.dodajGranu(2,4,7);
  G.dodajGranu(6,4,14);
  G.dodajGranu(6,2,4);
  G.dodajGranu(7,4,9);
  G.dodajGranu(6,7,10);

  auto MST = G.MSTPrim();
  cout<<MST.first<<endl;
  for(auto el: MST.second)
    cout<<el.first<<" "<<el.second<<endl;
  cout<<endl;
  auto MST1 = G.MSTKruskal();
  cout<<MST1.first<<endl;
  for(auto el: MST1.second)
    cout<<el.first<<" "<<el.second<<endl;*/


      TezinskiGraf G(6,true);
      G.dodajGranu(0,1,16);
      G.dodajGranu(1,2,12);
      G.dodajGranu(2,5,20);
      G.dodajGranu(0,3,13);
      G.dodajGranu(3,4,14);
      G.dodajGranu(4,5,4);
      G.dodajGranu(4,2,7);
      G.dodajGranu(3,1,4);
      G.dodajGranu(2,3,9);
      cout<<G.maksimalanProtok(0,5);
}
