/** @file Usuario.cc
    @brief Código de la clase Usuario
*/

#include "Usuario.hh"

Usuario::Usuario() 
{
    id_curso_inscrito = 0;
    numero_problemas_intentados = 0;
    numero_total_envios = 0;
}

void Usuario::inscribir_usuario_curso(int c, Curso& curso, Sesiones& cs) 
{
    id_curso_inscrito = c;
    curso.modificar_enviables(enviables,resueltos,cs);
}

void Usuario::desinscribir_usuario_curso() 
{
    id_curso_inscrito = 0;
}
void Usuario::incrementar_problemas_intentados() 
{
    ++numero_problemas_intentados;
}

void Usuario::incrementar_intentos_p(const string& p) 
{
    enviables.incrementar_intentos_usuario(p);
}

void Usuario::incrementar_total_envios() 
{
    ++numero_total_envios;
}

void Usuario::actualizar_enviables(const string& p, const string& s, const Problema& problema, Cursos& cc, Sesiones& cs ) 
{
    enviables.eliminar_enviable(p);
    cc.modificar_enviables_s_c(id_curso_inscrito,p,s,enviables,resueltos,cs);    
}

void Usuario::actualizar_resueltos(const string &p, const Problema& problema) 
{
    resueltos.anadir_resuelto(p,problema);
}

int Usuario::curso_usuario() const 
{
    return id_curso_inscrito;   
}

int Usuario::consultar_intentos_p(const string& p) const 
{
    return enviables.numero_total_envios_p(p);
}

int Usuario::numero_problemas_enviables() const 
{
    return enviables.numero_problemas();
}

void Usuario::problemas_resueltos() const 
{
    resueltos.listar_identificador_envios();
}

void Usuario::problemas_enviables() const 
{
    enviables.listar_identificador_envios();
}

void Usuario::consultar_problema_enviable(const string& p, Problema& problema) 
{
    enviables.consultar_problema(p,problema);
}

void Usuario::escribir() const 
{
    cout << '(' << numero_total_envios << ',' << resueltos.numero_problemas() << ',' <<
    numero_problemas_intentados << ',' << id_curso_inscrito << ')' << endl;
}
