#include "Clases.h"

bool sortByCursoa(Alumno &lhs,Alumno &rhs){ return lhs.getCursoMasAlto() > rhs.getCursoMasAlto() ; }
bool sortByCursod(Alumno &lhs,Alumno &rhs){ return lhs.getCursoMasAlto() < rhs.getCursoMasAlto() ; }
bool sortByApella(Alumno &lhs,Alumno &rhs){ return lhs.getApellidos() > rhs.getApellidos() ; }
bool sortByApelld(Alumno &lhs,Alumno &rhs){ return lhs.getApellidos() < rhs.getApellidos() ; }

void BaseAlumnos::eliminarAlumno(){ //Felipe
	string ap;
	int cont=0;
	cout << "Introduzca los apellidos del alumno a eliminar:"<< endl;
	getline(cin, ap);
	list<Alumno>::iterator it; 
	for(it=alumnos_.begin(); it != alumnos_.end(); ++it){
		if(it->getApellidos() == ap)
			cont++;
	}
	if(cont == 1){

		for(it=alumnos_.begin(); it != alumnos_.end(); ++it){
			if(it->getApellidos() == ap)
				alumnos_.erase(it);
			}
		cout << "Alumno con apellidos: '"<< ap <<"' eliminado con exito."<<endl;
	}
	else{
		if(cont == 0)
			cout << "No hay ningún alumno con los apellidos '"<<ap<<"' en nuestra base de datos" << endl;
		else{
			cont = 0;
			cout << "Hay varios alumnos con los apellidos: '" << ap << "'." << endl;
			cout << "Porfavor, introduzca el DNI del alumno a borrar:" << endl;
			getline(cin, ap);
			for(it=alumnos_.begin(); it != alumnos_.end(); ++it){
				if(it->getDNI() == ap){
					alumnos_.erase(it);
					cont++;
				}
			}
			if(cont == 1)
				cout << "Alumno con DNI: '"<< ap <<"' eliminado con exito." << endl;
			else
				cout << "El DNI: '"<< ap <<"' no coincide con ninguno de nuestra base de datos." << endl;
		}
	}
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
		cin.ignore();
		system("clear");
		if(opcion!=1 && opcion!=2){
			cout << "Número Incorrecto. Intentelo de nuevo." << endl;
		}
		else{
			if(opcion==1){//Coordinador
				cout << "A continuación procederemos a identificarle como profesor Coordinador." << endl;
				cout << "Introduzca DNI: ";
				getline(cin, dni);
				system("clear");
   				for (int i = 0; i < (int) v.size(); ++i)
   				{
   					compDNI = v[i].d;
   					compROL = v[i].r;
   					if(compDNI == dni && compROL == "Coordinador")
   						cout << "Identificado Correctamente." << endl;
   					while(compDNI == dni && compROL == "Coordinador"){
   						cout << "¿Desea iniciar o cambiar DNI?\n1. Iniciar.\n2. Cambiar DNI." << endl;
   						cin >> opcion;
   						cin.ignore();
   						system("clear");
   						if(opcion!= 1 && opcion!=2){
   							cout << "Numero Incorrecto. Intentalo de nuevo." << endl;
   						}
   						else{
   							if(opcion == 1){
   								remove("credenciales.bin");
   								ofstream fCreacion("credenciales.bin", ios::out | ios::binary);
								if (fCreacion.is_open()){
									for(int j=0; j < (int) v.size(); j++)
									fCreacion.write((char *)&v[j], sizeof(Auxiliar));
   								}
   								else{
   									cout << "Error al abrir el fichero." << endl;
   									exit(-1);
   								}
   								fCreacion.close();
   								cout << "Iniciando..." << endl;
   								setDNI(compDNI);
   								setRol(compROL);
   								return true;
   							}
   							else{
   								cout << "Introduzca el nuevo DNI: ";
   								getline(cin, dni);
   								remove("credenciales.bin");
   								ofstream fEscCoord("credenciales.bin", ios::out | ios::binary);
								if (fEscCoord.is_open()){
									for(int j=0; j < (int) v.size(); j++){
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
   								setDNI(dni);
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
				cin.ignore();
				system("clear");
   				if(opcion!= 1 && opcion!=2){
  					cout << "Numero Incorrecto. Intentalo de nuevo." << endl;
  					opcion = 3;
				}
				else{
					if(opcion == 1){//Registrarse
						for (int i = 0; i < (int) v.size(); ++i)
						{
							compROL = v[i].r;
							if(compROL=="Ayudante")
								contadorTipo++;
						}
						if(contadorTipo < 5){
							cout << "Registro de un profesor ayudante.\nIntroduce el DNI: ";
							getline(cin, dni);
							strcpy(aux.d, dni.c_str());
							strcpy(aux.r, "Ayudante");
							v.push_back(aux);
							remove("credenciales.bin");
							ofstream fEscAyud("credenciales.bin", ios::out | ios::binary);
							if (fEscAyud.is_open()){
								for(int i=0; i < (int) v.size(); i++)
									fEscAyud.write((char *)&v[i], sizeof(Auxiliar));
   							}
   							else{
   								cout << "Error al abrir el fichero." << endl;
   								exit(-1);
   							}
   							fEscAyud.close();
   							cout << "Registro correcto. Iniciando..." << endl;
   							setDNI(dni);
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
						getline(cin, dni);
						system("clear");
   						for (int i = 0; i < (int) v.size(); ++i)
   						{
   							compDNI = v[i].d;
   							compROL = v[i].r;
   							if(compDNI == dni && compROL == "Ayudante"){
   								cout << "Identificado Correctamente. Iniciando..." << endl;
   								remove("credenciales.bin");
   								ofstream fCreacionA("credenciales.bin", ios::out | ios::binary);
								if (fCreacionA.is_open()){
									for(int j=0; j < (int) v.size(); j++)
									fCreacionA.write((char *)&v[j], sizeof(Auxiliar));
   								}
   								else{
   									cout << "Error al abrir el fichero" << endl;
   									exit(-1);
   								}
   								fCreacionA.close();
   								setDNI(compDNI);
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
void BaseAlumnos::setListaAlumno(list<Alumno> lista){
	while(alumnos_.size()!=0)
		alumnos_.pop_back();
	alumnos_=lista;
}
void Profesor::eliminarBaseAlumnos(){ //Felipe
	int opcion=0;
	list<Alumno> alumnos;
	alumnos = base_.getListaAlumno();
	while(opcion!=1 && opcion!=2){
		cout << "¿Esta seguro que desea eliminar la base de datos de los alumnos?" << endl;
		cout << "1. Sí.\n2. No."<<endl;
		cin >> opcion;
		cin.ignore();
		system("clear");
		if(opcion!=1 && opcion!=2)
			cout << "Error. Vuelva a intentarlo introduciendo un número valido" << endl;
	}
	if(opcion == 1){
		if(alumnos.size()==0){
			cout << "La base de los alumnos esta vacia" << endl;
		}
		else{
			while(alumnos.size()!=0)
				alumnos.pop_back();
			cout << "Base de Alumnos eliminada con exito" << endl;
		}
	}
	base_.setListaAlumno(alumnos);
}


bool BaseAlumnos::insertarAlumno(){
	list<Alumno>::iterator it;
	Alumno alumno;
	string nombre;
	string apellidos;
	string DNI;
	string correo;
	int telefono;
	string direccion;
	int cursoMasAlto;
	int diaNacimiento, mesNacimiento, anoNacimiento;
	bool lider;
	int grupo;

	int opcion;
	
	cout<<"Introduce el DNI del alumno"<<endl;
	getline(cin, DNI);
	it = alumnos_.begin();
	while(it != alumnos_.end()){
		if(it->getDNI()==DNI) {
			cout << "ERROR.Este Alumno con este DNI ya existe" << endl;
			opcion=0;
			while(opcion!=1 && opcion !=2){
				cout << "¿Que desea?\n1. No introducir el alumno\n2.Introducir de nuevo el DNI" << endl;
				cin >> opcion;
				cin.ignore();
				system("clear");
				if(opcion!=1 && opcion !=2){
					cout << "ERROR. No ha seleccionado un número correcto. Vuelva a intentarlo" << endl;
				}
				else{
					if(opcion==2){
					cout << "Vuelva a introducir el DNI: ";
					getline(cin, DNI);
					it = alumnos_.begin();
					}
					else{
						cout << "No se ha introducido el alumno" << endl;
						return false;
					}
				}
			}
		}
		else{
			++it;
		}
	}
	cout<<"Introduzca el nombre del alumno"<<endl;
	getline(cin, nombre);
	cout<<"Introduzca el apellido del alumno"<<endl;
	getline(cin, apellidos);
	cout<<"Introduzca el correo del alumno"<<endl;
	getline(cin, correo);
	it=alumnos_.begin();
	while(it != alumnos_.end()){
		if(it->getCorreo()==correo) {
			cout << "ERROR.Este Alumno con este correo ya existe" << endl;
			opcion=0;
			while(opcion!=1 && opcion !=2){
				cout << "¿Que desea?\n1. No introducir el alumno\n2.Introducir de nuevo el correo" << endl;
				cin >> opcion;
				cin.ignore();
				system("clear");
				if(opcion!=1 && opcion !=2){
					cout << "ERROR. No ha seleccionado un número correcto. Vuelva a intentarlo" << endl;
				}
				else{
					if(opcion==2){
					cout << "Vuelva a introducir el correo: ";
					getline(cin, correo);
					it = alumnos_.begin();
					}
					else{
						cout << "No se ha introducido el alumno" << endl;
						return false;
					}
				}
			}
		}
		else{
			++it;
		}
	}

	cout<<"Introduzca el numero de telefono del alumno"<<endl;
	cin>>telefono;
	cin.ignore();
	cout<<"Introduzca la direccion del alumno"<<endl;
	getline(cin, direccion);
	cout<<"Introduzca el curso mas alto en el que el alumno esta matriculado"<<endl;
	cin>>cursoMasAlto;
	cin.ignore();
	cout<<"Introduzca el dia en el que el alumno nacio"<<endl;
	cin>>diaNacimiento;
	cin.ignore();
	cout<<"Introduzca el mes de nacimiento del alumno"<<endl;
	cin>>mesNacimiento;
	cin.ignore();
	cout<<"Introduzca el año de nacimiento del alumno"<<endl;
	cin>>anoNacimiento;
	cin.ignore();
	cout<<"Introduzca el grupo del alumno"<<endl;
	cin>>grupo;
	cin.ignore();
	cout<<"Introduzca si es lider o no de algun grupo"<<endl;
	opcion=0;
	while(opcion!=1 && opcion!=2){
		cout << "1.Lider\n2.No Lider" << endl;
		cin>>opcion;
		cin.ignore();
		if(opcion!=1 && opcion!=2){
			cout << "Error. Seleccione un número correcto" << endl;
		}
		else{
			if(opcion==1)
				lider=true;
			else
				lider=false;
		}
	}
	alumno.setNombre(nombre);
	alumno.setApellidos(apellidos);
	alumno.setDNI(DNI);
	alumno.setCorreo(correo);
	alumno.setTelefono(telefono);
	alumno.setDireccion(direccion);
	alumno.setCursoMasAlto(cursoMasAlto);
	alumno.setFechaNacimiento(diaNacimiento, mesNacimiento, anoNacimiento);
	alumno.setGrupo(grupo);
	if(lider == true) {
		for(it=alumnos_.begin(); it != alumnos_.end(); ++it){
			if(it->getGrupo() == alumno.getGrupo() && it->getLider() == true) {//Si hay alumnos en el grupo del estudiante insertado y si hay un lider en dicho grupo
				cout<<"En este grupo ya hay un lider."<<endl;
				cout << "Por lo que el alumno insertado estará en el grupo pero no será lider"<<endl;
				lider=false;
			}
			
		}

	}
	alumno.setLider(lider);
	alumnos_.push_back(alumno);
	return true;

}

void Alumno::setFechaNacimiento(int diaNacimiento, int mesNacimiento, int anoNacimiento) {
	string aux;
	while(mesNacimiento <= 0 || mesNacimiento > 12) {
		cout<<"El mes numero "<<mesNacimiento<<" no existe"<<endl;
		cout << "Introduzca de nuevo el número del mes:" << endl;
		cin >> mesNacimiento;
		cin.ignore();
	}
	if(mesNacimiento == 1) {
		while(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 2) {
		while(diaNacimiento <= 0 || diaNacimiento > 28) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 3) {
		while(diaNacimiento <= 0 || diaNacimiento > 29) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 4) {
		while(diaNacimiento <= 0 || diaNacimiento > 30) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 5) {
		while(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 6) {
		while(diaNacimiento <= 0 || diaNacimiento > 30) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 7) {
		while(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 8) {
		while(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 9) {
		while(diaNacimiento <= 0 || diaNacimiento > 30) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 10) {
		while(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 11) {
		while(diaNacimiento <= 0 || diaNacimiento > 30) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	if(mesNacimiento == 12) {
		while(diaNacimiento <= 0 || diaNacimiento > 31) {
			cout<<"El dia "<<diaNacimiento<<" no esta en el mes "<<mesNacimiento<<endl;
			cout << "Introduzca de nuevo el día del mes:" << endl;
			cin >> diaNacimiento;
			cin.ignore();
		}
	}
	
	aux = (static_cast<ostringstream*>(&(ostringstream() << diaNacimiento))->str())+
	"/"+(static_cast<ostringstream*>(&(ostringstream() << mesNacimiento))->str())+"/"+
	(static_cast<ostringstream*>(&(ostringstream() << anoNacimiento))->str());
	fechaNacimiento_ = aux;
}
void imprimeVector(vector <Alumno> v,int nele); //Cabeceras de funciones para que no haya error al compilar

void imprimeAlumno(Alumno a);

void BaseAlumnos::mostrarAlumno(){
	int menu,menu2;
	int comp=0;
	int comp2=0;
	int vit=0;
	int cont=0;
	int nele=0;
	string aux;
	vector <Alumno> v(150);
	list <Alumno>:: iterator i;
	for(i=alumnos_.begin();i != alumnos_.end();i++){
		v[vit].setNombre(i->getNombre());
		v[vit].setApellidos(i->getApellidos());
		v[vit].setDNI(i->getDNI());
		v[vit].setCorreo(i->getCorreo());
		v[vit].setTelefono(i->getTelefono());
		v[vit].setDireccion(i->getDireccion());
		v[vit].setCursoMasAlto(i->getCursoMasAlto());
		aux = (i->getFechaNacimiento());
		v[vit].setFechaNacimiento(atoi((aux.substr(0, aux.find("/"))).c_str()), 
			atoi((aux.substr(aux.find("/")+1, aux.find("/"))).c_str()), 
			atoi((aux.substr(aux.find(aux.substr(aux.find("/")+1, aux.find("/")))+1, aux.find("\n"))).c_str()));
		v[vit].setLider(i->getLider());
		vit++;
		nele++;
	}
	
	do{
	cout << "Mostrar todos los alumnos ....1"<< endl;
	cout << "Mostrar solo un alumno .......2"<< endl;
	cin>> menu;
	cin.ignore();
	//system("cls");
	
		switch(menu){
			case 1:
				do{
				cout << "Mostrar todos los alumnos ordenados ascendentemente por curso mas alto matriculado....1"<< endl;
				cout << "Mostrar todos los alumnos ordenados descendentemente por curso mas alto matriculado...2"<< endl;
				cout << "Mostrar todos los alumnos ordenados ascendentemente por apellidos.....................3"<< endl;
				cout << "Mostrar todos los alumnos ordenados descendentemente por apellidos....................4"<< endl;
				cin>> menu2;
				cin.ignore();			
					switch(menu2){
						case 1:
						sort(v.begin(),v.end(),sortByCursoa);
						imprimeVector(v,nele);
						comp2=1;
						break;

						case 2:
						sort(v.begin(),v.end(),sortByCursod);
						imprimeVector(v,nele);
						comp2=1;
						break;

						case 3:
						comp2=1;
						sort(v.begin(),v.end(),sortByApella);
						imprimeVector(v,nele);
						break;

						case 4:
						sort(v.begin(),v.end(),sortByApelld);
						imprimeVector(v,nele);
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
					cin.ignore();
					switch(menu2){
						case 1:
						cout <<"Introduzca el dni del alumno a mostrar"<<endl;
						cin>>aux;
						cin.ignore();
						for (int i=0;i< (int) v.size();i++){
							if(aux == v[i].getDNI()){
								imprimeAlumno(v[i]);
								comp2=1;
								break;
							}
						}
						cout <<"No se encontro el alumno"<<endl;
						comp2=1;
						break;

						case 2:
						cout <<"Introduzca los apellidos del alumno a mostrar"<<endl;
						getline(cin, aux);
						for (int i=0;i<(int) v.size();i++){
							if(aux == v[i].getApellidos()){
								cont++;
							}
						}
						if(cont!=1){
							cout <<"No se puede imprimir el alumno por apellidos"<<endl;
							break;
						}
						for (int i=0;i< (int) v.size();i++){
							if(aux == v[i].getApellidos()){
							imprimeAlumno(v[i]);	
							}
						}
						comp2 =1;
						break;

						default:
							cout << "Error ,introduzca una opcion válida"<< endl;
							break; 
					}

				}while(comp2 == 0);
				comp=1;
				break;

			default:
				cout << "Error ,introduzca una opcion válida"<< endl;
				break;
		}
	}while(comp == 0);
}

void imprimeVector(vector <Alumno> v, int nele){
	for(int i=0;i< nele;i++){
		cout<< "Nombre: "<< v[i].getNombre()<<endl;
		cout<< "Apellidos: "<<  v[i].getApellidos()<<endl;
		cout<< "DNI: "<<  v[i].getDNI()<<endl;
		cout<< "Correo: "<<  v[i].getCorreo()<<endl;
		cout<< "Telefono: "<<  v[i].getTelefono()<<endl;
		cout<< "Dirección: "<<  v[i].getDireccion()<<endl;
		cout<< "Curso más alto: "<<  v[i].getCursoMasAlto()<<endl;
		cout<< "Fecha de nacimiento: "<<  v[i].getFechaNacimiento()<<endl;
		cout<< "Grupo: "<<  v[i].getGrupo()<<endl;
		cout << "Lider: ";
		if(v[i].getLider())
			cout << "Si"<< endl;
		else
			cout << "No" << endl;
	}
}

void imprimeAlumno(Alumno a){
	cout<< "Nombre: "<< a.getNombre()<<endl;
	cout<< "Apellidos: "<< a.getApellidos()<<endl;
	cout<< "DNI: "<< a.getDNI()<<endl;
	cout<< "Correo: "<< a.getCorreo()<<endl;
	cout<< "Telefono: "<< a.getTelefono()<<endl;
	cout<< "Dirección: "<< a.getDireccion()<<endl;
	cout<< "Curso más alto: "<< a.getCursoMasAlto()<<endl;
	cout<< "Fecha de nacimiento: "<< a.getFechaNacimiento()<<endl;
	cout<< "Grupo: "<< a.getGrupo()<<endl;
	cout << "Lider: ";
	if(a.getLider())
		cout << "Si"<< endl;
	else
		cout << "No" << endl;
}