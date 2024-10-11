#define LISTA_HPP

#include "NodoLista.hpp"
using namespace std;

class Lista {
public:
    Lista();  
    ~Lista(); 

    void agregar(int valor);  
    int extraer();           
    int primero();           
    void mostrar() const;     
    int getLongitud() const;  
    bool vacia() const;       

private:
    pnodoLista cabeza;  
    int longitud;      
};

#endif // LISTA_HPP
