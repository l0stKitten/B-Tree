#include <iostream>
#include <string> 
//#include <stdio.h> //Por si nos da error en algo

//#include "lista.h"
#include "BT.h"
#include "BTree.h"
#include "leerRand.h"
using namespace std;

/*
  Integrantes:
    - Kristhyan Andree Kurt Lazarte Zubia
    - Johanna Stephanie Gárate Cárdenas
    - Juliana Valery Berrios Butrón
    - Alejandro Joaquín Vela Fernádez Dávila
    - Daria Beatriz López Franco
*/


int main() {
  BTree t(23); // A B-Tree with minimum degree 3
  LeerRand* lec = new LeerRand();
  string num = lec -> leer();
  while( num != " " && num != ""){
    int n = stoi(num);
    num = lec -> leer();
    t.insert(n);
  }
  
  t.traverse();
  
  cout << endl;
  int k = 1300;
  (t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
  cout << endl;

  k = 1;
  (t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
  cout << endl;

  t.remove(2170);
  cout << "Traversal of tree after removing 5479" << endl;
  cout << endl;
  t.traverse();
  cout << endl;

  /*BT* tree = new BT(2);
  tree -> insertarNodo(3);
  tree -> insertarNodo(5);
  tree -> root -> llaves -> imprimir(tree -> root -> llaves);

  tree -> insertarNodo(5);
  tree -> root -> llaves -> imprimir(tree -> root -> llaves);*/
  
  return 0;
} 