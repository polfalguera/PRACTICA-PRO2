#include "Usuarios.hh"
#include "Problemas.hh"
#include "Sesiones.hh"
#include "Cursos.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

int main() {
    Problemas cp;
    cp.leer_coleccion_problemas();
    Sesiones cs;
    cs.leer_conjunto_sesiones();
    Cursos cc;
    cc.leer_conjunto_cursos();
    Usuarios cu;
    
    
    

    string op;
    while (op != "fin") {
        if (op == "nuevo problema" or op == "np") {
            string p;
            cin >> p;

            if (cp.existe_problema(p)) cout << "Mensaje de error" << endl;
            else {
                cp.nuevo_problema(p);
                cout << cp.mida() << endl;
            }
        }
        else if (op == "nueva sesion" or op == "ns") {
            string s;
            cin >> s;

            if (cs.existe_sesion(s)) cout << "Mensaje de error" << endl;
            else {
                cs.nueva_sesion(s);
                cout << cs.mida() << endl;
            }
        }
        else if (op == "nuevo curso" or op == "nc") {
            if(cc.nuevo_curso(cs)) cout << cc.mida() << endl;
            else cout << "Mensaje de error" << endl;
        }
        else if (op == "alta usuario" or op == "a") {
            string u;
            cin >> u;

            if (cu.existe_usuario(u)) cout << "Mensaje de error" << endl;
            else {
                cu.alta_usuario(u);
                cout << cu.mida() << endl;
            }
        }
        else if (op == "baja usuario" or op == "b") {
            string u;
            cin >> u;
            
            if (not cu.existe_usuario(u)) cout << "Mensaje de error" << endl;
            else {
                cu.baja_usuario(u);
                cout << cu.mida() << endl;
            }

        }
        else if (op == "inscribir curso" or op == "i") {
            string u;
            int c;
            cin >> u >> c;

            if (not cu.existe_usuario(u)) cout << "Mensaje de error" << endl;
            else if (cu.consultar_usuario(u).consultar_curso() != 0) cout << "Mensaje de error" << endl;
            else if (not cc.existe_curso(c)) cout << "Mensaje de error" << endl;
            else cu.inscribir_curso(u,c);
        }
        else if (op == "curso usuario" or op == "cu") {
            string u;
            cin >> u;

            if (not cu.existe_usuario(u)) cout << "Mensaje de error" << cout;
            else cu.consultar_usuario(u).curso_usuario();
        }
        else if (op == "sesion problema" or op == "sp") {
            int c;
            string p;
            cin >> c >> p;

            if (not cc.existe_curso(c))) cout << "Mensaje de error" << endl;
            else if (not cp.existe_problema(p)) cout << "Mensaje de error" << endl;
            else if (not cc.consultar_curso(c).existe_problema_curso(p)) cout << "Mensaje de error" << endl;
            else cc.consultar_curso(c).sesion_problema(p);
            
        }
        else if (op == "problemas resueltos" or op == "pr") {
            string u;
            cin >> u;

            if (not cu.existe_usuario(u)) cout << "Mensaje de error" << endl;
            else cu.consultar_usuario(u).problemas_resueltos();
        }
        else if (op == "problemas enviables" or op == "pe") {
            string u;
            cin >> u;

            if (not cu.existe_usuario(u)) cout << "Mensaje de error" << endl;
            else cu.consultar_usuario(u).problemas_enviables();
        }
        else if (op == "envio" or op == "e") {
            string u, p;
            int r;
            cin >> u >> p >> r;
            cc.envio(u,p,r,cs,cu);
            cp.envio(p,r);
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

            if (not cc.existe_curso(c)) cout << "Mensaje de error" << endl;
            else cc.consultar_curso(c).escribir_curso();
        }
        else if (op == "listar usuarios" or op == "lu") {
            cu.listar_usuarios();
        }
        else if (op == "escribir usuario" or op == "eu") {
            string u;
            cin >> u;

            if (not cu.existe_usuario(u)) cout << "Mensaje de error" << endl;
            else cu.consultar_usuario(u).escribir_usuario();
        }
    }
}


