#include "Lista.hpp"
#include <stdexcept>
#include <iostream>

// Constructor: Inicializa la lista con cabeza nula y longitud 0
Lista::Lista() : cabeza(nullptr), longitud(0) {}

// Destructor: Elimina todos los nodos de la lista
Lista::~Lista() {
    while (!estaVacia()) {
        eliminar(cabeza->valor.getPid());
    }
}

// Método para insertar un proceso al inicio de la lista
void Lista::insertar(const Proceso& p) {
    NodoLista* nuevo = new NodoLista(p);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
    longitud++; // Incrementar longitud
}

// Método para enlistar procesos desde colas
void Lista::enlistarDesdeColas(Cola colas[], int numColas, Lista& listaNormal, Lista& listaTiempoReal) {
    for (int i = 0; i < numColas; ++i) {
        if (colas[i].estaVacia()) {
            std::cout << "No hay procesos en la cola de GPU " << i << " para enlistar.\n";
            continue;
        }
        while (!colas[i].estaVacia()) {
            Proceso p = colas[i].eliminar(); // Eliminar el proceso de la cola
            p.enEjecucion = true; // Establecer el estado del proceso en ejecución
            std::cout << "Proceso con PID " << p.getPid() << " ahora esta en ejecucion.\n"; // Mensaje de depuración
            if (i < numColas / 2) {
                listaNormal.insertar(p); // Insertar en la lista normal si es GPU 0 o 1
            } else {
                listaTiempoReal.insertar(p); // Insertar en la lista de tiempo real si es GPU 2 o 3
            }
        }
    }
}

// Método para eliminar un proceso de la lista por su PID
void Lista::eliminar(int pid) {
    NodoLista* actual = cabeza;
    NodoLista* anterior = nullptr;

    while (actual != nullptr) {
        std::cout << "Revisando nodo con PID: " << actual->valor.getPid() << std::endl;
        if (actual->valor.getPid() == pid) {
            std::cout << "Proceso encontrado. Eliminando PID: " << pid << std::endl;
            if (anterior == nullptr) {
                cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            longitud--; // Decrementar longitud
            std::cout << "Proceso eliminado. Longitud actual: " << longitud << std::endl;
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    throw std::runtime_error("Proceso no encontrado.");
}

// Método para buscar un proceso en la lista por su PID y devolver una referencia al proceso
Proceso& Lista::buscar(int pid) {
    NodoLista* actual = cabeza;

    while (actual != nullptr) {
        if (actual->valor.getPid() == pid) {
            return actual->valor; // Devolver una referencia al objeto Proceso
        }
        actual = actual->siguiente;
    }

    throw std::runtime_error("Proceso no encontrado");
}

// Método para ordenar la lista por prioridad (menor a mayor)
void Lista::ordenar() {
    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
        return; // No hay nada que ordenar si la lista está vacía o tiene un solo elemento
    }

    NodoLista* sorted = nullptr; // Lista ordenada

    while (cabeza != nullptr) {
        NodoLista* current = cabeza;
        cabeza = cabeza->siguiente;

        if (sorted == nullptr || current->valor.getPrioridad() < sorted->valor.getPrioridad()) {
            current->siguiente = sorted;
            sorted = current;
        } else {
            NodoLista* temp = sorted;
            while (temp->siguiente != nullptr && temp->siguiente->valor.getPrioridad() <= current->valor.getPrioridad()) {
                temp = temp->siguiente;
            }
            current->siguiente = temp->siguiente;
            temp->siguiente = current;
        }
    }

    cabeza = sorted;
}

// Método para verificar si la lista está vacía
bool Lista::estaVacia() const {
    return cabeza == nullptr;
}

// Método para obtener el puntero al primer nodo de la lista
NodoLista* Lista::getCabeza() const {
    return cabeza;
}

// Método para obtener la longitud de la lista
int Lista::getLongitud() const {
    return longitud; // Devolver longitud
}