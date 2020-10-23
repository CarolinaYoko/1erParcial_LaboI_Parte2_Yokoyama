#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "electrodomestico.h"
#include "reparacion.h"
#include "UTN.h"

int initReparacion(eReparacion *list, int len) {
	int i;
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

void harcodeoDatosReparacion(eReparacion *list, int tam, int *idReparaciones) {

	*idReparaciones = 5;
	int id[5] = { 1, 2, 3, 4, 5 };
	int serie[5] = { 123456, 7891022, 78909, 392022, 223322 };
	int idServicio[5] = { 20000, 20003, 20001, 20000, 20000 };
	int idCliente[5] = { 3, 4, 3, 5, 5 };
	eFecha modelo[5] = { { 20, 03, 2019 }, { 20, 06, 2020 }, { 14, 07, 2019 }, {
			30, 01, 2020 }, { 16, 10, 2020 } };
	int isEmpty[5] = { 1, 1, 1, 1, 1 };

	for (int i = 0; i < 5; ++i) {
		list[i].id = id[i];
		list[i].serie = serie[i];
		list[i].idServicio = idServicio[i];
		list[i].idCliente = idCliente[i];
		list[i].fecha = modelo[i];
		list[i].isEmpty = isEmpty[i];

	}

}

int hardcodearReparaciones(eReparacion *listaReparacion, int largoReparacion,
		int cantidad) {
	int vContador = 0;
	int vRetorno = -1;
	int i;

	if (listaReparacion != NULL && largoReparacion > 0 && cantidad > 0
			&& cantidad <= largoReparacion && cantidad < 11) {
		eReparacion
		listaAuxiliar[] =
		{

			{	1,123456,20001,1, {20,1,2018},1},
			{	2,700700,20000,4, {10,7,2019},1},
			{	3,123456,20002,4, {12,5,2020},1},
			{	4,700700,20000,3, {24,6,2019},1},
			{	5,123456,20003,8, {17,11,2018},1},
			{	6,400400,20002,4, {19,12,2019},1},
			{	7,123456,20001,1, {20,5,2013},1},
			{	8,400400,20003,2, {26,10,2017},1},
			{	9,300300,20003,7, {20,8,2013},1},
			{	10,123456,20000,5, {20,5,2013},1}
		};

		for (i = 0; i < cantidad; i++) {
			listaReparacion[i] = listaAuxiliar[i];
			vContador++;
		}
		vRetorno = vContador;
	}

	return vRetorno;
}

int findReparacionById(eReparacion *list, int len, int id) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && id > 0) {

		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == TRUE) {
				continue;
			} else if (list[i].id == id) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int printReparaciones(eReparacion *list, int len, eServicio *listaServicio,
		int lenServ) {
	int i;
	int retorno = -1;
	char bufferDescripcion[26];

	if (list != NULL && len > 0) {

		printf("\n\t| %5s | %11s | %11s | %20s | %10s |\n", "ID", "Serie",
				"ID-Servicio", "Descripcion Serie", "Fecha");

		for (i = 0; i < len; i++) {

			if (list[i].isEmpty == FALSE
					&& cargarDescServicio(list[i].idServicio, listaServicio,
							lenServ, bufferDescripcion) == 0) {

				printf("\t| %5d | %11d | %11d | %20s | %2d/%2d/%4d |\n",
						list[i].id, list[i].serie, list[i].idServicio,
						bufferDescripcion, list[i].fecha.dia, list[i].fecha.mes,
						list[i].fecha.anio);
			}
		}
		retorno = 0;
	}

	return retorno;
}

int printReparacion(eReparacion *list, int len, eServicio *listaServicio,
		int lenServ, int id) {

	int retorno = -1;
	int indice;
	char bufferDescripcion[26];

	if (list != NULL && len > 0) {
		indice = findReparacionById(list, len, id);
		printf("\n\t| %5s | %11s | %11s | %20s | %10s |\n", "ID", "Serie",
				"ID-Servicio", "Descripcion Serie", "Fecha");

		if (list[indice].isEmpty == FALSE
				&& cargarDescServicio(list[indice].idServicio, listaServicio,
						lenServ, bufferDescripcion) == 0) {

			printf("\t| %5d | %11d | %11d | %20s | %2d/%2d/%4d |\n",
					list[indice].id, list[indice].serie,
					list[indice].idServicio, bufferDescripcion,
					list[indice].fecha.dia, list[indice].fecha.mes,
					list[indice].fecha.anio);
			retorno = 0;
		}
	}
	return retorno;
}

int addReparacion(eReparacion *list, int len, int id, eElectrodomestico *lista,
		int lenElec, eServicio *servicios, int lenServ, eMarca *listaMarca,
		int lenMarca, eCliente *listaCliente, int tamCliente) {
	int retorno = -1;
	int i = 0;

	if (list != NULL && len > 0) {

		for (i = 0; i < len; i++) {

			if (list[i].isEmpty == TRUE) {

				if (pedirElectrodomesticoporSerie(&list[i].serie,
						"\nIngrese la serie del electrodomestico: ",
						"\nLa serie ingresada no es valida. Reingrese\n", lista,
						lenElec, listaMarca, lenMarca, 2) == 0
						&& pedirServicioporId(&list[i].idServicio,
								"\nIngrese el ID del servicio a efectuar: ",
								"\nEl ID ingresado no es valido. Reingrese",
								servicios, lenServ, 2) == 0
						&& pedirClienteporId(&list[i].idCliente,
								"\nIngrese el ID del cliente: \n",
								"\nEl ID ingresado no es valido. Reingrese",
								listaCliente, tamCliente, 2) == 0
						&& utn_getFecha(&list[i].fecha.dia, &list[i].fecha.mes,
								&list[i].fecha.anio,
								"\nIngrese la fecha de ingreso: ",
								"\nLa fecha ingresada no es valida. Reingrese",
								2) == 0) {
					list[i].id = id;
					list[i].isEmpty = FALSE;
					retorno = 0;
					break;
				} else {
					printf("Error en la carga. Reintente \n");
					retorno = -1;
					system("pause");
				}
			}
		}
	}
	if (retorno == -1) {
		printf("No hay lugar disponible");
	}

	return retorno;
}

int updateReparacion(eReparacion *list, int len, eServicio *listaServicio,
		int lenServ) {
	int retorno = -1;
	int resultado;
	int id;
	int menu;
	int indice;

	resultado = utn_getNumeroIntMin(&id, "Ingrese el ID de la reparacion: ",
			"El ID no es valido. Reingrese", 1, 2);
	indice = findReparacionById(list, len, id);

	if (list != NULL && len > 0 && resultado == 0 && indice != -1) {

		utn_getNumeroInt(&menu,
				"\nIngrese el campo a modificar: \n\n1-Serie \n2-IdServicio \n3-Fecha \n\nIngrese una opcion: ",
				"La opcion no es valida. Reingrese\n", 1, 3, 2);

		switch (menu) {
		case 1:

			if (utn_getNumeroIntMin(&list[indice].serie, "Ingrese la serie: ",
					"La serie ingresado no es valido. Reingrese", 1, 2)	== 0) {
				retorno = 0;
			} else {
				retorno = -1;
			}
			break;
		case 2:
			if (utn_getNumeroIntMin(&list[indice].idServicio,
					"Ingrese el ID del servicio: ",
					"La ID no es valido. Reingrese\n", 20000, 2) == 0) {
				retorno = 0;
			} else {
				retorno = -1;
			}
			break;
		case 3:
			if (utn_getFecha(&list[indice].fecha.dia, &list[indice].fecha.mes,
					&list[indice].fecha.anio, "Ingrese una fecha: ",
					"La fecha ingresada no es valida. Reingrese", 2) == 0) {
				retorno = 0;
			} else {
				retorno = -1;
			}
			break;

		}
		printReparacion(list, len, listaServicio, lenServ, id);
		retorno = 0;
	}
	return retorno;
}

int removeReparacion(eReparacion *list, int len) {
	int retorno = -1;
	int id;
	int indice;

	utn_getNumeroIntMin(&id, "\nIngrese el ID a eliminar: ",
			"\nEl ID no es valido. Reingrese", 1, 2);
	indice = findReparacionById(list, len, id);

	if (list != NULL && len > 0 && indice > 0) {
		list[indice].isEmpty = TRUE;
		retorno = 0;
	}
	return retorno;
}

