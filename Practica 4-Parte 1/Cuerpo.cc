#include "Clases.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

bool sortByCursoa(Alumno &lhs,Alumno &rhs){ return lhs.getCurso() > rhs.getCurso() ; }
bool sortByCursod(Alumno &lhs,Alumno &rhs){ return lhs.getCurso() < rhs.getCurso() ; }
bool sortByApella(Alumno &lhs,Alumno &rhs){ return lhs.getApellidos() > rhs.getApellidos() ; }
bool sortByApella(Alumno &lhs,Alumno &rhs){ return lhs.getApellidos() < rhs.getApellidos() ; }

void BaseAlumnos::eliminarAlumno(){ //Felipe

}
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

	
	cout<<"Introduce el DNI del alumno"<<endl;
	cin>>DNI;
	
	it = alumnos_.begin();
	while(it != alumnos_.end){
<<<<<<< HEAD
		if((*it).getDNI()==DNI) {
			cout<<"ERROR.Este Alumno ya existe"<<endl;
=======
		if(it.getDNI()==DNI) {
			cout<<("ERROR.Este Alumno ya existe")<<endl;
>>>>>>> d2224f7b0e2200563df37f12092dfb2680786d43
			exit(-1);
		}
	}
	cout<<"Introduzca el nombre del alumno"<<endl;
	cin>>nombre;
<<<<<<< HEAD
	cout<<"Introduzca el apellido del alumno"<<endl;
	cin>>apellidos;
	cout<<"Introduzca el corre del alumno"<<endl;
	cin>>correo;
	cout<<"Introduzca el numero de telefono del alumno"<<endl;
	cin>>telefono;
	cout<<"Introduzca la direccion del alumno"<<endl;
	cin>>direccion;
	cout<<"Introduzca el curso mas alto en el que el alumno esta matriculado"<<endl;
	cin>>cursoMasAlto;
	cout<<"Introduzca el dia en el que el alumno nacio"<<endl;
	cin>>diaNacimiento;
	cout<<"Introduzca el mes de nacimiento del alumno"<<endl;
	cin>>mesNacimiento;
	cout<<"Introduzca el año de nacimiento del alumno"<<endl;
	cin>>anoNacimiento;
	cout<<"Introduzca el grupo del alumno"<<endl;
	cin>>grupo;
	cout<<"¿El alumno sera lider del grupo?(Introduzca Si o No)"<<endl;
	cin>>lider;
=======
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

>>>>>>> d2224f7b0e2200563df37f12092dfb2680786d43
	alumno.setNombre(string nombre);
	alumno.setApellidos(string apellidos);
	alumno.setDNI(string DNI);
	alumno.setCorreo(string correo);
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
				cout<<"En este grupo ya hay un lider"<<endl;
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
		cout<<"El mes numero "<<mesNacimiento<<"no existe"<<endl;
		exit(-1);
	}
	if(mesNacimiento == 1) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 2) {
		if(diaNacimiento <= 0 || diaNacimiento > 28) {
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 3) {
		if(diaNacimiento <= 0 || diaNacimiento > 29) {
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 4) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 5) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 6) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 7) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 8) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 9) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 10) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 11) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 12) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
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
void Alumno::setLider(string lider) {
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
	string aux;
	vector <Alumno> v(150);
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
	cout << "Mostrar todos los alumnos ....1"<< endl;
	cout << "Mostrar solo un alumno .......2"<< endl;
	cin>> menu;
	list <Alumno>:: iterator i;
	//system("cls");
	
		switch(menu){
			case 1:
				do{
				cout << "Mostrar todos los alumnos ordenados ascendentemente por curso mas alto matriculado....1"<< endl;
				cout << "Mostrar todos los alumnos ordenados descendentemente por curso mas alto matriculado...2"<< endl;
				cout << "Mostrar todos los alumnos ordenados ascendentemente por apellidos.....................3"<< endl;
				cout << "Mostrar todos los alumnos ordenados descendentemente por apellidos....................4"<< endl;
				cin>> menu2;			
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
							cout << "Error ,introduzca una opcion válida"<< endl;
							break;					
					}
				}while(comp2 == 0);

				comp=1;
				break;

			case 2:
				do{
					cout <<"Mostrar un alumno por dni..........1"<<endl;
					cout <<"Mostrar un alumno por Apellidos....2"<<endl;
					cin >> menu2;
					switch(menu2){
						case 1:
						cout <<"Introduzca el dni del alumno a mostrar"<<endl;
						cin>>aux;
						for (int i=0;i<v.size();i++){
							if(aux == v[i].getDNI()){
								imprimeAlumno(v[i]);
								comp2=1
								break;
							}
						}
						cout <<"No se encontro el alumno"<<endl;
						comp2=1
						break;

						case 2:
						cout <<"Introduzca los apellidos del alumno a mostrar"<<endl;
						cin>>aux;
						for (int i=0;i<v.size();i++){
							if(aux == v[i].getApellidos()){
								cont++;
							}
						}
						if(cont!=1){
							cout <<"No se puede imprimir el alumno por apellidos"<<endl;
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
							cout >> "Error ,introduzca una opcion válida"<< endl;
							break; 
					}

				}while(comp2 == 0);
				comp=1;
				break;

			default:
				cout >> "Error ,introduzca una opcion válida"<< endl;
				break;
		}
	}while(comp == 0);
}

void imprimeVector(vector <Alumno> v){
	for(int i=0;i< v.size();i++){
			cout<< v[i].getNombre()<<endl;
			cout<< v[i].getApellidos()<<endl;
			cout<< v[i].getDNI()<<endl;
			cout<< v[i].getCorreo()<<endl;
			cout<< v[i].getTelefono()<<endl;
			cout<< v[i].getDireccion()<<endl;
			cout<< v[i].getCursoMasAlto()<<endl;
			cout<< v[i].getFechaNacimiento()<<endl;
			cout<< v[i].getGrupo()<<endl;
			cout<< v[i].getLider()<<endl;
	}
}
void imprimeAlumno(Alumno a){
			cout<< a.getNombre()<<endl;
			cout<< a.getApellidos()<<endl;
			cout<< a.getDNI()<<endl;
			cout<< a.getCorreo()<<endl;
			cout<< a.getTelefono()<<endl;
			cout<< a.getDireccion()<<endl;
			cout<< a.getCursoMasAlto()<<endl;
			cout<< a.getFechaNacimiento()<<endl;
			cout<< a.getGrupo()<<endl;
			cout<< a.getLider()<<endl;
}