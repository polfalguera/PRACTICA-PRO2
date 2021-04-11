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

        Se ejecuta automáticamente al declarar un conjunto de problemas.
        \pre Cierto
        \post El resultado es un conjunto de problemas vacío
    */
    Problemas();

    //Modificadoras

    /** @brief Añade un nuevo problema a la colección de problemas.
        \pre Cierto
        \post Se ha añadido un nuevo problema con identificador p al parámetro 
        implícito
    */
    void nuevo_problema(string p);

    //Consultoras

    /** @brief Consultora de la existencia de un problema dentro de la
        plataforma.
        \pre Cierto
        \post Devuelve <em>true</em> si el problema pertenece al parámetro
        implícito. En caso contrario, devuelve <em>false</em>
    */
    bool existe_problema(string p);

    /** @brief Consultora del número total de problemas que hay en la
        plataforma.
        \pre Cierto
        \post Devuelve el número total de problemas que contiene el 
        parámetro implícito
    */
    int numero_problemas();

    //Lectura

    /** @brief Operación de lectura.
        \pre Cierto
        \post El parámetro implícito contiene uno o más problemas
    */
    void leer_coleccion_problemas();

    //Escritura

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprime el número de envíos totales y el número de envíos
        con éxito realizados a un problema con identificador p
    */
    void escribir_problema(string p) const;

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen por pantalla los problemas de la colección, indicando
        para cada uno el número de envíos totales(t) y el número de envíos con
        éxito(e). El orden en el que se imprimen viene determinado por el ratio 
        (t+1)/(e+1), el cual también se imprime. En caso de empate, se imprimen
        en orden creciente por identificador
    */
    void listar_problemas() const;
    

};
#endif
