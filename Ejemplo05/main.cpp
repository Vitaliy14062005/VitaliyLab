#include <stdio.h>
#include <iostream>
using namespace std;
const int minimo = 0, maximo = 10;

int main(int argc, char **argv)
{
	int n;
	cout << "introduzca un numero entre" << minimo << "y" << maximo << "." << endl;
	cin >> n;
	if((n < minimo) || (n > maximo))
		cout << "el valor" << n << "esta feura del rango" << endl;
	else
		switch(n) {
			case 0:
				cout << "no existe definicion del primo en este caso" << endl;
				break;
			case 2:
			case 3:
			case 5:
			case 7:
				cout << "el numero" << n << "es primo" << endl;
				break;
			default:
				cout << "el numero" << n << "no es primo" << endl;
				break;
		};
		
	return 0;
}
