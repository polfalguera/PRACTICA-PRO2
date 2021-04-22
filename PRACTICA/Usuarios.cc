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

void Usuarios::inscribir_curso(string u, int c) {

}

Usuario Usuarios::consultar_usuario(string u) const {
    Usuario us;
    return us;
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
        cout << ((*it).first) << ' ';
        (*it).second.escribir_usuario();
        
        ++it;
    }
}