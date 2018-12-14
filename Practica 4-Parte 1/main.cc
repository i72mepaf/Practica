#include "Clases.h"

int main(int argc, char const *argv[])
{
	cout << "Versión beta de la base de los alumnos" << endl;
	Profesor p;
	int op = 0;
	if(p.identificaProfesor()==true){
		while(op!=10){
			cout << "Menu:" << endl;
			cout << "1. Insertar Alumno" << endl;
			cout << "2. Cargar" << endl;
			cout << "3. Guardar" << endl;
			cout << "4. Mostrar Alumnos" << endl;
			cout << "5. Modificar Alumno" << endl;
			cout << "6. Eliminar Alumno" << endl;
			cout << "7. Eliminar Base de Datos de los Alumnos" << endl;
			cout << "8. Cargar Copia de Seguridad" << endl;
			cout << "9. Guardar Copia de Seguridad" << endl;
			cout << "10. Salir" << endl;
			cin >> op;
			cin.ignore();
			system("clear");
			switch(op){
				case 1:{
					if(p.base_.insertarAlumno())
						cout << "Alumno insertado correctamente" << endl;
					else
						cout << "Alumno no insertado" << endl;
				}break;
				case 2: p.base_.cargarCopia();
				break;
				case 3: p.base_.guardarCopia();
				break;
				case 4: p.base_.mostrarAlumno();
				break;
				case 5: p.base_.modificarAlumno();
				break;
				case 6: p.base_.eliminarAlumno();
				break;
				case 7: p.eliminarBaseAlumnos();
				break;
				case 8: p.base_.cargarFichero();
				break;
				case 9: p.base_.guardarFichero();
				break;
				case 10: cout << "Saliendo..." << endl;
				break;
				default: cout << "Por favor, teclee un número de las opciones [1,10]" << endl;
			}
		}
	}
	else{
		while(op!=7){
			cout << "Menu:" << endl;
			cout << "1. Insertar Alumno" << endl;
			cout << "2. Mostrar Alumnos" << endl;
			cout << "3. Modificar Alumno" << endl;
			cout << "4. Eliminar Alumno" << endl;
			cout << "5. Cargar" << endl;
			cout << "6. Guardar" << endl;
			cout << "7. Salir" << endl;
			cin >> op;
			cin.ignore();
			system("clear");
			switch(op){
				case 1:{
					if(p.base_.insertarAlumno())
						cout << "Alumno insertado correctamente" << endl;
					else
						cout << "Alumno no insertado" << endl;
				}break;
				case 2: p.base_.mostrarAlumno();
				break;
				case 3: p.base_.modificarAlumno();
				break;
				case 4: p.base_.eliminarAlumno();
				break;
				case 5: p.base_.cargarCopia();
				break;
				case 6: p.base_.guardarCopia();
				break;
				case 7: cout << "Saliendo..." << endl;
				break;
				default: cout << "Por favor, teclee un número de las opciones [1,7]" << endl;
			}
		}
	}
	return 0;
}