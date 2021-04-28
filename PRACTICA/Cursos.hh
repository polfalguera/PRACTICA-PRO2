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
        contrario, devuelve <em>false</em>
    */
    bool nuevo_curso(const Sesiones& cjt_sesiones);

    /** @brief Toma nota del resultado de un envío hecho por un usuario a un 
        problema, actualizando a la vez todo lo que conlleva el envío en si y 
        que éste resulte exitoso o no.
        \pre Cierto
        \post Sea un envío exitoso o no, se actualizan las estadísticas del 
        usuario con identificador u y del problema con identificador p. Además,
        se actualizan los problemas resueltos y enviables del usuario y se 
        comprueba que con este envío el usuario haya completado o no el curso
        en el que estaba inscrito
    */
    //void envio(string u, string p, int r, const Sesiones& cjt_sesiones, const Usuarios& cjt_usuarios);

    /** @brief Incrementa una unidad el número de usuarios que han completado
        el curso.
        \pre El curso con identificador c existe
        \post Se ha incrementado una unidad el número de usuarios que han
        completado el parámetro implícito
    */
    void incrementar_usuarios_completado(int c);

    /** @brief Incrementa una unidad el número de usuarios que han completado
        el curso
        \pre El curso con identificador c existe
        \post Se ha incrementado una unidad el número de usuarios que han 
        completado el parámetro implícito
    */
    void incrementar_usuarios_inscritos(int c);

    /** @brief Decrementa una unidad el número de usuarios inscritos
        actualmente en el curso.
        \pre El curso con identificador c existe
        \post Se ha decrementado una unidad el número de usuarios inscritos
        actualmente en el parámetro implícito
    */
    void decrementar_usuarios_inscritos(int c);

    //Consultoras

    /** @brief Consultora de un curso de la plataforma.
        \pre El curso con identificador c existe
        \post Devuelve el curso perteneciente al parámetro implícito con 
        identificador c
    */
    Curso consultar_curso(int c) const;

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

    //Lectura

    /** @brief Operación de lectura.
        \pre Cierto
        \post El parámetro implícito contiene uno o más cursos
    */
    void leer_conjunto_cursos(const Sesiones& cs);

    //Escritura

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
