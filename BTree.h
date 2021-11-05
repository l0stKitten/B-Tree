#include <iostream>
#include "lista.h"
using namespace std;

struct NodoBT{
  Lista* llaves;
  NodoBT** hijos;
  bool hoja;
  bool hijoEmpty;
  int k; // Cuántas llaves máx o el grado del 
  int n; // Cuantos hijos hay actualmente

  NodoBT* padre;

  NodoBT(int _k, bool _hoja){
    k = _k;
    n = 0;
    llaves = new Lista(2*k - 1);
    hijos = new NodoBT* [2*k];
    padre = nullptr;
    hoja = _hoja;
    hijoEmpty = true;
  }
  ~NodoBT();

  void encontrarNodo(NodoBT* temp, int data, int t);
  void dividir(NodoBT* &root, int t);
};

class BT{
  public:
    NodoBT* root;
    int t; // el grado del árbol

    BT(int _t){
      root = nullptr;
      t = _t;
    }

    void insertarNodo(int data){
      if (root == nullptr){
        root = new NodoBT(t, true);
        root -> llaves -> insertar(root -> llaves, data);
      } else{
        // 1 Caso donde nuestra raíz es hoja
        // y está lleno
        if (root -> llaves -> full == true){
          if (root -> padre == nullptr && root -> hijoEmpty == true){
            root -> dividir(root, t);
          }
        }
      }
    }
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
>>>>>>> origin/main
