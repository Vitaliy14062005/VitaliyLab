#include <Gestor.hpp>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	Gestor gestor;
	char opcion;

	do {

		cout << "\n\t--------------------------------------------------------------"
				"--------\n";
		cout << "\tProcesos en la pila -> " << 0 /*gestor.ProcesosEnPila()*/
			 << "\n\tProcesos en las colas:\n \t\tGPU 0-> " << 0 /*gestor.ProcesosEnGPU0() */ << "\tGPU 1-> "
			 << 0 /*gestor.ProcesosEnGPU1() */ << "\tGPU 2-> " << 0 /*gestor.ProcesosEnGPU2() */ << "\tGPU 3-> "
			 << 0 /*gestor.ProcesosEnGPU3()*/
			 << " \n\tProcesos en las listas:\n \t\tNormal-> "
			 << 0 /*gestor.ProcesosEnListaNormal()*/ << "\tTiempo Real-> " << 0 /*gestor.ProcesosEnListaTiempoReal()*/
			 << "\n\tProcesos en el arbol -> " << 0							  /*gestor.ProcesosEnArbol()*/
			 << "\n";
		cout << "\t----------------------------------------------------------------"
				"------\n\n";

		cout << "\tA. Generar 12 Procesos de forma aleatoria y almacenarlos en la "
				"Pila.\n";
		cout << "\tB. Consultar todos los Procesos generados en la Pila.\n";
		cout << "\tC. Borrar los Procesos generados en la pila.\n";
		cout << "\tD. Simular llegada de los Procesos en las colas.\n";
		cout << "\tE. Consultar los Procesos en las colas de las GPUs 0 y 1.\n";
		cout << "\tF. Consultar los Procesos en las colas de las GPUs 2 y 3.\n";
		cout << "\tG. Borrar todos los Procesos de las colas.\n";
		cout << "\tH. Simular la entrada de los Procesos a las listas.\n";
		cout << "\tI. Mostrar los Procesos que hay en la lista Normal.\n";
		cout << "\tJ. Mostrar los Procesos que hay en la lista Tiempo Real.\n";
		cout << "\tK. Buscar en las listas el Proceso Normal de menor prioridad y "
				"el Proceso Tiempo Real de mayor prioridad.\n";
		cout << "\tL. Buscar Procesos por nombre de usuario en listas.\n";
		cout << "\tM. Eliminar Proceso por numero de PID en listas.\n";
		cout << "\tN. Cambiar prioridad de Proceso por numero de PID en listas.\n";
		cout << "\tO. Reiniciar el programa.\n";
		cout << "\tP. Crear y dibujar el ABB en consola.\n";
		cout << "\tQ. Mostrar los datos de todos los Procesos Normales ordenados "
				"por su prioridad de alta a baja.\n";
		cout << "\tR. Mostrar los datos de todos los Procesos en Tiempo real ordenados "
				"por su prioridad de alta a baja.\n";
		cout << "\tT. Mostrar los datos de todos los Procesos recorriendo el arbol "
				"en inorden.\n";
		cout << "\tU. Buscar en el ABB el Proceso Normal con la "
				"prioridad mas baja, asi como el Proceso Tiempo Real "
				"con la prioridad mas alta.\n";
		cout << "\tV. Mostrar los Procesos que se encuentran almacenados en un nodo "
				"hoja.\n";
		cout << "\tW. Eliminar un Proceso por su numero de prioridad "
				"y mostrar el arbol "
				"antes y despues de la eliminacion de dicho Proceso. "
				"Agregar el proceso a su correspondiente Lista.\n";
		cout << "\tS. Salir.\n\n";

		cout << "\tIndique la opcion deseada: ";
		cin >> opcion;
		opcion = toupper(opcion);
		// system("clear");
		system("cls");

		switch(opcion) {

		case 'A':
			// gestor.genera12Procesos();
			break;
		case 'B':
			// gestor.muestraProcesos();
			break;
		case 'C':
			// gestor.borraProcesosPila();
			break;
		case 'D':
			// gestor.encolarProcesos();
			break;
		case 'E':
			// gestor.muestraProcesosGPUs0y1();
			break;
		case 'F':
			// gestor.muestraProcesosGPUs2y3();
			break;
		case 'G':
			// gestor.borraProcesosColas();
			break;
		case 'H':
			// gestor.enlistarProcesos();
			break;
		case 'I':
			// gestor.muestraProcesosNormal();
			break;
		case 'J':
			// gestor.muestraProcesosTiempoReal();
			break;
		case 'K':
			// gestor.buscarProcesos();
			break;
		case 'L':
			// gestor.buscarProcesoPorNombreUsuario();
			break;
		case 'M':
			// gestor.eliminarProcesoPorPID();
			break;
		case 'N':
			// gestor.cambiarPrioridadProcesoPorPID();
			break;
		case 'O':
			// gestor.reiniciar();
			break;
		case 'P':
			//...;
			break;
		case 'Q':
			//...;
			break;
		case 'R':
			//...;
			break;
		case 'T':
			//...;
			break;
		case 'U':
			//...;
			break;
		case 'V':
			//...;
			break;
		case 'W':
			//...;
			break;
		case 'S':
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opcion incorrecta!\n\n";
			break;
		}
	} while(opcion != 'S');

	return 0;
}