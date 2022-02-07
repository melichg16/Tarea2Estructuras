#include "Arbol.h"
#include "Helper.h"

//CONSTRUCTOR
Arbol::Arbol()
{
    setRaiz(NULL);
}

//GETTERS & SETTERS
Nodo* Arbol::getRaiz() const {
    return raiz;
}
void Arbol::setRaiz(Nodo* raiz) {
    Arbol::raiz = raiz;
}

//METODOS

bool Arbol::insertarDato(int pDato) {
    if (this->raiz == nullptr) {
        Nodo* nuevo = new Nodo();
        nuevo->setDato(pDato);
        this->raiz = nuevo;
    }
    else {
        //Invoca metodo recursivo que posicionara el dato en la rama indicada.
        return buscarPI(this->raiz, pDato);
    }
    return true;
}
//PI : punto de insercion del dato en el arbol binario (metodo recursivo)
bool Arbol::buscarPI(Nodo* nodo, int pDato) {
    if (pDato < nodo->getDato() && nodo->getIzq() != nullptr) {
        return buscarPI(nodo->getIzq(), pDato);
    }
    else if (pDato < nodo->getDato() && nodo->getIzq() == nullptr) {
        nodo->setIzq(new Nodo(pDato));
    }
    else if (pDato > nodo->getDato() && nodo->getDer() != nullptr) {
        return buscarPI(nodo->getDer(), pDato);
    }
    else if (pDato > nodo->getDato() && nodo->getDer() == nullptr) {
        nodo->setDer(new Nodo(pDato));
    }
    else if (pDato == nodo->getDato()) {
        //Else en caso que el valor sea repetido, retorna false, ya que un ABB no puede tener valores iguales. 
        return false;
    }
    return true;
}

bool Arbol::estaVacio() {
    if (getRaiz() == nullptr) {
        return true;
    }
    return false;
}

string  Arbol::PreOrden(Nodo* raiz) {
    string rslt = "";
    Helper helper;
    stringstream sstm;

    if (raiz != NULL) {
        // PREORDEN: RAIZ -- IZQUIERDA -- DERECHA (RID)
        sstm << raiz->getDato() << " " << PreOrden(raiz->getIzq()) << " " << PreOrden(raiz->getDer());
        rslt += sstm.str();


        rslt = helper.ReplaceAll(rslt);
    }
    else if (estaVacio()) {
        return "Arbol binario de busqueda vacio.";
    }
    return rslt;
}

string Arbol::InOrden(Nodo* raiz) {
    string rslt = "";
    Helper helper;
    stringstream sstm;

    if (raiz != NULL) {
        // PREORDEN: IZQUIERDA -- RAIZ -- DERECHA (IRD)
        sstm << InOrden(raiz->getIzq()) << " " << raiz->getDato() << " " << InOrden(raiz->getDer());
        rslt += sstm.str();


        rslt = helper.ReplaceAll(rslt);
    }
    else if (estaVacio()) {
        return "Arbol binario de busqueda vacio.";
    }
    return rslt;
}

string Arbol::PostOrden(Nodo* raiz) {
    string rslt = "";
    Helper helper;
    stringstream sstm;

    if (raiz != NULL) {
        // PREORDEN: IZQUIERDA -- DERECHA -- RAIZ (IDR)
        sstm << PostOrden(raiz->getIzq()) << " " << PostOrden(raiz->getDer()) << " " << raiz->getDato();
        rslt += sstm.str();


        rslt = helper.ReplaceAll(rslt);
    }
    else if (estaVacio()) {
        return "Arbol binario de busqueda vacio.";
    }
    return rslt;
}

