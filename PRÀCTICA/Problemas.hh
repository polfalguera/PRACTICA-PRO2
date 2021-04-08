/** @file Problemas.hh
    @brief Especificación de la clase Problemas
*/

#ifndef _PROBLEMAS_HH_
#define _PROBLEMAS_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
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

    Problemas();
    /* Pre: cierto */
    /* Post: el resultado es un conjunto de problemas vacio */

    // Destructora: borra automaticamente los objetos locales en salir de un
    //ámbito de visibilidad

    ~Problemas();

    //Modificadoras

    void nuevo_problema(string p);
    /* Pre: p es un string que representa el identificador del problema a añadir */
    /* Post: el problema con identificador p se ha añadido al conjunto de problemas
    siempre y cuando no estuviera previamente */

    //Lectura

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
    void buscar_escribir_problema(string p));
};
#endif