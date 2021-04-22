#include "Sesiones.hh"

Sesiones::Sesiones() {

}

void Sesiones::nueva_sesion(string s) {
    Sesion sesion;
    sesion.leer_sesion();

    cjt_sesiones.insert(make_pair(s,sesion));

}

Sesion Sesiones::consultar_sesion(string s) const {
    Sesion ses;
    return ses;
}

bool Sesiones::existe_sesion(string s) const {
    return true;
}

int Sesiones::numero_sesiones() const {
    return 0;
}

void Sesiones::leer_conjunto_sesiones() {

}

void Sesiones::listar_sesiones() const {

}