program.x: program.o Problemas.o Curso.o Cursos.o Sesion.o Sesiones.o Usuario.o Usuarios.o
	g++ -o program.x program.o Problemas.o Curso.o Cursos.o Sesion.o Sesiones.o Usuario.o Usuarios.o

Problmeas.o: Problemas.cc Problemas.hh
	g++ -c Problemas.cc 

Curso.o: Curso.cc Curso.hh
	g++ -c Curso.cc 

Cursos.o: Cursos.cc Cursos.hh
	g++ -c Cursos.cc 

Sesion.o: Sesion.cc Sesion.hh
	g++ -c Sesion.cc 
Sesiones.o: Sesiones.cc Sesiones.hh
	g++ -c Sesiones.cc 

Usuario.o: Usuario.cc Usuario.hh
	g++ -c Usuario.cc 

Usuarios.o: Usuarios.cc Usuarios.hh
	g++ -c Usuarios.cc 

clean:
	rm *.o
	rm *.x
