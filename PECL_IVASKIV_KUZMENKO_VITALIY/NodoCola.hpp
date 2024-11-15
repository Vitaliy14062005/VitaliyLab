#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include "Proceso.hpp"

class NodoCola 
{
public:
    NodoCola(Proceso& p, NodoCola* sig = nullptr);
    ~NodoCola();

private:
    Proceso valor;
    NodoCola* siguiente;  // Puntero al siguiente nodo en la cola
    friend class Cola;
	friend class Gestor;
};

// Definición de un puntero a NodoCola
typedef NodoCola* pnodoCola;

#endif // NODOCOLA_HPP
