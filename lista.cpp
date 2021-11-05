#include <iostream>
#include "lista.h"
using namespace std;

void Lista::insertar(Lista* &list, int n){
  Nodo* num = new Nodo(n);
  bool repetido = false;

  // Evaluamos el espacio
  if (list -> espacio == list -> total){
    // no hay espacio
    cout << "No hay espacio" << endl;
    list -> full = true;
  }else{
    // si la lista está vacía
    if (list -> vacio == true){
      list -> head = num;
      list -> tail = num;
      list -> vacio = false;

    // si n es el menor dato de la lista
    } else if(n < list -> head -> valor){
      num -> next = list -> head;
      list -> head = num;

    // si n es el mayor dato de la lista
    } else if(n > list -> tail -> valor){
      list -> tail -> next = num;
      list -> tail = num;
    
    // n está dentro de la lista
    } else {
      Nodo* ant = list -> head;
      Nodo* temp = list -> head -> next;

      while (temp -> valor < n){
        if (n == ant -> valor || n == temp -> valor){
          cout << "El valor ya exite" << endl;
          repetido = true;
          break;
        }
        temp = temp -> next;
        ant = ant -> next;
      }

      num -> next = temp;
      ant -> next = num;
    }

    // aumentamos el espacio en 1
    if (repetido == false){
      list -> espacio += 1;
    }
  }
}

void Lista::eliminar(Lista* &list, int n){
  Nodo* temp = list -> head;
  bool lost = false;

  // si la lista está vacía
  if (list -> vacio == true){
    cout << "La lista está vacía" << endl;
  } else{
    // si es el primer elemento
    if (list -> head -> valor == n){
      list -> head = list -> head -> next;
      delete temp;

    // si es el último elemento o si está en el medio
    } else{
      Nodo* ant = list -> head;
      Nodo* sig = list -> head -> next;
      while (sig != nullptr && sig -> valor != n ){
        ant = ant -> next;
        sig = sig -> next;
      }
      // si no está
      if (sig == nullptr){
        lost = true;
      } else{
        temp = sig;
        ant -> next = sig -> next;
        delete temp;
      }
    }

  }
  // reducimos el espacio en 1
  if (lost == false){
    list -> espacio -= 1;
  }
}

void Lista::imprimir(Lista* list){
  for (Nodo* temp = list -> head; temp != nullptr; temp = temp -> next){
    cout << temp -> valor <<" ";
  }
  cout << endl;
}

void Lista::buscarIndex(Lista* list, int n){
  Nodo* temp = list -> head;
  int contador = 0;
  while (temp != nullptr && temp -> valor != n){
    temp = temp -> next;
    contador++;
  }
  cout << "Índice: " << contador << endl;
}

int Lista::getIndex(Lista* list, int i){
  Nodo* temp = list -> head;
  int contador = 0;
  while (temp != nullptr && contador!= i){
    temp = temp -> next;
    contador++;
  }
  return temp -> valor;
}