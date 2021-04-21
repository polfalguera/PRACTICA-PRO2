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
    @brief Representa una sesión de la plataforma Evaluator. Está formada
    por un conjunto de problemas, todos distintos entre ellos.
*/

class Sesion {
public:
    //Constructora

    /** @brief Constructora por defecto.
        \pre Cierto
        \post El resultado es una sesión vacía
    */
    Sesion();

    //Consultora

    /** @brief Consultora del número de problemas que contiene una sesión.
        \pre Cierto
        \post Devuelve el número de problemas que pertenecen al parámetro
        implícito
    */
    int consultar_numero_problemas() const;
    
    //Lectura

    /** @brief Operación de lectura.
       \pre Cierto
       \post El parámetro implícito contiene un número de problemas y un 
       conjunto de identificadores de dichos problemas
    */
    void leer_sesion();

    //Escritura

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen el número de problemas que forman parte del 
        parámetro implícito y sus identificadores
    */
    void escribir_sesion() const;
};
#endif
