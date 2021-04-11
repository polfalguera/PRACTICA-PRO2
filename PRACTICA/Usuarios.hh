/** @file Usuarios.hh
    @brief Especificación de la clase Usuarios
*/

#ifndef _USUARIOS_HH_
#define _USUARIOS_HH_

#include "Usuario.hh"

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
    @brief Representa el conjunt d'usuarios registrats a la plataforma EVALUATOR

*/

class Usuarios {
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
      \pre Cierto
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

    //Consultoras

    /** @brief Consultora de un usuario registrado en la plataforma.
        \pre Cierto
        \post Devuelve el usuario perteneciente al parámetro implícito con 
        identificador u
    */
    Usuario consultar_usuario(string u);

    /** @brief Consultora de la existencia de un usuario dentro de la plataforma.
        \pre Cierto
        \post Devuelve <em>true</em> si el usuario con identificador u pertenece 
        al parámetro implícito. En caso contrario, devuelve <em>false</em>
    */
    bool existe_usuario(string u);

    /** @brief Consultora del número total de usuarios que hay registrados en
        la plataforma.
        \pre Cierto
        \post Devuelve el número total de usuarios que contiene el parámetro
        implícito
    */
    int numero_usuarios();

    /** @brief Inscribe a un usuario a un curso de la plataforma.
        \pre Cierto
        \post El usuario con identificador u pasa a estar inscrito al curso con 
        identificador c
    */
    void inscribir_curso(string u, int c);

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
    void listar_usuarios();
};
#endif
