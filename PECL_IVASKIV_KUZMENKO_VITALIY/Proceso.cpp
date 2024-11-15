#include "Proceso.hpp"


using namespace std;


Proceso::Proceso(int prioridad)
{
    int* pids = generarPid();
    int indice = 0;
    
    this->prioridad = prioridad;
    this->pid = pids[indice]++;
    this->usuario = generarUsuario();
    this->enEjecucion = false;
    this->TiempoReal = (std::rand() % 2);
}

int* Proceso::generarPrioridadNormal()
{
	int n = 39;
    int* a = new int[n]; 

    for (int i = 0; i < n; ++i) {
        a[i] = i - 19 + 120;
    }
    random_shuffle(a, a + n); 

    return a; 
    
}

int* Proceso::generarPrioridadReal()
{
	int n = 100;
    int* a = new int[n]; 

    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
    random_shuffle(a, a + n); 

    return a; 
    
}

int* Proceso::generarPid()
{
    int n = 100;
    int* a = new int[n]; // Array para PIDs

    for (int i = 0; i < n; ++i) {
        a[i] = i + 300; // Valores de PID desde 300
    }
    random_shuffle(a, a + n); // Desordenar PIDs aleatorios

    return a; // Devolver el array de PIDs
}

int Proceso::generarUsuario()
{
    static int usuarios = 0;
    return ++usuarios; // Incrementa y devuelve el nuevo valor de usuarios
}

int Proceso::getPrioridad()
{
    return this->prioridad;
}

int Proceso::getPid()
{
    return this->pid;
}

int Proceso::getUsuario()
{
    return this->usuario;
}

bool Proceso::getenEjecucion()
{
    return this->enEjecucion;
}

void Proceso::setPrioridad(int prioridad)
{
    this->prioridad = prioridad;
}

void Proceso::setPid(int pid)
{
    this->pid = pid;
}

void Proceso::setenEjecucion(bool enEjecucion)
{
    this->enEjecucion = enEjecucion;
}

bool Proceso::esenEjecucion()
{
    return this->enEjecucion;
}

bool Proceso::esTiempoReal()
{
    return this->TiempoReal;
}

void Proceso::muestraPila()
{
    cout << "El proceso cuyo PID " << pid << " es de tipo " 
         << (TiempoReal ? "tiempo real" : "normal")<< std::endl;
}

void Proceso::muestraCola()
{
    cout << "El proceso cuyo PID " << pid << " es de tipo " 
         << (TiempoReal ? "tiempo real" : "normal") << ", su estado es " 
         << (enEjecucion ? "en ejecucion" : "parado") 
         << " y su prioridad es " << prioridad << std::endl;
}

void Proceso::muestraLista()
{
    cout << "El proceso cuyo PID " << pid << " es de tipo " 
         << (TiempoReal ? "tiempo real" : "normal") << ", su estado es " 
         << (enEjecucion ? "en ejecucion" : "parado") 
         << " y su prioridad es " << prioridad << std::endl;
}

void Proceso::muestraLista2()
{
	 std::cout << std::left << std::setw(10) << pid 
                  << std::setw(15) << usuario
                  << std::setw(15) << (TiempoReal ? "tiempo real" : "normal") 
                  << std::setw(15) << (enEjecucion ? "en ejecucion" : "parado") 
                  << std::setw(10) << prioridad 
                  << std::endl;
}

void Proceso::muestra4()
{
    cout << "El proceso cuyo PID " << pid << " es de tipo " 
         << (TiempoReal ? "tiempo real" : "normal") << ", su estado es " 
         << (enEjecucion ? "en ejecucion" : "parado") 
         << " y su prioridad es " << prioridad << std::endl;
}

Proceso::~Proceso()
{
    // Liberar memoria si es necesario
}
