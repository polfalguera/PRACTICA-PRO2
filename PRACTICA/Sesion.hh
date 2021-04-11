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

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen el número de problemas que forman parte del 
        parámetro implícito
    */
    void escribir_sesion() const;
};
#endif
