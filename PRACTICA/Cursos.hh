/** @file Cursos.hh
    @brief Especificación de la clase Cursos
*/

#ifndef _CURSOS_HH_
#define _CURSOS_HH_

#include "Curso.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif
using namespace std;

/*
 * Clase Cursos
 */

/** @class Cursos
    @brief Representa el conjunto de cursos de la plataforma Evaluator.
*/

class Cursos {
private:
    /** @brief Conjunto de cursos */
    vector<Curso> cjt_cursos;
public:
    //Constructora

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un conjunto de cursos.
        \pre Cierto
        \post El resultado es un conjunto de cursos vacío
    */
    Cursos();

    //Modificadoras

    /** @brief Añade un nuevo curso al conjunto de cursos siempre y cuando no 
        haya intersección de problemas entre las sesiones.
        \pre Cierto
        \post Si no hay intersección de problemas entre sesiones, añade un 
        nuevo curso al parámetro implícito y devuelve <em>true</em>. En caso
        contrario, devuelve <em>false</em> y no añade el curso
    */
    bool nuevo_curso(const Sesiones& cjt_sesiones);

    /** @brief Incrementa una unidad el número de usuarios que han completado
        un curso concreto.
        \pre El curso con identificador c pertenece al parámetro implícito
        \post Se ha incrementado una unidad el número de usuarios que han
        completado el curso con identificador c
    */
    void incrementar_usuarios_completado(int c);

    /** @brief Incrementa una unidad el número de usuarios que han completado
        un curso concreto.
        \pre El curso con identificador c pertenece al parámetro implícito
        \post Se ha incrementado una unidad el número de usuarios que han 
        completado el curso con identificador c
    */
    void incrementar_usuarios_inscritos(int c);

    /** @brief Decrementa una unidad el número de usuarios inscritos
        actualmente en un curso concreto.
        \pre El curso con identificador c pertenece al parámetro implícito
        \post Se ha decrementado una unidad el número de usuarios inscritos
        actualmente en el curso con identificador c
    */
    void decrementar_usuarios_inscritos(int c);

    /** @brief Actualiza los problemas enviables de un usuario tras haber
        realizado un envío con éxito de un problema perteneciente a un curso
        concreto.
        \pre El problema con identificador p y la sesión con identificador s 
        pertenecen al curso con identificador c, que a la vez pertenece al
        parámetro implícito
        \post Se han actualizado los problemas enviables de un usuario tras
        haber realizado un envío con éxito del problema con identificador p
    */
    void modificar_enviables_s_c(int c, const string& p, const string& s, Problemas& enviables, Problemas& resueltos, Sesiones& cs) const;

    //Consultoras

    /** @brief Consultora de un curso de la plataforma.
        \pre El curso con identificador c pertenece al parámetro implícito
        \post CURSO pasa a ser el curso con identificador c
    */
    void consultar_curso(int c, Curso& curso);

    /** @brief Consultora de la existencia de un curso dentro del conjunto
        de cursos.
        \pre Cierto
        \post Devuelve <em>true</em> si el curso pertenece al parámetro
        implícito. En caso contrario, devuelve <em>false</em>
    */
    bool existe_curso(int c) const;

    /** @brief Consultora del número total de cursos que hay en la
        plataforma.
        \pre El parámetro implícito no está vacío
        \post Devuelve el número total de cursos que contiene el 
        parámetro implícito
    */
    int numero_cursos() const;

    /** @brief Consultora del número de usuarios inscritos en un curso
        concreto.
        \pre El curso con identificador c pertenece al parámetro implícito
        \post Devuelve el número de usuarios inscritos actualmente en el curso
        con identificador c
    */
    int numero_inscritos_curso(int c) const;

    /** @brief Consultora de la existencia de un problema dentro de un curso
        concreto.
        \pre El curso con identificador c pertenece al parámetro implícito y
        el problema con identificador p existe
        \post Devuelve <em>true</em> si el problema con identificador p 
        pertenece al curso con identificador c. En caso contrario, devuelve
        <em>false</em>
    */
    bool existe_problema_curso(int c, const string& p) const;

    /** @brief Consultora de la sesión a la que pertenece un problema dentro de
        un curso concreto.
        \pre El curso con identificador c pertenece al parámetro implícito y
        el problema con identificador p pertence al curso c
        \post Se imprime el identificador de la sesión a la que pertence 
        el problema con identificador p dentro del curso con identificador c
    */
    void sesion_problema_curso(int c, const string& p) const;

    /** @brief Consultora del identificador de la sesión a la que pertenece un
        problema dentro de un curso concreto.
        \pre El curso con identificador c pertenece al parámetro implícito y
        el problema con identificador p pertence al curso c
        \post Devuelve el identificador de la sesión a la que pertenece el
        problema con identificador p dentro del curso con identificador c
    */
    string sesion_problema_p_curso(int c, const string& p) const;

    //Lectura

    /** @brief Operación de lectura.
        \pre Cierto
        \post El parámetro implícito contiene uno o más cursos
    */
    void leer_conjunto_cursos(const Sesiones& cs);

    //Escritura

    /** @brief Operación de escritura.
       \pre El curso con identificador c pertenece al parámetro implícito
       \post Se imprimen por pantalla los siguientes datos del curso con
       identificador c: el número de usuarios actuales o pasados que lo han
       completado, el número de usuarios inscritos actualmente y el número
       de sesiones que lo forman y los identificadores de dichas sesiones,
       en el mismo orden que se leyeron cuando se creó el curso

    */
    void escribir_curso(int c) const;

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen por pantalla los cursos del conjunto de forma
        creciente por su identificador. Para cada uno, se muestra el número
        de usuarios actuales o pasados que lo han completado, el número de
        usuarios inscritos actualmente y el número de sesiones que lo forman
        y los identificadores de dichas sesiones, en el mismo orden que se
        leyeron cuando se creó el curso
    */
    void listar_cursos() const;
};
#endif
