/** @file Usuarios.hh
    @brief Especificación de la clase Usuarios
*/

#ifndef _USUARIOS_HH_
#define _USUARIOS_HH_

#include "Usuario.hh"
#include "Cursos.hh"
#include "Sesiones.hh"
#include "Problemas.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
#endif
using namespace std;
/*
 * Clase Usuarios
 */

/** @class Usuarios
    @brief Representa el conjunto de usuarios registrados en la plataforma
    Evaluator.
*/

class Usuarios {
private:
    /** @brief Conjunto de usuarios */
    map<string,Usuario> cjt_usuarios;
public:
    //Constructora

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un conjunto de usuarios.
        \pre Cierto
        \post El resultado es un conjunto de usuarios vacío
    */
    Usuarios();

    //Modificadoras

    /** @brief Da de alta a un nuevo usuario en la plataforma.
      \pre El usuario con identificador u no pertenece al parámetro implícito
      \post Se ha añadido un usuario con identificador u al parámetro
      implícito
    */
    void alta_usuario(const string& u);

    /** @brief Da de baja a un usuario registrado de la plataforma.
      \pre El usuario con identificador u pertenece al parámetro implícito
      \post Se ha borrado del parámetro implícito el usuario con identificador
      u
    */
    void baja_usuario(const string& u);

    /** @brief Inscribe a un usuario a un curso de la plataforma.
        \pre El usuario y el curso con identificadores u y c respectivamente
        existen. El usuario u no está inscrito en ningún curso
        \post El usuario con identificador u pasa a estar inscrito al curso con 
        identificador c
    */
    void inscribir_curso (const string& u, int c, Sesiones& cjt_sesiones, Cursos& cjt_cursos);  

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
    void envio(const string& u, const string& p, int r, Sesiones& cjt_sesiones, Cursos& cjt_cursos, const Problemas& cjt_problemas);

    //Consultoras

    /** @brief Consultora de la existencia de un usuario dentro de la plataforma.
        \pre Cierto
        \post Devuelve <em>true</em> si el usuario con identificador u pertenece 
        al parámetro implícito. En caso contrario, devuelve <em>false</em>
    */
    bool existe_usuario(const string& u) const;

    /** @brief Consultora del número total de usuarios que hay registrados en
        la plataforma.
        \pre El parámetro implícito puede estar o no vacío
        \post Devuelve el número total de usuarios que contiene el parámetro
        implícito
    */
    int numero_usuarios() const; 

    /** @brief Consultora del identificador del curso en el cual está inscrito
        un usuario concreto.
        \pre El usuario con identificador u pertenece al parámetro implícito
        \post Si el usuario con identificador u está inscrito en algun curso, 
        devuelve el identificador de éste. En caso contrario, devuelve un 0
    */
    int consultar_curso_usuario(const string& u) const;

    //Lectura

    /** @brief Operación de lectura.
        \pre Cierto
        \post El parámetro implícito contiene uno o más usuarios
    */
    void leer_conjunto_usuarios();

    //Escritura

    /** @brief Imprime por pantalla los problemas resueltos de un usuario
        concreto.
        \pre El usuario con identificador u pertenece al parámetro implícito
        \post Se imprimen en orden creciente por identificador los problemas
        solucionados con éxito por el usuario con identificador u, ya sean del 
        curso en el cual está inscrito actualmente o de cursos anteriores.
        Además, para cada problema, se imprime el número de envíos realizados
        por el usuario a dicho problema
    */
    void problemas_resueltos_usuario(const string& u) const;

    
    /** @brief Imprime por pantalla los problemas enviables de un usuario
        concreto.
        \pre El usuario con identificador u pertenece al parámetro implícito
        \post Se imprimen en orden creciente por identificador los problemas
        que no ha solucionado todavía, pero ya puede realizar un envío, el 
        usuario con ientificador u en el curso en el cual está inscrito
        actualmente. Además, para cada problema, se imprime el número de envíos
        realizados por usuario a dicho problema
    */
   void problemas_enviables_usuario(const string& u) const;

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen los siguientes datos del usuario con identificador u:
        cuántos envíos en total ha realizado, cuántos problemas ha resuelto
        satisfactoriamente, cuántos problemas ha intentado resolver y el
        identificador del curso en el que está inscrito o un cero si no está
        inscrito en ninguno
    */
    void escribir_usuario(const string& u) const;

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen los usuarios registrados actualmente en la 
        plataforma, ordenados crecientemente por su nombre. Para cada uno, se  
        imprime cuántos envíos en total ha realizado, cuántos problemas ha 
        resuelto satisfactoriamente, cuántos problemas ha intentado resolver y 
        el identificador del curso en el que está inscrito o un cero si no está
        inscrito en ninguno
    */
    void listar_usuarios() const;
};
#endif
