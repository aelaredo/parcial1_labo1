#include "libreriaMascotas.h"
#include "libreriaRazasMascotas.h"
#include "libreriaPaises.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn_getData.h"


int FormatearMascotas (eMascota arrayMascotas[], int tamanioMascotas)
{
    int retorno = -1;
    int i;

    if (arrayMascotas != NULL && tamanioMascotas >0)
    {
        for (i=0;i<tamanioMascotas;i++)
        {
            arrayMascotas[i].isEmpty = 1;
        }
        retorno = 0;
    }
return retorno;
}

int InicializarMascotas (eMascota arrayMascotas[], int tamanioMascotas)
{
    int idMascota[]= {1,2,3,4,5};
    int idRaza[]= {4,3,4,2,5};
    char nombre[][50]={"Luna","Sofia","Beto","Francisco","Tobi"};
    int edad[]= {4,3,5,6,1};
    char sexo[]= {'f','f','m','m','m'};
    float peso[]={10.3,11.2,6.5,7.1,5.5,11.1};
    char tipo [][20]={"Gato","Gato","Gato","Perro","Perro"};
    int i;
    int retorno = -1;

    if (arrayMascotas != NULL && tamanioMascotas >0)
    {
        for (i=0;i<5;i++)
        {
        arrayMascotas[i].idMascota = idMascota[i];
        arrayMascotas[i].idRaza = idRaza[i];
        strcpy(arrayMascotas[i].nombre, nombre[i]);
        arrayMascotas[i].edad = edad[i];
        arrayMascotas[i].sexo = sexo[i];
        arrayMascotas[i].peso = peso[i];
        strcpy(arrayMascotas[i].tipo, tipo[i]);
        arrayMascotas[i].isEmpty = 0;
        }
        retorno = 0;
    }

    return retorno;
}

int emptyIndex (eMascota arrayMascotas[], int largo)
{
    int i;
    int index = -1;

    for (i=0; i<largo;i++)
    {
        if (arrayMascotas[i].isEmpty == 1) //////// cuando encontramos un lugar vacio, cortamos la iteracion
        {
            index = i;
            break;
        }
    }
    return index;
}


int estadoArrayMascotas (eMascota arrayMascotas[], int tamanioMascotas)
{
    int i;
    int contadorMascotas = 0;
    int estado = -1;

    if (arrayMascotas != NULL && tamanioMascotas > 0)
    {

        for (i=0;i<tamanioMascotas;i++)
        {
            if (arrayMascotas[i].isEmpty == 0)
            {
                contadorMascotas++;
            }
        }

    }

    estado = tamanioMascotas - contadorMascotas; ///////// esto hace que estado ahora tenga la cantidad espacios libres en el array


    return estado;

}

int buscarIndiceMascota(eMascota arrayMascotas[], int largo, int idMascota)
{
    int i;
    int retorno = -1;

    for (i=0; i<largo;i++)
    {
        if (arrayMascotas[i].idMascota== idMascota)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}


int altaMascota (eMascota arrayMascotas[], int tamanioMascotas, int idRaza, int idMascota)
{

    int retorno = -1;
    int indiceVacio;
    /////char auxNombre [20];
    /////char auxSexo;
    /////char auxTipo [20];

    if (arrayMascotas != NULL && tamanioMascotas > 0){

    indiceVacio = emptyIndex(arrayMascotas,tamanioMascotas);

    arrayMascotas[indiceVacio].idMascota = idMascota;

    arrayMascotas[indiceVacio].idRaza = idRaza;

    arrayMascotas[indiceVacio].isEmpty = 0;

    printf("\n Ingrese el nombre de la mascota\n");
    modificarNombre(arrayMascotas, indiceVacio);

    modificarEdad (arrayMascotas, indiceVacio);

    modificarPeso(arrayMascotas, indiceVacio);

    modificarSexo (arrayMascotas, indiceVacio);

    printf("\n Ingrese el tipo de  mascota\n");
    modificarTipo(arrayMascotas, indiceVacio);


    retorno =0;
    }

    return retorno;
}

int mostrarMascotas (eMascota arrayMascotas[], int tamanioMascotas, int IdFlag)
{
    int retorno = -1;
    int i;


    if (arrayMascotas != NULL && tamanioMascotas > 0){

    printf("\nID||Nombre       || Edad        || Sexo        || Peso    || Tipo |");

       for (i=0;i<tamanioMascotas;i++)
       {

           if (arrayMascotas[i].isEmpty == 0)
           {
               mostrarUnaMascota (arrayMascotas[i], IdFlag);
           }

       }

     retorno = 0;
    }


    return retorno;
}

int borrarMascota(eMascota arrayMascotas[], int tamanioMascota, int idBorrar)
{
    int retorno = -1;
    int i;

    if (arrayMascotas != NULL && tamanioMascota > 0){


    for (i=0;i<tamanioMascota;i++)
    {
        if (arrayMascotas[i].idMascota == idBorrar && arrayMascotas[i].isEmpty == 0)
        {
            printf("\nID ||  Nombre       || Edad        || Sexo       || Peso     || Tipo |");
            mostrarUnaMascota (arrayMascotas[i], 1);
            if (confirmEdit(idBorrar)==1){
                arrayMascotas[i].isEmpty = 1;
            }
        }

    }
    retorno = 0;
    }
return retorno;
}

int mostrarMascotasSegunRaza (eMascota arrayMascotas[], int tamanioMascotas, int idRaza )
{
    int i;
    int retorno=-1;
    int flagEncabezado = 0;



    for (i=0;i<tamanioMascotas;i++)
    {
        if (arrayMascotas[i].idRaza == idRaza && arrayMascotas[i].isEmpty == 0)
        {

                if (flagEncabezado == 0 )
                {
                    printf("\nNombre       || Edad        || Sexo        ||Peso        || Tipo |\n------------------------------------------------------------------");
                    flagEncabezado =1;
                }

            mostrarUnaMascota (arrayMascotas[i], 0);

            //////////printf("\n %-13s || %-4d || %-4c || %s ", arrayMascotas[i].nombre, arrayMascotas[i].edad, arrayMascotas[i].sexo, arrayMascotas[i].tipo);
            retorno = 0;
        }

    }
return retorno;

}

void mostrarUnaMascota (eMascota mascotaLocal, int idFlag)
{
    if (idFlag)
    {
        printf("\n%-2d || %-12s || %-11d || %-11c || %-10.2f || %s ",mascotaLocal.idMascota, mascotaLocal.nombre, mascotaLocal.edad, mascotaLocal.sexo, mascotaLocal.peso, mascotaLocal.tipo);
    }else{
        printf("\n%-12s || %-11d || %-11c || %-10.2f || %s ", mascotaLocal.nombre, mascotaLocal.edad, mascotaLocal.sexo, mascotaLocal.peso, mascotaLocal.tipo);
    }


}


void mascotasPorPeso(eMascota arrayMascotas[], int tamanioMascotas)
{
    int i;
    int j;
    eMascota auxMascota;


    for (i=0;i<tamanioMascotas-1;i++)
    {
        for (j=i+1;j<tamanioMascotas;j++)
        {
            if (arrayMascotas[i].isEmpty == 0 && arrayMascotas[i].peso <= arrayMascotas[j].peso )
            {
                auxMascota = arrayMascotas[i];
                arrayMascotas[i] = arrayMascotas[j];
                arrayMascotas[j] = auxMascota;
            }
        }

    }
    printf("\n\n--------------------------------------------------------------------");
    printf("\n| Nombre      || Edad        || Sexo        || Peso       || Tipo |");
    printf("\n--------------------------------------------------------------------");
    for (i=0;i<tamanioMascotas;i++)
    {
        if (arrayMascotas[i].isEmpty == 0){
        mostrarUnaMascota (arrayMascotas[i], 0);
        }
    }


}



int modificarMascota (eMascota arrayMascotas [], int indiceModificar, int opcion)
{

    int retorno = -1;

    if (arrayMascotas != NULL ){

    switch (opcion)
    {
    case 1:
        printf("Ingrese el nuevo nombre\n");
        modificarNombre(arrayMascotas, indiceModificar);
        break;
    case 2:
        modificarEdad(arrayMascotas, indiceModificar);
        break;
    case 3:
        modificarSexo(arrayMascotas, indiceModificar);
        break;
    case 4:
        modificarPeso(arrayMascotas, indiceModificar);
        break;
    case 5:
         printf("Ingrese el nuevo tipo\n");
        modificarTipo(arrayMascotas, indiceModificar);
        break;
    }

    retorno = 0;
}

return retorno;

}



int modificarNombre (eMascota arrayMascotas [], int indice)
{
    int retorno = -1;

    char auxNombre [20];
    if (arrayMascotas != NULL)
    {
    myGets(auxNombre, 20);

    while( esSoloLetras(auxNombre)==0)
    {
    printf("Error. El nombre solo admite letras\n");
    myGets(auxNombre, 20);
    }



    strcpy(arrayMascotas[indice].nombre, auxNombre);
    retorno = 0;
    }

return retorno;
}

int modificarTipo (eMascota arrayMascotas [], int indice)
{
    int retorno = -1;
    char auxTipo [20];
if (arrayMascotas != NULL)
    {
    myGets(auxTipo, 20);
    while (verificarTipo(auxTipo)==-1){
        printf("Error. El tipo solo puede ser perro, gato o raro\n");
        myGets(auxTipo, 20);
    }
    strcpy(arrayMascotas[indice].tipo, auxTipo);
    retorno = 0;
    }

    return retorno;
}


int verificarTipo (char str[])
{
    int retorno = -1;
    if ((strcmp(str, "Perro")==0) || (strcmp(str, "perro")==0) || (strcmp(str, "Gato")==0) || (strcmp(str, "gato")==0) || (strcmp(str, "Raro")==0) || (strcmp(str, "raro")==0))
    {
        retorno = 0;
    }

    return retorno;
}

int modificarEdad (eMascota arrayMascotas [], int indice)
{
    int retorno = -1;
    if (arrayMascotas != NULL)
    {
    getNumero(&arrayMascotas[indice].edad , "\n ingrese la edad de su mascota\n" , "\n edad no valida" , 0 , 100 , 10 );
    retorno = 0;
    }

    return retorno;
}

int modificarPeso (eMascota arrayMascotas [], int indice)
{
    int retorno = -1;
    if (arrayMascotas != NULL){
    getNumeroFlotante(&arrayMascotas[indice].peso,"\n ingrese el peso de su mascota\n", "\n peso no valido", 0, 200, 10);
    retorno = 0;
    }

    return retorno;
}

int modificarSexo (eMascota arrayMascotas [], int indice)
{
    int retorno = -1;
    char auxSexo;
    if (arrayMascotas != NULL){
    auxSexo = getChar("\n Ingrese el sexo de la mascota","\n Solo se permite F o M");
    arrayMascotas[indice].sexo = auxSexo;
    retorno = 0;
    }

    return retorno;
}

