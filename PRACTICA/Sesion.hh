/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/

#ifndef _SESION_HH_
#define _SESION_HH_

#include "Problemas.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
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
private:
    BinTree<string> problemas_sesion;
    vector<string> id_problemas;
    int numero_problemas;
public:
    //Constructora

    /** @brief Constructora por defecto.
        \pre Cierto
        \post El resultado es una sesión vacía
    */
    Sesion();

    //Modificadora

    /** @brief Lee el conjunto de problemas de una sesion
        \pre Cierto
        \post El parámetro implícito contiene un conjunto de problemas
    */
    void leer_problemas_sesion(BinTree<string>& problemas);

    //Consultora

    /** @brief Consultora del número de problemas que contiene una sesión.
        \pre Cierto
        \post Devuelve el número de problemas que pertenecen al parámetro
        implícito
    */
    int consultar_numero_problemas() const;

    /** @brief 
        \pre Cierto
        \post 
    */
    string consultar_problema_iesimo(int i) const;
    
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
        \post Se imprimen por pantalla los identificadores de los problemas 
        que forman el parámetro implícito
    */
    void escribir_problemas_sesion(const BinTree<string>& problemas) const;

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen el número de problemas que forman parte del 
        parámetro implícito y sus identificadores
    */
    void escribir_sesion() const;

    //-----------------------------------------------------------------
    /** @brief
        \pre
        \post
    */
    void modificar_enviables_sesion(Problemas& enviables, Problemas& resueltos);

    /** @brief
        \pre
        \post
    */
    void i_modificar_enviables_sesion(const BinTree<string>& problemas_sesion, Problemas& enviables, Problemas& resueltos);
#endif
};
