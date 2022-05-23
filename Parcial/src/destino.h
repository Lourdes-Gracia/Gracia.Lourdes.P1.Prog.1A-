/*
 * destino.h
 *
 *  Created on: 12 may. 2022
 *      Author: reyna
 */

#ifndef DESTINO_H_
#define DESTINO_H_

#endif /* DESTINO_H_ */


typedef struct{
    int id;
    char descripcion[25];
    float precio;
}eDestino;

int listarDestinos(eDestino destino[], int tam);
int buscarDestino(eDestino destino[], int tam, int id, int* pIndice);
int cargarDescripcionDestino(eDestino destino[], int tam, int id, char descripcion[]);
int validarDestino(eDestino destino[], int tam, int id);
