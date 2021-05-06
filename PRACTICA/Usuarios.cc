#include "Usuarios.hh"

Usuarios::Usuarios() {

}

void Usuarios::alta_usuario(string u) {
    Usuario usuario;
    cjt_usuarios.insert(make_pair(u,usuario));
}

void Usuarios::baja_usuario(string u) {
    map<string,Usuario>::iterator it = cjt_usuarios.find(u);
    
    cjt_usuarios.erase(it);
}

void Usuarios::inscribir_curso(string u, int c, const Sesiones& cs, Cursos& cc) {
    map<string,Usuario>::iterator itu = cjt_usuarios.find(u);
    Curso curso = cc.consultar_curso(c);

    (*itu).second.inscribir_usuario_curso(c,curso,cs);

}

void Usuarios::envio(string u, string p, int r, const Sesiones& cjt_sesiones, Cursos& cjt_cursos, const Problemas& cjt_problemas) {
    map<string,Usuario>::iterator it = cjt_usuarios.find(u);
    (*it).second.incrementar_total_envios();
 
    if ((*it).second.consultar_intentos_p(p) == 0) (*it).second.incrementar_problemas_intentados();

    (*it).second.incrementar_intentos_p(p);

    Problema problema = (*it).second.consultar_problema_enviable(p); 
    if (r == 1) {
        (*it).second.actualizar_resueltos(p,problema);

        int c = (*it).second.consultar_curso();
        Curso curso = cjt_cursos.consultar_curso(c);

        (*it).second.actualizar_enviables(p,problema,curso,cjt_sesiones);  

        if ((*it).second.numero_problemas_enviables() == 0) {
            (*it).second.desinscribir_usuario_curso();
            cjt_cursos.incrementar_usuarios_completado(c);
            cjt_cursos.decrementar_usuarios_inscritos(c);
        }
    }
}

Usuario Usuarios::consultar_usuario(string u) const {
    map<string,Usuario>::const_iterator it = cjt_usuarios.find(u);

    return (*it).second;
}

bool Usuarios::existe_usuario(string u) const {
    map<string,Usuario>::const_iterator it = cjt_usuarios.find(u);
    if (it == cjt_usuarios.end()) return false;
    
    return true;
}

int Usuarios::numero_usuarios() const {
    return cjt_usuarios.size();
}

void Usuarios::leer_conjunto_usuarios() {
    int numero_usuarios;
    cin >> numero_usuarios;

    string u;
    for (int i = 0; i < numero_usuarios; ++i) {
        cin >> u;
        Usuario usuario;
        cjt_usuarios.insert(make_pair(u,usuario));
    }
}

void Usuarios::listar_usuarios() const {
    map<string,Usuario>::const_iterator it = cjt_usuarios.begin();

    while (it != cjt_usuarios.end()) {
        cout << ((*it).first);
        (*it).second.escribir_usuario();

        ++it;   
    }
}