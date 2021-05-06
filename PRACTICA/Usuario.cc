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

void Usuario::desinscribir_usuario_curso() {
    id_curso_inscrito = 0;
}
void Usuario::incrementar_problemas_intentados() {
    ++numero_problemas_intentados;
}

void Usuario::incrementar_intentos_p(string p) {
    enviables.incrementar_intentos_usuario(p);
}

void Usuario::incrementar_total_envios() {
    ++numero_total_envios;
}

void Usuario::actualizar_enviables(string p, const Problema& problema, Curso& curso, const Sesiones& cs ) {
    enviables.eliminar_enviable(p);

    curso.modificar_enviables(enviables,resueltos,cs);    
}

void Usuario::actualizar_resueltos(string p, const Problema& problema) {
    resueltos.anadir_resuelto(p,problema);
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

int Usuario::consultar_intentos_p(string p) const {
    return enviables.numero_total_envios_p(p);
}

int Usuario::numero_problemas_enviables() const {
    return enviables.numero_problemas();
}

Problema Usuario::consultar_problema_enviable(string p) const {
    return enviables.consultar_problema(p);
}

void Usuario::escribir_usuario() const {
    cout << '(' << numero_total_envios << ',' << resueltos.numero_problemas() << ',' <<
    numero_problemas_intentados << ',' << id_curso_inscrito << ')' << endl;
}
