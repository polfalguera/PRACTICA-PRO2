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

bool Curso::existe_problema_curso(string p) const {
    map<string,string>::const_iterator it = problemas_sesiones_curso.find(p);
    if (it == problemas_sesiones_curso.end()) return false;

    return true;
}

void Curso::sesion_problema(string p) const {
    
}

int Curso::numero_usuarios_inscritos() const {
    return num_usuarios_inscritos;
}

void Curso::leer_curso() {
    int numero_sesiones_curso;
    cin >> numero_sesiones_curso;

    string s;
    for (int i = 0; i < numero_sesiones_curso; ++i) {
        cin >> s;
        sesiones_curso.push_back(s);
    }
}

void Curso::escribir_curso() const {
    cout << num_usuarios_completado << ' ' << num_usuarios_inscritos << ' ';
    int numero_sesiones_curso = sesiones_curso.size();
    cout << numero_sesiones_curso << " (" << sesiones_curso[0];
    for (int i = 1; i < numero_sesiones_curso; ++i) {
        cout << ' ' << sesiones_curso[i];
    }
    cout << ')' << endl;
}