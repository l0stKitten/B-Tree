#ifndef LEER_RAND_H_
#define LEER_RAND_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LeerRand{
private:
	//LeerRand();
	//static LeerRand *instancia;
	static string path;
	fstream file;
public:
	LeerRand();
	//static LeerRand* getInstance();
	string leer();
	~LeerRand();
};


#endif
