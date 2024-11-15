#ifndef PROCESO_HPP
#define PROCESO_HPP
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
class Proceso 
{
public:
	
	Proceso(int prioridad);
	int getPid();
	int getUsuario();
	int getPrioridad();
	void setPrioridad(int prioridad);
	void setPid(int pid);
	bool getenEjecucion();
	void setenEjecucion(bool enEjecucion);
	
	void setUsuario();
	bool esenEjecucion();
	bool esTiempoReal();
	void muestra();
	static void muestraCabeceras();
	~Proceso();
	
private:
	int* generarPid();
	int generarUsuario();
	int* generarPrioridadNormal();
	int* generarPrioridadReal();
	int prioridad;
    int pid;
    int usuario;
    bool enEjecucion;
    bool TiempoReal;
	friend class Gestor;
	
	
	
};

#endif // PROCESO_HPP