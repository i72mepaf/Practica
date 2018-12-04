<<<<<<< HEAD
=======
#include "Clases.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>

bool sortByCursoa(Alumno &lhs,Alumno &rhs){ return lhs.getCurso() > rhs.getCurso() ; }
bool sortByCursod(Alumno &lhs,Alumno &rhs){ return lhs.getCurso() < rhs.getCurso() ; }
bool sortByApella(Alumno &lhs,Alumno &rhs){ return lhs.getApellidos() > rhs.getApellidos() ; }
bool sortByApella(Alumno &lhs,Alumno &rhs){ return lhs.getApellidos() < rhs.getApellidos() ; }
>>>>>>> 04c3f11472e7e9d8bea16650784e0c3258d1f72c

void BaseAlumnos::eliminarAlumno(){ //Felipe

}
bool Profesor::identificaProfesor(){ /*Felipe //Requisito no funcional (el archivo de credenciales tiene 
que haber profesores, mínimo el profesor coordinador)

- SecuenciaIdentificarProfesor.jpg: El actor que hace este flujo de acciones no es el profesor, 
es un usuario no identificado. Puedo trollear a la aplicación diciendo que soy coordinador 
cuando realmente no lo soy (Hay que comprobar esto de alguna forma.) Lo de vuelva al punto 4.1 
se puede solucionar con un flujo loop. Las comprobaciones se pueden hacer en el mismo sistema, 
donde se haga un ‘match’ entre las credenciales del fichero y las que mete el usuario.*/
/*
Cuando se deseen guardar registros de este tipo en un archivo, se puede hacer de la manera siguiente:

 Persona p1;
 Persona p2;

 strcpy( p1.nombre, "Baltasar" );
 strcpy( p1.telefono, "988387028" );
 p1.edad = 33;

 strcpy( p2.nombre, "Pedro" );
 strcpy( p2.telefono, "988387018" );
 p1.edad = 33;

 ofstream f( "datos.bin", ios::binary );
 if ( f.is_open() ) {
	 f.write( (char *) &p1, sizeof( Persona ) );
	 f.write( (char *) &p2, sizeof( Persona ) );
 } else cout << "Error de apertura de archivo." << endl;
}

Es posible realizar una lectura de cada registro de la siguiente forma:

 Persona p;
 ifstream f( "datos.bin", ios::binary );

 if ( f.is_open() ) {
	f.read( (char *) &p, sizeof( Persona ) );
	while( !f.eof() ) {
		volcar( cout, p );
		f.read( (char *) &p, sizeof( Persona ) );
	}
 } else cout << "Error de apertura de archivo." << endl;
}

*/
	system("clear");
	Profesor aux;
	ifstream f("credenciales.bin", ios::binary);
	if (f.is_open()){
		while(!f.eof()){
			f.read((char*) &aux, sizeof(Profesor));


		}

	}

}
void Profesor::eliminarBaseAlumnos(){ //Felipe

}

<<<<<<< HEAD
void BaseAlumnos::insertarAlumno(){
	list<Alumno>::iterator it;
	Alumno alumno;
	std::string nombre;
	std::string apellidos;
	std::string DNI;
	std::string correo;
	int telefono;
	int direccion
	int cursoMasAlto;
	int diaNacimiento, mesNacimiento, anoNacimiento;
	bool lider;
	int grupo;

	
	std::cout<<"Introduce el DNI del alumno"<<endl;
	std::cin>>DNI;
	
	it = alumnos_.begin();
	while(it != alumnos_.end){
		if(it.getDNI()==DNI) {
			std::cout<<("ERROR.Este Alumno ya existe")<<endl;
			exit(-1);
		}
	}
	std::cout<<"Introduzca el nombre del alumno"<<endl;
	std::cin>>nombre;
	std::cout>>"Introduce el apellido del alumno"<<endl;
	std::cin>>apellidos;
	std::cout<<"Introduce el corre del alumno"<<endl;
	std::cin>>correo;
	std::cout<<"Introduce el numero de telefono del alumno"<<endl;
	std::cin>>telefono;
	std::cout<<"Introduce la direccion del alumno"<<endl;
	std::cin>>direccion;
	std::cout<<"Introduce el curso mas alto en el que el alumno esta matriculado"<<endl;
	std::cin>>cursoMasAlto;
	std::cout<<"Introduce el dia en el que el alumno nacio"<<endl;
	std::cin>>diaNacimiento;
	std::cout<<"Introduce el mes de nacimiento del alumno"<<endl;
	std::cin>>mesNacimiento;
	std::cout<<"Introduce el año de nacimiento del alumno"<<endl;
	std::cin>>anoNacimiento;
	std::cout<<"Este alumno es lider de algun grupo"<<endl;
	std::cin>>lider;
	std::cout<<"Grupo del alumno"<<endl:

	alumno.setNombre(std::string nombre);
	alumno.setApellidos(std::string apellidos);
	alumno.setDNI(std::string DNI);
	alumno.setCorreo(std::string correo);
	alumno.setTelefono(int telefono);
	alumno.setDireccion(int direccion);
	alumno.setCursoMasAlto(int cursoMasAlto);
	alumno.setFechaNacimiento(int diaNacimiento, int mesNacimiento, int anoNacimiento);
	alumno.setLider(bool lider);
	alumno.setGrupo(int grupo);
	alumnos_.push_back(alumno);
}

void Alumno::setNombre(std::string nombre) {
	nombre_=nombre;
}
void Alumno::setApellidos(std::string apellidos) {
	apellidos_=apellidos;
}
void Alumno::setDNI(std::string DNI) {
	DNI_ = DNI;
}
void Alumno::setCorreo(std::string correo) {
	correo_ = correo;
}
void Alumno::setTelefono(int telefono) {
	telefono_ = telefono;
}
void Alumno::setDireccion(int direccion) {
	direccion_ = direccion;
}
void Alumno::setCursoMasAlto(int cursoMasAlto) {
	cursoMasAlto_ = cursoMasAlto
}
void Alumno::setFechaNacimiento(int diaNacimiento, int mesNacimiento, int anoNacimiento) {
	std::string aux;
	if(mesNacimiento <= 0 || mesNacimiento > 12) {
		std::cout<<"El mes numero "<<mesNacimiento<<"no existe"<<endl;
		exit(-1);
	}
	if(mesNacimiento == 1) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 2) {
		if(diaNacimiento <= 0 || diaNacimiento > 28) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 3) {
		if(diaNacimiento <= 0 || diaNacimiento > 29) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 4) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 5) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 6) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 7) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 8) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 9) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 10) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 11) {
		if(diaNacimiento <= 0 || diaNacimiento > 30) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	if(mesNacimiento == 12) {
		if(diaNacimiento <= 0 || diaNacimiento > 31) {
			std::cout<<"El dia "<<diaNacimiento<<"no esta en el mes "<<mesNacimiento<<endl;
			exit(-1);
		}
	}
	itoa(diaNacimiento, mesNacimiento, anoNacimiento);
	aux = diaNacimiento+"/"+mesNacimiento+"/"+anoNacimiento;
	fechaNacimiento_ = aux;
}
void Alumno::setLider(bool lider) {}
void Alumno::setGrupo(int grupo) {
	grupo_ = grupo;

void BaseAlumnos::mostrarAlumno(){
	int menu,menu2;
	int comp=0;
	int comp2=0;
	int vit=0;
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
	cout >> "Mostrar todos los alumnos ....1"<< endl;
	cout >> "Mostrar solo un alumno .......2"<< endl;
	cin>> menu;
	list <Alumno>:: iterator i;
	//system("cls");
	
		switch(menu){
			case 1:
				do{
				cout >> "Mostrar todos los alumnos ordenados ascendentemente por curso mas alto matriculado....1"<< endl;
				cout >> "Mostrar todos los alumnos ordenados descendentemente por curso mas alto matriculado...2"<< endl;
				cout >> "Mostrar todos los alumnos ordenados ascendentemente por apellidos.....................3"<< endl;
				cout >> "Mostrar todos los alumnos ordenados descendentemente por apellidos....................4"<< endl;
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
							cout >> "Error ,introduzca una opcion válida"<< endl;
							break;					
					}
				}while(comp2 == 0);

				comp=1;
				break;

			case 2:
				do{
					cout >>"Mostrar un alumno por dni..........1"
					cout >>"Mostrar un alumno por Apellidos....2"
					cin >> menu2
					switch(menu2){
						case 1:
						for (int i=0;i<v.size();i++){
							if
						}

						comp2=1
						break;

						case 2:
						comp2=1;
						break;

						default:
							cout >> "Error ,introduzca una opcion válida"<< endl;
							break; 
					}

				}while(comp2 == 0),





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