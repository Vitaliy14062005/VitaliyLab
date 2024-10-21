#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"
#include "Proceso.hpp"
#include "Cola.hpp"

// Definición de la clase Lista
class Lista {
private:
    NodoLista* cabeza; // Puntero al primer nodo de la lista
    int longitud;      // Número de elementos en la lista

public:
    // Constructor: Inicializa el puntero cabeza a nullptr y la longitud a 0
    Lista();

    // Destructor: Libera la memoria de todos los nodos en la lista
    ~Lista();

    // Método para insertar un proceso al inicio de la lista
    void insertar(const Proceso& p);

	// Método para enlistar procesos desde colas
    static void enlistarDesdeColas(Cola colas[], int numColas, Lista& listaNormal, Lista& listaTiempoReal);
	
    // Método para eliminar un proceso de la lista por su PID
    void eliminar(int pid);

    // Método para buscar un proceso en la lista por su PID y devolver una referencia al proceso
    Proceso& buscar(int pid);

    // Método para ordenar la lista por prioridad
    void ordenar();

    // Método para verificar si la lista está vacía
    bool estaVacia() const;

    // Método para obtener el puntero al primer nodo de la lista
    NodoLista* getCabeza() const;

    // Método para obtener la longitud de la lista
    int getLongitud() const;

   
};

#endif // LISTA_HPP

