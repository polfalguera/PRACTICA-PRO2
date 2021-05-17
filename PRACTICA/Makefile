OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -std=c++11

program.exe: program.o Cursos.o Sesiones.o Problemas.o Usuarios.o Usuario.o Curso.o Sesion.o
	g++ -o program.exe program.o Cursos.o Sesiones.o Problemas.o Usuarios.o Usuario.o Curso.o Sesion.o
	
program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Cursos.o: Cursos.cc Cursos.hh
	g++ -c Cursos.cc $(OPCIONS)
	
Sesiones.o: Sesiones.cc Sesiones.hh
	g++ -c Sesiones.cc $(OPCIONS)
	
Problemas.o: Problemas.cc Problemas.hh
	g++ -c Problemas.cc $(OPCIONS)

Usuarios.o: Usuarios.cc Usuarios.hh
	g++ -c Usuarios.cc $(OPCIONS)

Usuario.o: Usuario.cc Usuario.hh
	g++ -c Usuario.cc $(OPCIONS)
	
Curso.o: Curso.cc Curso.hh
	g++ -c Curso.cc $(OPCIONS)
	
Sesion.o: Sesion.cc Sesion.hh
	g++ -c Sesion.cc $(OPCIONS)
tar: program.cc Cursos.cc Cursos.hh Sesiones.cc Sesiones.hh Problemas.cc Problemas.hh Usuarios.cc Usuarios.hh Curso.cc Curso.hh Sesion.cc Sesion.hh Usuario.cc Usuario.hh
	 tar -cvf practica.tar Makefile program.cc Cursos.cc Cursos.hh Sesiones.cc Sesiones.hh Problemas.cc Problemas.hh Usuarios.cc Usuarios.hh Curso.cc Curso.hh Sesion.cc Sesion.hh Usuario.cc Usuario.hh pol.falguera.html.zip

clean:
	rm -f *.o
	rm -f *.exe
