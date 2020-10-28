#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "libreriaRazasMascotas.h"
#include "libreriaMascotas.h"
#include "libreriaRazas.h"
#include "libreriaPaises.h"
#include "utn_getData.h"
#define TAMRAZA 10
#define TAMMASCO 10
#define TAMPAISES 5


int main()
{

    eRaza arrayRazas [TAMRAZA];
    eMascota arrayMascotas [TAMMASCO];
    ePais arrayPaises[TAMPAISES];
    FormatearMascotas ( arrayMascotas, TAMMASCO);
    FormatearRazas ( arrayRazas, TAMRAZA);
    InicializarMascotas ( arrayMascotas,  TAMMASCO);
    InicializarRazas ( arrayRazas,  TAMRAZA);
    InicializarPaises(arrayPaises, TAMPAISES);

    int menu;
    int idMascota =5;
    int idRaza = 5;
    int idBorrar;
    int idModificar;
    int indiceModificar;
    int opcionModificar;
    int opcionOrden;
    int razaAlta;
    char paisAlta[20];


    do{
    printf("\n\n Opciones:\n 1.Alta \n 2.Listar mascotas \n 3. Listar razas con las mascotas \n 4. Borrar mascota \n 5. Listar mascotas por peso o cod tel. \n 6. Modificar mascota \n 7. Alta de Raza \n 8.Mostrar pais con mas mascotas\n 10. Salir \n");

    if (getNumero(&menu,"Ingrese una opcion", "opcion no valida", 1, 10, 20)==0)
    {
        switch (menu)
        {
            case 1:
                if (emptyIndex(arrayMascotas, TAMMASCO)==-1)
                {
                    printf("el array esta lleno");
                }else
                {
                mostrarRazas(arrayRazas, arrayPaises, TAMRAZA, TAMPAISES, 1);
                getNumero(&razaAlta,"\n Ingrese una la raza del animal a dar de alta", "opcion no valida", 1, 9999999, 20);
                    while (buscarIndiceRaza(arrayRazas, TAMRAZA, razaAlta)==-1)
                    {
                    printf("\n No existe la raza ingresada");
                    getNumero(&razaAlta,"\n Ingrese una la raza del animal a dar de alta", "opcion no valida", 1, 9999999, 20);
                    }
                idMascota++;
                altaMascota (arrayMascotas, TAMMASCO , razaAlta, idMascota);
                }
                break;
            case 2:
                if (estadoArrayMascotas ( arrayMascotas, TAMMASCO) != TAMMASCO)
                {
                    mostrarDatosMascotas ( arrayRazas,  arrayMascotas,  TAMRAZA,  TAMMASCO);
                }else{
                printf("\n No existen mascotas ingresadas\n");
                }

                break;
            case 3:
                if (estadoArrayMascotas ( arrayMascotas, TAMMASCO) != TAMMASCO)
                {
                    mostrarRazasYsusMascotas (arrayRazas, arrayMascotas, arrayPaises, TAMRAZA , TAMMASCO, TAMPAISES );
                } else{
                printf("\n No existen mascotas ingresadas\n");
                }

                break;
            case 4:
                if (estadoArrayMascotas ( arrayMascotas, TAMMASCO) != TAMMASCO)
                {
                    mostrarMascotas ( arrayMascotas, TAMMASCO, 1);
                getNumero(&idBorrar,"\n Ingrese ID de mascota para borrarla", "opcion no valida", 1, TAMMASCO, 20);
                borrarMascota( arrayMascotas, TAMMASCO, idBorrar);
                }else{
                printf("\n No existen mascotas ingresadas\n");
                }

                break;
            case 5:
                if (estadoArrayMascotas ( arrayMascotas, TAMMASCO) != TAMMASCO)
                {
                    getNumero(&opcionOrden,"\n Ingrese como desea ordenar\n 1. Ordenar por peso 2. Ordenar por cod. telefonico", "opcion no valida", 1, 2, 20);
                    if (opcionOrden == 1){
                        mascotasPorPeso(arrayMascotas, TAMMASCO);
                    } else {
                        mascotasPorCodtel(arrayMascotas, arrayRazas, arrayPaises, TAMMASCO, TAMRAZA, TAMPAISES);

                    }

                }else {
                printf("\n No existen mascotas ingresadas\n");
                }

                break;
            case 6:
                if (estadoArrayMascotas ( arrayMascotas, TAMMASCO) != TAMMASCO)
                {
                    mostrarMascotas ( arrayMascotas, TAMMASCO, 1);
                    getNumero(&idModificar,"\n Ingrese ID de mascota a modificar", "opcion no valida", 1, TAMMASCO, 20);
                    indiceModificar = buscarIndiceMascota(arrayMascotas, TAMMASCO, idModificar);
                    if (indiceModificar != -1 && confirmEdit(idModificar)==1)
                    {
                    getNumero(&opcionModificar,"\n Ingrese dato a modificar\n 1.Modificar Nombre\n 2. Modificar Edad\n 3. Modificar Sexo \n 4. Modificar Peso \n 5. Modificar Tipo\n", "opcion no valida", 1, 6, 20);
                    modificarMascota(arrayMascotas, indiceModificar, opcionModificar);
                    }else {
                    printf("\n No existe el id de la mascota");
                    }
                }else
                {
                printf("\n No existen mascotas ingresadas\n");
                }
                break;
            case 7:
                idRaza++;
                printf("\n Elija de que pais es la raza\n");
                mostrarPaises(arrayPaises, TAMPAISES);
                myGets(paisAlta, 20);
                while (buscarIndicePais(arrayPaises, TAMPAISES, paisAlta)==-1)
                {
                    printf("\n Por favor elija un pais disponible ");
                    myGets(paisAlta, 20);
                }
                altaDeRaza(arrayRazas, TAMRAZA, idRaza, paisAlta);
                break;
            case 8:
                if (estadoArrayMascotas ( arrayMascotas, TAMMASCO) != TAMMASCO)
                {
                    contarMascotasPais( arrayRazas,  arrayMascotas, TAMRAZA, TAMMASCO);
                }else
                {
                    printf("\n No existen mascotas ingresadas\n");
                }
                break;
            case 9:
                borrarRaza(arrayMascotas, arra)
                break;
        }
    }
    }while(menu != 10);


return 0;
}
