/**
 * @mainpage Práctica PRO2 - Programa usando un diseño modular: Plataforma "EVALUATOR".
 
En esta práctica se construye un programa modular que ofrece un menú de opciones para gestionar 
el contenido de la plataforma Evaluator, así como la actividad de los usuarios registrados y sus
estadísiticas en la plataforma.

Se introducen las clases <em>Problemas</em>, <em>Sesion</em>, <em>Sesiones</em>, <em>Curso</em>, <em>Cursos</em>,
<em>Usuario</em> y <em>Usuarios</em>.
*/

/** @file program.cc
    @brief Programa principal para el ejercicio <em>Plataforma "EVALUATOR"</em>.
*/

#include "Usuarios.hh"
#include "Problemas.hh"
#include "Sesiones.hh"
#include "Cursos.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/** @brief Programa principal para el ejercicio <em>Plataforma "EVALUATOR"</em>.
*/

int main() {
    Problemas cp;
    cp.leer_coleccion_problemas();
    Sesiones cs;
    cs.leer_conjunto_sesiones();
    Cursos cc;
    cc.leer_conjunto_cursos(cs);
    Usuarios cu;
    cu.leer_conjunto_usuarios();
    
    string op;
    while (cin >> op and op != "fin") {
        if (op == "nuevo_problema" or op == "np") {
            string p;
            cin >> p;

            cout << '#' << op << ' ' << p << endl;

            if (cp.existe_problema(p)) cout << "error: el problema ya existe" << endl;
            else {
                cp.nuevo_problema(p);
                cout << cp.numero_problemas() << endl;
            }
        }
        else if (op == "nueva_sesion" or op == "ns") {
            string s;
            cin >> s;
            
            cout << '#' << op << ' ' << s << endl;

            if (cs.existe_sesion(s)) cout << "error: la sesion ya existe" << endl;
            else {
                cs.nueva_sesion(s);
                cout << cs.numero_sesiones() << endl; 
            }
        }
        else if (op == "nuevo_curso" or op == "nc") {

            cout << '#' << op << endl;

            if(cc.nuevo_curso(cs)) cout << cc.numero_cursos() << endl;
            else cout << "error: curso mal formado" << endl;
        }
        else if (op == "alta_usuario" or op == "a") {
            string u;
            cin >> u;

            cout << '#' << op << ' ' << u << endl;

            if (cu.existe_usuario(u)) cout << "error: el usuario ya existe" << endl;
            else {
                cu.alta_usuario(u);
                cout << cu.numero_usuarios() << endl;
            }
        }
        else if (op == "baja_usuario" or op == "b") {
            string u;
            cin >> u;

            cout << '#' << op << ' ' << u << endl;
            
            if (not cu.existe_usuario(u)) cout << "error: el usuario no existe" << endl;
            else {
                int c = cu.consultar_curso_usuario(u);
                if(c != 0) cc.decrementar_usuarios_inscritos(c);

                cu.baja_usuario(u);
                cout << cu.numero_usuarios() << endl;
            }
        }
        else if (op == "inscribir_curso" or op == "i") {
            string u;
            int c;
            cin >> u >> c;

            cout << '#' << op << ' ' << u << ' ' << c << endl;

            if (not cu.existe_usuario(u)) cout << "error: el usuario no existe" << endl;
            else if (not cc.existe_curso(c)) cout << "error: el curso no existe" << endl;
            else if (cu.consultar_curso_usuario(u) != 0) cout << "error: usuario inscrito en otro curso" << endl;
            else {
                cu.inscribir_curso(u,c,cs,cc);
                cc.incrementar_usuarios_inscritos(c);
                cout << cc.numero_inscritos_curso(c) << endl;                
            }
        }
        else if (op == "curso_usuario" or op == "cu") {
            string u;
            cin >> u;

            cout << '#' << op << ' ' << u << endl;

            if (not cu.existe_usuario(u)) cout << "error: el usuario no existe" << endl;
            else cout << cu.consultar_curso_usuario(u) << endl;
        }
        else if (op == "sesion_problema" or op == "sp") {
            int c;
            string p;
            cin >> c >> p;

            cout << '#' << op << ' ' << c << ' ' << p << endl;

            if (not cc.existe_curso(c)) cout << "error: el curso no existe" << endl;
            else if (not cp.existe_problema(p)) cout << "error: el problema no existe" << endl;
            else if (not cc.existe_problema_curso(c,p)) cout << "error: el problema no pertenece al curso" << endl;
            else cc.sesion_problema_curso(c,p);
            
        }
        else if (op == "problemas_resueltos" or op == "pr") {
            string u;
            cin >> u;

            cout << '#' << op << ' ' << u << endl;

            if (not cu.existe_usuario(u)) cout << "error: el usuario no existe" << endl;
            else cu.problemas_resueltos_usuario(u);
        }
        else if (op == "problemas_enviables" or op == "pe") {
            string u;
            cin >> u;

            cout << '#' << op << ' ' << u << endl;

            if (not cu.existe_usuario(u)) cout << "error: el usuario no existe" << endl;
            else if (cu.consultar_curso_usuario(u) == 0) cout << "error: usuario no inscrito en ningun curso" << endl;
            else cu.problemas_enviables_usuario(u);
        }
        else if (op == "envio" or op == "e") {
            string u, p;
            int r;
            cin >> u >> p >> r;

            cout << '#' << op << ' ' << u << ' ' << p << ' ' << r << endl; 

            cu.envio(u,p,r,cs,cc,cp);
            cp.envio(p,r);
            
        }
        else if (op == "listar_problemas" or op == "lp") {
            cout << '#' << op << endl;
            cp.listar_problemas();
        }
        else if (op == "escribir_problema" or op == "ep") {
            string p;
            cin >> p;   

            cout << '#' << op << ' ' << p << endl;

            if (not cp.existe_problema(p)) cout << "error: el problema no existe" << endl;
            else cp.escribir_problema(p);
        }
        else if (op == "listar_sesiones" or op == "ls") {
            cout << '#' << op << endl;
            cs.listar_sesiones();
        }
        else if (op == "escribir_sesion" or op == "es") {
            string s;
            cin >> s;

            cout << '#' << op << ' ' << s << endl;

            if (not cs.existe_sesion(s)) cout << "error: la sesion no existe" << endl;
            else {
                cout << s << ' ';
                cs.escribir_sesion(s);
            }
        }
        else if (op == "listar_cursos" or op == "lc") {
            cout << '#' << op << endl;
            cc.listar_cursos();
        }
        else if (op == "escribir_curso" or op == "ec") {
            int c;
            cin >> c;

            cout << '#' << op << ' ' << c << endl;

            if (not cc.existe_curso(c)) cout << "error: el curso no existe" << endl;
            else {
                cout << c << ' ';
                cc.escribir_curso(c);
            }
        }
        else if (op == "listar_usuarios" or op == "lu") {
            cout << '#' << op << endl;
            cu.listar_usuarios();
        }
        else if (op == "escribir_usuario" or op == "eu") {
            string u;
            cin >> u;

            cout << '#' << op << ' ' << u << endl;

            if (not cu.existe_usuario(u)) cout << "error: el usuario no existe" << endl;
            else { 
                cout << u;
                cu.escribir_usuario(u);
            }
        }
    }
}


