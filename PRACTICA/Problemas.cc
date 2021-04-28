#include "Problemas.hh"

Problemas::Problemas() {

}

void Problemas::nuevo_problema(string p) {
    Problema problema;
    problema.num_total_envios = 0;
    problema.num_total_correctos = 0;
    problema.ratio = 1;
    cjt_problemas.insert(make_pair(p,problema));
}

void Problemas::envio(string p, int r) {
    
}

void Problemas::actualizar_ratio(string p) {
    map<string,Problema>::iterator it = cjt_problemas.find(p);

    (*it).second.ratio = ((*it).second.num_total_envios+1) / ((*it).second.num_total_correctos+1);

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
    
    cout << p << '(' << (*it).second.num_total_envios << ',';
    cout << (*it).second.num_total_correctos << ',' << (*it).second.ratio;
    cout << ')' << endl;
}

void Problemas::listar_problemas() const {
    vector<pair<string,double>> ordenacion_problemas;
    map<string,Problema>::const_iterator it = cjt_problemas.begin();

    while (it != cjt_problemas.end()) {
        pair<string,double> p;
        p.first = (*it).first;
        p.second = (*it).second.ratio;
        ordenacion_problemas.push_back(p);
        ++it;
    }

    sort (ordenacion_problemas.begin(),ordenacion_problemas.end(),comp);

    int numero_problemas = cjt_problemas.size();

    for (int i = 0; i < numero_problemas; ++i) {
        escribir_problema(ordenacion_problemas[i].first);
    }
}

void Problemas::listar_identificador_envios() const {
    map<string,Problema>::const_iterator it = cjt_problemas.begin();

    while (it != cjt_problemas.end()) {
        cout << (*it).first << '(' << (*it).second.num_total_envios << ')' << endl;
        ++it;
    }
}

bool Problemas::comp(const pair<string,double>& a, const pair<string,double>& b) {
    if (a.second == b.second) return a.first < b.first;

    return a.second < b.second;
}