#include "NodoPila.hpp"

NodoPila::NodoPila(Proceso& p, NodoPila* sig) : valor(p), siguiente(sig)
{
	
}
NodoPila::~NodoPila()
{
	
}
