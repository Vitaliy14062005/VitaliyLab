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
        actual->valor.muestra(); 
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
		int objetivo;

        if (proceso.esTiempoReal()) {
            // Lógica específica para procesos de tiempo real
            nuevaPrioridad = proceso.generarPrioridadReal();
        } else {
            // Lógica específica para procesos normales
            nuevaPrioridad = proceso.generarPrioridadNormal();
        }
        proceso.setPrioridad(nuevaPrioridad[0]); // Asignar la primera prioridad del array
        delete[] nuevaPrioridad; // Liberar la memoria asignada
		

		if (!proceso.esTiempoReal()) { // Proceso normal
			if (colas[1].getLongitud() < colas[0].getLongitud()) {
				objetivo = 1;
			} else {
				objetivo = 0;
			}
		} else { // Proceso en tiempo real
			if (colas[3].getLongitud() < colas[2].getLongitud()) {
				objetivo = 3;
			} else {
				objetivo = 2;
			}
		}
			colas[objetivo].insertar(proceso);
			
		}  
}

void Gestor::muestraProcesosGPUs0y1()
{
    for (int i = 0; i < 2; ++i) {
        std::cout << "GPU " << i << ":" << std::endl;
        pnodoCola actual = colas[i].primero; 
        while (actual != nullptr) {
            actual->valor.muestra(); 
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
            actual->valor.muestra(); 
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
	Proceso::muestraCabeceras();
    while (actual != nullptr) {
        actual->valor.muestra(); // Llamar al método muestra
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }
}

void Gestor::muestraProcesosTiempoReal()
{
    pnodoLista actual = listaTiempoReal.getCabeza();
	
	Proceso::muestraCabeceras();
    while (actual != nullptr) {
        actual->valor.muestra(); // Llamar al método muestra
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
		menorPrioridadNormal->muestra();
    }
    if (mayorPrioridadTiempoReal != nullptr) {
		std::cout << "Tiempo Real mayor prioridad ->";
        mayorPrioridadTiempoReal->muestra();
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
			Proceso::muestraCabeceras();
			p.muestra();
        }
        actual = actual->siguiente;
    }

    actual = listaTiempoReal.getCabeza();
    
    while (actual != nullptr) {
        Proceso p = actual->valor;
        if (p.getUsuario() == usuario) {
			Proceso::muestraCabeceras();
			actual->valor.muestra();
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
		Proceso::muestraCabeceras();
		procesoEliminado.muestra();
        procesoEliminado.setenEjecucion(false);
		procesoEliminado.muestra();
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
	
    while (actual != nullptr) {
        if (actual->valor.getPid() == pid) {
			actual->valor.muestra();
			std::cout << "Ingrese la nueva prioridad: ";
			std::cin >> nuevaPrioridad;
            actual->valor.setPrioridad(nuevaPrioridad);
			Proceso::muestraCabeceras();
			actual->valor.muestra();
            encontrado = true;
        }
        actual = actual->siguiente;
    }

    // Si no se encontró en listaNormal, intentar cambiar prioridad en listaTiempoReal
    if (!encontrado) {
        actual = listaTiempoReal.getCabeza();
		Proceso::muestraCabeceras();
        while (actual != nullptr) {
            if (actual->valor.getPid() == pid) {
				actual->valor.muestra();
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
				actual->valor.muestra();
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

void Gestor::crearydibujarABB()
{
	int* nuevaPrioridad;

    // Insertar el nodo raíz ficticio con prioridad 100
    abb.insertar(100);

    // Extraer los procesos de la pila e insertarlos en el ABB
    while (pila.getLongitud() > 0) {
        Proceso proceso = pila.extraer();
		if (proceso.esTiempoReal()) {
            // Lógica específica para procesos de tiempo real
            nuevaPrioridad = proceso.generarPrioridadReal();
        } else {
            // Lógica específica para procesos normales
            nuevaPrioridad = proceso.generarPrioridadNormal();
        }
        proceso.setPrioridad(nuevaPrioridad[0]); // Asignar la primera prioridad del array
        delete[] nuevaPrioridad; // Liberar la memoria asignada
        abb.insertar(proceso.getPrioridad()); 
    }

    // Dibujar el ABB
    std::cout << "Arbol Binario de Busqueda (ABB):" << std::endl;
    abb.dibujar();
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
    return abb.getLongitud();
}

