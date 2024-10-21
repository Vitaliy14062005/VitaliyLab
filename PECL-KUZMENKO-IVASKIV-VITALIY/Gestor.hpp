#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"

// Definición de la clase Gestor
class Gestor {
private:
    Pila pila;                // Pila para gestionar procesos
    Cola colas[4];            // Array de 4 colas para diferentes tipos de procesos
    Lista listaNormal;        // Lista para procesos normales
    Lista listaTiempoReal;    // Lista para procesos en tiempo real

public:
    // Constructor: Inicializa el gestor
    Gestor();

    // Destructor: Libera los recursos utilizados por el gestor
    ~Gestor();

    // Método para generar 12 procesos
    void genera12Procesos();

    // Método para mostrar todos los procesos
    void muestraProcesos();

    // Método para borrar todos los procesos de la pila
    void borraProcesosPila();

    // Método para encolar procesos desde la pila a las colas
    void encolarProcesos();

    // Método para mostrar los procesos en las colas de GPU 0 y 1
    void muestraProcesosGPUs0y1();

    // Método para mostrar los procesos en las colas de GPU 2 y 3
    void muestraProcesosGPUs2y3();

    // Método para borrar todos los procesos de las colas
    void borraProcesosColas();

    // Método para enlistar procesos
    void enlistarProcesos();

    // Método para mostrar los procesos en la lista normal
    void muestraProcesosNormal();

    // Método para mostrar los procesos en la lista de tiempo real
    void muestraProcesosTiempoReal();

    // Método para buscar un proceso por nombre de usuario
    void buscarProcesoPorNombreUsuario();

    // Método para eliminar un proceso por su PID
    void eliminarProcesoPorPID();

    // Método para cambiar la prioridad de un proceso por su PID
    void cambiarPrioridadProcesoPorPID();

    // Método para reiniciar el gestor
    void reiniciar();

    // Método para buscar procesos
    void buscarProcesos(); 

    // Métodos para obtener el número de procesos en diferentes estructuras
    int ProcesosEnPila() const;
    int ProcesosEnGPU0() const;
    int ProcesosEnGPU1() const;
    int ProcesosEnGPU2() const;
    int ProcesosEnGPU3() const;
    int ProcesosEnListaNormal() const;
    int ProcesosEnListaTiempoReal() const;
    int ProcesosEnArbol() const;
};

#endif // GESTOR_HPP
