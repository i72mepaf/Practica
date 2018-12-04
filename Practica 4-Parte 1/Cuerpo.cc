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