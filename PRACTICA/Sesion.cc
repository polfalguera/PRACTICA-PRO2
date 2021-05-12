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

void Sesion::leer_problemas_sesion(BinTree<int>& problemas) {
    string p;
    cin >> p;
    if(p != "0"){
        int posicio = id_problemas.size();
        id_problemas.push_back(p);
        ++numero_problemas;
        BinTree<int> e,d;
        leer_problemas_sesion(e);
        leer_problemas_sesion(d);
        problemas = BinTree<int>(posicio,e,d);
    }
}

void Sesion::leer_sesion() {
    
    leer_problemas_sesion(problemas_sesion);

}

void Sesion::escribir_problemas_sesion(const BinTree<int>& problemas) const {
    if (not problemas.empty()){
        cout << "(";
        escribir_problemas_sesion(problemas.left());
        escribir_problemas_sesion(problemas.right());
        cout << id_problemas[problemas.value()];
        cout << ")";
    }
}

void Sesion::escribir() const {
    cout << numero_problemas << ' ';
    escribir_problemas_sesion(problemas_sesion);
    cout << endl;

}

void Sesion::modificar_enviables_s(Problemas& enviables, Problemas& resueltos) {
    i_modificar_enviables_s(problemas_sesion,enviables,resueltos);
}

void Sesion::i_modificar_enviables_s(const BinTree<int>& problemas_sesion, Problemas& enviables, Problemas& resueltos) {
    if (not problemas_sesion.empty()) {
        if (resueltos.existe_problema(id_problemas[problemas_sesion.value()])) {
            i_modificar_enviables_s(problemas_sesion.left(),enviables,resueltos);
            i_modificar_enviables_s(problemas_sesion.right(),enviables,resueltos);
        }
        else {
            enviables.nuevo_problema(id_problemas[problemas_sesion.value()]);
        }
    }
}

void Sesion::modificar_enviables_envio(const string& p, bool& encontrado, Problemas& enviables, Problemas& resueltos) {
    i_modificar_enviables_envio(problemas_sesion,p,encontrado,enviables,resueltos);
}

void Sesion::i_modificar_enviables_envio(const BinTree<int>& problemas_sesion, const string& p, bool& encontrado, Problemas& enviables, Problemas& resueltos) {
    if (not problemas_sesion.empty()) {
        if (id_problemas[problemas_sesion.value()] == p ) {
            i_modificar_enviables_s(problemas_sesion,enviables,resueltos);
            encontrado = false;
        }
        else {
            i_modificar_enviables_envio(problemas_sesion.left(),p,encontrado,enviables,resueltos);
            if (not encontrado) i_modificar_enviables_envio(problemas_sesion.right(),p,encontrado,enviables,resueltos);
        }
    }
}



