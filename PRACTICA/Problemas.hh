/** @file Problemas.hh
    @brief Especificación de la clase Problemas
*/

#ifndef _PROBLEMAS_HH_
#define _PROBLEMAS_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#endif
using namespace std;

struct Problema {
    /** @brief Número total de envíos realizados al problema */
    int num_total_envios;
    /** @brief Número total de usuarios que han resuelto el problema */
    int num_total_correctos;
    /** @brief Ratio del problema */
    double ratio;
};

/*
 * Clase Problemas
 */

/** @class Problemas
    @brief Representa la colección de problemas de la plataforma Evaluator.
*/

class Problemas {
private:
    /** @brief Colección de problemas */
    map<string,Problema> cjt_problemas;

    //Modificadora

    /** @brief Actualiza el ratio de un problema cuando un usuario realiza
        un envío a dicho problema.
        \pre El problema con identificador p existe
        \post Se ha actualizado el ratio del problema en cuestión
    */
    void actualizar_ratio(Problema& p);

    //Comparación

    /** @brief Operación de comparación.
        \pre Cierto
        \post Devuelve <em>true</em> si el ratio o el string de a son mayores que los de b.
        En caso contrario, devuelve <em>false</em> 
    */
    static bool comp(const pair<string,double>& a, const pair<string,double>& b);
public:
    //Constructora

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un conjunto de problemas.
        \pre Cierto
        \post El resultado es un conjunto de problemas vacío.
    */
    Problemas();

    //Modificadoras

    /** @brief Añade un nuevo problema a la colección de problemas.
        \pre El problema con identificador p no pertenence al parámetro
        implícito 
        \post Se ha añadido un nuevo problema con identificador p al parámetro 
        implícito
    */
    void nuevo_problema(const string& p);

    /** @brief Actualiza las estadísticas de un problema cuando un usuario
        realiza un envío a dicho problema, teniendo en cuenta si lo ha resuelto
        o no.
        \pre El problema con identificador p es un problema enviable de un
        usuario. r es un entero que puede tomar por valor 0 o 1
        \post Se han actualizado las estadísticas del problema con 
        identificador p tras recibir un envío por parte de un usuario
    */
    void envio(const string& p, int r);

    /** @brief Incrementa una unidad los intentos realizados a un problema
        por un usuario.
        \pre Cierto
        \post Se ha incrementado una unidad los intentos realizados por un
        usuario al problema en cuestión
    */
    void incrementar_intentos_usuario(const string& p);

    /** @brief Elimina un problema del conjunto de problemas enviables de un
        usuario.
        \pre El problema con identificador p pertenece al conjunto de problemas
        enviables de un usuario
        \post Se ha eliminado el problema con identificador p de los problemas
        enviables de un usuario
    */
    void eliminar_enviable(const string& p);
    
    /** @brief Añade un problema al conjunto de problemas resueltos de un 
        usuario.
        \pre El problema con identificador p no pertenece al conjunto de 
        problemas resueltos por un usuario  
        \post Se ha añadido el problema con identificador p al conjunto 
        de problemas resueltos por un usuario
    */
    void anadir_resuelto(const string& p, const Problema& problema);
     
    //Consultoras

    /** @brief Consultora de la existencia de un problema dentro de la
        colección de problemas.
        \pre Cierto
        \post Devuelve <em>true</em> si el problema con identificador p
        pertenece al parámetro implícito. En caso contrario, devuelve 
        <em>false</em>
    */
    bool existe_problema(const string& p) const;

    /** @brief Consultora del número total de problemas que hay en la
        plataforma.
        \pre El parámetro implícito no está vacío
        \post Devuelve el número total de problemas que contiene el 
        parámetro implícito
    */
    int numero_problemas() const;

    /** @brief Consultora del número total de envíos realizados por un usuario
        a un problema.
        \pre Cierto
        \post Devuelve el número total de envíos realizados por un usuario al 
        problema con identificador p
    */
    int numero_total_envios_p(const string& p) const;

    /** @brief Consultora de un problema perteneciente a un conjunto de 
        problemas.
        \pre El problema con identificador p pertenece al parámetro implícito
        \post PROBLEMA pasa a ser el problema con identificador p
    */
    void consultar_problema(const string& p, Problema& problema);

    //Lectura

    /** @brief Operación de lectura.
        \pre Cierto
        \post El parámetro implícito contiene uno o más problemas
    */
    void leer_coleccion_problemas();

    //Escritura

    /** @brief Operación de escritura.
        \pre El problema con identificador p existe
        \post Se imprimen por pantalla el número de envíos totales y el número
        de envíos realizados con éxito a un problema con identificador p
    */
    void escribir_problema(const string& p) const; 

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen por pantalla los problemas de la colección, indicando
        para cada uno el número de envíos totales(t) y el número de envíos con
        éxito(e). El orden en el que se imprimen viene determinado por el ratio 
        (t+1)/(e+1), el cual también se imprime. En caso de empate, se imprimen
        en orden creciente por identificador
    */
    void listar_problemas() const;

    /** @brief Operación de escritura.
       \pre Cierto
       \post Se imprimen por pantalla los identificadores de los problemas que
       forman el parámetro implícito, además de los envíos que se han realizado
       a dicho problema
    */
    void listar_identificador_envios() const;
};
#endif
