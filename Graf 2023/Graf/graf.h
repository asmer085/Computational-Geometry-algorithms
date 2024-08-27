#ifndef GRAF_H
#define GRAF_H

#include <list>
#include <vector>
using namespace std;

class Graf {
  int n;
  bool usmjeren;
  vector<list<int>> lista_susjedstva;
  void DFSRek(int trenutni, vector<bool> &posjecen);
  void DFSVremenaRek(int trenutni, vector<bool> &posjecen, int &time);
  void TopoloskoSortiranjeRek(int trenutni, vector<bool> &posjecen, list<int> &rezultat);
  public:
  Graf(int n, bool usmjeren = false):n(n), usmjeren(usmjeren) { lista_susjedstva.resize(n); }
  void dodajGranu(int i, int j);
  void BFS(int pocetni);
  void DFS();
  void DFSVremena(int pocetni);
  vector<int> udaljenosti(int pocetni);
  vector<int> najkraciPut(int pocetni, int krajnji);
  void ispisi();
  list<int> TopoloskoSortiranje();
};




#endif // GRAF_H
