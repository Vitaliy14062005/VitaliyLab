#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include "Proceso.hpp" // Incluir solo lo necesario

// Definición de la clase NodoPila
class NodoPila {
public:
    // Constructor: Inicializa el nodo con un proceso y un puntero al siguiente nodo (por defecto nullptr)
    NodoPila(const Proceso& p, NodoPila* sig = nullptr);

    // Destructor: Libera los recursos utilizados por el nodo
    ~NodoPila();

private:
    Proceso valor;        // Valor del nodo, que es un objeto Proceso
    NodoPila* siguiente;  // Puntero al siguiente nodo en la pila

    // Declarar la clase Pila como amiga para permitir el acceso a los miembros privados
    friend class Pila;
};

// Definición de un puntero a NodoPila
typedef NodoPila* pnodoPila;

#endif // NODOPILA_HPP