#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stablo.h"
using namespace std;

void Ispisi(int &broj) {
  cout<<broj<<" ";
}

int main() {

  Stablo<int> s;
  s.Insert(50);
  s.Insert(30);
  s.Insert(10);
  s.Insert(60);
  s.Insert(100);
  s.Insert(80);
  s.Insert(40);
  s.Insert(70);
  s.Insert(90);
  s.Insert(55);
  s.Insert(57);
  s.Insert(58);
  s.Insert(56);
  /*srand(time(NULL));
  for(int i = 0; i < 1000; i++) {
    s.Insert(rand());
  }*/
  s.InOrder(Ispisi);
  cout<<endl;
  s.Erase(50);
  //s.InOrder(Ispisi);
  s.InOrderIterativni(Ispisi);
  //cout<<endl;
  //cout<<s.visina()<<endl;
}
