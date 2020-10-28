#ifndef LIBRERIARAZASMASCOTAS_H_INCLUDED
#define LIBRERIARAZASMASCOTAS_H_INCLUDED
#include "libreriaMascotas.h"
#include "libreriaRazas.h"
#include "libreriaPaises.h"

typedef struct
{
    char pais [20];
    int cantidadMascotas;
}ePaisMascotas;



/** \brief Muestra las mascotas junto con su informacion de la raza
 *
 * \param El array con la informacion de las razas
 * \param El array con las mascotas
 * \return -1 si no se ejecuto la funcion 0 si se ejecuto bien
 *
 */
int mostrarDatosMascotas (eRaza [], eMascota [], int , int );

////////////////////////////////////////////////////////////////////////////

/** \brief Muestra cada raza como un encabezado, y abajo una lista con sus caracteristicas
 *
 * \param [] eRaza El array con la informacion de las razas
 * \param [] eMascota El array con las mascotas
 * \param int El tamanio del array de razas
 * \param int El tamanio del array de mascotas
 * \return -1 si no se ejecuto la funcion 0 si se ejecuto bien
 *
 */

int mostrarRazasYsusMascotas (eRaza [], eMascota [], ePais[], int , int, int);


////////////////////////////////////////////////////////////////////////////

/** \brief A partir de los paises disponibles se compara y se cuenta cuantas mascotas son de la raza de ese pais
 *
 * \param [] eRaza El array con la informacion de las razas
 * \param [] eMascota El array con las mascotas
 * \param int El tamanio del array de razas
 * \param int El tamanio del array de mascotas
 * \return int -1 si no se ejecuto la funcion 0 si se ejecuto bien
 *
 */
int contarMascotasPais(eRaza [], eMascota [] , int , int );

////////////////////////////////////////////////////////////////////////////

int mascotasPorCodtel (eMascota  [], eRaza [] , ePais [], int , int , int );


int borrarRaza(eMascota  [], eRaza  [], int , int , int );

#endif // LIBRERIARAZASMASCOTAS_H_INCLUDED
