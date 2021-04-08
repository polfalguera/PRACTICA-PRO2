#include "Usuarios.hh"
#include "Problemas.hh"
#include "Sesiones.hh"
#include "Cursos.hh"
#include <iostream>

using namespace std;

int main() {
    Cursos cc;
    cc.leer_conjunto_cursos();
    Sesiones cs;
    cs.leer_conjunto_sesiones();
    Problemas cp;
    cp.leer_coleccion_problemas();
    Usuarios cu;

    string op;
    while (op != "fin") {
        if (op == "nuevo problema" or op == "np") {
            string p;
            cin >> p;
            cp.nuevo_problema(p);
        }
        else if (op == "nueva sesion" or op == "ns") {
            string s;
            cin >> s;
            cs.nueva_sesion(s);             
        }
        else if (op == "nuevo curso" or op == "nc") {
            int c;
            cin >> c;
            cc.nuevo_curso(c);
        }
        else if (op == "alta usuario" or op == "a") {
            string u;
            cin >> u;

            Usuario us;
            usuario.leer_usuario();
            cu.alta_usuario(u,us);
        }
        else if (op == "baja usuario" or op == "b") {
            string u;
            cin >> u;

            cu.baja_usuario(u);
        }
        else if (op == "inscribir curso" or op == "i") {

        }
        else if (op == "curso usuario" or op == "cu") {
            string u;
            cin >> u;
        }
        else if (op == "sesion problema" or op == "sp") {

        }
        else if (op == "problemas resuletos" or op == "pr") {

        }
        else if (op == "problemas enviables" or op == "pe") {

        }
        else if (op == "envio" or op == "e") {

        }
        else if (op == "listar_problemas" or op == "lp") {
            cp.listar_problemas();
        }
        else if (op == "escribrir problema" or op == "ep") { 
            string p;
            cin >> p;

            cp.buscar_escribir_problema(p);
        }
        else if (op == "listar sesiones" or op == "ls") {
            cs.listar_sesiones();
        }
        else if (op == "escribir sesion" or op == "es") {
            string s;
            cin >> s;

            cs.buscar_escribir_sesion(s);
        }
        else if (op == "listar cursos" or op == "lc") {
            cc.listar_cursos();
        }
        else if (op == "escribir curso" or op == "ec") {
            int c;
            cin >> c;

            cc.buscar_escribir_curso(c)
        }
        else if (op == "listar usuarios" or op == "lu") {
            
        }
        else if (op == "escribir usuario" or op == "eu")
    }
}