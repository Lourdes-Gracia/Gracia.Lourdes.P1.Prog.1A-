/*
 * avion.c
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

int menu()
{
    int opcion;
    system("cls");
    printf("     *** Menu 1er Parcial ***\n");
    printf("1- Alta Avion\n");
    printf("2- Modificar Avion\n");
    printf("3- Baja Avion\n");
    printf("4- Listar Aviones\n");
    printf("5- Listar Aerolineas\n");
    printf("6- Listar Tipos\n");
    printf("7- Listar Destinos\n");
    printf("8- Alta Vuelo\n");
    printf("9- Listar Vuelos\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;

}
int altaAvion(eAvion avion[], int tamav, eAerolinea aerolinea[], int tama, eTipo tipo, int tamT, int* proximoIdAvion)
{
	int todoOk = 0;
	    int indice;
	    eAvion nuevoAvion;

        if(avion != NULL && tamav > 0 && proximoIdAvion != NULL)
	    {
	        if(buscarAvionLibre(avion, tamav, &indice))
	        {

	            if(indice == - 1)
	            {
	                printf("No hay lugar en el sistema\n");
	            }
	            else
	            {

	                printf("Ingrese el id de la Aerolinea (1000, 1001, 1002, 1003) :");
   	                scanf("%d", &nuevoAvion.idAerolinea);
   	                while( !validarAerolinea(aerolinea , tama, nuevoAvion.idAerolinea))
  	                {
  	                    printf("Id invalido. Ingrese el id de la Aerolinea (1000, 1001, 1002, 1003) :");
   	                    scanf("%d", &nuevoAvion.idAerolinea);
  	                }

   	             printf("Ingrese el id del tipo de avion (5000, 5001, 5002, 5003) :");
   	             scanf("%d", &nuevoAvion.idAerolinea);
   	             while( !validarTipo( tipo.id , tama, nuevoAvion.idTipo))
   	                   {
   	                     printf("Id invalido. Ingrese el id del tipo de avion: (5000, 5001, 5002, 5003) : ");
   	                    scanf("%d", &nuevoAvion.idTipo);
   	                  }

	                printf("Ingrese capacidad (entre 10 y 300");
	                scanf("%d", &nuevoAvion.capacidad);
	                while( !(nuevoAvion.capacidad >= 10 && nuevoAvion.capacidad  <= 300) )
	                 {
	                      printf("Capacidad invalida, reingrese capacidad (entre 10 y 300");
	                      scanf("%d", &nuevoAvion.capacidad);
	                  }




	                nuevoAvion.isEmpty = 0;
	                nuevoAvion.id = *proximoIdAvion;
	                *proximoIdAvion = *proximoIdAvion + 1;
	                avion[indice] = nuevoAvion;
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

int buscarAvionLibre(eAvion vec[], int tam, int* pIndex)
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

int menuModificarAvion()
{
    int opcion;
    printf("     *** Campos a modificar ***\n");
    printf("1- Tipo\n");
    printf("2- Capacidad\n");
    printf("3- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
int modificarAvion(eAvion avion[], int tamav, eAerolinea aerolineas[], int tama)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char salir = 'n';
    //char auxCad[100];
    //eFecha fecha;
    if(avion != NULL && tamav > 0)
    {
        listarAviones(avion, tamav, aerolineas, tama);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        if( buscarAvion(avion, tamav, legajo, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un empleado con legajo %d\n", legajo);
            }
            else
            {
                mostrarAvion(avion[indice], aerolineas, tama);


                do
                {
                    switch(menuModificarAvion())
                    {

                        case 1:
                        printf("Ingrese nuevo Id: ");
                        scanf("%d", &avion[indice].id);
                        printf("Se ha modificado el Id\n");
                        break;

                    case 2:
                        printf("Ingrese nueva capacidad: ");
                        scanf("%d", &avion[indice].capacidad);
                        printf("Se ha modificado la capacidad\n");

                        break;
                    case 3:
                        salir = 's';
                        break;
                    }
                    system("pause");

                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar avion\n");
        }

        todoOk = 1;
    }
    return todoOk;
}
int listarAviones(eAvion vec[], int tam, eAerolinea aerolinea[], int tama)
{
    int todoOk = 0;
    int flag = 0;
    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf("          *** Listado de Aviones ***\n\n");
        printf(" IdAvion     IdAerolinea     IdTipo     Capacidad \n");
        printf("------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarAvion(vec[i], aerolinea, tama);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay aviones en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}
int buscarAvion(eAvion vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty == 0 &&  vec[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
int mostrarAvion(eAvion avion, eAerolinea aerolinea[], int tam)
{
    int todoOk = 0;
   char capacidad[20];

    if(aerolinea != NULL && tam > 0)
    {
        cargarDescripcionAerolinea( aerolinea, tam, avion.idAerolinea, capacidad);
        printf("  %4d      %4d       %4d      %4s \n",
               avion.id,
			   avion.idAerolinea,
			   avion.idTipo,
               capacidad
              );
        todoOk = 1;
    }
    return todoOk;
}
int bajaAvion(eAvion avion[], int tamav,eAerolinea aerolineas[], int tama)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(avion != NULL && tamav > 0)
    {
    	listarAviones(avion, tamav, aerolineas, tama);
        printf("Ingrese Id: ");
        scanf("%d", &id);
        if( buscarAvion(avion, tamav, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un avion con el Id %d\n", id);
            }
            else
            {
            	mostrarAvion(avion[indice], aerolineas, tama);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    avion[indice].isEmpty = 1;
                    printf("Baja realizada con el exito!!!\n");
                    todoOk = 1;
                }
            }

        }
        else
        {
            printf("Ocurrio un problema al buscar avion\n");
        }

        todoOk = 1;
    }
    return todoOk;
}
int ordenarAvionPorAerolineaYCapacidad(eAvion vec[], int tam)
{
     int todoOk = 0;
	 eAvion auxAvion;
	    if (vec != NULL && tam > 0)
	    {
		for (int i = 0; i < tam - 1; i++)
		{
			for (int j = i + 1; j < tam; j++)
			{
				  if( ((vec[i].idAerolinea == vec[j].idAerolinea) && (vec[i].capacidad > vec[j].capacidad))
				   || ((vec[i].idAerolinea != vec[j].idAerolinea) && (vec[i].idAerolinea > vec[j].idAerolinea) ))
				                {
				                    auxAvion = vec[i];
				                    vec[i] = vec[j];
				                    vec[j] = auxAvion;
				                }
				else
				 {

				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
int inicializarAvion(eAvion vec[], int tam)
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
