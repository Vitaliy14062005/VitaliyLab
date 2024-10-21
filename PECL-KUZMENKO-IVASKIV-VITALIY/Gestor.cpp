#include "Gestor.hpp"
#include <iostream>   // Para std::cout
#include <cstdlib>    // Para std::srand y std::rand
#include <ctime>      // Para std::time
#include <algorithm>  // Para std::sort
#include <vector>     // Para std::vector

// Constructor: Inicializa el gestor y establece la semilla para la generación de números aleatorios
Gestor::Gestor() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Establecer la semilla para std::rand usando el tiempo actual
}

// Destructor: Libera los recursos utilizados por el gestor
Gestor::~Gestor() {
}

void Gestor::genera12Procesos() {
    for (int i = 0; i < 12; ++i) {
        int pid = 300 + i + 1; // PID único a partir de 300
        std::string nombre = "Usuario" + std::to_string(i + 1); // Nombre del usuario
        bool enEjecucion = false; // Estado del proceso (parado)
        bool esValido = true;
        bool esTiempoReal = (std::rand() % 2 == 1); // Generar si es tiempo real o no

        int prioridad;
        if (esTiempoReal) {
            prioridad = std::rand() % 100; // Prioridad para procesos en tiempo real (0-99)
        } else {
            prioridad = -19 + (std::rand() % 39); // Prioridad para procesos normales (-19 a +19)
            prioridad = 120 + prioridad; // Ajuste de prioridad para procesos normales
        }

        // Crear el proceso
        Proceso p(pid, nombre, enEjecucion, prioridad, esTiempoReal, esValido);

        // Imprimir todos los detalles del proceso
        std::cout << "Proceso " << i + 1 << ":\n"
                  << "  PID: " << p.getPid() << "\n"
                  << "  Nombre de Usuario: " << p.getNombreUsuario() << "\n"
                  << "  Estado: " << (p.getEnEjecucion() ? "En Ejecucion" : "Parado") << "\n"
                  << "  Prioridad: " << p.getPrioridad() << "\n"
                  << "  Tipo: " << (p.getEsTiempoReal() ? "Tiempo Real" : "Normal") << "\n"
                  << "  Valido: " << (p.getEsValido() ? "Si" : "No") << "\n";

        // Almacenar el proceso en la pila
        pila.insertar(p);
    }
}

void Gestor::muestraProcesos() {
    if (pila.estaVacia()) {
        std::cout << "No hay procesos en la pila.\n";
        return;
    }

    pila.mostrar(); // Llamar al método mostrar de la pila
}

void Gestor::borraProcesosPila() {
    while (!pila.estaVacia()) {
        pila.extraer(); // Extraer y eliminar todos los procesos de la pila
    }
}

void Gestor::encolarProcesos() {
    Cola::encolarDesdePila(pila, colas, 4);
}

void Gestor::muestraProcesosGPUs0y1() {
    for (int i = 0; i < 2; ++i) {
        if (colas[i].estaVacia()) {
            std::cout << "No hay procesos en la cola de GPU " << i << ".\n";
            continue;
        }
        std::cout << "GPU " << i << " - ";
        colas[i].mostrar();
    }
}

void Gestor::muestraProcesosGPUs2y3() {
    for (int i = 2; i < 4; ++i) {
        if (colas[i].estaVacia()) {
            std::cout << "No hay procesos en la cola de GPU " << i << ".\n";
            continue;
        }
        std::cout << "GPU " << i << " - ";
        colas[i].mostrar();
    }
}

void Gestor::borraProcesosColas() {
    for (int i = 0; i < 4; ++i) {
        if (colas[i].estaVacia()) {
            std::cout << "No hay procesos en la cola de GPU " << i << " para borrar.\n";
            continue;
        }
        while (!colas[i].estaVacia()) {
            colas[i].eliminar(); // Eliminar todos los procesos de la cola
        }
    }
}

void Gestor::enlistarProcesos() {
    for (int i = 0; i < 4; ++i) {
        if (colas[i].estaVacia()) {
            std::cout << "No hay procesos en la cola de GPU " << i << " para enlistar.\n";
            continue;
        }
        while (!colas[i].estaVacia()) {
            Proceso p = colas[i].eliminar(); // Eliminar el proceso de la cola
            p.enEjecucion = true; // Establecer el estado del proceso en ejecución
            std::cout << "Proceso con PID " << p.getPid() << " ahora esta en ejecucion.\n"; // Mensaje de depuración
            if (i < 2) {
                listaNormal.insertar(p); // Insertar en la lista normal si es GPU 0 o 1
            } else {
                listaTiempoReal.insertar(p); // Insertar en la lista de tiempo real si es GPU 2 o 3
            }
        }
    }
}

void Gestor::muestraProcesosNormal() {
    NodoLista* actual = listaNormal.getCabeza();
    std::cout << "Procesos en la lista Normal:\n";
    while (actual != nullptr) {
        Proceso p = actual->valor;
        std::cout << "PID: " << p.getPid() 
                  << ", Usuario: " << p.getNombreUsuario() 
                  << ", Prioridad: " << p.getPrioridad() 
                  << ", En ejecucion: " << (p.getEnEjecucion() ? "Si" : "No") 
                  << std::endl;
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }
}

void Gestor::muestraProcesosTiempoReal() {
    NodoLista* actual = listaTiempoReal.getCabeza();
    std::cout << "Procesos en la lista Tiempo Real:\n";
    while (actual != nullptr) {
        Proceso p = actual->valor;
        std::cout << "PID: " << p.getPid() 
                  << ", Usuario: " << p.getNombreUsuario() 
                  << ", Prioridad: " << p.getPrioridad() 
                  << ", En ejecucion: " << (p.getEnEjecucion() ? "Si" : "No") 
                  << std::endl;
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }
}


void Gestor::buscarProcesos() {
    if (listaNormal.estaVacia() && listaTiempoReal.estaVacia()) {
        std::cout << "No hay procesos en las listas.\n";
        return;
    }

    // Buscar el proceso con la menor prioridad en la lista normal
    NodoLista* actual = listaNormal.getCabeza();
    Proceso* menorPrioridadNormal = nullptr;
    while (actual != nullptr) {
        if (menorPrioridadNormal == nullptr || actual->valor.getPrioridad() > menorPrioridadNormal->getPrioridad()) {
            menorPrioridadNormal = &actual->valor;
        }
        actual = actual->siguiente;
    }

    if (menorPrioridadNormal != nullptr) {
        std::cout << "Proceso con menor prioridad en lista Normal:\n";
        std::cout << "PID: " << menorPrioridadNormal->getPid() 
                  << ", Usuario: " << menorPrioridadNormal->getNombreUsuario() 
                  << ", Prioridad: " << menorPrioridadNormal->getPrioridad() 
                  << std::endl;
    } else {
        std::cout << "No hay procesos en la lista Normal.\n";
    }

    // Buscar el proceso con la mayor prioridad en la lista de tiempo real
    actual = listaTiempoReal.getCabeza();
    Proceso* mayorPrioridadTiempoReal = nullptr;
    while (actual != nullptr) {
        if (mayorPrioridadTiempoReal == nullptr || actual->valor.getPrioridad() < mayorPrioridadTiempoReal->getPrioridad()) {
            mayorPrioridadTiempoReal = &actual->valor;
        }
        actual = actual->siguiente;
    }

    if (mayorPrioridadTiempoReal != nullptr) {
        std::cout << "Proceso con mayor prioridad en lista Tiempo Real:\n";
        std::cout << "PID: " << mayorPrioridadTiempoReal->getPid() 
                  << ", Usuario: " << mayorPrioridadTiempoReal->getNombreUsuario() 
                  << ", Prioridad: " << mayorPrioridadTiempoReal->getPrioridad() 
                  << std::endl;
    } else {
        std::cout << "No hay procesos en la lista Tiempo Real.\n";
    }
}

void Gestor::buscarProcesoPorNombreUsuario() {
    std::string nombreUsuario;
    std::cout << "Ingrese el nombre de usuario: ";
    std::cin >> nombreUsuario;

    NodoLista* actual = listaNormal.getCabeza();
    std::cout << "Buscando en la lista Normal:\n";
    while (actual != nullptr) {
        Proceso p = actual->valor;
        if (p.getNombreUsuario() == nombreUsuario) {
            std::cout << "Encontrado - PID: " << p.getPid() 
                      << ", Usuario: " << p.getNombreUsuario() 
                      << ", Prioridad: " << p.getPrioridad() 
                      << std::endl;
        }
        actual = actual->siguiente;
    }

    actual = listaTiempoReal.getCabeza();
    std::cout << "Buscando en la lista Tiempo Real:\n";
    while (actual != nullptr) {
        Proceso p = actual->valor;
        if (p.getNombreUsuario() == nombreUsuario) {
            std::cout << "Encontrado - PID: " << p.getPid() 
                      << ", Usuario: " << p.getNombreUsuario() 
                      << ", Prioridad: " << p.getPrioridad() 
                      << std::endl;
        }
        actual = actual->siguiente;
    }
}

void Gestor::eliminarProcesoPorPID() {
    int pid;
    std::cout << "Ingrese el PID del proceso a eliminar: ";
    std::cin >> pid;

    bool eliminado = false;

    try {
        listaNormal.eliminar(pid);
        std::cout << "Proceso con PID " << pid << " eliminado de la lista Normal.\n";
        eliminado = true;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error en lista Normal: " << e.what() << "\n";
    }

    try {
        listaTiempoReal.eliminar(pid);
        std::cout << "Proceso con PID " << pid << " eliminado de la lista Tiempo Real.\n";
        eliminado = true;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error en lista Tiempo Real: " << e.what() << "\n";
    }

    if (!eliminado) {
        std::cout << "Proceso con PID " << pid << " no encontrado en ninguna lista.\n";
    }
}

void Gestor::cambiarPrioridadProcesoPorPID() {
    int pid, nuevaPrioridad;
    std::cout << "Ingrese el PID del proceso: ";
    std::cin >> pid;
    std::cout << "Ingrese la nueva prioridad: ";
    std::cin >> nuevaPrioridad;

    bool cambiado = false;

    try {
        Proceso& p = listaNormal.buscar(pid); // Obtener una referencia
        p.prioridad = nuevaPrioridad;
        std::cout << "Prioridad del proceso con PID " << pid << " cambiada a " << nuevaPrioridad << " en la lista Normal.\n";
        listaNormal.ordenar(); // Reordenar la lista después de cambiar la prioridad
        cambiado = true;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error en lista Normal: " << e.what() << "\n";
    }

    try {
        Proceso& p = listaTiempoReal.buscar(pid); // Obtener una referencia
        p.prioridad = nuevaPrioridad;
        std::cout << "Prioridad del proceso con PID " << pid << " cambiada a " << nuevaPrioridad << " en la lista Tiempo Real.\n";
        listaTiempoReal.ordenar(); // Reordenar la lista después de cambiar la prioridad
        cambiado = true;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error en lista Tiempo Real: " << e.what() << "\n";
    }

    if (!cambiado) {
        std::cout << "Proceso con PID " << pid << " no encontrado en ninguna lista.\n";
    }
}

void Gestor::reiniciar() {
    borraProcesosPila();
    borraProcesosColas();
    while (!listaNormal.estaVacia()) {
        listaNormal.eliminar(listaNormal.getCabeza()->valor.getPid());
    }
    while (!listaTiempoReal.estaVacia()) {
        listaTiempoReal.eliminar(listaTiempoReal.getCabeza()->valor.getPid());
    }
}

int Gestor::ProcesosEnPila() const {
    return pila.getLongitud();
}

int Gestor::ProcesosEnGPU0() const {
    return colas[0].getLongitud();
}

int Gestor::ProcesosEnGPU1() const {
    return colas[1].getLongitud();
}

int Gestor::ProcesosEnGPU2() const {
    return colas[2].getLongitud();
}

int Gestor::ProcesosEnGPU3() const {
    return colas[3].getLongitud();
}

int Gestor::ProcesosEnListaNormal() const {
    return listaNormal.getLongitud();
}

int Gestor::ProcesosEnListaTiempoReal() const {
    return listaTiempoReal.getLongitud();
}

int Gestor::ProcesosEnArbol() const {
    // SIGUIENTE PARTE
    return 0; 
}