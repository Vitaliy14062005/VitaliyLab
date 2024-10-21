#include "Cola.hpp"
#include "Proceso.hpp"
#include "Pila.hpp"
#include <iostream>

// Constructor: Inicializa los punteros a nullptr y la longitud a 0
Cola::Cola() : primero(nullptr), ultimo(nullptr), longitud(0) {}

// Método para insertar un proceso al final de la cola
void Cola::insertar(const Proceso& p) {
    NodoCola* nuevo = new NodoCola(p); // Crear un nuevo nodo
    if (ultimo)
        ultimo->siguiente = nuevo; // Enlazar el último nodo al nuevo nodo
    ultimo = nuevo; // Actualizar el último nodo
    if (!primero)
        primero = nuevo; // Si la cola estaba vacía, actualizar el primer nodo
    longitud++; // Incrementar la longitud de la cola
}

// Método para encolar procesos desde una pila
void Cola::encolarDesdePila(Pila& pila, Cola colas[], int numColas) {
    if (pila.estaVacia()) {
        std::cout << "No hay procesos en la pila para encolar.\n";
        return;
    }

    // Contar el número de procesos en la pila
    int numProcesos = pila.getLongitud();
    std::cout << "Se han encontrado " << numProcesos << " procesos en la pila.\n";

    // Encolar los procesos
    while (!pila.estaVacia()) {
        try {
            Proceso p = pila.extraer();
            p.enEjecucion = false; // Establecer el estado del proceso en parado

            // Determinar la cola con menos procesos
            int targetQueue = -1;
            if (!p.esTiempoReal) { // Proceso normal
                int minSize = colas[0].getLongitud();
                targetQueue = 0;
                for (int i = 1; i < numColas / 2; ++i) {
                    if (colas[i].getLongitud() < minSize) {
                        minSize = colas[i].getLongitud();
                        targetQueue = i;
                    }
                }
            } else { // Proceso en tiempo real
                int minSize = colas[numColas / 2].getLongitud();
                targetQueue = numColas / 2;
                for (int i = numColas / 2 + 1; i < numColas; ++i) {
                    if (colas[i].getLongitud() < minSize) {
                        minSize = colas[i].getLongitud();
                        targetQueue = i;
                    }
                }
            }

            colas[targetQueue].insertar(p);  // Encolar en la cola correspondiente
        } catch (const std::runtime_error& e) {
            std::cerr << "Error al extraer: " << e.what() << "\n";
        }
    }

    // Ordenar las colas después de encolar los procesos
    for (int i = 0; i < numColas; ++i) {
        colas[i].ordenar();
    }
}

// Método para mostrar todos los procesos en la cola
void Cola::mostrar() const {
    NodoCola* aux = primero;
    std::cout << "\tEl contenido de la cola es:\n";
    while (aux) {
        std::cout << "\t- PID: " << aux->valor.getPid() 
                  << ", Usuario: " << aux->valor.getNombreUsuario() 
                  << ", Prioridad: " << aux->valor.getPrioridad() 
                  << std::endl;
        aux = aux->siguiente; // Avanzar al siguiente nodo
    }
    std::cout << std::endl;
}

// Método para eliminar y devolver el primer proceso de la cola
Proceso Cola::eliminar() {
    if (!primero)
        return Proceso(-1, "", false, 0, false, false); // Devuelve un objeto Proceso indicando que está vacío

    NodoCola* nodo = primero;
    Proceso p = nodo->valor;
    primero = nodo->siguiente; // Actualizar el primer nodo
    delete nodo; // Liberar la memoria del nodo eliminado
    if (!primero)
        ultimo = nullptr; // Si la cola queda vacía, actualizar el último nodo
    longitud--; // Decrementar la longitud de la cola

    // Mostrar los detalles del proceso eliminado
    std::cout << "Eliminado: PID=" << p.getPid() 
              << ", Usuario=" << p.getNombreUsuario() 
              << ", Prioridad=" << p.getPrioridad() 
              << ", Tiempo Real=" << (p.getEsTiempoReal() ? "Si" : "No") 
              << std::endl;

    return p;
}

// Método para ver el primer proceso de la cola sin eliminarlo
Proceso Cola::verPrimero() const {
    if (!primero)
        return Proceso(-1, "", false, 0, false, false); // Devuelve un objeto Proceso indicando que está vacío

    return primero->valor;
}

// Método para ordenar los procesos en la cola por prioridad
void Cola::ordenar() {
    if (primero == nullptr || primero->siguiente == nullptr) {
        return; // No hay nada que ordenar si la cola está vacía o tiene un solo elemento
    }

    NodoCola* sorted = nullptr; // Lista ordenada

    while (primero != nullptr) {
        NodoCola* current = primero;
        primero = primero->siguiente;

        if (sorted == nullptr || current->valor.getPrioridad() < sorted->valor.getPrioridad()) {
            current->siguiente = sorted;
            sorted = current;
        } else {
            NodoCola* temp = sorted;
            while (temp->siguiente != nullptr && temp->siguiente->valor.getPrioridad() <= current->valor.getPrioridad()) {
                temp = temp->siguiente;
            }
            current->siguiente = temp->siguiente;
            temp->siguiente = current;
        }
    }

    primero = sorted;

    // Actualizar el puntero 'ultimo'
    ultimo = primero;
    while (ultimo != nullptr && ultimo->siguiente != nullptr) {
        ultimo = ultimo->siguiente;
    }
}

// Destructor: Libera la memoria de todos los nodos en la cola
Cola::~Cola() {
    while (primero)
        eliminar();
}