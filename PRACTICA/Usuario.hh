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

    //Consultoras

    /** @brief Consultora del curso al cual está inscrito el parámetro implícito
        \pre Cierto
        \post Si el parámetro implícito existe, se imprime el identificador del
        curso al cual está inscrito o un 0 si no está inscitro a ningun curso.
        En caso contrario, se imprime por pantalla un mensaje de error
    */
    void curso_usuario(const Usuario& usuario);

    //Lectura

    void leer_usuario();
};
#endif
