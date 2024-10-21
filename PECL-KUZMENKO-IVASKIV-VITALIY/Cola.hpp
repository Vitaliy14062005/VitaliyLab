#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"
#include "Proceso.hpp"
#include "Pila.hpp" 

// Definición de la clase Cola
class Cola {
private:
    NodoCola* primero; // Puntero al primer nodo de la cola
    NodoCola* ultimo;  // Puntero al último nodo de la cola
    int longitud;      // Número de elementos en la cola

public:
    // Constructor: Inicializa los punteros a nullptr y la longitud a 0
    Cola(); 

    // Destructor: Libera la memoria de todos los nodos en la cola
    ~Cola();

    // Método para insertar un proceso al final de la cola
    void insertar(const Proceso& p);
	
	// Método para encolar procesos desde una pila
    static void encolarDesdePila(Pila& pila, Cola colas[], int numColas);
	
    // Método para eliminar y devolver el primer proceso de la cola
    Proceso eliminar();

    // Método para verificar si la cola está vacía
    bool estaVacia() const { return primero == nullptr; }

    // Método para mostrar todos los procesos en la cola
    void mostrar() const;

    // Método para ver el primer proceso de la cola sin eliminarlo
    Proceso verPrimero() const;

    // Método para obtener la longitud de la cola
    int getLongitud() const { return longitud; }
	
    // Método para ordenar los procesos en la cola por prioridad
    void ordenar();
};

#endif // COLA_HPP