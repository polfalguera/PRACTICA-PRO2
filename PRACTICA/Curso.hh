/** @file Curso.hh
    @brief Especificación de la clase Curso
*/

#ifndef _CURSO_HH_
#define _CURSO_HH_

#include "Sesiones.hh"
#include "Problemas.hh"

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
    conjunto de problemas, con la característica de que, en un mismo curso,
    no aparece el mismo problema más de una vez.
*/

class Curso {
private:
    /** @brief Identificadores de las sesiones del curso */
    vector<string> sesiones_curso;
    /** @brief Identificadores de los problemas del curso y, para cada uno,
        la sesión a la que pertenecen
    */ 
    map<string,string> problemas_sesiones_curso;
    /** @brief Número de usuarios, tanto actuales como anteriores, que han
        completado el curso
    */ 
    int num_usuarios_completado;
    /** @brief Número de usuarios inscritos actualmente en el curso*/ 
    int num_usuarios_inscritos;
public:
    //Constructora

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un curso.
        \pre Cierto
        \post El resultado es un curso sin sesiones y, por ello, sin problemas.
        Tampoco tiene un número de usuarios que lo haya completado ni usuarios
        inscritos
    */
    Curso();

    //Modificadoras

    /** @brief Incrementa una unidad el número de usuarios que han completado
        un curso.
        \pre Cierto
        \post Se ha incrementado una unidad el número de usuarios que han
        completado el parámetro implícito
    */
    void incrementar_completados();

    /** @brief Incrementa una unidad el número de usuarios inscritos 
        actualmente en el curso.
        \pre Cierto
        \post Se ha incrementado una unidad el número de usuarios inscritos 
        actualmente en el parámetro implícito
    */
    void incrementar_inscritos();

    /** @brief Decrementa una unidad el número de usuarios inscritos
        actualmente en el curso.
        \pre Cierto
        \post Se ha decrementado una unidad el número de usuarios inscritos
        actualmente en el parámetro implícito
    */
    void decrementar_inscritos();

    /** @brief Actualiza los problemas enviables de un usuario tras ser
        inscrito a un curso.
        \pre Cierto
        \post Se han actualizado los problemas enviables de un usuario tras
        ser inscrito al parámetro implícito
    */
    void modificar_enviables(Problemas& enviables, Problemas& resueltos, Sesiones& cs) const;

    /** @brief Actualiza los problemas enviables de un usuario tras haber
        realizado un envío con éxito de un problema perteneciente a un curso.
        \pre El problema con identificador p y la sesión con identificador s 
        pertenecen al parámetro implícito
        \post Se han actualizado los problemas enviables de un usuario tras
        haber realizado un envío con éxito del problema con identificador p
    */
    void modificar_enviables_s(const string& p, const string& s, Problemas& enviables, Problemas& resueltos, Sesiones& cs) const;

    //Consultoras

    /** @brief Consultora de la existencia de un problema dentro de un curso.
        \pre El problema con identificador p existe
        \post Devuelve <em>true</em> si el problema con identificador p
        pertenece al parámetro implícito. En caso contrario, devuelve
        <em>false</em>
    */
    bool existe_problema_curso_c(const string& p) const;

    /** @brief Consultora de la sesión a la que pertenece un problema dentro de
        un curso.
        \pre El problema con identificador p pertenece al parámetro implícito
        \post Se imprime el identificador de la sesión a la que pertence 
        el problema con identificador p dentro del párametro implícito
    */
    void sesion_problema(const string& p) const;

    /** @brief Consultora del identificador de la sesión a la que pertenece un
        problema dentro de un curso.
        \pre El problema con identificador p pertenece al parámetro implícito
        \post Devuelve el identificador de la sesión a la que pertenece el
        problema con identificador p dentro del parámetro implícito
    */
    string sesion_problema_p(const string& p) const;

    /** @brief Consultora del número de usuarios inscritos en un curso.
        \pre Cierto
        \post Devuelve el número de usuarios inscritos al parámetro implícito
    */
    int numero_usuarios_inscritos() const;

    //Lectura

    /** @brief Operación de lectura.
        \pre Cierto
        \post Si no hay intersección de problemas, devuelve <em>false</em>. En
        caso contrario, devuelve <em>true</em>. El parámetro implícito pasa 
        a tener los identificadores de las sesiones que lo forman y, para cada 
        sesión, los identificadores de los problemas que las forman
    */
    bool leer_curso(const Sesiones& cs);

    //Escritura

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen por pantalla los siguientes datos del parámetro
        implícito:
        el número de usuarios actuales o pasados que lo han completado, el
        número de usuarios inscritos actualmente y el número de sesiones que lo
        forman y los identificadores de dichas sesiones, en el mismo orden que
        se leyeron cuando se creó el curso
    */
    void escribir() const;
};
#endif
