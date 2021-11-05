#include <iostream>
#include "BTree.h"
using namespace std;

void NodoBT::encontrarNodo(NodoBT* temp, int data, int t){
  if (temp -> hoja == true){
    temp -> llaves -> insertar(temp -> llaves, data);
  } else{
    
  }
}

void NodoBT::dividir(NodoBT* &root, int t){
  NodoBT* temp = new NodoBT(t, false);
  temp -> n = t - 1;
  int media = t;
  int valorM = root-> llaves -> getIndex(root-> llaves, t);
  root -> llaves -> eliminar(root -> llaves, valorM);
  temp -> llaves -> insertar(temp -> llaves, valorM);
  
}