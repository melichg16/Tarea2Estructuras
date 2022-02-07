// Tarea2Estructuras2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// TAREA 02: Realizar la programación de un árbol binario de búsqueda (ABB) que reciba números enteros y 
// permita mostrarlos en preorden, inorden y postorden.
// ESTUDIANTES: 
// Gabriel Calvo
// David Solano
// Mónica Zúñiga 

#include <iostream>
#include <iomanip>
#include <string>
#include "Gestor.h"

using namespace std;

//PROTOTIPO DE FUNCIONES
int menu(int answer);
void insertarEnABB();
void mostrarPreOrden();
void mostrarInOrden();
void mostrarPostOrden();

//VARIABLES ESTATICAS
static Gestor* gestor = new Gestor();

int main()
{
    int answer;
    bool keepLooping = true;

    do
    {
        system("CLS");
        cout << " _____________________________________________________" << endl;
        cout << "|Por Favor digite un numero del menu:                 |" << endl;
        cout << "|1. Insertar dato en arbol binario de busqueda (ABB). |" << endl;
        cout << "|2. Mostrar datos en preorden.                        |" << endl;
        cout << "|3. Mostrar datos en inorden.                         |" << endl;
        cout << "|4. Mostrar datos en postorden.                       |" << endl;
        cout << "|0. Salir.                                            |" << endl;
        cout << "|_____________________________________________________|" << endl;
        cin >> answer;
        system("CLS");

        menu(answer);

        if (answer == 0)
        {
            keepLooping = false;
        }
        else
        {
            keepLooping = true;
        }
    } while (keepLooping);
}

//MENU PRINCIPAL

int menu(int answer)
{
    switch (answer)
    {
    case 1:
        insertarEnABB();
        break;
    case 2:
        mostrarPreOrden();
        system("PAUSE");
        break;
    case 3:
        mostrarInOrden();
        system("PAUSE");
        break;
    case 4:
        mostrarPostOrden();
        system("PAUSE");
        break;
    case 0:
        cout << "Gracias." << endl;
        break;
    default:
        cout << "Opcion incorrecta." << endl;
    }
    return answer;
}

//FUNCIONES DEL MENU

void insertarEnABB() {
    int input = -1;
    bool valid = false;
    do
    {
        cout << "Favor digite un numero entero a agregar: " << flush;
        cin >> input;
        if (cin.good())
        {
            valid = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Favor inserte un numero entero." << endl;
        }
    } while (!valid);

    cout << gestor->insertarEnABB(input) << endl;
}

void mostrarPreOrden() {
    cout << gestor->mostrarPreOrden() << endl;
}

void mostrarInOrden() {
    cout << gestor->mostrarInOrden() << endl;
}

void mostrarPostOrden() {
    cout << gestor->mostrarPostOrden() << endl;
}

