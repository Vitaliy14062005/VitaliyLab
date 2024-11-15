#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include "Proceso.hpp"

class NodoLista 
{
public:
    NodoLista(Proceso& p, NodoLista* sig = nullptr);
    ~NodoLista();

    Proceso valor;        
    NodoLista* siguiente;  // Puntero al siguiente nodo en la lista
    friend class Lista;
	friend class Gestor;
};

// Definición de un puntero a NodoLista
typedef NodoLista* pnodoLista;

#endif // NODOLISTA_HPP
