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

void Usuarios::inscribir_curso(string u, int c, const Sesiones& cs, const Cursos& cc) {
    map<string,Usuario>::iterator itu = cjt_usuarios.find(u);
    Curso curso = cc.consultar_curso(c);

    (*itu).second.inscribir_usuario_curso(c,curso,cs);

}

void Usuarios::envio(string u, string p, int r, const Sesiones& cjt_sesiones, const Cursos& cjt_cursos) {
    map<string,Usuario>::iterator it = cjt_usuarios.find(u);
    Usuario usuario = (*it).second;
    usuario.incrementar_total_envios();
 
    if (usuario.consultar_intentos_p(p) == 0) usuario.incrementar_problemas_intentados();

    usuario.incrementar_intentos_p(string p); 
    if (r == 1) {

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