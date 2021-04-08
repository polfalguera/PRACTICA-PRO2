/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/

#ifndef _SESION_HH_
#define _SESION_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include "BinTree.hh"
#endif
using namespace std;

/*
 * Clase Sesion
 */

/** @class Sesion
    @brief Representa una sesión con un conjunto de problemas que pertenece
    a uno o a más de los cursos de EVALUATOR

    Todos los problemas son distintos entre ellos
*/
class Sesion {
public:
    //Constructoras

    Sesion();
    /* Pre: cierto */
    /* Post: el resultado es una sesión vacía */

    // Destructora: borra automaticamente los objetos locales en salir de un
    // ámbito de visibilidad

    ~Sesion();

    //Lectura

    void leer_sesion();
    /* Pre: cierto */
    /* Post: el parámetro implícito contiene un numero de problemas y un
    conjunto de identificadores de dichos problemas */

    //Escritura

    void escribir_sesion() const;
    /* Pre: cierto */
    /* Post: en caso que s sea un identificador válido, se imprime por pantalla
    el número de problemas que forman la sesión y los identificadores de dichos
    problemas. En caso contrario, se imprime un mensaje de error por pantalla
    */
};
#endif
