#ifndef COLA_HPP
#define COLA_HPP
#include "NodoCola.hpp"
#include "Proceso.hpp"
#include "Pila.hpp"
#include <iostream>

class Cola
{

public:
    Cola(); 
    ~Cola();
    void insertar(Proceso& p);
    Proceso eliminar();
    Proceso verPrimero();
    int getLongitud();
	int decidirCola(Proceso&, Cola cola[]);
private:
    pnodoCola primero, ultimo; // Puntero al primer y ultimo nodo de la cola
    int longitud;
	friend class Gestor;

};

#endif // COLA_HPP