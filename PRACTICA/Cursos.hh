/** @file Cursos.hh
    @brief Especificación de la clase Cursos
*/

#ifndef _CURSOS_HH_
#define _CURSOS_HH_

#include "Curso.hh"

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

        Se ejecuta automàticamente al declarar un curso.
        \pre Cierto
        \post El resultado es un conjunto de cursos vacío
    */
    Cursos();

    //Modificadoras

    /** @brief Añade un nuevo curso al conjunto de cursos.
        \pre c es un entero que represental el identificador del curso a añadir
        \post se ha añadido el curso con identificador c al conjunto de cursos
        siempre y cuando este no estuviera previamente y cumpla la no repetición
        de problemas dentro del mismo. En caso contrario, se imprime un mensaje
        de error
    */
    void nuevo_curso(int c);

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

    /** @brief Consultora de un curso perteneciente al parámetro implícito
        \pre c es el identificador de un curso
        \post Devuelve el curso perteneciente al parámetro implícito con 
        identificador c
    */
    Curso consultar_curso(int c);

    /** @brief Consultora de la existencia de un curso dentro del
        parámetro implícito
        \pre c es el identificador de un curso
        \post Devuelve <em>true</em> si el curso pertenece al parámetro
        implícito. En caso contrario, devuelve <em>false</em>
    */
    bool existe_curso(int c);

    /** @brief Consultora de el cumplimiento de la restricción de no repetición
        \pre p es el identificador de un problema
        \post Devuelve true si el problema pertenece al parámetro implícito.
        En caso contrario, devuelve false
    */
    bool repeticion_ejercicios(const Curso& curso);

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

        Se leen los cursos que formaran parte de la plataforma EVALUATOR.
        \pre Cierto
        \post El parámetro implícito contiene uno o más cursos
    */
    void leer_conjunto_cursos();

    //Escritura

    /** @brief Operación de escritura.

        Se listan los cursos actuales de la plataforma EVALUATOR
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
