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
    /** @brief Posición del vector de los identificadores de los problemas de
        la sesión estructurados según los prerequisitos
    */
    BinTree<int> problemas_sesion;
    /** @brief Identificadores de los problemas de la sesión */
    vector<string> id_problemas;
    /** @brief Número de problemas de la sesión */
    int numero_problemas;
    
    //Modificadoras

    /** @brief Dados los problemas enviables y resueltos de un usuario, 
        actualiza los problemas enviables del usuario al ser inscrito en un 
        curso, estudiando que problemas de la sesión puede enviar.
        \pre Cierto
        \post Se han actualizado los problemas enviables de un usuario,
        estudiando que problemas de la sesión pueden enviar
    */
    void i_modificar_enviables_s(const BinTree<int>& problemas_sesion, Problemas& enviables, Problemas& resueltos) const;

    /** @brief Dados los problemas enviables y resueltos de un usuario,
        actualiza los problemas enviables del usuario al haber realizado 
        el envío de un problema con éxito. Los problemas que pasan a ser
        enviables son los que tenían como prerequisito el problema del qual
        se ha hecho el envío.
        \pre El problema con identificador p pertenece al parámetro implícito
        \post Se han actualizado los problemas enviables de un usuario,
        estudiando que problemas pasan a ser enviables tras realizar un envío
        con éxito
    */
    void i_modificar_enviables_envio(const BinTree<int>& problemas_sesion, const string& p, bool& encontrado, Problemas& enviables, Problemas& resueltos) const;

    //Lectura

    /** @brief Lee el conjunto de problemas de una sesion
        \pre Cierto
        \post El parámetro implícito contiene los problemas estructurados
        según los prerequisitos
    */
    void leer_problemas_sesion(BinTree<int>& problemas);

    //Escritura

    /** @brief Operación de escritura.
     
        Se ejecuta automáticamente al declarar una sesión.
        \pre Cierto
        \post Se imprimen por pantalla los identificadores de los problemas 
        que forman parte del parámetro implícito
    */
    void escribir_problemas_sesion(const BinTree<int>& problemas) const;
public:
    //Constructora

    /** @brief Constructora por defecto.
        \pre Cierto
        \post El resultado es una sesión vacía
    */
    Sesion();

    //Modificadoras

    /** @brief Actualiza los problemas enviables de un usuario al ser inscrito
        en un curso, estudiando que problemas de la sesión puede enviar.
        \pre Cierto
        \post Se han actualizado los problemas enviables de un usuario,
        estudiando que problemas de la sesión puede enviar
    */
    void modificar_enviables_s(Problemas& enviables, Problemas& resueltos) const;

    /** @brief Actualiza los problemas enviables de un usuario al haber
        realizado el envío de un problema con éxito. Los problemas que pasan
        a ser enviables son los que tenían como prerequisito el problema 
        del qual se ha hecho el envío.
        \pre El problema con identificador p pertenece al parámetro implícito
        \post Se han actualizado los problemas enviables de un usuario,
        estudiando que problemas pasan a ser enviables tras realizar un envío
        con éxito
    */
    void modificar_enviables_envio(const string& p, bool& encontrado, Problemas& enviables, Problemas& resueltos) const;

    //Consultora

    /** @brief Consultora del número de problemas que contiene una sesión.
        \pre Cierto
        \post Devuelve el número de problemas que contiene el parámetro
        implícito
    */
    int consultar_numero_problemas() const;

    /** @brief Consultora del identificador de un problema perteneciente a una
        sesión.
        \pre Cierto
        \post Devuelve el identificador del problema i-esimo
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
        \post Se imprimen por pantalla el número de problemas que forman parte
        del parámetro implícito y sus identificadores 
    */
    void escribir() const;
#endif
};
