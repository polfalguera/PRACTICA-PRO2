/** @file Sesiones.hh
    @brief Especificación de la clase Sesiones
*/

#ifndef _SESIONES_HH_
#define _SESIONES_HH_

#include "Sesion.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif
using namespace std;

/*
 * Clase Sesiones
 */

/** @class Sesiones
    @brief Representa el conjunto de sesiones pertenecientes a la plataforma
    EVALUATOR.
*/
class Sesiones {
public:
    //Constructoras

    Sesiones();
    /* Pre: cierto */
    /* Post: el resultado es un conjunto de sesiones vacio */

    // Destructora: borra automaticamente los objetos locales en salir de un
    //ambito de visibilidad

    ~Sesiones();

    //Modificadoras

    void nueva_sesion(string s);
    /* Pre: s es un string que representa el identificador de la sesión
    a añadir */
    /* Post: la sesión con idetificador s se ha añadido al conjunto de
    sesiones */

    //Lectura

    void leer_conjunto_sesiones();
    /* Pre: cierto */
    /* Post: el parámetro implícito contiene una o más sesiones */

    //Escritura

    /* Pre: cierto */
    /* Post: se imprime por pantalla las sesiones actuales de la plataforma
    crecientemente por su identificador y, mostrando para cada sesión, el
    número de problemas que la forman y los identificadores de dichos problemas
    */
    void listar_sesiones();

    /** @brief Operación de escritura.

        Busca y imprime una sesión perteneciente al parámetro implícito.
        \pre s es el identificador de una sesión
        \post Si s pertenece al parámetro implícito, se imprime el número de
        problemas que la forman y los identificadores de dichos prolemas,
        siguiendo su estructura de prerequisitos en postorden. En caso que
        no exista, se imprime mensaje de error
    */
   void buscar_escribir_sesion(string s);




};
#endif
