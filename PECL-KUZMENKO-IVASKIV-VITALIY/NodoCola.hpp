#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP

#include "Proceso.hpp"

// Definición de la clase NodoCola
class NodoCola {
public:
    // Constructor: Inicializa el nodo con un proceso y un puntero al siguiente nodo (por defecto nullptr)
    NodoCola(const Proceso& p, NodoCola* sig = nullptr);

    // Destructor: Libera los recursos utilizados por el nodo
    ~NodoCola();

private:
    Proceso valor;        // Valor del nodo, que es un objeto Proceso
    NodoCola* siguiente;  // Puntero al siguiente nodo en la cola

    // Declarar la clase Cola como amiga para permitir el acceso a los miembros privados
    friend class Cola;
};

// Definición de un puntero a NodoCola
typedef NodoCola* pnodoCola;

#endif // NODOCOLA_HPP
