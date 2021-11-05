#include <iostream>
using namespace std;

struct Nodo{
	int valor;
	Nodo* next;

  Nodo(int val){
    valor = val;
    next = nullptr;
  }
  
};

class Lista{
  public: 
    Nodo *head;
    Nodo *tail;
    bool vacio;
    int espacio;
    int total;
    bool full;

  public:
    Lista(int t){
      head = nullptr;
      tail = nullptr;
      vacio = true;
      espacio = 0;
      total = t;
      full = false;
    }

    ~Lista(){}

  
    void insertar(Lista* &list, int n);
    void eliminar(Lista* &list, int n);
    void imprimir(Lista* list);
    void buscarIndex(Lista* list, int n);
    int getIndex(Lista* list, int i);
};