#include "Lista.hpp"
#include <iostream>

Lista::Lista() {
    cabeza = NULL;
    longitud = 0;
}


void Lista::agregar(int valor) {
    pnodoLista nuevo = new NodoLista(valor, cabeza);
    cabeza = nuevo;
    longitud++;
}

int Lista::extraer() {
    if (!cabeza)
        return -1; // Si la lista está vacía, devolvemos -1 o puedes lanzar una excepción.

    pnodoLista nodo = cabeza;
    int valor = nodo->valor;
    cabeza = cabeza->siguiente;
    delete nodo;
    longitud--;

    return valor;
}

int Lista::primero() {
    if (!cabeza)
        return 0; // Si la lista está vacía, devuelve 0 o un valor que indique que no hay elementos.
    return cabeza->valor;
}

void Lista::mostrar() const {
    pnodoLista aux = cabeza;
    std::cout << "\tEl contenido de la lista es: ";  
    while (aux) {
        std::cout << "->" << aux->valor;
        aux = aux->siguiente;
    }
    std::cout << std::endl;
}

int Lista::getLongitud() const {
    return this->longitud;
}

bool Lista::vacia() const {
    return cabeza == nullptr;
}
Lista::~Lista() {
    pnodoLista aux;
    while (cabeza) {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
}
