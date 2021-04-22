#include "Problemas.hh"

Problemas::Problemas() {

}

void Problemas::nuevo_problema(string p) {
    Problema problema;
    problema.first = 0;
    problema.second = 0;

    cjt_problemas.insert(make_pair(p,problema));
}

void Problemas::envio(string p, int r) {
    
}

bool Problemas::existe_problema(string p) const {
    map<string,Problema>::const_iterator it = cjt_problemas.find(p);
    if (it == cjt_problemas.end()) return false;
    
    return true;
}

int Problemas::numero_problemas() const {
    return cjt_problemas.size();
}

void Problemas::leer_coleccion_problemas() {
    int num_problemas;
    cin >> num_problemas;
    
    string p;
    for (int i = 0; i < num_problemas; ++i) {
        cin >> p;
        nuevo_problema(p);
    }
}

void Problemas::escribir_problema(string p) const {
    map<string,Problema>::const_iterator it = cjt_problemas.find(p);
    
    double t = (*it).second.first;
    double e = (*it).second.second;
    double ratio = (t+1)/(e+1);
    cout << p << ' ' << (*it).second.first << ' ' << (*it).second.second << ' ' << ratio << endl;
}

void Problemas::listar_problemas() const {

}