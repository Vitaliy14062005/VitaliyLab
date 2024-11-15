#include "Lista.hpp"


Lista::Lista() : cabeza(nullptr), longitud(0)
{

}


void Lista::insertar(Proceso& p) 
{
    pnodoLista nuevo = new NodoLista(p); // Crear un nuevo nodo

    if (cabeza == nullptr) {
        // Si la lista está vacía, el nuevo nodo es la cabeza
        cabeza = nuevo;
    } else {
        // Si la lista no está vacía, enlazar el último nodo al nuevo nodo
        pnodoLista actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }

    longitud++; // Incrementar la longitud de la lista
}

Proceso Lista::eliminar(int pid) {
    NodoLista* actual = cabeza;
    NodoLista* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->valor.getPid() == pid) {
			Proceso procesoEliminado = actual->valor;
            if (anterior == nullptr) {
                cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            longitud--;
            return procesoEliminado;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
}

pnodoLista Lista::getCabeza()
{
    return cabeza;
}

int Lista::getLongitud()
{
    return longitud; 
}

Lista::~Lista()
{
	while(cabeza){
		 eliminar(cabeza->valor.getPid());
	}
}