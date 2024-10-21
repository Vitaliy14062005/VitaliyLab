#include "Proceso.hpp"

// Constructor: Inicializa el proceso con los valores proporcionados
Proceso::Proceso(int p, const std::string& nombre, bool ejec, int prio, bool tiempoReal, bool valido)
    : pid(p),                  // Inicializa el identificador del proceso
      nombreUsuario(nombre),   // Inicializa el nombre del usuario
      enEjecucion(ejec),       // Inicializa el estado de ejecución
      prioridad(prio),         // Inicializa la prioridad del proceso
      esTiempoReal(tiempoReal),// Inicializa si el proceso es de tiempo real
      esValido(valido)         // Inicializa si el proceso es válido
{}
