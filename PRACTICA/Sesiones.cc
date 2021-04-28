#include "Sesiones.hh"

Sesiones::Sesiones() {

}

void Sesiones::nueva_sesion(string s) {
    Sesion sesion;
    sesion.leer_sesion();

    cjt_sesiones.insert(make_pair(s,sesion));

}

Sesion Sesiones::consultar_sesion(string s) const {
    map<string,Sesion>::const_iterator it = cjt_sesiones.find(s);
    return (*it).second;
}

bool Sesiones::existe_sesion(string s) const {
    map<string,Sesion>::const_iterator it = cjt_sesiones.find(s);
    if (it == cjt_sesiones.end()) return false;

    return true;
}

int Sesiones::numero_sesiones() const {
    return cjt_sesiones.size();
}

void Sesiones::leer_conjunto_sesiones() {
    int numero_sesiones;
    cin >> numero_sesiones;

    string s;
    for (int i = 0; i < numero_sesiones; ++i) {
        cin >> s;
        nueva_sesion(s);
    }

}

void Sesiones::listar_sesiones() const {
    map<string,Sesion>::const_iterator it = cjt_sesiones.begin();

    while (it != cjt_sesiones.end()) {
        cout << ((*it).first) << ' ';
        (*it).second.escribir_sesion();

        ++it;   
    }
}