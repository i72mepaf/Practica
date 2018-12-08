#include "Clases.h"

int main(int argc, char const *argv[])
{
	cout << "Versión beta de la base de los alumnos" << endl;
	Profesor p;
	BaseAlumnos b;
	int op = 0;
	if(p.identificaProfesor()==true){
		while(op!=9){
			cout << "Menu:" << endl;
			cout << "1. Insertar Alumno" << endl;
			cout << "2. Cargar Copia de Seguridad" << endl;
			cout << "3. Guardar Copia de Seguridad" << endl;
			cout << "4. Buscar Alumno" << endl;
			cout << "5. Mostrar Alumnos" << endl;
			cout << "6. Modificar Alumno" << endl;
			cout << "7. Eliminar Alumno" << endl;
			cout << "8. Eliminar Base de Datos de los Alumnos" << endl;
			cout << "9. Salir" << endl;
			cin >> op;
			system("clear");
			switch(op){
				case 1:{
					if(b.InsertarAlumno())
						cout << "Alumno insertado correctamente" << endl;
					else
						cout << "Alumno no insertado" << endl;
				}break;
				case 2: p.cargarFichero();
				break;
				case 3: p.guardarFichero();
				break;
				case 4: b.buscarAlumno();
				break;
				case 5: b.mostrarAlumno();
				break;
				case 6: b.modificarAlumno();
				break;
				case 7: b.eliminarAlumno();
				break;
				case 8: p.eliminarBaseAlumnos();
				break;
				case 9: cout << "Saliendo..." << endl;
				break;
				default: cout << "Por favor, teclee un número de las opciones [1,9]" << endl;
			}
		}
	}
	else{
		while(op!=6){
			cout << "Menu:" << endl;
			cout << "1. Insertar Alumno" << endl;
			cout << "2. Buscar Alumno" << endl;
			cout << "3. Mostrar Alumnos" << endl;
			cout << "4. Modificar Alumno" << endl;
			cout << "5. Eliminar Alumno" << endl;
			cout << "6. Salir" << endl;
			cin >> op;
			system("clear");
			switch(op){
				case 1:{
					if(b.InsertarAlumno())
						cout << "Alumno insertado correctamente" << endl;
					else
						cout << "Alumno no insertado" << endl;
				}break;
				case 2: b.buscarAlumno();
				break;
				case 3: b.mostrarAlumno();
				break;
				case 4: b.modificarAlumno();
				break;
				case 5: b.eliminarAlumno();
				break;
				case 6: cout << "Saliendo..." << endl;
				break;
				default: cout << "Por favor, teclee un número de las opciones [1,6]" << endl;
			}
		}
	}
	return 0;
}