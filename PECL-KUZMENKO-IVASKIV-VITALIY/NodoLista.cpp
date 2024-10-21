#include "NodoLista.hpp"

// Constructor: Inicializa el nodo con un proceso y un puntero al siguiente nodo (por defecto nullptr)
NodoLista::NodoLista(const Proceso& p, NodoLista* sig)
    : valor(p), siguiente(sig) {}

// Definición del destructor
NodoLista::~NodoLista() {}