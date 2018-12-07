#include "Clases.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>
<<<<<<< HEAD
#include <stdlib.h>
=======
using namespace std;
>>>>>>> rama_felipe

bool sortByCursoa(Alumno &lhs,Alumno &rhs){ return lhs.getCurso() > rhs.getCurso() ; }
bool sortByCursod(Alumno &lhs,Alumno &rhs){ return lhs.getCurso() < rhs.getCurso() ; }
bool sortByApella(Alumno &lhs,Alumno &rhs){ return lhs.getApellidos() > rhs.getApellidos() ; }
bool sortByApella(Alumno &lhs,Alumno &rhs){ return lhs.getApellidos() < rhs.getApellidos() ; }

void BaseAlumnos::eliminarAlumno(){ //Felipe

}
<<<<<<< HEAD
bool Profesor::identificaProfesor(){ /*Felipe //Requisito no funcional (el archivo de credenciales tiene 
que haber profesores, mínimo el profesor coordinador)

- SecuenciaIdentificarProfesor.jpg: El actor que hace este flujo de acciones no es el profesor, 
es un usuario no identificado. Puedo trollear a la aplicación diciendo que soy coordinador 
cuando realmente no lo soy (Hay que comprobar esto de alguna forma.) Lo de vuelva al punto 4.1 
se puede solucionar con un flujo loop. Las comprobaciones se pueden hacer en el mismo sistema, 
donde se haga un ‘match’ entre las credenciales del fichero y las que mete el usuario.*/
	int opcion = 0;
	while(opcion!=1 && opcion!=2){
	std::cout << "¿Es profesor Coordinador o Ayudante?" << std::endl;
	std::cout << "1. Coordinador\n2. Ayudante" << endl;
	std::cin >> opcion;
	system("clear");
	if(opcion!=1 && opcion!=2){
		cout << "Número Incorrecto. Intentelo de nuevo" <<std::endl;
=======
struct Auxiliar
{
	char d[100];
	char r[100];
};
bool Profesor::identificaProfesor(){
	int opcion = 0, contadorTipo=0;
	string dni, compDNI, compROL;
	Auxiliar aux;
	vector<Auxiliar> v;
	ifstream fichero("credenciales.bin", ios::in | ios::binary);
	if (fichero.is_open()){
		while(!fichero.eof() && fichero.read((char *)&aux, sizeof(Auxiliar))){
			v.push_back(aux);
		}
>>>>>>> rama_felipe
	}
	else{
		cout << "Error al abrir credenciales.bin porque no existe en el directorio." << endl;
		exit(-1);
	}
   	fichero.close();
		cout << "Bienvenido al programa de la base de datos de alumnos." << endl;
	while(opcion!=1 && opcion!=2){
		cout << "¿Es profesor Coordinador o Ayudante?" << endl;
		cout << "1. Coordinador.\n2. Ayudante." << endl;
		cin >> opcion;
		system("clear");
		if(opcion!=1 && opcion!=2){
			cout << "Número Incorrecto. Intentelo de nuevo." << endl;
		}
		else{
			if(opcion==1){//Coordinador
				cout << "A continuación procederemos a identificarle como profesor Coordinador." << endl;
				cout << "Introduzca DNI: ";
				cin >> dni;
				system("clear");
   				for (int i = 0; i < v.size(); ++i)
   				{
   					compDNI = v[i].d;
   					compROL = v[i].r;
   					if(compDNI == dni && compROL == "Coordinador")
   						cout << "Identificado Correctamente." << endl;
   					while(compDNI == dni && compROL == "Coordinador"){
   						cout << "¿Desea iniciar o cambiar DNI?\n1. Iniciar.\n2. Cambiar DNI." << endl;
   						cin >> opcion;
   						system("clear");
   						if(opcion!= 1 && opcion!=2){
   							cout << "Numero Incorrecto. Intentalo de nuevo." << endl;
   						}
   						else{
   							if(opcion == 1){
   								remove("credenciales.bin");
   								ofstream fCreacion("credenciales.bin", ios::out | ios::binary);
								if (fCreacion.is_open()){
									for(int j=0; j < v.size(); j++)
									fCreacion.write((char *)&v[j], sizeof(Auxiliar));
   								}
   								else{
   									cout << "Error al abrir el fichero." << endl;
   									exit(-1);
   								}
   								fCreacion.close();
   								cout << "Iniciando..." << endl;
   								setDni(compDNI);
   								setRol(compROL);
   								return true;
   							}
   							else{
   								cout << "Introduzca el nuevo DNI: ";
   								cin >> dni;
   								remove("credenciales.bin");
   								ofstream fEscCoord("credenciales.bin", ios::out | ios::binary);
								if (fEscCoord.is_open()){
									for(int j=0; j < v.size(); j++){
										compROL = v[j].r;
										if(compROL == "Coordinador")
											strcpy(v[j].d, dni.c_str());
										fEscCoord.write((char *)&v[j], sizeof(Auxiliar));
									}
   								}
   								else{
   									cout << "Error al abrir el fichero." << endl;
   									exit(-1);
   								}
   								fEscCoord.close();
   								cout << "DNI cambiado con exito. Iniciando..." << endl;
   								setDni(dni);
   								setRol("Coordinador");
   								return true;
   							}
   						}
   					}
				}
				cout << "Lo sentimos, no hemos podido identificarle, intentelo de nuevo." << endl;
   				opcion = 3;
   			}
			else{//Ayudante
				cout << "¿Desea registrarse o identificarse?" << endl;
				cout << "1. Registrar.\n2. Identificar." << endl;
				cin >> opcion;
				system("clear");
   				if(opcion!= 1 && opcion!=2){
  					cout << "Numero Incorrecto. Intentalo de nuevo." << endl;
  					opcion = 3;
				}
				else{
					if(opcion == 1){//Registrarse
						for (int i = 0; i < v.size(); ++i)
						{
							compROL = v[i].r;
							if(compROL=="Ayudante")
								contadorTipo++;
						}
						if(contadorTipo < 5){
							cout << "Registro de un profesor ayudante.\nIntroduce el DNI: ";
							cin >> dni;
							strcpy(aux.d, dni.c_str());
							strcpy(aux.r, "Ayudante");
							v.push_back(aux);
							remove("credenciales.bin");
							ofstream fEscAyud("credenciales.bin", ios::out | ios::binary);
							if (fEscAyud.is_open()){
								for(int i=0; i < v.size(); i++)
									fEscAyud.write((char *)&v[i], sizeof(Auxiliar));
   							}
   							else{
   								cout << "Error al abrir el fichero." << endl;
   								exit(-1);
   							}
   							fEscAyud.close();
   							cout << "Registro correcto. Iniciando..." << endl;
   							setDni(dni);
   							setRol("Ayudante");
   							return false;
						}
						else{
							cout << "Lo sentimos. Ya existen registrados 5 profesores ayudantes." << endl;
  							opcion = 3;
						}
					}
					else{//Identificarse
						cout << "A continuación procederemos a identificarle como profesor Ayudante." << endl;
						cout << "Introduzca el DNI: ";
						cin >> dni;
						system("clear");
   						for (int i = 0; i < v.size(); ++i)
   						{
   							compDNI = v[i].d;
   							compROL = v[i].r;
   							if(compDNI == dni && compROL == "Ayudante"){
   								cout << "Identificado Correctamente. Iniciando..." << endl;
   								remove("credenciales.bin");
   								ofstream fCreacionA("credenciales.bin", ios::out | ios::binary);
								if (fCreacionA.is_open()){
									for(int j=0; j < v.size(); j++)
									fCreacionA.write((char *)&v[j], sizeof(Auxiliar));
   								}
   								else{
   									cout << "Error al abrir el fichero" << endl;
   									exit(-1);
   								}
   								fCreacionA.close();
   								setDni(compDNI);
   								setRol(compROL);
   								return false;
							}
						}
							cout << "No se ha podido identificar, intentelo de nuevo." << endl;
							opcion = 3;
					}
				}
			}
		}
	}
}
void Profesor::eliminarBaseAlumnos(){ //Felipe

}


void BaseAlumnos::insertarAlumno(){
	list<Alumno>::iterator it;
	Alumno alumno;
	string nombre;
	string apellidos;
	string DNI;
	string correo;
	int telefono;
	int direccion;
	int cursoMasAlto;
	int diaNacimiento, mesNacimiento, anoNacimiento;
	bool lider;
	int grupo;

	
<<<<<<< HEAD
	std::cout<<"Introduce el DNI del alumno"<<std::endl;
	std::cin>>DNI;
=======
	cout<<"Introduce el DNI del alumno"<<endl;
	cin>>DNI;
>>>>>>> rama_felipe
	
	it = alumnos_.begin();
	while(it != alumnos_.end){
<<<<<<< HEAD
		if((*it).getDNI()==DNI) {
			std::cout<<"ERROR.Este Alumno ya existe"<<endl;
=======
		if(it.getDNI()==DNI) {
<<<<<<< HEAD
			std::cout<<("ERROR.Este Alumno ya existe")<<std::endl;
>>>>>>> d2224f7b0e2200563df37f12092dfb2680786d43
			exit(-1);
		}
	}
	std::cout<<"Introduzca el nombre del alumno"<<std::endl;
	std::cin>>nombre;
<<<<<<< HEAD
	std::cout<<"Introduzca el apellido del alumno"<<endl;
	std::cin>>apellidos;
	std::cout<<"Introduzca el corre del alumno"<<endl;
	std::cin>>correo;
	std::cout<<"Introduzca el numero de telefono del alumno"<<endl;
	std::cin>>telefono;
	std::cout<<"Introduzca la direccion del alumno"<<endl;
	std::cin>>direccion;
	std::cout<<"Introduzca el curso mas alto en el que el alumno esta matriculado"<<endl;
	std::cin>>cursoMasAlto;
	std::cout<<"Introduzca el dia en el que el alumno nacio"<<endl;
	std::cin>>diaNacimiento;
	std::cout<<"Introduzca el mes de nacimiento del alumno"<<endl;
	std::cin>>mesNacimiento;
	std::cout<<"Introduzca el año de nacimiento del alumno"<<endl;
	std::cin>>anoNacimiento;
	std::cout<<"Introduzca el grupo del alumno"<<endl;
	std::cin>>grupo;
	std::cout<<"¿El alumno sera lider del grupo?(Introduzca Si o No)"<<endl;
	std::cin>>lider;
=======
	std::cout>>"Introduce el apellido del alumno"<<std::endl;
	std::cin>>apellidos;
	std::cout<<"Introduce el corre del alumno"<<std::endl;
	std::cin>>correo;
	std::cout<<"Introduce el numero de telefono del alumno"<<std::endl;
	std::cin>>telefono;
	std::cout<<"Introduce la direccion del alumno"<<std::endl;
	std::cin>>direccion;
	std::cout<<"Introduce el curso mas alto en el que el alumno esta matriculado"<<std::endl;
	std::cin>>cursoMasAlto;
	std::cout<<"Introduce el dia en el que el alumno nacio"<<std::endl;
	std::cin>>diaNacimiento;
	std::cout<<"Introduce el mes de nacimiento del alumno"<<std::endl;
	std::cin>>mesNacimiento;
	std::cout<<"Introduce el año de nacimiento del alumno"<<std::endl;
	std::cin>>anoNacimiento;
	std::cout<<"Este alumno es lider de algun grupo"<<std::endl;
	std::cin>>lider;
	std::cout<<"Grupo del alumno"<<std::endl:

>>>>>>> d2224f7b0e2200563df37f12092dfb2680786d43
	alumno.setNombre(std::string nombre);
	alumno.setApellidos(std::string apellidos);
	alumno.setDNI(std::string DNI);
	alumno.setCorreo(std::string correo);
=======
			cout<<("ERROR.Este Alumno ya existe")<<endl;
			exit(-1);
		}
	}
	cout<<"Introduzca el nombre del alumno"<<endl;
	cin>>nombre;
	cout>>"Introduce el apellido del alumno"<<endl;
	cin>>apellidos;
	cout<<"Introduce el corre del alumno"<<endl;
	cin>>correo;
	cout<<"Introduce el numero de telefono del alumno"<<endl;
	cin>>telefono;
	cout<<"Introduce la direccion del alumno"<<endl;
	cin>>direccion;
	cout<<"Introduce el curso mas alto en el que el alumno esta matriculado"<<endl;
	cin>>cursoMasAlto;
	cout<<"Introduce el dia en el que el alumno nacio"<<endl;
	cin>>diaNacimiento;
	cout<<"Introduce el mes de nacimiento del alumno"<<endl;
	cin>>mesNacimiento;
	cout<<"Introduce el año de nacimiento del alumno"<<endl;
	cin>>anoNacimiento;
	cout<<"Este alumno es lider de algun grupo"<<endl;
	cin>>lider;
	cout<<"Grupo del alumno"<<endl:

	alumno.setNombre(string nombre);
	alumno.setApellidos(string apellidos);
	alumno.setDNI(string DNI);
	alumno.setCorreo(string correo);
>>>>>>> rama_felipe
	alumno.setTelefono(int telefono);
	alumno.setDireccion(int direccion);
	alumno.setCursoMasAlto(int cursoMasAlto);
	alumno.setFechaNacimiento(int diaNacimiento, int mesNacimiento, int anoNacimiento);
	alumno.setGrupo(int grupo);
	if(lider == "Si") { //Si el profesor introduce "Si" se procedera a comprobar si hay un lider en ese grupo
		list<Alumno>::iterator it2;
		it2 = alumnos_.begin();
		while(it2 != alumnos_.end()) {
			if((*it2).getGrupo() == alumno.getGrupo() && (*it2).getLider() == true) {//Si hay alumnos en el grupo del estudiante insertado y si hay un lider en dicho grupo
				std::cout<<"En este grupo ya hay un lider"<<endl;
			}else {
				alumno.setLider();
			}
			
		}

	}
	alumnos_.push_back(alumno);
}

void Alumno::setNombre(string nombre) {
	nombre_=nombre;
}
void Alumno::setApellidos(string apellidos) {
	apellidos_=apellidos;
}
void Alumno::setDNI(string DNI) {
	DNI_ = DNI;
}
void Alumno::setCorreo(string correo) {
	correo_ = correo;
}
void Alumno::setTelefono(int telefono) {
	telefono_ = telefono;
}
void Alumno::setDireccion(int direccion) {
	direccion_ = direccion;
}
void Alumno::setCursoMasAlto(int cursoMasAlto) {
	cursoMasAlto_ = cursoMasAlto;
}
void Alumno::setFechaNacimiento(int diaNacimiento, int mesNacimiento, int anoNacimiento) {
	string aux;
	if(mesNacimiento <= 0 || mesNacimiento > 12) {
<<<<<<< HEAD
		std::cout<<"El mes numero "<<mesNacimiento<<"no existe"<<std::endl;
=======
		cout<<"El mes numero "<<mesNacimiento<<"no existe"<<endl;
>>>>>>> rama_felipe
		exit(-1);
	}
	if(mesNacimiento == 1) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
<<<<<<< HEAD
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<std::endl;
=======
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
>>>>>>> rama_felipe
			exit(-1);
		}
	}
	if(mesNacimiento == 2) {
		if(diaNacimiento <= 0 || diaNacimiento > 28) {
<<<<<<< HEAD
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<std::endl;
=======
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
>>>>>>> rama_felipe
			exit(-1);
		}
	}
	if(mesNacimiento == 3) {
		if(diaNacimiento <= 0 || diaNacimiento > 29) {
<<<<<<< HEAD
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<std::endl;
=======
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
>>>>>>> rama_felipe
			exit(-1);
		}
	}
	if(mesNacimiento == 4) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
<<<<<<< HEAD
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<std::endl;
=======
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
>>>>>>> rama_felipe
			exit(-1);
		}
	}
	if(mesNacimiento == 5) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
<<<<<<< HEAD
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<std::endl;
=======
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
>>>>>>> rama_felipe
			exit(-1);
		}
	}
	if(mesNacimiento == 6) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
<<<<<<< HEAD
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<std::endl;
=======
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
>>>>>>> rama_felipe
			exit(-1);
		}
	}
	if(mesNacimiento == 7) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
<<<<<<< HEAD
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<std::endl;
=======
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
>>>>>>> rama_felipe
			exit(-1);
		}
	}
	if(mesNacimiento == 8) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
<<<<<<< HEAD
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<std::endl;
=======
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
>>>>>>> rama_felipe
			exit(-1);
		}
	}
	if(mesNacimiento == 9) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
<<<<<<< HEAD
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<std::endl;
=======
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
>>>>>>> rama_felipe
			exit(-1);
		}
	}
	if(mesNacimiento == 10) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
<<<<<<< HEAD
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<std::endl;
=======
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
>>>>>>> rama_felipe
			exit(-1);
		}
	}
	if(mesNacimiento == 11) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
<<<<<<< HEAD
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<std::endl;
=======
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
>>>>>>> rama_felipe
			exit(-1);
		}
	}
	if(mesNacimiento == 12) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
<<<<<<< HEAD
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<std::endl;
=======
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
>>>>>>> rama_felipe
			exit(-1);
		}
	}
	itoa(diaNacimiento, mesNacimiento, anoNacimiento);
	aux = diaNacimiento+"/"+mesNacimiento+"/"+anoNacimiento;
	fechaNacimiento_ = aux;
}
void Alumno::setGrupo(int grupo) {
	grupo_ = grupo;
<<<<<<< HEAD
}
void Alumno::setLider(std::string lider) {
	if(lider == "Si") {
		lider_ = true;
	}else {
		lider_ = false;
	}
}
=======
=======
>>>>>>> d2224f7b0e2200563df37f12092dfb2680786d43

void BaseAlumnos::mostrarAlumno(){
	int menu,menu2;
	int comp=0;
	int comp2=0;
	int vit=0;
	int cont=0;
	std::string aux;
	std::vector <Alumno> v(150);
	for(i=alumnos_.begin();i != alumnos_.end();i++){
		v[vit].setNombre(i->getNombre());
		v[vit].setApellidos(i->getApellidos());
		v[vit].setDni(i->getDNI());
		v[vit].setCorreo(i->getCorreo());
		v[vit].setTelefono(i->getTelefono());
		v[vit].setDireccion(i->getDireccion());
		v[vit].setCursoMasAlto(i->getCurso());
		v[vit].setFechaNacimiento(i->getFechaNacimiento());
		v[vit].setGrupo(i->getGrupo());
		v[vit].setLider(i->getLider());
		vit++;
	}
	
	do{
	std::cout << "Mostrar todos los alumnos ....1"<< std::endl;
	std::cout << "Mostrar solo un alumno .......2"<< std::endl;
	std::cin>> menu;
	list <Alumno>:: iterator i;
	//system("cls");
	
		switch(menu){
			case 1:
				do{
				std::cout << "Mostrar todos los alumnos ordenados ascendentemente por curso mas alto matriculado....1"<< std::endl;
				std::cout << "Mostrar todos los alumnos ordenados descendentemente por curso mas alto matriculado...2"<< std::endl;
				std::cout << "Mostrar todos los alumnos ordenados ascendentemente por apellidos.....................3"<< std::endl;
				std::cout << "Mostrar todos los alumnos ordenados descendentemente por apellidos....................4"<< std::endl;
				std::cin>> menu2;			
					switch(menu2){
						case 1:
						sort(v.begin(),v.end(),sortByCursoa);
						imprimeVector(v);
						comp2=1;
						break;

						case 2:
						sort(v.begin(),v.end(),sortByCursod);
						imprimeVector(v);
						comp2=1;
						break;

						case 3:
						comp2=1;
						sort(v.begin(),v.end(),sortByApella);
						imprimeVector(v);
						break;

						case 4:
						sort(v.begin(),v.end(),sortByApelld);
						imprimeVector(v);
						comp2=1;
						break;

						default:
							std::cout << "Error ,introduzca una opcion válida"<< std::endl;
							break;					
					}
				}while(comp2 == 0);

				comp=1;
				break;

			case 2:
				do{
					std::cout <<"Mostrar un alumno por dni..........1"<<std::endl;
					std::cout <<"Mostrar un alumno por Apellidos....2"<<std::endl;
					std::cin >> menu2;
					switch(menu2){
						case 1:
						std::cout <<"Introduzca el dni del alumno a mostrar"<<std::endl;
						cin>>aux;
						for (int i=0;i<v.size();i++){
							if(aux == v[i].getDNI()){
								imprimeAlumno(v[i]);
								comp2=1
								break;
							}
						}
						std::cout <<"No se encontro el alumno"<<std::endl;
						comp2=1
						break;

						case 2:
						std::cout <<"Introduzca los apellidos del alumno a mostrar"<<std::endl;
						cin>>aux;
						for (int i=0;i<v.size();i++){
							if(aux == v[i].getApellidos()){
								cont++;
							}
						}
						if(cont!=1){
							std::cout <<"No se puede imprimir el alumno por apellidos"<<std::endl;
							break;
						}
						for (int i=0;i<v.size();i++){
							if(aux == v[i].getApellidos()){
							imprimeAlumno(v[i]);	
							}
						}
						comp2 =1;
						break;

						default:
							std::cout >> "Error ,introduzca una opcion válida"<< std::endl;
							break; 
					}

				}while(comp2 == 0);
				comp=1;
				break;

			default:
				std::cout >> "Error ,introduzca una opcion válida"<< std::endl;
				break;
		}
	}while(comp == 0);
}

void imprimeVector(vector <Alumno> v){
	for(int i=0;i< v.size();i++){
			std::cout<< v[i].getNombre()<<std::endl;
			std::cout<< v[i].getApellidos()<<std::endl;
			std::cout<< v[i].getDNI()<<std::endl;
			std::cout<< v[i].getCorreo()<<std::endl;
			std::cout<< v[i].getTelefono()<<std::endl;
			std::cout<< v[i].getDireccion()<<std::endl;
			std::cout<< v[i].getCursoMasAlto()<<std::endl;
			std::cout<< v[i].getFechaNacimiento()<<std::endl;
			std::cout<< v[i].getGrupo()<<std::endl;
			std::cout<< v[i].getLider()<<std::endl;
	}
}
void imprimeAlumno(Alumno a){
			std::cout<< a.getNombre()<<std::endl;
			std::cout<< a.getApellidos()<<std::endl;
			std::cout<< a.getDNI()<<std::endl;
			std::cout<< a.getCorreo()<<std::endl;
			std::cout<< a.getTelefono()<<std::endl;
			std::cout<< a.getDireccion()<<std::endl;
			std::cout<< a.getCursoMasAlto()<<std::endl;
			std::cout<< a.getFechaNacimiento()<<std::endl;
			std::cout<< a.getGrupo()<<std::endl;
			std::cout<< a.getLider()<<std::endl;
}