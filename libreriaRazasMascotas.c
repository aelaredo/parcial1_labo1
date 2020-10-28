#include "libreriaRazas.h"
#include "libreriaRazasMascotas.h"
#include "libreriaMascotas.h"
#include "libreriaPaises.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>


int mostrarDatosMascotas (eRaza arrayRazas[], eMascota arrayMascotas[], int tamanioRazas, int tamanioMascotas)
{
    int i;
    /////int j;
    int retorno = -1;
    int indexInfoRaza;


    if(arrayRazas != NULL && arrayMascotas != NULL && tamanioRazas >0 && tamanioMascotas>0)
    {

    printf("\n Nombre     || Edad || Sexo || Peso   || Tipo  || Raza       ||  Origen      || Tamaño \n --------------------------------------------------------------------------------------");
        for (i=0;i<tamanioMascotas;i++)
        {
            if (arrayMascotas[i].isEmpty == 0)
            {

                //////////////
                indexInfoRaza = buscarIndiceRaza(arrayRazas, tamanioRazas , arrayMascotas[i].idRaza);
                /////////////
                printf("\n %-10s || %-4d || %-4c || %-6.1f || %-5s || %-10s ||  %-10s  || %s ", arrayMascotas[i].nombre, arrayMascotas[i].edad, arrayMascotas[i].sexo,arrayMascotas[i].peso , arrayMascotas[i].tipo, arrayRazas[indexInfoRaza].descripcion,arrayRazas[indexInfoRaza].pais, arrayRazas[indexInfoRaza].tamanio);
            }
        }
        retorno = 0;
    }

    return retorno;

}


int mostrarRazasYsusMascotas (eRaza arrayRazas[], eMascota arrayMascotas[],ePais arrayPaises[], int tamanioRazas, int tamanioMascotas, int tamanioPaises)
{
    int i;
    int indiceInfoPais;
    /////int j;
    int retorno = -1;
    /////int flagMascotadeRaza ;

    if(arrayRazas != NULL && arrayMascotas != NULL && tamanioRazas >0 && tamanioMascotas>0)
    {
        for (i=0;i<tamanioRazas;i++)
        {
            if (arrayRazas[i].isEmpty==0)
            {
            /////flagMascotadeRaza = 0;
            printf("\n\n\n\n-------------------------------------------------");
            indiceInfoPais = buscarIndicePais(arrayPaises, tamanioPaises, arrayRazas[i].pais);
            mostrarUnaRaza (arrayRazas[i], arrayPaises[indiceInfoPais] , 0);
            //////////printf("\n|Raza      || Tamaño || Pais de origen |\n|%-9s || %-6s || %-14s |\n",arrayRazas[i].descripcion, arrayRazas[i].tamanio, arrayRazas[i].pais);
            printf("-----------------------------------------------------\n");


            if (mostrarMascotasSegunRaza (arrayMascotas, tamanioMascotas , arrayRazas[i].idRaza )==-1)
                {
                printf("\nNo hay mascotas con esta raza\n");
                }
            }
        }

        retorno = 0;
    }

    return retorno;
}

int contarMascotasPais(eRaza arrayRazas[], eMascota arrayMascotas[] , int tamanioRazas, int tamanioMascotas)
{
    int i;
    int j;
    int retorno = -1;
    int max;
    int indiceInfoRaza;
    /////char auxPais [20];
    ePaisMascotas arrayPaisMascotas [tamanioRazas];
    char pais[][20]={"Raro", "Tailandia","Alemania","Persia","Belgica", "Argentina" };

    if(arrayRazas != NULL && arrayMascotas != NULL && tamanioRazas >0 && tamanioMascotas>0)
    {



    for (i=0;i<5;i++)
    {
        strcpy(arrayPaisMascotas[i].pais,  pais[i]);
        /////////strcpy(arrayPaisMascotas[i].pais, arrayRazas[i].pais);
        arrayPaisMascotas[i].cantidadMascotas = 0;
    }


    for (i=0;i<tamanioMascotas;i++)
    {
        for(j=0;j<5;j++)
        {
            ///////////
            indiceInfoRaza = buscarIndiceRaza(arrayRazas, tamanioRazas , arrayMascotas[i].idRaza);
            //////////
            if (strcmp(arrayPaisMascotas[j].pais, arrayRazas[indiceInfoRaza].pais)==0)
            {
                arrayPaisMascotas[j].cantidadMascotas++;
            }

        }
    }

    for(i=0 ; i<5 ; i++)
    {
        if(i == 0 || arrayPaisMascotas[i].cantidadMascotas > max)
        {
            max = arrayPaisMascotas[i].cantidadMascotas;
        }
    }


    for(i=0 ; i<5 ; i++)
    {
        if (arrayPaisMascotas[i].cantidadMascotas == max)
        {
            printf("\n El pais %s tiene la mayor representacion en la veterinaria con %d animales registrados", arrayPaisMascotas[i].pais, arrayPaisMascotas[i].cantidadMascotas);
        }
    }

    retorno = 0;
}


return retorno;

}

int mascotasPorCodtel (eMascota arrayMascotas [], eRaza arrayRazas [], ePais arrayPaises[], int tamanioMascotas, int tamanioRazas, int tamanioPaises)
{
    int retorno = -1;
    int i;
    int indicePais;
    int indiceRaza;
    int indicePaisj;
    int indiceRazaj;
    eMascota auxMascota;

    if (arrayMascotas != NULL && arrayRazas != NULL && arrayPaises != NULL)
    {

    for (i=0;i<tamanioMascotas-1;i++)
    {
        if (arrayMascotas[i].isEmpty == 0 && arrayMascotas[i+1].isEmpty == 0)
        {
            indiceRaza = buscarIndiceRaza (arrayRazas, tamanioRazas, arrayMascotas[i].idRaza);
            indicePais = buscarIndicePais (arrayPaises, tamanioPaises, arrayRazas[indiceRaza].pais);
            indiceRazaj = buscarIndiceRaza (arrayRazas, tamanioRazas, arrayMascotas[i+1].idRaza);
            indicePaisj = buscarIndicePais (arrayPaises, tamanioPaises, arrayRazas[indiceRazaj].pais);
            if (arrayPaises[indicePais].codigoTelefonico < arrayPaises[indicePaisj].codigoTelefonico)
            {
            auxMascota = arrayMascotas[i];
            arrayMascotas[i] = arrayMascotas[i+1];
            arrayMascotas[i+1] = auxMascota;
        }
        }

    }


    printf("\n Nombre     || Raza       || Cod Telefonico |");
    for (i=0;i<tamanioMascotas;i++)
    {
        if(arrayMascotas[i].isEmpty == 0){
        indiceRaza = buscarIndiceRaza (arrayRazas, tamanioRazas, arrayMascotas[i].idRaza);
        indicePais = buscarIndicePais (arrayPaises, tamanioPaises, arrayRazas[indiceRaza].pais);

        printf("\n %-10s || %-10s || %-4d || ",arrayMascotas[i].nombre, arrayRazas[indiceRaza].descripcion, arrayPaises[indicePais].codigoTelefonico);

        }
    }
    retorno = 0;
}
return  retorno;
}

int borrarRaza(eMascota arrayMascotas [], eRaza arrayRazas [], int tamanioMascotas, int tamanioRazas, int idRaza)
{
    int retorno = -1;
    int i;
    int indiceRaza;

    if (arrayMascotas != NULL && arrayRazas != NULL && tamanioMascotas > 0 && tamanioRazas >0)
    {
        for (i=0; i < tamanioRazas; i++)
        {
            if (arrayRazas[i].isEmpty == 0 && arrayRazas[i].idRaza)
            {
                arrayRazas[i].isEmpty = 1;
            }

        }

        for (i=0; i < tamanioMascotas; i++)
        {
            if (arrayMascotas[i].isEmpty == 0 && arrayMascotas[i].idRaza)
            {
                arrayMascotas[i].isEmpty = 1;
            }

        }
        retorno = 0;
    }

    return retorno;
}




