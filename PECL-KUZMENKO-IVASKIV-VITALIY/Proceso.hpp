#ifndef PROCESO_HPP
#define PROCESO_HPP

#include <string> // Incluir solo lo necesario

// Definición de la clase Proceso
class Proceso {
public:
    int pid;                  // Identificador del proceso
    std::string nombreUsuario; // Nombre del usuario que ejecuta el proceso
    bool enEjecucion;         // Estado de ejecución del proceso
    int prioridad;            // Prioridad del proceso
    bool esTiempoReal;        // Indica si el proceso es de tiempo real
    bool esValido;            // Indica si el proceso es válido

    // Constructor con parámetros: Inicializa todos los atributos del proceso
    Proceso(int p, const std::string& nombre, bool ejec, int prio, bool tiempoReal, bool valido);

    // Métodos getter: Devuelven los valores de los atributos del proceso
    int getPid() const { return pid; }
    std::string getNombreUsuario() const { return nombreUsuario; }
    bool getEnEjecucion() const { return enEjecucion; }
    int getPrioridad() const { return prioridad; }
    bool getEsTiempoReal() const { return esTiempoReal; }
    bool getEsValido() const { return esValido; }
};

#endif // PROCESO_HPP
