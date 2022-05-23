/*
 * tipo.c
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

int buscarTipo(eTipo tipo[], int tam, int id, int* pIndice)
{
    int todoOk = 0;
    if(tipo != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(tipo[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
int validarTipo(eTipo tipo[], int tam, int id)
{
    int esValido = 0;
    int indice;

    buscarTipo(tipo, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int listarTipos(eTipo tipo[], int tam)
{

int todoOk = 0;

    if(tipo != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de Tipos de Avion  ***\n");
        printf("   Id       Descripcion    \n");
        printf("--------------------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d     %10s \n", tipo[i].id, tipo[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}
