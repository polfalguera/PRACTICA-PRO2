#include "Usuarios.hh"

Usuarios::Usuarios() {

}

void Usuarios::alta_usuario(const string& u) {
    Usuario usuario;
    cjt_usuarios.insert(make_pair(u,usuario));
}

void Usuarios::baja_usuario(const string& u) {
    map<string,Usuario>::iterator it = cjt_usuarios.find(u);
    
    cjt_usuarios.erase(it);
}

void Usuarios::inscribir_curso(const string& u, int c, Sesiones& cs, Cursos& cc) {
    map<string,Usuario>::iterator itu = cjt_usuarios.find(u);
    Curso curso;
    cc.consultar_curso(c,curso);

    (*itu).second.inscribir_usuario_curso(c,curso,cs);

}

void Usuarios::envio(const string& u, const string& p, int r, Sesiones& cjt_sesiones, Cursos& cjt_cursos, const Problemas& cjt_problemas) {
    map<string,Usuario>::iterator it = cjt_usuarios.find(u);
    (*it).second.incrementar_total_envios();
 
    if ((*it).second.consultar_intentos_p(p) == 0) (*it).second.incrementar_problemas_intentados();

    (*it).second.incrementar_intentos_p(p);

    Problema problema;
    (*it).second.consultar_problema_enviable(p,problema); 
    if (r == 1) {
        (*it).second.actualizar_resueltos(p,problema);

        int c = (*it).second.curso_usuario();
        Curso curso;
        cjt_cursos.consultar_curso(c,curso);

        string s = cjt_cursos.sesion_problema_curso_aux(c,p);

        (*it).second.actualizar_enviables(p,s,problema,curso,cjt_sesiones);  

        if ((*it).second.numero_problemas_enviables() == 0) {
            (*it).second.desinscribir_usuario_curso();
            cjt_cursos.incrementar_usuarios_completado(c);
            cjt_cursos.decrementar_usuarios_inscritos(c);
        }
    }
}

bool Usuarios::existe_usuario(const string& u) const {
    map<string,Usuario>::const_iterator it = cjt_usuarios.find(u);
    if (it == cjt_usuarios.end()) return false;
    
    return true;
}

int Usuarios::numero_usuarios() const {
    return cjt_usuarios.size();
}

int Usuarios::consultar_curso_usuario(const string& u) const {
    map<string,Usuario>::const_iterator it = cjt_usuarios.find(u);

    return (*it).second.curso_usuario();
}

void Usuarios::problemas_resueltos_usuario(const string& u) const {
    map<string,Usuario>::const_iterator it = cjt_usuarios.find(u);

    (*it).second.problemas_resueltos();
}

void Usuarios::problemas_enviables_usuario(const string& u) const {
    map<string,Usuario>::const_iterator it = cjt_usuarios.find(u);

    (*it).second.problemas_enviables();
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

void Usuarios::escribir_usuario(const string& u) const {
    map<string,Usuario>::const_iterator it = cjt_usuarios.find(u);

    (*it).second.escribir();
}

void Usuarios::listar_usuarios() const {
    map<string,Usuario>::const_iterator it = cjt_usuarios.begin();

    while (it != cjt_usuarios.end()) {
        cout << ((*it).first);
        (*it).second.escribir();

        ++it;   
    }
}