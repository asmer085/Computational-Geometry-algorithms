#ifndef STABLO_H
#define STABLO_H

template <typename Tip>
class Stablo {
  struct Cvor {
    Tip el;
    Cvor *rod,*ld,*dd;
    Cvor(Tip el, Cvor* rod = nullptr, Cvor* ld = nullptr, Cvor* dd = nullptr):el(el),rod(rod),ld(ld),dd(dd){}
  };

  Cvor* korijen;
  int broj_elemenata;
  void InOrderRek(Cvor* cvor, void (f)(Tip&));
  int visinaRek(Cvor *cvor);
  Cvor* sljedbenik(Cvor* cvor);
  Cvor* Begin();

  public:
  Stablo():broj_elemenata(0),korijen(nullptr){}
  void Insert(Tip element);
  bool Find(Tip element);
  bool Empty() { return broj_elemenata == 0; }
  int visina() { return visinaRek(korijen); }
  void InOrder(void (f)(Tip&)) { if(!Empty()) InOrderRek(korijen,f);}
  void Erase(Tip element);
  void InOrderIterativni(void (f)(Tip&));
};

#include "stablo.cpp"



#endif // STABLO_H
