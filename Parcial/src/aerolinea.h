/*
 * aerolinea.h
 *
 *  Created on: 12 may. 2022
 *      Author: reyna
 */


#ifndef AEROLINEA_H_
#define AEROLINEA_H_
#endif /* AEROLINEA_H_ */


typedef struct{
    int id;
    char descripcion[20];
}eAerolinea;

int buscarAerolinea(eAerolinea aerolinea[], int tam, int id, int* pIndice);
int validarAerolinea(eAerolinea aerolinea[], int tam, int id);
int cargarDescripcionAerolinea(eAerolinea aerolinea[], int tam, int id, char descripcion[]);
int listarAerolineas(eAerolinea aerolineas[], int tam);
