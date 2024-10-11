#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include <iostream>

using namespace std;

class NodoLista {
public:
    NodoLista(int valor, NodoLista* sig = nullptr);
    ~NodoLista();

private:
    int valor;
    NodoLista* siguiente;
    friend class Lista;
};

typedef NodoLista* pnodoLista;

#endif // NODOLISTA_HPP
