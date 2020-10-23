#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "electrodomestico.h"
#include "UTN.h"

int initElectrodomestico(eElectrodomestico *list, int len) {
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

void harcodeoDatosElectrodomestico(eElectrodomestico *list, int tam,
		int *idElectrodomesticos) {

	*idElectrodomesticos = 3;
	int id[3] = { 1, 2, 3 };
	int serie[3] = { 123456, 7891022, 80090 };
	int idMarca[3] = { 1000, 1001, 1000 };
	int modelo[3] = { 2020, 2000, 1999 };
	int isEmpty[3] = { 1, 1, 1 };

	for (int i = 0; i < 3; ++i) {
		list[i].id = id[i];
		list[i].serie = serie[i];
		list[i].idMarca = idMarca[i];
		list[i].modelo = modelo[i];
		list[i].isEmpty = isEmpty[i];
	}
}

int hardcodearElectrodomesticos(eElectrodomestico *list,
		int largoElectodomestico, int cantidad) {
	int vContador = 0;
	int vRetorno = -1;
	int i;

	if (list != NULL && largoElectodomestico > 0 && cantidad > 0
			&& cantidad <= largoElectodomestico && cantidad < 11) {
		eElectrodomestico listaAuxiliar[] = {

		{ 1, 123456, 1002, 2019, 1 }, { 2, 700700, 1000, 2020, 1 }, { 3, 797979,
				1003, 2018, 1 }, { 4, 898989, 1001, 2020, 1 }, { 5, 454545,
				1004, 2019, 1 }, { 6, 400400, 1002, 2018, 1 }, { 7, 232323,
				1004, 2020, 1 }, { 8, 121212, 1000, 2019, 1 }, { 9, 300300,
				1002, 2018, 1 }, { 10, 909090, 1000, 2020, 1 } };

		for (i = 0; i < cantidad; i++) {
			list[i] = listaAuxiliar[i];
			vContador++;
		}
		vRetorno = vContador;
	}

	return vRetorno;
}

int findElectrodomesticoById(eElectrodomestico *list, int len, int id) {
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

int findElectrodomesticoBySerie(eElectrodomestico *list, int len, int serie) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && serie > 0) {

		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == TRUE) {
				continue;
			} else if (list[i].serie == serie) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int printElectrodomesticos(eElectrodomestico *list, int len, eMarca *lista,
		int tamLista) {
	int i;
	int retorno = -1;
	int paso = 0;
	char descripcion[21];

	if (list != NULL && len > 0) {

		for (i = 0; i < len; i++) {
			if (paso == 0) {
				paso = 1;
				printf("\n\t| %5s | %8s | %8s | %20s |\n", "ID", "Serie",
						"Modelo", "Descripcion Marca");
			}

			if (cargarDescMarca(list[i].idMarca, lista, tamLista, descripcion)
					== 0 && list[i].isEmpty == FALSE) {

				printf("\t| %5d | %8d | %8d | %20s |\n", list[i].id,
						list[i].serie, list[i].modelo, descripcion);
			}

		}
		retorno = 0;
	} else {
		printf("No hay electrodomesticos que mostrar");
	}

	return retorno;
}

int printElectrodomestico(eElectrodomestico *list, int len, int id) {

	int retorno = -1;
	int indice;
	if (list != NULL && len > 0) {
		indice = findElectrodomesticoById(list, len, id);

		printf("\n\t| %5s | %8s | %8s | %8s |\n", "ID", "Serie", "ID-Marca",
				"Modelo");

		printf("\t| %5d | %8d | %8d | %8d |\n", list[indice].id,
				list[indice].serie, list[indice].idMarca, list[indice].modelo);
		retorno = 0;
	}
	return retorno;
}

int addElectrodomestico(eElectrodomestico *list, int len, eMarca *listaMarca,
		int lenMarca, int id) {
	int retorno = -1;
	int i = 0;

	if (list != NULL && len > 0) {

		for (i = 0; i < len; i++) {

			if (list[i].isEmpty == TRUE) {
				if (utn_getNumeroIntMin(&list[i].serie, "Ingrese la serie: ",
						"La serie ingresada no es valido. Reingrese", 1, 2) == 0
						&& pedirMarcaporId(&list[i].idMarca,
								"Ingrese el ID de la marca: ",
								"El ID ingresado no es valido. Reingrese",
								listaMarca, lenMarca, 2) == 0
						&& utn_getNumeroInt(&list[i].modelo, "Ingrese modelo: ",
								"El modelo ingresado no es valido. Reingrese",
								1990, 2020, 2) == 0) {

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

int updateElectrodomestico(eElectrodomestico *list, int len) {
	int retorno = -1;
	int resultado;
	int id;
	int menu;
	int indice;

	resultado = utn_getNumeroIntMin(&id, "Ingrese el ID del electrodomestico: ",
			"El ID no es valido. Reingrese", 1, 2);
	indice = findElectrodomesticoById(list, len, id);

	if (list != NULL && len > 0 && resultado == 0 && indice != -1) {

		utn_getNumeroInt(&menu,
				"\nIngrese el campo a modificar: \n\n1-Serie \n2-Modelo \n\nIngrese una opcion: ",
				"La opcion no es valida. Reingrese\n", 1, 2, 2);

		switch (menu) {
		case 1:
			if (utn_getNumeroIntMin(&list[indice].serie, "Ingrese la serie: ",
					"La serie ingresado no es valido. Reingrese", 1, 2)
					== 0) {
				retorno = 0;
			} else {
				retorno = -1;
			}
			break;
		case 2:
			if (utn_getNumeroInt(&list[indice].modelo, "Ingrese el modelo: ",
					"El modelo ingresado no es valido. Reingrese\n", 1990, 2020,
					2) == 0) {
				retorno = 0;
			} else {
				retorno = -1;
			}
		}
		printElectrodomestico(list, len, id);
		retorno = 0;
	}
	return retorno;
}

int removeElectrodomestico(eElectrodomestico *list, int len) {
	int retorno = -1;
	int id;
	int indice;

	utn_getNumeroInt(&id, "\nIngrese el ID a eliminar: ",
			"\nEl ID no es valido. Reingrese", 1, 99999, 2);
	indice = findElectrodomesticoById(list, len, id);

	if (list != NULL && len > 0 && indice > 0) {
		list[indice].isEmpty = TRUE;
		retorno = 0;
	}
	return retorno;
}

int sortElectrodomestico(eElectrodomestico *list, int len, int order) {
	int retorno = -1;
	int i;
	int j;
	eElectrodomestico aux;

	if (list != NULL && len > 0) {

		switch (order) {
		case 0: //Orden ascendente
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++) {

					if (list[i].modelo > list[j].modelo) {
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					} else if (list[i].modelo == list[j].modelo
							&& list[i].serie > list[j].serie) {
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
			retorno = 0;
			break;
		case 1: //Orden descendente
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++) {

					if (list[i].modelo < list[j].modelo) {
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					} else if (list[i].modelo == list[j].modelo
							&& list[i].serie < list[j].serie) {
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int hayAltasElectrodomesticos(eElectrodomestico *list, int len) {
	int i;
	int retorno = 0;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE) {
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int validarSerieElectrodomestico(eElectrodomestico *list, int len, int serie) {

	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && serie > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].serie == serie) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int pedirElectrodomesticoporSerie(int *serie, char *mensaje, char *mensajeError,
		eElectrodomestico *list, int len, eMarca *lista, int lenMarca,
		int reintentos) {
	int retorno = -1;
	int serieBuffer;

	if (serie != NULL && list != NULL && len > 0 && reintentos >= 0) {

		do {
			if (printElectrodomesticos(list, len, lista, lenMarca) == 0
					&& utn_getNumeroIntMin(&serieBuffer, mensaje, mensajeError,
							1, 2) == 0
					&& validarSerieElectrodomestico(list, len, serieBuffer)
							== 0) {
				*serie = serieBuffer;
				retorno = 0;
				break;
			}
			reintentos--;
			printf(mensajeError);

		} while (reintentos >= 0);
	}
	return retorno;
}
