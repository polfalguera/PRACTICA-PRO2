/** @file Curso.hh
    @brief Especificación de la clase Curso
*/

#ifndef _CURSO_HH_
#define _CURSO_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 * Clase Curso
 */

/** @class Curso
    @brief Representa un curso
*/

class Curso {
public:
    //Constructora

    /** @brief Creadora por defecto.
        
        Se ejecuta automàticamente al declarar un curso.
        \pre Cierto
        \post El resultado es un curso sin sesiones y, por ello, sin problemas.
        Tampoco tiene un número de usuarios que lo haya completado ni usurarios
        inscritos
    */
    Curso();

    //Lectura

    /** @brief Operación de lectura.
        
        Se leen el identificador del parámetro implícito y identificadores
        válidos de las sesiones que lo forman.
        \pre Cierto
        \post El parámetro implícito contiene un número de sesiones, cada una
        formada por un número de problemas. También contiene el número de 
        usuarios que han completado el curso, tanto actuales como pasados,
        y el número de usuarios inscritos en él
    */
    void leer_curso();

    //Escritura

    /** @brief Operación de escritura.
        
        Se listan los cursos actuales de la plataforma EVALUATOR
        \pre Cierto
        \post Se imprimen por pantalla los siguientes atributos del parámetro
        implícito:
        el número de usuarios actuales o pasados que lo han completado, el
        número de usuarios inscritos actualmente y el número de sesiones que lo
        forman y los identificadores de dichas sesiones, en el mismo orden que
        se leyeron cuando se creó el curso
    */
   void escribir_curso();
};
#endif
