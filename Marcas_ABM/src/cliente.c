#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "UTN.h"

#define LENCLIENTE 10

int findClienteById(eCliente *list, int len, int id) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && id > 0) {

		for (i = 0; i < len; i++) {
			if (list[i].id == id) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int hardcodearCliente(eCliente *list, int largoCliente, int cantidad) {
	int vContador = 0;
	int vRetorno = -1;
	int i;

	if (list != NULL && largoCliente > 0 && cantidad > 0
			&& cantidad <= largoCliente && cantidad < 11) {
		eCliente
		listaAuxiliar[] =
		{

			{	1,"Maria","Perez"},
			{	2,"Juan","Martinez"},
			{	3,"Dario","Gomez"},
			{	4,"Candela","Cuda"},
			{	5,"Marina","Arias"},
			{	6,"Carolina","Yokoyama"},
			{	7,"Nicolas","Gushiken"},
			{	8,"Cristina","Ramos"},
			{	9,"Daniel","Tamashiro"},
			{	10,"Lydia","Morales"}
		};

		for (i = 0; i < cantidad; i++) {
			list[i] = listaAuxiliar[i];
			vContador++;
		}
		vRetorno = vContador;
	}

	return vRetorno;
}

void harcodeoDatosCliente(eCliente *list, int tam, int *idCliente) {

	*idCliente = 5;
	int id[5] = { 1, 2, 3, 4, 5 };
	char nombre[][51] = { "Maria", "Juan", "Dario", "Candela", "Marta" };
	char apellido[][51] = { "Perez", "Martinez", "Gomez", "Cuda", "Arias" };

	for (int i = 0; i < 5; ++i) {
		list[i].id = id[i];
		strncpy(list[i].nombre, nombre[i], 51);
		strncpy(list[i].apellido, apellido[i], 51);
	}
}

int printClientes(eCliente *list, int len) {
	int i;
	int retorno = -1;

	if (list != NULL && len > 0) {

		printf("\n\t| %5s | %15s | %15s |\n", "ID", "Nombre", "Apellido");

		for (i = 0; i < len; i++) {

			printf("\t| %5d | %15s | %15s |\n", list[i].id, list[i].nombre,
					list[i].apellido);
		}
		retorno = 0;
	}

	return retorno;
}

int printCliente(eCliente *list, int len, int id) {

	int retorno = -1;
	int indice;
	if (list != NULL && len > 0) {

		indice = findClienteById(list, len, id);

		printf("\n\t| %5s | %15s | %15s |\n", "ID", "Nombre", "Apellido");

		printf("\t| %5d | %15s | %15s |\n", list[indice].id,
				list[indice].nombre, list[indice].apellido);

		retorno = 0;
	}
	return retorno;
}

int validarIdCliente(eCliente *list, int len, int id) {

	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && id > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].id == id) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int pedirClienteporId(int *id, char *mensaje, char *mensajeError, eCliente *list, int len, int reintentos) {
	int retorno = -1;
	int idBuffer;

	if (id != NULL && list != NULL && len > 0 && reintentos >= 0) {

		do {
			if (printClientes(list, LENCLIENTE) == 0 && utn_getNumeroIntMin(&idBuffer, mensaje, mensajeError, 1, 2)==0 && validarIdCliente(list, len, idBuffer)==0) {
				*id = idBuffer;
				retorno = 0;
				break;
			}
			reintentos--;

		} while (reintentos >= 0);
	}
	return retorno;
}

int cargarDescCliente(int id, eCliente *list, int len, char *nombreCliente, char *apellidoCliente) {

	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && nombreCliente != NULL && apellidoCliente != NULL ) {

		for (i = 0; i < len; i++) {
			if (list[i].id == id) {
				strncpy(nombreCliente, list[i].nombre, 51);
				strncpy(apellidoCliente, list[i].apellido, 51);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


