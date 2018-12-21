#include "Clases.h"

int main(int argc, char const *argv[])
{
	Profesor p; // Creamos un objeto de la clase profesor y hacemos su debida identificación en identificaProfesor() 
	int op = 0; // Creamos está variable para hacer de seleccion del menú
	if(p.identificaProfesor()==true){ // Si identificaProfesor() devuelve true es profesor Coordinador
		while(op!=11){
			cout << "Menu:" << endl;
			cout << "1. Insertar Alumno" << endl;
			cout << "2. Cargar" << endl;
			cout << "3. Guardar" << endl;
			cout << "4. Mostrar Alumnos" << endl;
			cout << "5. Modificar Alumno" << endl;
			cout << "6. Buscar Alumno" << endl;
			cout << "7. Eliminar Alumno" << endl;
			cout << "8. Eliminar Base de Datos de los Alumnos" << endl;
			cout << "9. Cargar Copia de Seguridad" << endl;
			cout << "10. Guardar Copia de Seguridad" << endl;
			cout << "11. Salir" << endl;
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
				case 2: p.base_.cargar();
				break;
				case 3: p.base_.guardar();
				break;
				case 4: p.base_.mostrarAlumno();
				break;
				case 5: p.base_.modificarAlumno();
				break;
				case 6: p.base_.buscarAlumno();
				break;
				case 7: p.base_.eliminarAlumno();
				break;
				case 8: p.eliminarBaseAlumnos();
				break;
				case 9: p.base_.cargarCopia();
				break;
				case 10: p.base_.guardarCopia();
				break;
				case 11: cout << "Saliendo..." << endl;
				break;
				default: cout << "Por favor, teclee un número de las opciones [1,11]" << endl;
			}
		}
	}
	else{				//Si identificaProfesor() devuelve false es profesor Ayudante
		while(op!=8){
			cout << "Menu:" << endl;
			cout << "1. Insertar Alumno" << endl;
			cout << "2. Mostrar Alumnos" << endl;
			cout << "3. Modificar Alumno" << endl;
			cout << "4. Eliminar Alumno" << endl;
			cout << "5. Buscar Alumno" << endl;
			cout << "6. Cargar" << endl;
			cout << "7. Guardar" << endl;
			cout << "8. Salir" << endl;
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
				case 5: p.base_.buscarAlumno();
				break;
				case 6: p.base_.cargar();
				break;
				case 7: p.base_.guardar();
				break;
				case 8: cout << "Saliendo..." << endl;
				break;
				default: cout << "Por favor, teclee un número de las opciones [1,8]" << endl;
			}
		}
	}
	return 0;
}