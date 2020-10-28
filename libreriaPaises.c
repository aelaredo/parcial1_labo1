#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "libreriaPaises.h"


int InicializarPaises (ePais arrayPaises[], int tamanioPaises)
{
    int retorno = -1;
    if (arrayPaises != NULL && tamanioPaises > 0)
    {
        int i;
        char nombreDePais[][50] = {"Argentina", "Alemania", "Belgica", "Tailandia", "Persia"};
        char continente [][50] = {"America", "Europa", "Europa", "Asia", "Asia"};
        int codigoTelefonico[]= {54, 49, 32, 66, 98};


            for (i = 0; i < tamanioPaises; i++)
            {
            strcpy(arrayPaises[i].nombreDePais, nombreDePais[i]);
            strcpy(arrayPaises[i].continente, continente[i]);
            arrayPaises[i].codigoTelefonico = codigoTelefonico[i];
            }
    retorno = 0;
    }

    return retorno;
}

int mostrarPaises (ePais arrayPaises[], int tamanioPaises)
{
    int retorno = -1;
    int i;
    if (arrayPaises != NULL && tamanioPaises > 0)
    {
        printf("\n| Pais       || Continente || Codigo Telefonico |\n");
        for (i=0;i<tamanioPaises;i++)
        {
            printf(" \n| %-10s || %-10s || %-14d ", arrayPaises[i].nombreDePais, arrayPaises[i].continente, arrayPaises[i].codigoTelefonico );
        }



        retorno = 0;
    }



    return retorno;
}

int buscarIndicePais(ePais arrayPaises[], int tamanioPaises, char paisBuscar[])
{
    int i;
    int retorno = -1;

    for (i=0; i<tamanioPaises;i++)
    {
        if (strcmp (arrayPaises[i].nombreDePais, paisBuscar)==0)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

