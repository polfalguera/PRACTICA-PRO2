/** @file Usuario.hh
    @brief Especificación de la clase Usuario
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#include "Problemas.hh"
#include "Cursos.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
#endif
using namespace std;

/*
 * Clase Usuario
 */

/** @class Usuario
    @brief Representa un usuario registrado en la plataforma Evaluator.
*/

class Usuario {
private: 
    /** @brief Identificador del curso en el cual está inscrito el usuario */
    int id_curso_inscrito;
    /** @brief Número total de problemas intentados por el usuario */
    int numero_problemas_intentados;
    /** @brief Número total de envíos realizados por el usuario */
    int numero_total_envios;
    /** @brief Conjunto de problemas resuletos del usuario */
    Problemas resueltos;
    /** @brief Conjunto de problemas enviables del usuario */
    Problemas enviables;
public:
    //Constructora

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un usuario.
        \pre Cierto
        \post El resultado es un usuario no inscrito a ningún curso y con zero
        problemas intentados y resueltos y, por tanto, con zero problemas 
        enviables
    */
    Usuario(); 

    //Modificadoras

    /** @brief Inscribe a un usuario a un curso y actualiza sus problemas
        enviables.
        \pre El curso con identificador c existe
        \post Se ha inscrito al parámetro implícito al curso con identificador
        c y se han actualizado sus problemas enviables
    */
    void inscribir_usuario_curso(int c, Curso& curso, Sesiones& cs);

    /** @brief Desinscribe a un usuario del curso al cual estaba inscrito
        actualmente.
        \pre El parámetro implícito está inscrito en un curso
        \post El parámetro implícito ha dejado de estar inscrito en un curso
    */
    void desinscribir_usuario_curso();

    /** @brief Incrementa una unidad el número total de problemas intentados
        por un usuario.
        \pre Cierto
        \post Se ha incrementado una unidad el número total de problemas
        intentados por el parámetro implícito
    */
    void incrementar_problemas_intentados();

    /** @brief Incrementa una unidad el número de intentos realizados por 
        un usuario a un problema concreto.
        \pre El problema con identificador p pertenece a los problemas
        enviables del parámetro implícito
        \post Se ha incrementado una unidad los intentos que el parámetro
        implícito ha realizado en el problema con identificador p
    */
    void incrementar_intentos_p(const string& p);

    /** @brief Incrementa una unidad el número total de envíos realizados
        por un usuario.
        \pre Cierto
        \post Se ha incrementado una unidad el número total de envíos
        realizados por el parámetro implícito
    */
    void incrementar_total_envios();

    /** @brief Actualiza los problemas enviables de un usuario tras haber 
        realizado un envío con éxito a un problema concreto.
        \pre El problema con identificador p pertenece al conjunto de 
        problemas enviables del parámetro implícito. La sesión con 
        identificador s pertenece al curso al cual está inscrito el parámetro
        implícito. El problema p pertenece a la sesión s
        \post Se han actualizado los problemas enviables del parámetro 
        implícito tras haber realizado un envío con éxito al problema con
        identificador p y se a eliminado éste del conjunto de problemas
        enviables
    */
    void actualizar_enviables(const string& p, const string& s, const Problema& problema, Cursos& cc, Sesiones& cs);

    /** @brief Actualiza los problemas resueltos de un usuario tras haber 
        realizado un envío con éxito a un problema concreto.
        \pre El problema con identificador p no pertenece al conjunto de 
        problemas resuletos del parámetro implícito
        \post El problema con identificador p ha pasado a pertenecer al 
        conjunto de problemas resuletos del parámetro implícito
    */
    void actualizar_resueltos(const string& p, const Problema& problema);

    //Consultoras

    /** @brief Consultora del curso al cual está inscrito un usuario.
        \pre Cierto
        \post Si el parámetro implícito está inscrito en algun curso, devuelve
        el identificador de éste. En caso contrario, devuelve un 0
    */
    int curso_usuario() const;

    /** @brief Consultora del número de intentos realizados por un usuario
        a un problema concreto.
        \pre Cierto
        \post Devuelve el número de intentos realizados por el parámetro 
        implícito al problema con identificador p
    */
    int consultar_intentos_p(const string& p) const;

    /** @brief Consultora del número de problemas enviables de un usuario.
        \pre Cierto
        \post Devuelve el número total de problemas enviables del parámetro
        implícito
    */
    int numero_problemas_enviables() const;   

    //Escritura

    /** @brief Imprime por pantalla los problemas resueltos de un usuario.
        \pre Cierto
        \post Se imprimen en orden creciente por identificador los problemas
        solucionados con éxito por el parámetro implícito, ya sean del curso
        en el cual está inscrito actualmente o de cursos anteriores. Además,
        para cada problema, se imprime el número de envíos realizados por el 
        parámetro implícito a dicho problema
    */
    void problemas_resueltos() const;

    /** @brief Imprime por pantalla los problemas enviables de un usuario.
        \pre Cierto
        \post Se imprimen en orden creciente por identificador los problemas
        que no ha solucionado todavía, pero ya puede realizar un envío, el 
        parámetro implícito en el curso en el cual está inscrito actualmente.
        Además, para cada problema, se imprime el número de envíos realizados
        por el parámetro implícito a dicho problema
    */
    void problemas_enviables() const;

    /** @brief Consultora de un problema enviable de un usuario.
        \pre El problema con identificador p pertenece al conjunto de 
        problemas enviables del parámetro implícito
        \post PROBLEMA pasa a ser el problema con identificador p
    */
    void consultar_problema_enviable(const string& p, Problema& problema);

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen los siguientes datos del parámetro implícito:
        cuántos envíos en total ha realizado, cuántos problemas ha resuelto
        satisfactoriamente, cuántos problemas ha intentado resolver y el
        identificador del curso en el que está inscrito o un cero si no está
        inscrito en ninguno
    */
   void escribir() const;
};
#endif
