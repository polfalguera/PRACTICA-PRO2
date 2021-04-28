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

    /** @brief Registra a un nuevo usuario en la plataforma.
      \pre El usuario con identificador u existe
      \post Se ha añadido un usuario con identificador u al parámetro
      implícito
    */
    void alta_usuario(string u);

    /** @brief Da de baja a un usuario registrado de la plataforma.
      \pre Cierto
      \post Se ha borrado del parámetro implícito el usuario con identificador
      u
    */
    void baja_usuario(string u);

    /** @brief Inscribe a un usuario a un curso de la plataforma.
        \pre El usuario y el curso con identificadores u y c respectivamente
        existen. El usuario u no está inscrito en ningún curso
        \post El usuario con identificador u pasa a estar inscrito al curso con 
        identificador c
    */
    void inscribir_curso (string u, int c, const Sesiones& cjt_sesiones, const Cursos& cjt_cursos);  

    //Consultoras

    /** @brief Consultora de un usuario registrado en la plataforma.
        \pre Cierto
        \post Devuelve el usuario perteneciente al parámetro implícito con 
        identificador u
    */
    Usuario consultar_usuario(string u) const;

    /** @brief Consultora de la existencia de un usuario dentro de la plataforma.
        \pre Cierto
        \post Devuelve <em>true</em> si el usuario con identificador u pertenece 
        al parámetro implícito. En caso contrario, devuelve <em>false</em>
    */
    bool existe_usuario(string u) const;

    /** @brief Consultora del número total de usuarios que hay registrados en
        la plataforma.
        \pre El parámetro implícito puede estar o no vacío
        \post Devuelve el número total de usuarios que contiene el parámetro
        implícito
    */
    int numero_usuarios() const; 

    //Lectura

    /** @brief Operación de lectura.
        \pre Cierto
        \post El parámetro implícito contiene uno o más usuarios
    */
    void leer_conjunto_usuarios();

    //Escritura

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
