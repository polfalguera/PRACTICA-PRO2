/** @file Usuarios.hh
    @brief Especificación de la clase Usuarios
*/

#ifndef _USUARIOS_HH_
#define _USUARIOS_HH_

#include "Usuario.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
#endif

/*
 * Clase Usuarios
 */

/** @class Usuarios
    @brief Representa el conjunt d'Usuarios registrats a la plataforma EVALUATOR

*/

class Usuarios {
private:
//Defineixes els atributs, però no els esmentes explícitament

public:
    //Constructores

    Usuarios();
    /* Pre: cert */
    /* Post: el resultat es un conjunt d'Usuarios buit */

    // Destructora: esborra automaticament els objectes locals en sortir
    // d'un ambit de visibilitat

    ~Usuarios();

    //Modificadores

    /** @brief Registra a un nuevo usuario en la plataforma
      \pre u representa el identificador del usuario a dar de alta y us
      el usuario en si
      \post Se ha añadido el usuario con identificador u al parámetro
      implícito, si este no existía previamente, y se imprime por pantalla
      el número de usuarios registrados tras ser añadido. En caso que el
      usuario ya exista, se imprime un mensaje de error  
    */
    void alta_usuario(string u, const Usuario& us);

    /** @brief Da de baja a un usuario de la plataforma
      \pre u representa el identificador del usuario a dar de baja
      \post Si u es un identificador válido, se borra de la plataforma el
      usuario con identificador u y se imprime por pantalla el número de 
      usuarios registrados tras ser borrado. En caso que no exista el usuario,
      se imprime por pantalla un mensaje de error  
    */
    void baja_usuario(string u);    
};
#endif
