#ifndef PERSONA_HPP
#define PERSONA_HPP
#include <iostream>

class Persona
{
private:
	bool genero;
	int edad;
	char dni[10];
	void generarDNI();
public:
	
	Persona(int edad);
	~Persona();
	Persona();
	
	int getEdad() const;
	bool esMujer() const;
	void setEdad(int edad);
	void mostrar() const;

};

#endif // PERSONA_HPP
