#include "Usuario.hh"

Usuario::Usuario() {
    id_curso_inscrito = 0;
    numero_problemas_intentados = 0;
    numero_total_envios = 0;
}

void Usuario::inscribir_usuario_curso(int c, Curso& curso, const Sesiones& cs) {
    id_curso_inscrito = c;
    curso.modificar_enviables(enviables,resueltos,cs);
}

void Usuario::curso_usuario() const {
    cout << id_curso_inscrito << endl;
}

int Usuario::consultar_curso() const {
    return id_curso_inscrito;   
}

void Usuario::problemas_resueltos() const {
    resueltos.listar_identificador_envios();
}

void Usuario::problemas_enviables() const {
    enviables.listar_identificador_envios();
}

void Usuario::escribir_usuario() const {
    cout << '(' << numero_total_envios << ',' << resueltos.numero_problemas() << ',' <<
    numero_total_envios << ',' << id_curso_inscrito << ')' << endl;
}
