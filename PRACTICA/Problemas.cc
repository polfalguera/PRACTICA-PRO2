#include "Problemas.hh"

Problemas::Problemas() {

}

void Problemas::nuevo_problema(const string& p) {
    Problema problema;
    problema.num_total_envios = 0;
    problema.num_total_correctos = 0;
    problema.ratio = 1;
    cjt_problemas.insert(make_pair(p,problema));
}

void Problemas::envio(const string& p, int r) {
    map<string,Problema>::iterator it = cjt_problemas.find(p);
    (*it).second.num_total_envios += 1;
    if (r == 1) (*it).second.num_total_correctos += 1;
    actualizar_ratio((*it).second);
}

void Problemas::actualizar_ratio(Problema& p) {

    p.ratio = (double)(p.num_total_envios+1) / (double)(p.num_total_correctos+1);

}

void Problemas::incrementar_intentos_usuario(const string& p) {
    map<string,Problema>::iterator it = cjt_problemas.find(p);

    (*it).second.num_total_envios += 1;
}

void Problemas::eliminar_enviable(const string& p) {
    map<string,Problema>::iterator it = cjt_problemas.find(p);
    cjt_problemas.erase((*it).first);
}

void Problemas::anadir_resuelto(const string& p, const Problema& problema) {
    cjt_problemas.insert(make_pair(p,problema));
}

bool Problemas::existe_problema(const string& p) const {
    map<string,Problema>::const_iterator it = cjt_problemas.find(p);
    if (it == cjt_problemas.end()) return false;
    
    return true;
}

int Problemas::numero_problemas() const {
    return cjt_problemas.size();
}

int Problemas::numero_total_envios_p(const string& p) const {
    map<string,Problema>::const_iterator it = cjt_problemas.find(p);

    return (*it).second.num_total_envios;
}

void Problemas::consultar_problema(const string& p, Problema& problema) {
    map<string,Problema>::const_iterator it = cjt_problemas.find(p);

    problema = (*it).second;
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

void Problemas::escribir_problema(const string& p) const {
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