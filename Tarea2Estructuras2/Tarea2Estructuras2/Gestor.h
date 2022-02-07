#pragma once
#include <string>
#include "Arbol.h"

using namespace std;

class Gestor
{
private:
	Arbol arbol;
public:
	string insertarEnABB(int);
	string mostrarPreOrden();
	string mostrarInOrden();
	string mostrarPostOrden();
};


