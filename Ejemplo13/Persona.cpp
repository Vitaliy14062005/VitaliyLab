#include "Persona.hpp"
using namespace std;
Persona::Persona() {
    this->edad = 0;          // Edad predeterminada
    this->genero = false;    // Género predeterminado (0 = Hombre)
    generarDNI();            // Generar un DNI aleatorio
}
void Persona::generarDNI(){
	for (int i = 0; i < 8; i++){
		dni[i] = '0' + rand() % 10;
	}
	dni[8] = 'A' + rand() % 26;
	 dni[9] = '\0';  
}
// Constructor con parámetro edad
Persona::Persona(int edad) {
    this->edad = edad;
    this->genero = rand() % 2;  // Genero aleatorio: 0 = Hombre, 1 = Mujer
    generarDNI();
}

// Destructor
Persona::~Persona() {
    // Destructor vacío porque no hay recursos dinámicos que liberar
}

// Obtener la edad
int Persona::getEdad() const {
    return edad;
}

// Determinar si la persona es mujer
bool Persona::esMujer() const {
    return genero;  // Retorna 1 si es mujer, 0 si es hombre
}

// Establecer la edad
void Persona::setEdad(int edad) {
    this->edad = edad;
}

// Mostrar información de la persona
void Persona::mostrar() const {
    cout << "DNI: " << dni << ", Edad: " << edad << ", Género: " 
         << (genero ? "Mujer" : "Hombre") << endl;
}

