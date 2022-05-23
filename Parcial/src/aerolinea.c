/*
 * aerolinea.c
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

int validarAerolinea(eAerolinea aerolinea[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarAerolinea(aerolinea, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}


int buscarAerolinea(eAerolinea aerolinea[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(aerolinea != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(aerolinea[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
int cargarDescripcionAerolinea(eAerolinea aerolinea[], int tam, int id, char descripcion[])
{
	int todoOk = 0;
	int indice;

	    buscarAerolinea(aerolinea,tam, id,&indice);

	    if(descripcion != NULL && indice != -1 )
	    {
	       strcpy(descripcion, aerolinea[indice].descripcion);
	       todoOk = 1;
	    }
	  return todoOk;
	}

int listarAerolineas(eAerolinea aerolineas[], int tam)
{

int todoOk = 0;

    if(aerolineas != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de Aerolineas  ***\n");
        printf("  Id       Descripcion    \n");
        printf("--------------------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d     %10s  \n", aerolineas[i].id, aerolineas[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}
