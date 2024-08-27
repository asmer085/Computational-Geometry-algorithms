#ifndef STABLO_CPP
#define STABLO_CPP

#include "stablo.h"
#include <iostream>
using namespace std;

template <typename Tip>
void Stablo<Tip>::Insert(Tip element) {
  if(Empty()) {
    korijen = new Cvor(element);
    broj_elemenata++;
    return;
  }

  Cvor *trenutni = korijen, *prethodni = nullptr;
  while(trenutni != nullptr) {
    prethodni = trenutni;
    if(element < trenutni->el)
        trenutni = trenutni->ld;
    else if(element > trenutni->el)
        trenutni = trenutni->dd;
    else return;
  }

  if(element < prethodni->el)
    prethodni->ld = new Cvor(element, prethodni);
  else prethodni->dd = new Cvor(element, prethodni);
  broj_elemenata++;
}

template <typename Tip>
bool Stablo<Tip>::Find(Tip element) {
  Cvor *trenutni = korijen;
  while(trenutni != nullptr) {
    if(element < trenutni->el)
        trenutni = trenutni->ld;
    else if(element > trenutni->el)
        trenutni = trenutni->dd;
    else return true;
  }
  return false;
}

template <typename Tip>
void Stablo<Tip>::InOrderRek(Cvor* cvor, void (f)(Tip&)) {
  if(cvor->ld != nullptr)
    InOrderRek(cvor->ld,f);
  f(cvor->el);
  cout<<"LD: ";
  if(cvor->ld != nullptr) f(cvor->ld->el);
  cout<<"DD: ";
  if(cvor->dd != nullptr) f(cvor->dd->el);
  cout<<endl;
  if(cvor->dd != nullptr)
    InOrderRek(cvor->dd, f);
}

template <typename Tip>
int Stablo<Tip>::visinaRek(Cvor *cvor) {
  if(cvor == nullptr)
    return 0;

  return 1 + max(visinaRek(cvor->ld),visinaRek(cvor->dd));
}

template <typename Tip>
void Stablo<Tip>::Erase(Tip element) {

  Cvor *trenutni = korijen;
  while(trenutni != nullptr) {
    if(element < trenutni->el)
        trenutni = trenutni->ld;
    else if(element > trenutni->el)
        trenutni = trenutni->dd;
    else break;
  }
  if(trenutni == nullptr) return;

  //ako je list
  if(trenutni->ld == nullptr && trenutni->dd == nullptr) {
    if(trenutni == korijen) {
        korijen = nullptr;
    }
    else {
        if(trenutni == trenutni->rod->ld)
            trenutni->rod->ld = nullptr;
        else trenutni->rod->dd = nullptr;
    }
  }
  //ako nema desnog djeteta
  else if(trenutni->dd == nullptr) {
    Cvor* dijete = trenutni->ld;
    dijete->rod = trenutni->rod;
    if(trenutni == korijen) {
        korijen = dijete;
    }
    else {
        if(trenutni->rod->ld == trenutni)
            trenutni->rod->ld = dijete;
        else trenutni->rod->dd = dijete;
    }
  }
  //ako nema lijevog djeteta
  else if(trenutni->ld == nullptr) {
    Cvor* dijete = trenutni->dd;
    dijete->rod = trenutni->rod;
    if(trenutni == korijen) {
        korijen = dijete;
    }
    else {
        if(trenutni->rod->ld == trenutni)
            trenutni->rod->ld = dijete;
        else trenutni->rod->dd = dijete;
    }
  }
  //ako ima oba djeteta
  else {
    Cvor* target = sljedbenik(trenutni);
    if(target == target->rod->ld)
        target->rod->ld = target->dd;
    else target->rod->dd = target->dd;

    if(target->dd != nullptr) {
       target->dd->rod = target->rod;
    }

    target->ld = trenutni->ld;
    target->dd = trenutni->dd;
    target->rod = trenutni->rod;
    trenutni->ld->rod = target;
    trenutni->dd->rod = target;
    if(korijen == trenutni) {
       korijen = target;
    }
    else {
       if(trenutni == trenutni->rod->ld)
            trenutni->rod->ld = target;
       else trenutni->rod->dd = target;
    }
  }

  delete trenutni;
  broj_elemenata--;

}

template <typename Tip>
typename Stablo<Tip>::Cvor* Stablo<Tip>::sljedbenik(Cvor* cvor) {
  if(cvor->dd != nullptr) {
    Cvor* target = cvor->dd;
    while(target->ld != nullptr)
        target = target->ld;
    return target;
  }
  else {
    Cvor *target = cvor;
    while(target->rod != nullptr && target->rod->dd == target)
        target = target->rod;
    return target->rod;
  }
}

template <typename Tip>
typename Stablo<Tip>::Cvor* Stablo<Tip>::Begin() {
  Cvor *trenutni = korijen;
  if(trenutni == nullptr) return nullptr;
  while(trenutni->ld != nullptr)
    trenutni = trenutni->ld;
  return trenutni;
}

template <typename Tip>
void Stablo<Tip>::InOrderIterativni(void (f)(Tip&)) {
  Cvor* trenutni = Begin();
  while(trenutni != nullptr) {
    f(trenutni->el);
    trenutni = sljedbenik(trenutni);
  }
}
#endif // STABLO_CPP
