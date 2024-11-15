#include "Gestor.hpp"

Gestor::Gestor()
{
    std::srand(std::time(0));
}

Gestor::~Gestor()
{

}

void Gestor::genera12Procesos() 
{
	if (pila.getLongitud() < 48) {
            for (int i = 0; i < 12; ++i) {
                Proceso proceso(0);
                pila.insertar(proceso);
		}
	}
}

void Gestor::muestraProcesos()
{
	pnodoPila actual = pila.ultimo; 
	while (actual != nullptr) {
        actual->valor.muestraPila(); 
        actual = actual->siguiente;
    }
}

void Gestor::borraProcesosPila()
{
	pila.~Pila();
}

void Gestor::encolarProcesos()
{
	while (pila.getLongitud() > 0) {
        Proceso proceso = pila.extraer();
        int* nuevaPrioridad;

        if (proceso.esTiempoReal()) {
            // Lógica específica para procesos de tiempo real
            nuevaPrioridad = proceso.generarPrioridadReal();
        } else {
            // Lógica específica para procesos normales
            nuevaPrioridad = proceso.generarPrioridadNormal();
        }
        proceso.setPrioridad(nuevaPrioridad[0]); // Asignar la primera prioridad del array
        delete[] nuevaPrioridad; // Liberar la memoria asignada
		int objetivo = cola.decidirCola(proceso, colas);
		colas[objetivo].insertar(proceso);
		
	}  
}

void Gestor::muestraProcesosGPUs0y1()
{
    for (int i = 0; i < 2; ++i) {
        std::cout << "GPU " << i << ":" << std::endl;
        pnodoCola actual = colas[i].primero; 
        while (actual != nullptr) {
            actual->valor.muestraCola(); 
            actual = actual->siguiente;
        }
    }
}

void Gestor::muestraProcesosGPUs2y3()
{
    for (int i = 2; i < 4; ++i)
		{
        std::cout << "GPU " << i << ":" << std::endl; // Imprimir el encabezado de la GPU
        pnodoCola actual = colas[i].primero; 
        while (actual != nullptr) {
            actual->valor.muestraCola(); 
            actual = actual->siguiente;
        }
    }
}

void Gestor::borraProcesosColas()
{
	colas[0].~Cola();
	colas[1].~Cola();
	colas[2].~Cola();
	colas[3].~Cola();
}

void Gestor::enlistarProcesos()
{
    bool colasVacias = false;

    while (!colasVacias) {
        colasVacias = true; // Suponemos que las colas están vacías hasta que se demuestre lo contrario

        for (int i = 0; i < 4; ++i) {
            if (colas[i].getLongitud() > 0) {
                colasVacias = false; // Si encontramos una cola no vacía, cambiamos el estado
                Proceso p = colas[i].eliminar(); 
                p.enEjecucion = true; // Establecer el estado del proceso en ejecución
                if (i < 2) {
                    listaNormal.insertar(p); // Insertar en la lista normal si es GPU 0 o 1
                } else {
                    listaTiempoReal.insertar(p); // Insertar en la lista de tiempo real si es GPU 2 o 3
                }
            }
        }
    }
}

void Gestor::muestraProcesosNormal()
{
    pnodoLista actual = listaNormal.getCabeza();
	std::cout << std::left << std::setw(10) << "PID" 
              << std::setw(15) << "Usuario" 
              << std::setw(15) << "Tipo" 
              << std::setw(15) << "Estado" 
              << std::setw(10) << "Prioridad" 
              << std::endl;
    while (actual != nullptr) {
        actual->valor.muestraLista2(); // Llamar al método muestra
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }
}

void Gestor::muestraProcesosTiempoReal()
{
    pnodoLista actual = listaTiempoReal.getCabeza();
	std::cout << std::left << std::setw(10) << "PID" 
              << std::setw(15) << "Usuario" 
              << std::setw(15) << "Tipo" 
              << std::setw(15) << "Estado" 
              << std::setw(10) << "Prioridad" 
              << std::endl;
    while (actual != nullptr) {
        actual->valor.muestraLista2(); // Llamar al método muestra
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }
}

void Gestor::buscarProcesos()
{
    NodoLista* actual = listaNormal.getCabeza();
    Proceso* menorPrioridadNormal = nullptr;
    while (actual != nullptr) {
        if (menorPrioridadNormal == nullptr || actual->valor.getPrioridad() > menorPrioridadNormal->getPrioridad()) {
            menorPrioridadNormal = &actual->valor;
        }
        actual = actual->siguiente;
    }

    // Buscar el proceso con la mayor prioridad en la lista de tiempo real
    actual = listaTiempoReal.getCabeza();
    Proceso* mayorPrioridadTiempoReal = nullptr;
    while (actual != nullptr) {
        if (mayorPrioridadTiempoReal == nullptr || actual->valor.getPrioridad() < mayorPrioridadTiempoReal->getPrioridad()) {
            mayorPrioridadTiempoReal = &actual->valor;
        }
        actual = actual->siguiente;
    }

    // Mostrar los procesos encontrados
    if (menorPrioridadNormal != nullptr) {
        std::cout << "Normal menor prioridad ->";
		menorPrioridadNormal->muestra4();
    }
    if (mayorPrioridadTiempoReal != nullptr) {
		std::cout << "Tiempo Real mayor prioridad ->";
        mayorPrioridadTiempoReal->muestra4();
    }
}

void Gestor::buscarProcesoPorNombreUsuario()
{
    int usuario;
    std::cout << "Ingrese el usuario: ";
    std::cin >> usuario;

    NodoLista* actual = listaNormal.getCabeza();
    while (actual != nullptr) {
        Proceso p = actual->valor;
        if (p.getUsuario() == usuario) {
			actual->valor.muestraPila();
        }
        actual = actual->siguiente;
    }

    actual = listaTiempoReal.getCabeza();
    std::cout << std::left << std::setw(10) << "PID" 
              << std::setw(15) << "Usuario" 
              << std::setw(15) << "Tipo" 
              << std::setw(15) << "Estado" 
              << std::setw(10) << "Prioridad" 
              << std::endl;
    while (actual != nullptr) {
        Proceso p = actual->valor;
        if (p.getUsuario() == usuario) {
			actual->valor.muestraLista2();
        }
        actual = actual->siguiente;
    }
}

void Gestor::eliminarProcesoPorPID()
{
    int pid;
    std::cout << "Ingrese el PID del proceso a eliminar: ";
    std::cin >> pid;

    Proceso procesoEliminado(0);
    bool encontrado = false;

    // Intentar eliminar de listaNormal
    NodoLista* actual = listaNormal.getCabeza();
    while (actual != nullptr) {
        if (actual->valor.getPid() == pid) {
            procesoEliminado = listaNormal.eliminar(pid);
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    }

    // Si no se encontró en listaNormal, intentar eliminar de listaTiempoReal
    if (!encontrado) {
        actual = listaTiempoReal.getCabeza();
        while (actual != nullptr) {
            if (actual->valor.getPid() == pid) {
                Proceso procesoEliminado = listaTiempoReal.eliminar(pid);
                encontrado = true;
                break;
            }
            actual = actual->siguiente;
        }
    }

    if (encontrado) {
		std::cout << std::left << std::setw(10) << "PID" 
              << std::setw(15) << "Usuario" 
              << std::setw(15) << "Tipo" 
              << std::setw(15) << "Estado" 
              << std::setw(10) << "Prioridad" 
              << std::endl;
		procesoEliminado.muestraLista2();
        procesoEliminado.setenEjecucion(false);
		procesoEliminado.muestraLista();
        pila.insertar(procesoEliminado);
    }
}

void Gestor::cambiarPrioridadProcesoPorPID()
{
    int pid, nuevaPrioridad;
    std::cout << "Ingrese el PID del proceso: ";
    std::cin >> pid;
    bool encontrado = false;

    // Intentar cambiar prioridad en listaNormal
    NodoLista* actual = listaNormal.getCabeza();
	std::cout << std::left << std::setw(10) << "PID" 
              << std::setw(15) << "Usuario" 
              << std::setw(15) << "Tipo" 
              << std::setw(15) << "Estado" 
              << std::setw(10) << "Prioridad" 
              << std::endl;
    while (actual != nullptr) {
        if (actual->valor.getPid() == pid) {
			actual->valor.muestraLista2();
			std::cout << "Ingrese la nueva prioridad: ";
			std::cin >> nuevaPrioridad;
            actual->valor.setPrioridad(nuevaPrioridad);
			std::cout << std::left << std::setw(10) << "PID" 
              << std::setw(15) << "Usuario" 
              << std::setw(15) << "Tipo" 
              << std::setw(15) << "Estado" 
              << std::setw(10) << "Prioridad" 
              << std::endl;
			actual->valor.muestraLista2();
            encontrado = true;
        }
        actual = actual->siguiente;
    }

    // Si no se encontró en listaNormal, intentar cambiar prioridad en listaTiempoReal
    if (!encontrado) {
        actual = listaTiempoReal.getCabeza();
		std::cout << std::left << std::setw(10) << "PID" 
              << std::setw(15) << "Usuario" 
              << std::setw(15) << "Tipo" 
              << std::setw(15) << "Estado" 
              << std::setw(10) << "Prioridad" 
              << std::endl;
        while (actual != nullptr) {
            if (actual->valor.getPid() == pid) {
				actual->valor.muestraLista2();
			std::cout << "Ingrese la nueva prioridad: ";
			std::cin >> nuevaPrioridad;
            actual->valor.setPrioridad(nuevaPrioridad);
                actual->valor.setPrioridad(nuevaPrioridad);
				std::cout << std::left << std::setw(10) << "PID" 
              << std::setw(15) << "Usuario" 
              << std::setw(15) << "Tipo" 
              << std::setw(15) << "Estado" 
              << std::setw(10) << "Prioridad" 
              << std::endl;
				actual->valor.muestraLista2();
                encontrado = true;
            }
            actual = actual->siguiente;
        }
    }
}

void Gestor::reiniciar()
{
	pila.~Pila();
	colas[0].~Cola();
	colas[1].~Cola();
	colas[2].~Cola();
	colas[3].~Cola();
	listaNormal.~Lista();
	listaTiempoReal.~Lista();
}

int Gestor::ProcesosEnPila()
{
    return pila.getLongitud();
}

int Gestor::ProcesosEnGPU0()
{
    return colas[0].getLongitud();
}

int Gestor::ProcesosEnGPU1()
{
    return colas[1].getLongitud();
}

int Gestor::ProcesosEnGPU2()
{
    return colas[2].getLongitud();
}

int Gestor::ProcesosEnGPU3()
{
    return colas[3].getLongitud();
}

int Gestor::ProcesosEnListaNormal()
{
    return listaNormal.getLongitud();
}

int Gestor::ProcesosEnListaTiempoReal()
{
    return listaTiempoReal.getLongitud();
}
int Gestor::ProcesosEnArbol()
{
    return 0;
}

