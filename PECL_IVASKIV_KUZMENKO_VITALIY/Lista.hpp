#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"
#include "Proceso.hpp"
#include "Cola.hpp"
#include <stdexcept>
#include <iostream>


// Definición de la clase Lista
class Lista {
private:
    pnodoLista cabeza; // Puntero al primer nodo de la lista
    int longitud;      // Número de elementos en la lista
	friend class Gestor;
	friend class Proceso;

public:
    Lista();
    ~Lista();
    void insertar(Proceso& p);
    Proceso eliminar(int pid);
    Proceso& buscar(int pid);
    pnodoLista getCabeza();
    int getLongitud();

   
};

#endif // LISTA_HPP