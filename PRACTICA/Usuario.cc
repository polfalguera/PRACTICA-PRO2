#include "Usuario.hh"

Usuario::Usuario() {
    id_curso_inscrito = 0;
    numero_problemas_intentados = 0;
    numero_total_envios = 0;
    //Que hago con los maps?
}

void Usuario::modificar_inscripciones() {

}

void Usuario::curso_usuario() const {

}

int Usuario::consultar_curso() const {
    return id_curso_inscrito;   
}

void Usuario::problemas_resueltos() const {

}

void Usuario::problemas_enviables() const {

}

void Usuario::escribir_usuario() const {
    cout << '(' << numero_total_envios << ", " << resueltos.size() << ", " <<
    numero_total_envios << ", " << id_curso_inscrito << ')' << endl;
}
