#include <stdio.h>
#include <iostream>
#include "Persona.hpp"
using namespace std;
 const int NUM_PERSONAS = 10;
bool edadYaExiste(int edad, const Persona personas[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (personas[i].getEdad() == edad) {
            return true;
        }
    }
    return false;
}
int main() {
    srand(time(0));

	Persona personas[NUM_PERSONAS];
	
    for (int i = 0; i < NUM_PERSONAS; i++) {
        int edad;
        do {
            edad = 18 + rand() % 10; // Generar edad entre 18 y 27
        } while (edadYaExiste(edad, personas, i)); // Comprobar que la edad no esté repetida

        personas[i] = Persona(edad);
    }

    for (int i = 0; i < NUM_PERSONAS; i++) {
        personas[i].mostrar();
    }
	cin.get();
    return 0;
}
