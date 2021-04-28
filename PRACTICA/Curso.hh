/** @file Curso.hh
    @brief Especificación de la clase Curso
*/

#ifndef _CURSO_HH_
#define _CURSO_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
#endif
using namespace std;

/*
 * Clase Curso
 */

/** @class Curso
    @brief Representa un curso que pertenece a la plataforma Evaluator. 
    Está formado por un conjunto de sesiones y estas, a la vez, por un
    conjunto de problemas, con la característica de que en un mismo curso
    no aparece el mismo problema más de una vez.
*/

class Curso {
private:
    vector<string> sesiones_curso; //vector, list o set?
    map<string,string> problemas_sesiones_curso;
    int num_usuarios_completado;
    int num_usuarios_inscritos;
public:
    //Constructora

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un curso.
        \pre Cierto
        \post El resultado es un curso sin sesiones y, por ello, sin problemas.
        Tampoco tiene un número de usuarios que lo haya completado ni usurarios
        inscritos
    */
    Curso();

    //Modificadoras

    /** @brief Incrementa una unidad el número de usuarios que han completado
        el curso.
        \pre El curso con identificador c existe
        \post Se ha incrementado una unidad el número de usuarios que han
        completado el parámetro implícito
    */
    void incrementar_completados();

    /** @brief Incrementa una unidad el número de usuarios inscritos 
        actualmente en el curso.
        \pre El curso con identificador c existe
        \post Se ha incrementado una unidad el número de usuarios inscritos 
        actualmente el parámetro implícito
    */
    void incrementar_inscritos();

    /** @brief Decrementa una unidad el número de usuarios inscritos
        actualmente en el curso.
        \pre El curso con identificador c existe
        \post Se ha decrementado una unidad el número de usuarios inscritos
        actualmente en el parámetro implícito
    */
    void decrementar_inscritos();


    //Consultoras

    /** @brief Consultora del cumplimiento de la restricción de no repetición
        de problemas.
        \pre Cierto
        \post Devuelve <em>true</em> si se cumple la restricción de no 
        repetición de problemas. En caso contrario, devuelve <em>false</em>
    */
    bool repeticion_ejercicios() const;

    /** @brief Consultora de la existencia de un problema dentro de un curso.
        \pre El problema con identificador p existe
        \post Devuelve <em>true</em> si el problema con identificador p
        pertenece al parámetro implícito. En caso contrario, devuelve
        <em>false</em>
    */
    bool existe_problema_curso(string p) const;

    /** @brief Consulta la sesion a la que pertenece un problema dentro de un
        curso
        \pre El problema con identificador p existe
        \post Se imprime el identificador de la sesión a la que pertence 
        el problema con identificador p dentro del párametro implícito
    */
    void sesion_problema(string p) const;

    int numero_usuarios_inscritos() const;

    //Lectura

    /** @brief Operación de lectura.

        \pre Cierto
        \post El parámetro implícito contiene un número de sesiones, cada una
        formada por un número de problemas. También contiene el número de
        usuarios que han completado el curso, tanto actuales como pasados,
        y el número de usuarios inscritos en él
    */
    void leer_curso();

    //Escritura

    /** @brief Operación de escritura.

        \pre Cierto
        \post Se imprimen los siguientes datos del parámetro implícito:
        el número de usuarios actuales o pasados que lo han completado, el
        número de usuarios inscritos actualmente y el número de sesiones que lo
        forman y los identificadores de dichas sesiones, en el mismo orden que
        se leyeron cuando se creó el curso
    */
    void escribir_curso() const;
};
#endif
