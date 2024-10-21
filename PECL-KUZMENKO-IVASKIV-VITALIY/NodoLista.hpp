#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include "Proceso.hpp" // Incluir solo lo necesario

// Definición de la clase NodoLista
class NodoLista {
public:
    // Constructor: Inicializa el nodo con un proceso y un puntero al siguiente nodo (por defecto nullptr)
    NodoLista(const Proceso& p, NodoLista* sig = nullptr);

    // Destructor: Libera los recursos utilizados por el nodo
    ~NodoLista();


    Proceso valor;        // Valor del nodo, que es un objeto Proceso
    NodoLista* siguiente; // Puntero al siguiente nodo en la lista

    // Declarar la clase Lista como amiga para permitir el acceso a los miembros privados
    friend class Lista;
};

// Definición de un puntero a NodoLista
typedef NodoLista* pnodoLista;

#endif // NODOLISTA_HPP