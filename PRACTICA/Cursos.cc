/** @file Cursos.cc
    @brief Código de la clase Cursos
*/

#include "Cursos.hh"

Cursos::Cursos() 
{

}

bool Cursos::nuevo_curso(const Sesiones& cjt_sesiones) 
{
     Curso c;
     if (not c.leer_curso(cjt_sesiones)) {
         cjt_cursos.push_back(c);
         return true;
     }

     return false;
}

void Cursos::incrementar_usuarios_completado(int c) 
{
    cjt_cursos[c-1].incrementar_completados();
}

void Cursos::incrementar_usuarios_inscritos(int c) 
{
    cjt_cursos[c-1].incrementar_inscritos();
}

void Cursos::decrementar_usuarios_inscritos(int c) 
{
    cjt_cursos[c-1].decrementar_inscritos();
}

void Cursos::consultar_curso(int c, Curso& curso) 
{
    curso = cjt_cursos[c-1];
}

void Cursos::modificar_enviables_s_c(int c, const string& p, const string& s, Problemas& enviables, Problemas& resueltos, Sesiones& cs) const 
{
    cjt_cursos[c-1].modificar_enviables_s(p,s,enviables,resueltos,cs);
}

bool Cursos::existe_curso(int c) const 
{
    int numero_cursos = cjt_cursos.size();
    int i = 0;
    while (i != numero_cursos) {
        if ((i+1) == c) return true;
        ++i;
    }

    return false;
}

int Cursos::numero_cursos() const 
{
    return cjt_cursos.size();
}

int Cursos::numero_inscritos_curso(int c) const 
{
    return cjt_cursos[c-1].numero_usuarios_inscritos();
}

bool Cursos::existe_problema_curso(int c, const string& p) const 
{
    return cjt_cursos[c-1].existe_problema_curso_c(p);
}

void Cursos::sesion_problema_curso(int c, const string& p) const 
{
    return cjt_cursos[c-1].sesion_problema(p);
}

string Cursos::sesion_problema_p_curso(int c, const string& p) const 
{
    return cjt_cursos[c-1].sesion_problema_p(p);
}

void Cursos::leer_conjunto_cursos(const Sesiones& cs) 
{
    int numero_cursos;
    cin >> numero_cursos;

    for (int i = 0; i < numero_cursos; ++i) {
        Curso c;
        c.leer_curso(cs);
        cjt_cursos.push_back(c);
    }
}

void Cursos::escribir_curso(int c) const 
{
    cjt_cursos[c-1].escribir();
}

void Cursos::listar_cursos() const 
{
    int numero_cursos = cjt_cursos.size();
    for (int i = 0; i < numero_cursos; ++i) {
        cout << i+1 << ' ';
        cjt_cursos[i].escribir();
    }
}