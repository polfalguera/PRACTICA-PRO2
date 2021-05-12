#include "Sesiones.hh"

Sesiones::Sesiones() {

}

void Sesiones::nueva_sesion(string s) {
    Sesion sesion;
    sesion.leer_sesion();

    cjt_sesiones.insert(make_pair(s,sesion));

}

void Sesiones::modificar_envibales_sesion(const string& s, Problemas& enviables, Problemas& resueltos) {
    map<string,Sesion>::iterator it = cjt_sesiones.find(s);

    (*it).second.modificar_enviables_s(enviables,resueltos);
}

void Sesiones::modificar_envibales_envio_s(const string& p, const string& s, Problemas& enviables, Problemas& resueltos) {
    map<string,Sesion>::iterator it = cjt_sesiones.find(s);

    bool encontrado = false;
    (*it).second.modificar_enviables_envio(p,encontrado,enviables,resueltos);
}

int Sesiones::numero_problemas_sesion(const string& s) const {
    map<string,Sesion>::const_iterator it = cjt_sesiones.find(s);

    return (*it).second.consultar_numero_problemas();
}

string Sesiones::problema_iessimo_sesion(const string& s, int i) const {
    map<string,Sesion>::const_iterator it = cjt_sesiones.find(s);

    return (*it).second.consultar_problema_iesimo(i);
}

bool Sesiones::existe_sesion(const string& s) const {
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

void Sesiones::escribir_sesion(const string& s) const {
    map<string,Sesion>::const_iterator it = cjt_sesiones.find(s);

    (*it).second.escribir();
}

void Sesiones::listar_sesiones() const {
    map<string,Sesion>::const_iterator it = cjt_sesiones.begin();

    while (it != cjt_sesiones.end()) {
        cout << ((*it).first) << ' ';
        (*it).second.escribir();

        ++it;   
    }
}