#ifndef LIBRERIAMASCOTAS_H_INCLUDED
#define LIBRERIAMASCOTAS_H_INCLUDED

typedef struct
{
    int idMascota;
    int idRaza;
    char nombre[50];
    int edad;
    char sexo;
    float peso;
    char tipo [20];
    int isEmpty;
}eMascota;

/** \brief Formatea el array de mascotas para que este todo vacio con isEmpty 1
 *
 * \param eMascota [] Array de mascotas
 * \param int tamanio de array de mascotas
 * \return -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */
int FormatearMascotas (eMascota [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Harcodea unos datos en el array de mascotas
 *
 * \param eMascota [] Array de mascotas
 * \param int tamanio de array de mascotas
 * \return -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */
int InicializarMascotas (eMascota [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief A partir de un ID de mascota devuelve la posicion del array en la que esta ese ID
 *
 * \param [] eMascota Array de mascotas
 * \param int tamanio de array de mascotas
 * \param int el id de la mascota a buscar
 * \return int la posicion del array mascotas en la que esta la mascota con el id. Si no existe ese ID devuelve -1
 *
 */
int buscarIndiceMascota(eMascota [], int , int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Nos devuelve la cantidad de espacios libres en el array de mascotas
 *
 * \param [] eMascota Array de mascotas
 * \param int tamanio de array de mascotas
 * \return La cantidad de espacios libres si devuelve el tamanio del array es que esta vacio
 *
 */
int estadoArrayMascotas (eMascota [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief A partir de una opcion nos redirige para modificar distintas partes de la estructura mascotas
 *
 * \param [] eMascota Array de mascotas
 * \param int el indice en el array mascotas a ser modificado
 * \param int las opciones de moficicacion 1 para modificar el nombre, 2 para modificar la edad, 3 para modificar el sexo, 4 para modificar el peso, 5 para modificar el tipo
 * \return -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */
int modificarMascota (eMascota  [], int , int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief modifica el nombre de una mascota
 *
 * \param [] eMascota Array de mascotas
 * \param int El indice a ser modificado
 * \return -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */
int modificarNombre (eMascota [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief modifica el tipo de una mascota
 *
 * \param [] eMascota Array de mascotas
 * \param int El indice a ser modificado
 * \return -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */

int modificarTipo (eMascota  [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief modifica la edad de una mascota
 *
 * \param [] eMascota Array de mascotas
 * \param int El indice a ser modificado
 * \return -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */

int modificarEdad (eMascota  [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief modifica el peso de una mascota
 *
 * \param [] eMascota Array de mascotas
 * \param int El indice a ser modificado
 * \return -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */

int modificarPeso (eMascota  [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief modifica el sexo de una mascota
 *
 * \param [] eMascota Array de mascotas
 * \param int El indice a ser modificado
 * \return -1 si no se ejecuta la funcion, 0 si se ejecuto bien
 *
 */

int modificarSexo (eMascota  [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Verifica que los tipos estan entre los posibles
 *
 * \param char [] El string a ser verificado
 * \return 0 si se paso la verificacion -1 si hubo un error
 *
 */
int verificarTipo (char []);

//////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Funcion que loopea el array de mascotas mostrando una mascota por vez e imprimiendo el encabezado una vez
 *
 * \param eMascota [] Array de mascotas
 * \param int El tamanio de array de mascotas
 * \param int 1 para que imprima el ID de la mascota 0 para que no muestre el ID
 * \return 0 si se ejecuta la funcion -1 si hubo un error
 *
 */

int mostrarMascotas (eMascota [], int, int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Recibe una ID de raza y muestra todas las mascotas de esa raza
 *
 * \param eMascota [] Array de mascotas
 * \param int El tamanio de array de mascotas
 * \param int El id de la raza a ser mostrada
 * \return 0 si se paso la verificacion -1 si hubo un error
 *
 */
int mostrarMascotasSegunRaza (eMascota [], int , int  );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief ordena las mascotas por peso e imprime el resultado
 *
 * \param [] eMascota Array de mascotas
 * \param int El tamanio de array de mascotas
 * \return void
 *
 */
void mascotasPorPeso(eMascota [], int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Recibe el array y la id a ser borrada para borrar logicamente esa posicion con .isEmpty
 *
 * \param [] eMascotaArray de mascotas
 * \param int El tamanio de array de mascotas
 * \param int el ID de la mascota a ser borrada
 * \return int 0 si se ejecuto la funcion -1 si hubo un error
 *
 */
int borrarMascota( eMascota [], int, int);

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Recibe una estructura de mascota y la imprime con o sin ID
 *
 * \param eMascota la mascota a ser impresa
 * \param int La opcion para que se imprima con ID o sin ID
 * \return
 *
 */
void mostrarUnaMascota (eMascota , int);

/////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Da de alta una mascota a partir de un ID de raza y un ID de mascota que se lo pasamos
 *
 * \param [] eMascota Array de mascotas
 * \param int El tamanio de array de mascotas
 * \param int El id de raza verificado para que se le de de alta a esa mascota
 * \param int El id de la mascota ya pasado por parametro
 * \return int 0 si se ejecuto la funcion -1 si hubo un error
 *
 */
int altaMascota (eMascota [], int , int, int );

//////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Devuelve el primer espacio libre en el array de mascotas
 *
 * \param [] eMascota Array de mascotas
 * \param int El tamanio de array de mascotas
 * \return La primer posicion libre que tenga el array, -1 si esta totalmente lleno
 *
 */
int emptyIndex (eMascota [], int );



#endif // LIBRERIAMASCOTAS_H_INCLUDED
