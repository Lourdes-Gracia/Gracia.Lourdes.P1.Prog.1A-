/*
 * vuelo.h
 *
 *  Created on: 12 may. 2022
 *      Author: reyna
 */

#ifndef VUELO_H_
#define VUELO_H_



#endif /* VUELO_H_ */

typedef struct{
    int id;
    int idAvion;
    int idDestino;
    int isEmpty;
    eFecha fecha;
}eVuelo;

int inicializarVuelo(eVuelo vec[], int tam);
int altaVuelo(eVuelo vuelo[], int tamV, eAvion avion[], int tamA, eAerolinea aerolineas[], int tamAe, eDestino destino[], int tamD, int* id);
int listarVuelos(eVuelo vuelo[], int tamV, eAvion avion[], int tamA, eAerolinea aerolinea[], int tamS, eDestino destino[], int tamD);
int buscarVueloLibre(eVuelo vec[], int tam, int* pIndex);
