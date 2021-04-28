#include "Usuario.hh"

Usuario::Usuario() {
    id_curso_inscrito = 0;
    numero_problemas_intentados = 0;
    numero_total_envios = 0;
}

void Usuario::modificar_inscripciones(int c) {
    id_curso_inscrito = c;
}

void Usuario::curso_usuario() const {
    cout << id_curso_inscrito << endl;
}

int Usuario::consultar_curso() const {
    return id_curso_inscrito;   
}

void Usuario::problemas_resueltos() const {
    map<string,int>::const_iterator it = resueltos.begin();

    while (it != resueltos.end()) {
        cout << (*it).first << ' ' << (*it).second << endl;
        ++it;
    }
}

void Usuario::problemas_enviables() const {
    map<string,int>::const_iterator it = enviables.begin();

    while (it != enviables.end()) {
        cout << (*it).first << ' ' << (*it).second << endl;
        ++it;
    }
}

void Usuario::escribir_usuario() const {
    cout << '(' << numero_total_envios << ',' << resueltos.size() << ',' <<
    numero_total_envios << ',' << id_curso_inscrito << ')' << endl;
}
