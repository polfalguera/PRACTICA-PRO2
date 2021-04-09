/** @file Usuario.hh
    @brief Especificación de la clase Usuario
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_

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
    @brief Representa un usuario registrado en la plataforma EVALUATOR.

*/

class Usuario {
private:
//Defineixes els atributs, però no els esmentes explícitament

public:
    //Constructores

    Usuario();
    /* Pre: cert */
    /* Post: el resultat es un Usuario no inscrit a cap curs i amb zero problemes
    intentats i resolts i, per tant, amb zero problemes enviables */

    // Destructora: esborra automaticament els objectes locals en sortir
    // d'un ambit de visibilitat

    ~Usuario();

    //Modificadoras

    /** @brief Inscribe al parámetro implícito a un curso determinado
        \pre c es el identificador de un curso
        \post El parámetro implícito pasa a estar inscrito al curso con 
        identificador c
    */
    void inscribir_curso(int c);

    /** @brief Consultora del curso al cual está inscrito el parámetro implícito
        \pre Cierto
        \post Si el parámetro implícito existe, se imprime el identificador del
        curso al cual está inscrito o un 0 si no está inscitro a ningun curso.
        En caso contrario, se imprime por pantalla un mensaje de error
    */
    void modificar_inscripciones();    

    //Consultoras

    /** @brief Consultora del curso al cual está inscrito el parámetro implícito
        \pre Cierto
        \post Se imprime el identificador del curso al cual está inscrito o un 0
        si no está inscitro a ningun curso.
    */
    void curso_usuario();

    /** @brief Consultora del curso al cual está inscrito el parámetro implícito
        \pre Cierto
        \post Si el parámetro implícito está inscrito en algun curso, devuelve
        el identificador de éste. En caso contrario, devuelve un 0
    */
    int consultar_curso();

    /** @brief Consultora de los problemas resueltos por el parámetro implícito
        \pre Cierto
        \post Se imprimen en orden creciente por identificador los problemas
        solucionados con éxito por el parámetro implícito, ya sean del curso
        en el cual está inscrito actualmente o de cursos anteriores. Además,
        para cada problema, se imprime el número de envíos realizados por el 
        parámetro implícito a dicho problema
    */
    void problemas_resueltos();

    /** @brief Consultora de los problemas enviables por el parámetro implícito
        \pre Cierto
        \post Se imprimen en orden creciente por identificador los problemas
        que no ha solucionado todavía, pero ya puede realizar un envío, el 
        parámetro implícito en el curso en el cual está inscrito actualmente.
        Además, para cada problema, se imprime el número de envíos realizados
        por el parámetro implícito a dicho problema
    */
    void problemas_enviables();

    //Lectura

    /** @brief Operación de lectura del parámetro implícito
        \pre Cierto
        \post El parámetro implícito pasa a tener los atributos leídos por
        el canal estandard de entrada
    */
    void leer_usuario();

    //Escritura

    /** @brief Operación de escritura
        \pre Cierto
        \post Se imprimen por pantalla los atributos del parámetro implícito
    */
   void escribir_usuario();
};
#endif
