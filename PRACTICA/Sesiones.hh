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
    /** @brief Conjunto de sesiones */
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
        \pre La sesión con identificador s no pertenece al parámetro implícito
        \post Se ha añadido una nueva sesión con identificador s al parámetro
        implícito
    */
    void nueva_sesion(const string& s);

    /** @brief Actualiza los problemas enviables de un usuario al ser inscrito
        en un curso, estudiando que problemas de una sesión concreta puede 
        enviar.
        \pre La sesión con identificador s pertenece al parámetro implícito
        \post Se han actualizado los problemas enviables de un usuario,
        estudiando que problemas de la sesión con identificador s se pueden
        enviar
    */
    void modificar_enviables_sesion(const string& s, Problemas& enviables, Problemas& resueltos) const;
    
    /** @brief Actualiza los problemas enviables de un usuario al haber
        realizado el envío de un problema con éxito. Los problemas que pasan
        a ser enviables son los que tenían como prerequisito el problema 
        del qual se ha hecho el envío.
        \pre La sesión con identificador s pertenece al parámetro implícito
        \post Se han actualizado los problemas enviables de un usuario,
        estudiando que problemas pasan a ser enviables tras realizar un envío
        con éxito
    */
    void modificar_envibales_envio_s(const string& p, const string& s, Problemas& enviables, Problemas& resueltos) const;

    //Consultoras  

    /** @brief Consultora del número total de problemas que hay en una sesión
        concreta.
        \pre La sesión con identificador s pertenece al parámetro implícito
        \post Devuelve el número de problemas que contiene la sesión con 
        identificador s.
    */
    int numero_problemas_sesion(const string& s) const;

    /** @brief Consultora del identificador de un problema perteneciente a
        una sesión concreta.
        \pre La sesión con identificador s pertenece al parámetro implícito.
        i es un entero >= 0
        \post Devuelve el identificador del problema i-esimo
        perteneciente a la sesión con identificador s
    */
    string problema_iesimo_sesion(const string& s, int i) const;

    /** @brief Consultora de la existencia de una sesión dentro del
        conjunto de sesiones.
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

    /** @brief Operación de escritura.
        \pre La sesión con identificador s existe
        \post Se imprimen por pantalla el número de problemas que forman parte
        de la sesión con identificador s y sus identificadores
    */
    void escribir_sesion(const string& s) const;

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen por pantalla las sesiones actuales de la plataforma 
        en orden creciente por su identificador y mostrando, para cada sesión,
        el número de problemas que la forman y los identificadores de dichos 
        problemas
    */
    void listar_sesiones() const;
};
#endif
