#include "Clases.h"

int main(int argc, char const *argv[])
{
	cout << "Versión beta de la base de los alumnos" << endl;
	Profesor p;
	int op = 0;
	if(p.identificaProfesor()==true){
		while(op!=8){
			cout << "Menu:" << endl;
			cout << "1. Insertar Alumno" << endl;
			cout << "2. Cargar Copia de Seguridad" << endl;
			cout << "3. Guardar Copia de Seguridad" << endl;
			cout << "4. Mostrar Alumnos" << endl;
			cout << "5. Modificar Alumno" << endl;
			cout << "6. Eliminar Alumno" << endl;
			cout << "7. Eliminar Base de Datos de los Alumnos" << endl;
			cout << "8. Salir" << endl;
			cin >> op;
			system("clear");
			switch(op){
				case 1:{
					if(p.getBase().insertarAlumno())
						cout << "Alumno insertado correctamente" << endl;
					else
						cout << "Alumno no insertado" << endl;
				}break;
				case 2: p.cargarFichero();
				break;
				case 3: p.guardarFichero();
				break;
				case 4: p.getBase().mostrarAlumno();
				break;
				case 5: p.getBase().modificarAlumno();
				break;
				case 6: p.getBase().eliminarAlumno();
				break;
				case 7: p.eliminarBaseAlumnos();
				break;
				case 8: cout << "Saliendo..." << endl;
				break;
				default: cout << "Por favor, teclee un número de las opciones [1,8]" << endl;
			}
		}
	}
	else{
		while(op!=6){
			cout << "Menu:" << endl;
			cout << "1. Insertar Alumno" << endl;
			cout << "2. Mostrar Alumnos" << endl;
			cout << "3. Modificar Alumno" << endl;
			cout << "4. Eliminar Alumno" << endl;
			cout << "5. Salir" << endl;
			cin >> op;
			system("clear");
			switch(op){
				case 1:{
					if(p.getBase().insertarAlumno())
						cout << "Alumno insertado correctamente" << endl;
					else
						cout << "Alumno no insertado" << endl;
				}break;
				case 2: p.getBase().mostrarAlumno();
				break;
				case 3: p.getBase().modificarAlumno();
				break;
				case 4: p.getBase().eliminarAlumno();
				break;
				case 5: cout << "Saliendo..." << endl;
				break;
				default: cout << "Por favor, teclee un número de las opciones [1,5]" << endl;
			}
		}
	}
	return 0;
}