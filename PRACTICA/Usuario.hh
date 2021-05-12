/** @file Usuario.hh
    @brief Especificación de la clase Usuario
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#include "Problemas.hh"
#include "Curso.hh"

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
    int id_curso_inscrito;
    int numero_problemas_intentados;
    int numero_total_envios;
    Problemas resueltos;
    Problemas enviables;
public:
    //Constructora

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un conjunto de usuarios.
        \pre Cierto
        \post El resultado es un usuario no inscrito a ningun curso y con zero
        problemas intentados y resueltos y, por tanto, con zero problemas 
        enviables
    */
    Usuario(); 

    //Modificadoras

    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    void inscribir_usuario_curso(int c, Curso& curso, Sesiones& cs);

    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    void desinscribir_usuario_curso();

    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    void incrementar_problemas_intentados();

    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    void incrementar_intentos_p(const string& p);

    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    void incrementar_total_envios();

    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    void actualizar_enviables(const string& p, const string& s, const Problema& problema, Curso& curso, Sesiones& cs);

    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    void actualizar_resueltos(const string& p, const Problema& problema);

    //Consultoras

    /** @brief Consultora del curso al cual está inscrito un usuario.
        \pre Cierto
        \post Si el parámetro implícito está inscrito en algun curso, devuelve
        el identificador de éste. En caso contrario, devuelve un 0
    */
    int curso_usuario() const;

    /** @brief Consultora de los problemas resueltos de un usuario.
        \pre Cierto
        \post Se imprimen en orden creciente por identificador los problemas
        solucionados con éxito por el parámetro implícito, ya sean del curso
        en el cual está inscrito actualmente o de cursos anteriores. Además,
        para cada problema, se imprime el número de envíos realizados por el 
        parámetro implícito a dicho problema
    */
    void problemas_resueltos() const;

    /** @brief Consultora de los problemas enviables de un usuario.
        \pre Cierto
        \post Se imprimen en orden creciente por identificador los problemas
        que no ha solucionado todavía, pero ya puede realizar un envío, el 
        parámetro implícito en el curso en el cual está inscrito actualmente.
        Además, para cada problema, se imprime el número de envíos realizados
        por el parámetro implícito a dicho problema
    */
    void problemas_enviables() const;

    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    int consultar_intentos_p(const string& p) const;

    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    int numero_problemas_enviables() const;   
    
    /** @brief Hola falta cambiarlo.
        \pre
        \post
    */
    void consultar_problema_enviable(const string& p, Problema& problema);

    //Escritura

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
