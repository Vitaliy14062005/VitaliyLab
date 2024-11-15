#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"
#include "Proceso.hpp"
#include <iostream>

class Pila {
public:
    Pila();
    ~Pila();
    void insertar(Proceso& p);
    Proceso extraer();
    Proceso cima();
    void mostrar();
    int getLongitud();

private:
    pnodoPila ultimo;           
    int longitud;   
	friend class Gestor;
};

#endif // PILA_HPP
