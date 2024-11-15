#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "NodoArbol.hpp"

#include <vector>
using namespace std;

class Arbol
{
public:
    Arbol();
    void insertar(int val);
    void pintar();
    void dibujar();
    ~Arbol();
    int getLongitud();

private:
    int longitud;
    pnodoAbb raiz;
    pnodoAbb insertar(pnodoAbb, int);
    void pintar(pnodoAbb);
    int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos,
                     char linkChar);
};

#endif // ARBOL_HPP
