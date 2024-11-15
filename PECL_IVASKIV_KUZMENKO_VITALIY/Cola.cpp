#include "Cola.hpp"



Cola::Cola() : primero(nullptr), ultimo(nullptr), longitud(0)
{

}

void Cola::insertar(Proceso& p)
{
   
	pnodoCola nuevo = new NodoCola(p);
	int prioridad = p.getPrioridad();
	if (longitud == 0)
	{
		primero = ultimo = nuevo;
	}
	else if (primero->valor.getPrioridad() > prioridad)
	{
		nuevo->siguiente = primero;
		primero = nuevo;

	}
	else
	{
		pnodoCola actual = primero;
		while (actual->siguiente != NULL && actual->siguiente->valor.getPrioridad() <= prioridad)
		{
			actual = actual->siguiente;
		}
		
		nuevo->siguiente = actual->siguiente;
		actual->siguiente = nuevo;
		
		if (nuevo->siguiente == nullptr)
		{
			ultimo = nuevo;
		}
}
	longitud++;
}

int Cola::getLongitud() 
{
    return this->longitud; //La función devuelve el valor de la variable miembro longitud de la instancia actual de la pila (this)
}

Proceso Cola::eliminar()
{
    NodoCola* nodo = primero;
    Proceso p = nodo->valor;
    primero = nodo->siguiente; // Actualizar el primer nodo
    delete nodo; // Liberar la memoria del nodo eliminado
    if (!primero)
        ultimo = nullptr; // Si la cola queda vacía, actualizar el último nodo
    longitud--; // Decrementar la longitud de la cola
	return p;
}

Proceso Cola::verPrimero()
{
   return primero->valor;
}

Cola::~Cola()
{
    while (primero)
        eliminar();
}