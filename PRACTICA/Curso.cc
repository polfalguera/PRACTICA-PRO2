#include "Curso.hh"

Curso::Curso() {
    num_usuarios_completado = 0;
    num_usuarios_inscritos = 0;
}

void Curso::incrementar_completados() {
    ++num_usuarios_completado;
}

void Curso::incrementar_inscritos() {
    ++num_usuarios_inscritos;
}

void Curso::decrementar_inscritos() {
    --num_usuarios_inscritos;
}

bool Curso::repeticion_ejercicios() const {
    return true;
}

bool Curso::existe_problema_curso(const string& p) const {
    map<string,string>::const_iterator it = problemas_sesiones_curso.find(p);
    if (it == problemas_sesiones_curso.end()) return false;

    return true;
}

void Curso::sesion_problema(const string& p) const {
    map<string,string>::const_iterator it = problemas_sesiones_curso.find(p);

    cout << (*it).second << endl;
}

string Curso::sesion_problema_aux(const string& p) const {
    map<string,string>::const_iterator it = problemas_sesiones_curso.find(p);

    return (*it).second;
}

int Curso::numero_usuarios_inscritos() const {
    return num_usuarios_inscritos;
}

bool Curso::leer_curso(const Sesiones& cs) {
    int numero_sesiones_curso;
    cin >> numero_sesiones_curso;

    string s;
    bool interseccion = false;
    for (int i = 0; i < numero_sesiones_curso; ++i) {
        cin >> s;
        sesiones_curso.push_back(s);

        int numero_problemas_sesion = cs.numero_problemas_sesion(s);
        for (int i = 0; i < numero_problemas_sesion; ++i) {
            string p = cs.problema_iessimo_sesion(s,i);
            if (not interseccion) {
                map<string,string>::iterator it = problemas_sesiones_curso.find(p);
                if (not interseccion and it != problemas_sesiones_curso.end()) interseccion = true;
                else problemas_sesiones_curso.insert(make_pair(p,s));
            }
        }
    }
    return interseccion;
}

void Curso::escribir() const {
    cout << num_usuarios_completado << ' ' << num_usuarios_inscritos << ' ';
    int numero_sesiones_curso = sesiones_curso.size();
    cout << numero_sesiones_curso << " (" << sesiones_curso[0];
    for (int i = 1; i < numero_sesiones_curso; ++i) {
        cout << ' ' << sesiones_curso[i];
    }
    cout << ')' << endl;
}

void Curso::modificar_enviables(Problemas& enviables, Problemas& resueltos, Sesiones& cs) {
    int numero_sesiones_curso = sesiones_curso.size();
    
    for (int i = 0; i < numero_sesiones_curso; ++i) {
        cs.modificar_envibales_sesion(sesiones_curso[i],enviables,resueltos);
    }
}

void Curso::modificar_enviables_s(const string& p, const string& s, Problemas& enviables, Problemas& resueltos, Sesiones& cs) {
    cs.modificar_envibales_envio_s(p,s,enviables,resueltos);
}