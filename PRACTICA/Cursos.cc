#include "Cursos.hh"

Cursos::Cursos() {

}

bool Cursos::nuevo_curso(const Sesiones& cjt_sesiones) {
    return true;
}

/*void Cursos::envio(string u, string p, int r, const Sesiones& cjt_sesiones, const Usuarios& cjt_usuarios) {

}*/

void Cursos::incrementar_usuarios_completado(int c) {
    cjt_cursos[c-1].incrementar_completados();
}

void Cursos::incrementar_usuarios_inscritos(int c) {
    cjt_cursos[c-1].incrementar_inscritos();
}

void Cursos::decrementar_usuarios_inscritos(int c) {
    cjt_cursos[c-1].decrementar_inscritos();
}

Curso Cursos::consultar_curso(int c) const {
    return cjt_cursos[c-1];
}

bool Cursos::existe_curso(int c) const {
    int numero_cursos = cjt_cursos.size();
    int i = 0;
    while (i != numero_cursos) {
        if ((i+1) == c) return true;
        ++i;
    }

    return false;
}

int Cursos::numero_cursos() const {
    return cjt_cursos.size();
}

void Cursos::leer_conjunto_cursos(const Sesiones& cs) {
    int numero_cursos;
    cin >> numero_cursos;

    for (int i = 0; i < numero_cursos; ++i) {
        Curso c;
        c.leer_curso(cs);
        cjt_cursos.push_back(c);
    }
}

void Cursos::listar_cursos() const {
    int numero_cursos = cjt_cursos.size();
    for (int i = 0; i < numero_cursos; ++i) {
        cout << i+1 << ' ';
        cjt_cursos[i].escribir_curso();
    }
}