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
    int num_total_envios;
    int num_total_correctos;
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
    map<string,Problema> cjt_problemas;
public:
    //Constructora

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un conjunto de problemas.
        \pre Cierto
        \post El resultado es un conjunto de problemas vacío
    */
    Problemas();

    //Modificadoras

    /** @brief Añade un nuevo problema a la colección de problemas.
        \pre El problema con identificador p existe
        \post Se ha añadido un nuevo problema con identificador p al parámetro 
        implícito
    */
    void nuevo_problema(const string& p);

    /** @brief Actualiza las estadísticas de un problema al realizarse un 
        envío de dicho problema por un usuario.
        \pre Cierto
        \post Se han actualizado las estadísticas del problema con 
        identificador p tras recibir un envío por parte de un usuario
    */
    void envio(const string& p, int r);

    /** @brief Actualiza el ratio de un problema tras realizarse un envio
        a dicho problema.
        \pre Cierto
        \post Se ha actualizado el ratio del problema en cuestión
    */
    void actualizar_ratio(Problema& p);

    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    void incrementar_intentos_usuario(const string& p);

    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    void eliminar_enviable(const string& p);
    
    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    void anadir_resuelto(const string& p, const Problema& problema);
     
    //Consultoras

    /** @brief Consultora de la existencia de un problema dentro de la
        colección de problemas.
        \pre Cierto
        \post Devuelve <em>true</em> si el problema pertenece al parámetro
        implícito. En caso contrario, devuelve <em>false</em>
    */
    bool existe_problema(const string& p) const;

    /** @brief Consultora del número total de problemas que hay en la
        plataforma.
        \pre El parámetro implícito no está vacío
        \post Devuelve el número total de problemas que contiene el 
        parámetro implícito
    */
    int numero_problemas() const;

    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    int numero_total_envios_p(const string& p) const;

    /** @brief Hola falta cambiarlo.
        \pre
        \post
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
        \post Se imprime el número de envíos totales y el número de envíos
        realizados con éxito a un problema con identificador p
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
    
    //Comparación

    /** @brief Operación de comparación.
        \pre 
        \post Devuelve <em>true</em> si el ratio o el string de a és mayor que los de b.
        En caso contrario, devuelve <em>false</em> 
    */
    static bool comp(const pair<string,double>& a, const pair<string,double>& b);
};
#endif
