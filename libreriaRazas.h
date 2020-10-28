#ifndef LIBRERIARAZAS_H_INCLUDED
#define LIBRERIARAZAS_H_INCLUDED
#include "libreriaPaises.h"


typedef struct
{
    int idRaza;
    char descripcion[50];
    char tamanio[50];
    char pais [20];
    int isEmpty;
}eRaza;


/** \brief Formatea el array de razas para que este todo vacio con isEmpty 1
 *
 * \param eRaza [] Array de razas
 * \param int tamanio de array de razas
 * \return -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */

int FormatearRazas (eRaza [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Harcodea unos datos en el array de razas
 *
 * \param eRaza [] Array de razas
 * \param int tamanio de array de razas
 * \return -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */

int InicializarRazas (eRaza [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Da de alta una raza a partir de una id pasada por parametro
 *
 * \param [] eRaza Array de razas
 * \param int tamanio de array de razas
 * \param int La id de la raza unica e incremental
 * \param char[] el pais de la raza
 * \return int -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */
int altaDeRaza(eRaza [], int, int, char[] );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Se pasa una id de raza por parametro y devuelve la posicion del array de razas en la quye esta esa ID
 *
 * \param [] eRaza Array de razas
 * \param int tamanio de array de razas
 * \param int el ID de la raza que quiero buscar
 * \return int la posicion en el array de razas en la que esta el id que busco si me devuelve -1 no se encontro la raza
 *
 */
int buscarIndiceRaza(eRaza [], int , int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Modifica la descripcion de la raza
 *
 * \param [] eRaza Array de razas
 * \param int el indice a ser modificado
 * \return int -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */
int modificarDescripcion (eRaza  [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Modifica el pais de la raza
 *
 * \param [] eRaza Array de razas
 * \param int el indice a ser modificado
 * \return int -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */
int modificarPais (eRaza  [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Modifica el tamanio de la raza
 *
 * \param [] eRaza Array de razas
 * \param int el indice a ser modificado
 * \return int -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */

int modificarTamanio (eRaza [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Devuelve el primer espacio libre en el array de razas
 *
 * \param [] eRaza Array de razas
 * \param int El tamanio de array de razas
 * \return La primer posicion libre que tenga el array, -1 si esta totalmente lleno
 *
 */
int emptyIndexRaza (eRaza [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Loopea el array de razas imprimiendo el encabezado va imprimiendo una raza por vez
 *
 * \param [] eRaza Array de razas
 * \param int El tamanio de array de razas
 * \param int Un flag para indicar si se deben imprimir los ID o no
 * \return int -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */
int mostrarRazas (eRaza [], ePais [], int, int, int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Recibe una estructura raza y la imprime con o sin ID
 *
 * \param eRaza la estructura a ser impresa
 * \param int 1 si quiero imprimir el ID de la raza y 0 si no quiero que imprima el ID
 * \return void
 *
 */
void mostrarUnaRaza (eRaza, ePais, int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief verifica que los tamanios ingresados sea Chico Mediano o Grande
 *
 * \param char [] el string a ser verificado
 * \return 0 si se verifico o -1 si no se verifico.
 *
 */
int verificarTamanio (char []);


#endif // LIBRERIARAZAS_H_INCLUDED
