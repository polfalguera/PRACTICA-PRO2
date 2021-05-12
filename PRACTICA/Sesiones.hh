/** @file Sesiones.hh
    @brief Especificación de la clase Sesiones
*/

#ifndef _SESIONES_HH_
#define _SESIONES_HH_

#include "Sesion.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif
using namespace std;

/*
 * Clase Sesiones
 */

/** @class Sesiones
    @brief Representa el conjunto de sesiones de la plataforma Evaluator.
*/
class Sesiones {
private:
    map<string,Sesion> cjt_sesiones;
public:
    //Constructora

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un conjunto de sesiones.
        \pre Cierto
        \post El resultado es un conjunto de sesiones vacío
    */
    Sesiones();

    //Modificadoras

    /** @brief Añade una nueva sesión al conjunto de sesiones.
        \pre La sesión con identificador s existe
        \post Se ha añadido una nueva sesion con identificador s al parámetro
        implícito
    */
    void nueva_sesion(string s);

    /** @brief
        \pre
        \post
    */
    void modificar_envibales_sesion(const string& s, Problemas& enviables, Problemas& resueltos);
    
    /** @brief
        \pre
        \post
    */
    void modificar_envibales_envio_s(const string& p, const string& s, Problemas& enviables, Problemas& resueltos);

    //Consultoras  

    /** @brief Falta hacer cambios.
        \pre
        \post
    */
    int numero_problemas_sesion(const string& s) const;

    /** @brief Falta hacer cambios.
        \pre
        \post
    */
    string problema_iessimo_sesion(const string& s, int i) const;

    /** @brief Consultora de la existencia de una sesión dentro del
        parámetro implícito.
        \pre Cierto
        \post Devuelve <em>true</em> si la sesión con identificador s pertenece 
        al parámetro implícito. En caso contrario, devuelve <em>false</em>
    */
    bool existe_sesion(const string& s) const;

    /** @brief Consultora del número total de sesiones que hay en la
        plataforma.
        \pre El parámetro implícito no está vacío
        \post Devuelve el número total de sesiones que contiene el 
        parámetro implícito
    */
    int numero_sesiones() const;

    //Lectura

    /** @brief Operación de lectura.
        \pre Cierto
        \post El parámetro implícito contiene una o más sesiones
    */
    void leer_conjunto_sesiones();

    //Escritura

    /** @brief
        \pre
        \post
    */
    void escribir_sesion(const string& s) const;

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen las sesiones actuales de la plataforma en orden
        creciente por su identificador y mostrando, para cada sesión, el número
        de problemas que la forman y los identificadores de dichos problemas
    */
    void listar_sesiones() const;
};
#endif
