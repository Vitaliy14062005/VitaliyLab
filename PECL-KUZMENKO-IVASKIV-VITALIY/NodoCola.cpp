#include "NodoCola.hpp"

// Constructor: Inicializa el nodo con un proceso y un puntero al siguiente nodo (por defecto nullptr)
NodoCola::NodoCola(const Proceso& p, NodoCola* sig)
    : valor(p), siguiente(sig) {}

// Destructor: Libera los recursos utilizados por el nodo
NodoCola::~NodoCola() {}
