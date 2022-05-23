/*
 * vuelo.c
 *
 *  Created on: 12 may. 2022
 *      Author: reyna
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "aerolinea.h"
#include "avion.h"
#include "destino.h"
#include "fecha.h"
#include "vuelo.h"
#include "tipo.h"

int inicializarVuelo(eVuelo vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaVuelo(eVuelo vuelo[], int tamV, eAvion avion[], int tamA, eAerolinea aerolineas[], int tamAe, eDestino destino[], int tamD, int* id){
    int todoOk = 0;
    int indice;
    eVuelo nuevoVuelo;
    eFecha fecha;

    if(vuelo != NULL && avion != NULL && aerolineas != NULL && destino != NULL && id != NULL && tamV > 0 && tamA > 0 && tamAe > 0 && tamD > 0)
    {

        system("cls");
        printf("       *** Alta Vuelo*** \n");
        printf("-------------------------------------------\n\n");


        if( buscarVueloLibre(vuelo, tamV, &indice) )
        {
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
            	listarAviones(avion, tamA, aerolineas, tamAe);
                printf("Ingrese id avion \n");
                scanf("%d", &nuevoVuelo.idAvion);
                buscarAvion(avion, tamA, nuevoVuelo.idAvion, &indice);

                while( indice == -1){
                printf("Vuelo invalido. Ingrese id avion\n");
                scanf("%d", &nuevoVuelo.idAvion);
                buscarAvion(avion, tamA, nuevoVuelo.idAvion, &indice);
                }

                listarDestinos(destino, tamD);
                printf("Ingrese id destino \n");
                scanf("%d", &nuevoVuelo.idDestino);

                while( !validarDestino(destino, tamD, nuevoVuelo.idDestino )){
                printf("Destino invalido. Ingrese id destino nuevamente \n");
                scanf("%d", &nuevoVuelo.idDestino);
                }

                printf("Ingrese Fecha  dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                nuevoVuelo.fecha = fecha;

                nuevoVuelo.isEmpty = 0;
                nuevoVuelo.id = *id;
                *id = *id + 1;
                vuelo[indice] = nuevoVuelo;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}
int listarVuelos(eVuelo vuelo[], int tamV, eAvion avion[], int tamA, eAerolinea aerolinea[], int tamS, eDestino destino[], int tamD)
{
    int todoOk = 0;
    int flag = 0;
    char descripcion[20];

     if(vuelo != NULL && aerolinea != NULL && avion != NULL && destino != NULL  && tamA > 0 && tamD > 0 && tamS > 0 && tamV> 0)
    {
        system("cls");
        printf("          *** Listado de Vuelos ***\n\n");
        printf("  Id          IdAvion        Destino    Fecha\n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i=0; i < tamA; i++)
        {
            if( !vuelo[i].isEmpty )
            {
                cargarDescripcionDestino(destino, tamD, vuelo[i].idDestino, descripcion);
                printf("   %d     %d      %10s          %02d/%02d/%02d\n", vuelo[i].id, vuelo[i].idAvion, descripcion, vuelo[i].fecha.dia, vuelo[i].fecha.mes, vuelo[i].fecha.anio);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay vuelos en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}
int buscarVueloLibre(eVuelo vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
