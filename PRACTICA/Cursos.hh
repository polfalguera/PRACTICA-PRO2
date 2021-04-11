/** @file Cursos.hh
    @brief Especificación de la clase Cursos
*/

#ifndef _CURSOS_HH_
#define _CURSOS_HH_

#include "Curso.hh"
#include "Sesiones.hh"
#include "Usuarios.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif
using namespace std;

/*
 * Clase Cursos
 */

/** @class Cursos
    @brief Representa el conjunto de cursos de la plataforma EVALUATOR
*/

class Cursos {
public:
    //Constructora

    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar un conjunto de cursos.
        \pre Cierto
        \post El resultado es un conjunto de cursos vacío
    */
    Cursos();

    //Modificadoras

    /** @brief Añade un nuevo curso al conjunto de cursos siempre y cuando no 
        haya intersección de problemas entre las sesiones.
        \pre Cierto
        \post Si no hay intersección de problemas entre sesiones, añade un 
        nuevo curso al parámetro implícito y devuelve <em>true/<em>. En caso
        contrario, devuelve <em>false</em>
    */
    bool nuevo_curso(const Sesiones& cjt_sesiones);

    /** @brief Incrementa una unidad el número de usuarios que han completado
        el curso.
        \pre cierto
        \post se ha incrementado una unidad el número de usuarios que han
        completado el parámetro implícito
    */
    void incrementar_usuarios_completado();

    /** @brief Incrementa una unidad el número de usuarios inscritos
        actualmente en el curso.
        \pre cierto
        \post se ha incrementado una unidad el número de usuarios inscritos
        actualmente en el parámetro implícito
    */
    void incrementar_usuarios_inscritos();

    /** @brief Decrementa una unidad el número de usuarios inscritos
        actualmente en el curso.
        \pre cierto
        \post se ha decrementado una unidad el número de usuarios inscritos
        actualmente en el parámetro implícito
    */
    void decrementar_usuarios_inscritos();

    //Consultoras

    /** @brief Consultora de un curso de la plataforma.
        \pre Cierto
        \post Devuelve el curso perteneciente al parámetro implícito con 
        identificador c
    */
    Curso consultar_curso(int c);

    /** @brief Consultora de la existencia de un curso dentro de la plataforma.
        \pre Cierto
        \post Devuelve <em>true</em> si el curso pertenece al parámetro
        implícito. En caso contrario, devuelve <em>false</em>
    */
    bool existe_curso(int c);

    /** @brief Consultora del número total de cursos que hay en la
        plataforma.
        \pre Cierto
        \post Devuelve el número total de cursos que contiene el 
        parámetro implícito
    */
    int numero_cursos();

    /** @brief Consulta la sesion a la que pertenece un problema dentro de un
        curso
        \pre c es el identificador de un curso y p es el identificador de un
        problema
        \post Si c es un curso válido y p pertenece a c, se imprime la sesión
        a la que pertenece p dentro de c. En caso que el curso no existao el
        problema no pertenezca al curso, se imprime un mensaje de error
    */
    void sesion_problema(int c, string p);



    //Lectura

    /** @brief Operación de lectura.
        \pre Cierto
        \post El parámetro implícito contiene uno o más cursos
    */
    void leer_conjunto_cursos();

    //Escritura

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen por pantalla los cursos del conjunto de forma
        creciente por su identificador. Para cada uno, se muestra el número
        de usuarios actuales o pasados que lo han completado, el número de
        usuarios inscritos actualmente y el número de sesiones que lo forman
        y los identificadores de dichas sesiones, en el mismo orden que se
        leyeron cuando se creó el curso
    */
    void listar_cursos();

};
#endif
