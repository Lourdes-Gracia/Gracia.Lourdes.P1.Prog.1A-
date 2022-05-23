/*
 ============================================================================
 Name        : Parcial.c
 Author      : Lu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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

#define TAMAV 5
#define TAMV 5

#define TAMA 5
#define TAMT 4
#define TAMD 4

int main()
{
    char salir = 'n';

    setbuf(stdout, NULL);
    int proximoIdAvion = 001;
    int proximoIdVuelo = 1;

   eAvion lista[TAMAV];
   eVuelo listaV[TAMV];
   eAerolinea aerolineas[TAMA] =
   {
		   {1000, "Lan"},
		   {1001, "Iberia"},
		   {1002, "Norwegian"},
		   {1003, "American"},
		   {1004, "Austral"}
   };
   eTipo tipos[TAMT] =
      {
   		   {5000, "Jet"},
   		   {5001, "Helice"},
   		   {5002, "Planeador"},
   		   {5003, "Carga"},
      };
   eDestino destinos[TAMD] =
      {
   		   {20000, "Calafate", 22250},
   		   {20001, "Miami", 103000},
   		   {20002, "Madrid", 84400},
   		   {20003, "Amsterdam", 95600},
      };

   inicializarAvion(lista, TAMAV);
   inicializarVuelo(listaV, TAMV);

do {
	switch(menu())
	{

	case 1:

	      if( altaAvion(lista, TAMAV, aerolineas, TAMA, tipos, TAMT, &proximoIdAvion))
	            {
	                printf("Avion agregado con exito!!!\n");
	            }
	            else
	            {
	                printf("Problema al hacer el alta de avion\n");
	            }

		    break;
	case 2:
	    if( modificarAvion(lista, TAMAV, aerolineas, TAMA) == 0)
	     {
           printf("Problema al hacer la modificacion del avion\n");
	     }
			break;
	case 3:
		if( bajaAvion(lista, TAMAV, aerolineas, TAMA) == 0)
        {
            printf("Problema al hacer la baja del avion \n");
        }
			break;
	case 4:

		 //ordenarAvionPorAerolineaYCapacidad(lista, TAMAV);
		listarAviones(lista, TAMAV, aerolineas, TAMA);

		break;
	case 5:
		listarAerolineas(aerolineas, TAMA);

			break;
	case 6:
		listarTipos(tipos, TAMT);
			break;
	case 7:
		listarDestinos(destinos, TAMD);
			break;
	case 8:
        if(altaVuelo(listaV, TAMV, lista, TAMAV, aerolineas, TAMA, destinos, TAMD, &proximoIdVuelo))
           {
               printf("Vuelo agregado con exito!!!\n");
           }
           else
           {
               printf("Problema al hacer el alta de Vuelo\n");
           }

           break;
	case 9:
		 listarVuelos(listaV, TAMV, lista, TAMAV, aerolineas, TAMA, destinos, TAMD);
			break;
    case 10:
           salir = 's';
           break;
       }
       system("pause");

   }
   while(salir != 's');

	return 0;
}
