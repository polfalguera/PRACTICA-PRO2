#include "Sesion.hh"

Sesion::Sesion() {
    numero_problemas = 0;
}

int Sesion::consultar_numero_problemas() const {
    return 0;
}

void leer_problemas_sesion(BinTree<string>& problemas) {
    string p;
    cin >> p;
    if(p != "0"){
        BinTree<string> e,d;
        leer_problemas_sesion(e);
        leer_problemas_sesion(d);
        problemas = BinTree<string>(p,e,d);
    }
}

void Sesion::leer_sesion() {
    
    //leer_problemas_sesion(problemas_sesion);

}

void Sesion::escribir_sesion() const {

}