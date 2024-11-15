#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Arbol.hpp"
#include <cstdlib>
#include <ctime>
class Gestor {
public:
    Gestor();
    ~Gestor();
    void genera12Procesos();
	void muestraProcesos();
	void borraProcesosPila();
	void encolarProcesos();
	void muestraProcesosGPUs0y1();
    void muestraProcesosGPUs2y3();
	void borraProcesosColas();
	void enlistarProcesos();
	void muestraProcesosNormal();
	void muestraProcesosTiempoReal();
    void buscarProcesos();
	void buscarProcesoPorNombreUsuario();
	void eliminarProcesoPorPID();
	void cambiarPrioridadProcesoPorPID();
	void reiniciar();
	void crearydibujarABB();
	int ProcesosEnListaNormal();
    int ProcesosEnListaTiempoReal();
	int ProcesosEnGPU0();
    int ProcesosEnGPU1();
    int ProcesosEnGPU2();
    int ProcesosEnGPU3();
    int ProcesosEnPila();
	int ProcesosEnArbol();
	
private:
    Pila pila;
	Cola cola;
	Arbol abb;
	Cola colas[4];
	Lista listaNormal;
    Lista listaTiempoReal;
	friend class Proceso;
};

#endif // GESTOR_HPP

