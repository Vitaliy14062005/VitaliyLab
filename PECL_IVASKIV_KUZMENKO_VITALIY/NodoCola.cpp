#include "NodoCola.hpp"
NodoCola::NodoCola(Proceso& p, NodoCola* sig) : valor(p), siguiente(sig)
{

}


NodoCola::~NodoCola()
{
	
}
