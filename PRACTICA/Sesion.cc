#include "Sesion.hh"

Sesion::Sesion() {
    numero_problemas = 0;
}

int Sesion::consultar_numero_problemas() const {
    return numero_problemas;
}

void Sesion::leer_problemas_sesion(BinTree<string>& problemas) {
    string p;
    cin >> p;
    if(p != "0"){
        ++numero_problemas;
        BinTree<string> e,d;
        leer_problemas_sesion(e);
        leer_problemas_sesion(d);
        problemas = BinTree<string>(p,e,d);
    }
}

void Sesion::leer_sesion() {
    
    leer_problemas_sesion(problemas_sesion);

}

void Sesion::escribir_problemas_sesion(const BinTree<string>& problemas) const {
    if (not problemas.empty()){
        cout << "(";
        escribir_problemas_sesion(problemas.left());
        escribir_problemas_sesion(problemas.right());
        cout << problemas.value();
        cout << ")";
    }
}

void Sesion::escribir_sesion() const {
    cout << numero_problemas << ' ';
    escribir_problemas_sesion(problemas_sesion);
    cout << endl;

}