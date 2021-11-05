#include <iostream>
#include "lista.h"
using namespace std;

struct NodoBT{
  Lista* llaves;
  NodoBT** hijos;
  bool hoja;
  int k; // Cuántas llaves máx o el grado del 
  int n; // Cuantos hijos hay actualmente

  NodoBT* padre;

  NodoBT(int _k, bool _hoja){
    k = _k;
    llaves = new Lista(2*k - 1);
    hijos = new NodoBT* [2*k];
    padre = nullptr;
    hoja = _hoja;
  }
  ~NodoBT();

  void imprimir();
};

class BT{
  NodoBT* root;
  int t;

  BT(int _t){
    root = nullptr;
    t = _t;
  }
};