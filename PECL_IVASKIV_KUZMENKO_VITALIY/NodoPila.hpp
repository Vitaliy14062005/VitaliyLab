#ifndef NODOPILA_HPP
#define NODOPILA_HPP
#include "Proceso.hpp"

class NodoPila 
{
public:
  
    NodoPila(Proceso& p, NodoPila* sig = nullptr);
    ~NodoPila();

    Proceso valor;        
    NodoPila* siguiente;  // Puntero al siguiente nodo en la pila
    friend class Pila;
	friend class Gestor;
};

// Definición de un puntero a NodoPila
typedef NodoPila* pnodoPila;

#endif // NODOPILA_HPP