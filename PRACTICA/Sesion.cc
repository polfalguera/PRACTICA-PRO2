#include "Sesion.hh"

Sesion::Sesion() {
    numero_problemas = 0;
}

int Sesion::consultar_numero_problemas() const {
    return numero_problemas;
}

string Sesion::consultar_problema_iesimo(int i) const {
    return id_problemas[i];
}

void Sesion::leer_problemas_sesion(BinTree<string>& problemas) {
    string p;
    cin >> p;
    if(p != "0"){
        id_problemas.push_back(p);
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

void Sesion::modificar_enviables_sesion(Problemas& enviables, Problemas& resueltos) {
    i_modificar_enviables_sesion(problemas_sesion,enviables,resueltos);
}

void Sesion::i_modificar_enviables_sesion(const BinTree<string>& problemas_sesion, Problemas& enviables, Problemas& resueltos) {
    if (resueltos.existe_problema(problemas_sesion.value())) {
        BinTree<string> e, d;
        e = problemas_sesion.left();
        i_modificar_enviables_sesion(e,enviables,resueltos);
        d = problemas_sesion.right();
        i_modificar_enviables_sesion(d,enviables,resueltos);
    }
    else {
        enviables.nuevo_problema(problemas_sesion.value());
    }
}

