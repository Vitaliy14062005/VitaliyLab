#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"
#include "Proceso.hpp"
#include <list> // Incluir solo lo necesario

// Definición de la clase Pila
class Pila {
public:
    // Constructor: Inicializa la pila
    Pila();

    // Destructor: Libera los recursos utilizados por la pila
    ~Pila();

    // Método para insertar un proceso en la pila
    void insertar(const Proceso& p);

    // Método para extraer y devolver el proceso en la cima de la pila
    Proceso extraer();

    // Método para ver el proceso en la cima de la pila sin extraerlo
    Proceso cima() const;

    // Método para mostrar todos los procesos en la pila
    void mostrar() const;

    // Método para obtener la longitud de la pila
    int getLongitud() const;

    // Método para verificar si la pila está vacía
    bool estaVacia() const;

private:
    pnodoPila ultimo;           // Puntero al último nodo de la pila
    int longitud;               // Número de elementos en la pila
    std::list<Proceso> listaProcesos; // Lista de procesos
};

#endif // PILA_HPP