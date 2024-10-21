#include "Pila.hpp"
#include <iostream>
// Constructor: Inicializa la pila con el último nodo nulo y longitud 0
Pila::Pila() : ultimo(nullptr), longitud(0) {}

// Método para insertar un proceso en la pila
void Pila::insertar(const Proceso& p) {
    NodoPila* nuevo = new NodoPila(p, ultimo); // Crear un nuevo nodo
    ultimo = nuevo; // Actualizar el puntero al último nodo
    longitud++; // Incrementar la longitud de la pila
    std::cout << "Insertado: PID=" << p.getPid() 
              << ", Usuario=" << p.getNombreUsuario() 
              << ", Prioridad=" << p.getPrioridad()
			  << ", En ejecucion: " << (p.getEnEjecucion() ? "Si" : "No")  
              << ", Tiempo Real=" << (p.getEsTiempoReal() ? "Si" : "No") 
              << std::endl;
}

// Método para extraer y devolver el proceso en la cima de la pila
Proceso Pila::extraer() {
    if (!ultimo) {
        throw std::runtime_error("La pila esta vacia");
    }

    NodoPila* nodo = ultimo;
    Proceso p = nodo->valor;
    ultimo = nodo->siguiente; // Actualizar el puntero al último nodo
    delete nodo; // Liberar la memoria del nodo extraído
    longitud--; // Decrementar la longitud de la pila

    // Imprimir los detalles del proceso extraído
    std::cout << "Extraido: PID=" << p.getPid() 
              << ", Usuario=" << p.getNombreUsuario() 
              << ", Prioridad=" << p.getPrioridad() 
			  << ", En ejecucion: " << (p.getEnEjecucion() ? "Si" : "No") 
              << ", Tiempo Real=" << (p.getEsTiempoReal() ? "Si" : "No") 
              << std::endl;

    return p;
}

// Método para ver el proceso en la cima de la pila sin extraerlo
Proceso Pila::cima() const {
    if (!ultimo) {
        throw std::runtime_error("La pila esta vacia");
    }

    return ultimo->valor;
}

// Método para mostrar todos los procesos en la pila
void Pila::mostrar() const {
    NodoPila* aux = ultimo;
    std::cout << "\tEl contenido de la pila es:\n";  
    while (aux) {
        std::cout << "\t- PID: " << aux->valor.getPid() 
                  << ", Usuario: " << aux->valor.getNombreUsuario() 
                  << ", Prioridad: " << aux->valor.getPrioridad() 
                  << ", Tiempo Real=" << (aux->valor.getEsTiempoReal() ? "Si" : "No") 
                  << std::endl;
        aux = aux->siguiente; // Avanzar al siguiente nodo
    }
    std::cout << std::endl;
}

// Método para obtener la longitud de la pila
int Pila::getLongitud() const {
    return longitud;
}

// Método para verificar si la pila está vacía
bool Pila::estaVacia() const {
    return ultimo == nullptr;
}

// Destructor: Libera los recursos utilizados por la pila
Pila::~Pila() {
    while (ultimo) {
        NodoPila* aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux; // Liberar la memoria del nodo
    }
}
