#include "NodoArbol.hpp"

NodoArbol::NodoArbol(int dato)
{
    this->dato = dato;
    this->izq = nullptr;
    this->der = nullptr;
}

NodoArbol::~NodoArbol() {}