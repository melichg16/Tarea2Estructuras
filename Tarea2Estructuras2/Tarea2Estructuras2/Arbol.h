#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "Nodo.h"
using namespace std;

class Arbol
{
public:
    //CONSTRUCTOR
    Arbol();

    //GETTERS & SETTERS
    Nodo* getRaiz() const;
    void setRaiz(Nodo*);

    //METODOS
    // Insertar en árbol ordenado:
    bool insertarDato(int);
    bool buscarPI(Nodo* nodo, int pDato);
    bool estaVacio();
    string PreOrden(Nodo*);
    string InOrden(Nodo*);
    string PostOrden(Nodo*);


private:
    Nodo* raiz;
    int altura;
};

