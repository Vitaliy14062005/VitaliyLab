#include "Pila.hpp"


Pila::Pila() : ultimo(nullptr), longitud(0) {}

void Pila::insertar(Proceso& p)
{
    pnodoPila nuevo = new NodoPila(p, ultimo);
    ultimo = nuevo; // Actualizar el puntero al último nodo
    longitud++; 

 }

Proceso Pila::extraer() 
{
    NodoPila* nodo = ultimo; //Aquí se crea un puntero nodo que apunta al último nodo de la pila.
    Proceso v = nodo->valor; //Se extrae el valor del nodo al que apunta nodo y se almacena en la variable v.
    ultimo = nodo->siguiente; //El puntero ultimo se actualiza para que apunte al siguiente nodo en la pila
    delete nodo; 
    longitud--; 
    return v;
}

Proceso Pila::cima() 
{
    return ultimo->valor; //La función devuelve el valor del nodo al que apunta ultimo, que es el nodo en la cima de la pila
}

int Pila::getLongitud() 
{
    return this->longitud; //La función devuelve el valor de la variable miembro longitud de la instancia actual de la pila (this)
}

Pila::~Pila() 
{
    while (ultimo) {
        NodoPila* aux = ultimo; ////Aquí se crea un puntero aux que apunta al último nodo de la pila.
        ultimo = ultimo->siguiente; ////El puntero ultimo se actualiza para que apunte al siguiente nodo en la pila
        delete aux; // Liberar la memoria del nodo
		longitud = 0;
    }
}
