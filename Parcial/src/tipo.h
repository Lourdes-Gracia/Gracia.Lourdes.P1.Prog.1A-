/*
 * tipo.h
 *
 *  Created on: 12 may. 2022
 *      Author: reyna
 */

#ifndef TIPO_H_
#define TIPO_H_

#endif /* TIPO_H_ */

typedef struct
{
    int id;
    char descripcion[20];
} eTipo;

int buscarTipo(eTipo tipo[], int tam, int id, int* pIndice);
int validarTipo(eTipo tipo[], int tam, int id);
int listarTipos(eTipo tipo[], int tam);

