#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include <iostream>
class NodoArbol
{
public:
    NodoArbol(int dato);
    ~NodoArbol();

private:
    int dato; // Aquí se almacenan enteros pero en vuestra práctica se deben almacenar pacientes
    NodoArbol* izq;
    NodoArbol* der;

    friend class Arbol;
};
typedef NodoArbol* pnodoAbb;
#endif // NODOARBOL_HPP