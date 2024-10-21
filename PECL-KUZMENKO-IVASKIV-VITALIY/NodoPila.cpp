#include "NodoPila.hpp"

// Constructor: Inicializa el nodo con un proceso y un puntero al siguiente nodo (por defecto nullptr)
NodoPila::NodoPila(const Proceso& p, NodoPila* sig) 
	  : valor(p), siguiente(sig) {}

// Destructor: Libera los recursos utilizados por el nodo
NodoPila::~NodoPila() {}
