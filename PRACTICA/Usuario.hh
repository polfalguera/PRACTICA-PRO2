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
    @brief Representa un usuario registrado en la plataforma Evaluator.
*/

class Usuario {
private: 
    int id_curso_inscrito;
    int numero_problemas_intentados;
    int numero_total_envios;
    map<string,int> resueltos;
    map<string,int> enviables;
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

    /** @brief Se actualiza el identificador del curso en el cual está inscrito 
        un usuario. El identificador será 0 en caso de que pase a no estar 
        inscrito en nigun curso.
        \pre Cierto
        \post El parámetro implícito pasa a estar suscrito a otro curso o a
        ninguno
    */
    void modificar_inscripciones(int c);

    //Consultoras

    /** @brief Consultora del curso al cual está inscrito un usuario.
        \pre Cierto
        \post Se imprime el identificador del curso al cual está inscrito
        el parámetro implícito o un 0 si no está inscitro a ningun curso
    */
    void curso_usuario() const;

    /** @brief Consultora del curso al cual está inscrito un usuario.
        \pre Cierto
        \post Si el parámetro implícito está inscrito en algun curso, devuelve
        el identificador de éste. En caso contrario, devuelve un 0
    */
    int consultar_curso() const;

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

    //Escritura

    /** @brief Operación de escritura.
        \pre Cierto
        \post Se imprimen los siguientes datos del parámetro implícito:
        cuántos envíos en total ha realizado, cuántos problemas ha resuelto
        satisfactoriamente, cuántos problemas ha intentado resolver y el
        identificador del curso en el que está inscrito o un cero si no está
        inscrito en ninguno
    */
   void escribir_usuario() const;
};
#endif
