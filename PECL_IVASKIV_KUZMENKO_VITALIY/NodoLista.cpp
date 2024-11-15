#include "NodoLista.hpp"
NodoLista::NodoLista(Proceso& p, NodoLista* sig) : valor(p), siguiente(sig)
{
	
}


NodoLista::~NodoLista()
{
	
}