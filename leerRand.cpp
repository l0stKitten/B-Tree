#include "leerRand.h"

//LeerRand *LeerRand::instancia = NULL;
string LeerRand::path = "datos.txt";

LeerRand::LeerRand(){
	file.open(path,ios::in);
}

/*
LeerRand* LeerRand::getInstance(){
	if (!instancia)
		instancia = new LeerRand();
	return instancia;
}
*/

string LeerRand::leer(){
	string tp="";
	if (file.is_open()){
		getline(file, tp);
	}
	return tp;
	
}

LeerRand::~LeerRand(){
	file.close();
}
