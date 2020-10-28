#ifndef LIBRERIAPAISES_H_INCLUDED
#define LIBRERIAPAISES_H_INCLUDED

typedef struct
{
    char nombreDePais[50];
    char continente[50];
    int codigoTelefonico;
}ePais;

/** \brief Harcodea la informacion de los paises
 *
 * \param ePais [] array de paises a ser llenado
 * \param  int tamanio de array de paises
 * \return 0 si salio bien -1 si fallo la funcion
 *
 */
int InicializarPaises (ePais [], int );

/** \brief Muestra los paises que componen el array
 *
 * \param ePais [] array de paises a ser mostrado
 * \param int tamanio de array de paises
 * \return 0 si salio bien -1 si fallo la funcion
 *
 */
int mostrarPaises (ePais [], int );

/** \brief Devuelve la posicion en el array que corresponda al pais pasado por parametro
 *
 * \param [] ePais array de paises en el que este el pais a ser buscado
 * \param int tamanio de array de paises
 * \param [] char pais a ser buscado dentro del array
 * \return int posicion en el array de paises, -1 si no encontro el pais
 *
 */
int buscarIndicePais(ePais [], int , char []);


#endif // LIBRERIAPAISES_H_INCLUDED
