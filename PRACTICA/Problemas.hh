/** @file Problemas.hh
    @brief Especificación de la clase Problemas
*/

#ifndef _PROBLEMAS_HH_
#define _PROBLEMAS_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif
using namespace std;

/*
 * Clase Problemas
 */

/** @class Problemas
    @brief Representa la colección de problemas de la plataforma EVALUATOR
*/

class Problemas {
private:
//Defines atributos, pero no los mencionas explicitamente

public:
    //Constructoras

    /** @brief Creadora por defecto.

        Se ejecuta automàticamente al declarar un problema.
        \pre Cierto
        \post El resultado es un conjunto de problemas vacío
    */
    Problemas();

    //Modificadoras

    /** @brief Añade un nuevo problema a la colección.
        \pre p es un string que representa el identificador del problema a
        añadir
        \post Se ha añadido el problema con identificador p al parámetro
        implícito
    */
    void nuevo_problema(string p);

    //Consultoras

    /** @brief Consultora de la existencia de un problema dentro del
        parámetro implícito
        \pre p es el identificador de un problema
        \post Devuelve <em>true</em> si el problema pertenece al parámetro
        implícito. En caso contrario, devuelve <em>false</em>
    */
    bool existe_problema(string p);

    //Lectura

    /** @brief Añade un nuevo problema a la colección.
        \pre p es un string que representa el identificador del problema a
        añadir
        \post Se ha añadido el problema con identificador p al parámetro
        implícito
    */

    void leer_coleccion_problemas();
    /* Pre: cierto */
    /* Post: el parámetro implícito contiene 1 o más problemas */

    //Consultora o Escritura?

    void listar_problemas() const;
    /* Pre: cierto */
    /* Post: se imprimen por pantalla los problemas de la colección, indicando
    para cada uno el número de envíos totales(t) y el número de envíos con éxito(e).
    El orden en el que se imprimen viene determinado por el ratio (t+1)/(e+1),
    el cual también se imprime por pantalla. En caso de empate, se imprimen en
    orden creciente por identificador */

    /** @brief Operación de escritura.

        Busca y imprime un problema perteneciente al parámetro implícito.
        \pre p es el identificador de un problema
        \post Si p pertenece al parámetro implícito, se imprime por pantalla
        el número de envíos totales y el número de envíos con éxito del
        problema. En caso que no exista, se imprime un mensaje de error
    */
    void buscar_escribir_problema(string p);
};
#endif
