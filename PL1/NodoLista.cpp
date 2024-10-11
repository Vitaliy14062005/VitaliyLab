#include "NodoLista.hpp"

NodoLista::NodoLista(int v, NodoLista* sig) {
    valor = v;
    siguiente = sig;
}

NodoLista::~NodoLista() {
}
