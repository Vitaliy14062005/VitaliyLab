#include <stdio.h>

#include <iostream>
using namespace std;

int menor(int x, int y) { // declaración y definición juntas
    return x < y ? x : y;
}

int menorde3(int x, int y, int z); // solo la declaración

int main(int argc, char** argv) {
    int a, b, c;  // Declaramos las variables a, b, y c

    cout << "Escribe tres datos enteros: ";
    cin >> a >> b >> c;  // Recibimos los tres datos enteros

    cout << "El menor de los tres números es: " << menorde3(a, b, c) << endl;

    return 0;
}

int menorde3(int x, int y, int z) { // Aquí la definición
    return menor(menor(x, y), z);
}