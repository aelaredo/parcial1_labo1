#include "libreriaRazas.h"
#include "libreriaPaises.h"
#include "utn_getData.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int FormatearRazas (eRaza arrayRazas[], int tamanioRazas)
{
    int retorno = -1;
    int i;

    if (arrayRazas != NULL && tamanioRazas >0)
    {
        for (i=0;i<tamanioRazas;i++)
        {
            arrayRazas[i].isEmpty = 1;
        }
        retorno = 0;
    }
return retorno;
}


int InicializarRazas (eRaza arrayRazas[], int tamanioRazas)
{
    int idRaza[]={1,2,3,4,5,6,7};
    char descripcion[][20]={"Raro", "Siames","Doberman","Persa","Pastor B.", "Pastor A.", "Dogo" };
    char tamanio[][20]={"Raro", "Chico","Grande","Mediano","Grande", "Grande", "Grande" };
    char pais[][20]={"Raro", "Tailandia","Alemania","Persia","Belgica", "Alemania", "Argentina" };
    int retorno = -1;
    int i;

    if (arrayRazas != NULL && tamanioRazas >0)
    {
        for (i=0;i<7;i++)
        {
        arrayRazas[i].idRaza = idRaza[i];
        strcpy(arrayRazas[i].descripcion, descripcion[i]);
        strcpy(arrayRazas[i].tamanio, tamanio[i]);
        strcpy(arrayRazas[i].pais, pais[i]);
        arrayRazas[i].isEmpty = 0;
        }
        retorno = 0;
    }

    return retorno;
}

int emptyIndexRaza (eRaza arrayRazas[], int tamanioRazas)
{
    int i;
    int index = -1;

    for (i=0; i<tamanioRazas;i++)
    {
        if (arrayRazas[i].isEmpty == 1) //////// cuando encontramos un lugar vacio, cortamos la iteracion
        {
            index = i;
            break;
        }
    }
    return index;
}



int altaDeRaza(eRaza arrayRazas[], int tamanioRazas, int idRaza, char pais [])
{
    int indiceVacio;
    int retorno = -1;

    if (arrayRazas != NULL && tamanioRazas > 0)
    {
    indiceVacio = emptyIndexRaza(arrayRazas,tamanioRazas);


    arrayRazas[indiceVacio].idRaza  =  idRaza;
    arrayRazas[indiceVacio].isEmpty = 0;

    printf("\n Indique el nombre de la nueva raza \n ");
    modificarDescripcion(arrayRazas, indiceVacio);

    printf("\n Indique el tamanio de la nueva raza \n ");
    modificarTamanio(arrayRazas, indiceVacio);

    strcpy(arrayRazas[indiceVacio].pais, pais);
    /*
    printf("\n Indique el pais de origen de la nueva raza \n ");
    modificarPais(arrayRazas, indiceVacio);
    */

    retorno = 0;
    }

    return retorno;

}

int modificarDescripcion (eRaza arrayRazas [], int indice)
{
    int retorno = -1;

    if (arrayRazas != NULL)
    {
        char auxDescripcion [20];

        myGets(auxDescripcion, 20);

        while( esSoloLetras(auxDescripcion)==0)
        {
        printf("Error. El nombre de la raza solo admite letras\n");
        myGets(auxDescripcion, 20);
        }

        strcpy(arrayRazas[indice].descripcion, auxDescripcion);
        retorno = 0;
    }

    return retorno;

}

int modificarTamanio (eRaza arrayRazas [], int indice)
{
    int retorno = -1;
    char auxTamanio [20];

    if(arrayRazas != NULL)
    {
        myGets(auxTamanio, 20);

    while (verificarTamanio(auxTamanio)==-1){
        printf("Error. El tamanio solo puede ser chico, mediano o grande\n");
        myGets(auxTamanio, 20);
    }

    strcpy(arrayRazas[indice].tamanio, auxTamanio);
    retorno = 0;
    }

    return retorno;
}

int verificarTamanio (char str[])
{
    int retorno = -1;
    if ((strcmp(str, "Chico")==0) || (strcmp(str, "Mediano")==0) || (strcmp(str, "Grande")==0) || (strcmp(str, "chico")==0) || (strcmp(str, "mediano")==0) || (strcmp(str, "grande")==0))
    {
        retorno = 0;

    }

    return retorno;
}

int modificarPais (eRaza arrayRazas [], int indice)
{
    int retorno = -1;
    char auxPais [20];

    if (arrayRazas != NULL)
    {
    myGets(auxPais, 20);

        while( esSoloLetras(auxPais)==0)
        {
        printf("Error. El pais solo puede ser Tailandia, Alemania ,Persia o Belgica \n");
        myGets(auxPais, 20);
        }

    strcpy(arrayRazas[indice].pais, auxPais);

    retorno = 0;
    }

   return retorno;
}


int mostrarRazas (eRaza arrayRazas[], ePais arrayPaises [], int tamanioRazas, int tamanioPaises, int idFlag)
{
    int retorno = -1;
    int i;
    int flagEncabezado = 0;
    int indicePais;


    if (arrayRazas != NULL && tamanioRazas >0)
    {
        for (i=0;i<tamanioRazas;i++)
        {
            if (flagEncabezado == 0 && idFlag == 1)
            {
                    printf("\n| ID || Raza       || Tamaño     || Pais de origen || Continente      || Cod. Telefonico\n");
                    flagEncabezado = 1;
            } else if (flagEncabezado == 0 )
            {
                printf("\n|| Raza       || Tamaño     || Pais de origen |\n");
            }

            if (arrayRazas[i].isEmpty==0)
            {
                indicePais = buscarIndicePais(arrayPaises, tamanioPaises, arrayRazas[i].pais);
                mostrarUnaRaza (arrayRazas[i],arrayPaises[indicePais], 1);
            }

        }
        retorno = 0;
    }
    return retorno;
}

void mostrarUnaRaza (eRaza razaLocal, ePais paisLocal, int flagID)
{

    if(flagID == 1 && strcmp(razaLocal.descripcion, "Raro")!=0)
    {
        printf(" \n| %-2d || %-10s || %-10s || %-14s || %-14s || %-10d|\n", razaLocal.idRaza, razaLocal.descripcion, razaLocal.tamanio, razaLocal.pais, paisLocal.continente, paisLocal.codigoTelefonico );
    }else if (strcmp(razaLocal.descripcion, "Raro")!=0) {
        printf(" \n| %-10s || %-10s || %-14s || %-14s || %-10d|\n", razaLocal.descripcion, razaLocal.tamanio, razaLocal.pais, paisLocal.continente, paisLocal.codigoTelefonico );
    } else if (flagID == 1 && strcmp(razaLocal.descripcion, "Raro")==0)
    {
    printf(" \n| %-2d || %-10s || %-10s || %-14s |\n", razaLocal.idRaza, razaLocal.descripcion, razaLocal.tamanio, razaLocal.pais);

    } else if (strcmp(razaLocal.descripcion, "Raro")==0)
    {
    printf("\n| %-10s || %-10s || %-14s |\n", razaLocal.descripcion, razaLocal.tamanio, razaLocal.pais);
    }



}


int buscarIndiceRaza(eRaza arrayRazas[], int tamanioRazas, int idRaza)
{
    int i;
    int retorno = -1;

    for (i=0; i<tamanioRazas;i++)
    {
        if (arrayRazas[i].idRaza== idRaza && arrayRazas[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}




