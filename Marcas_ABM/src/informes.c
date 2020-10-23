/*
 * informes.c
 *
 *  Created on: 18 oct. 2020
 *      Author: Carolina
 */
#define TAM 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"
#include "informes.h"
#include "reparacion.h"
#include "servicio.h"

void MenuInformes(eElectrodomestico *listaElect, int lenElec,
		eCliente *listaClientes, int lenClientes,
		eReparacion *listaReparaciones, int lenReparaciones,
		eServicio *listaServicios, int lenServicio, eMarca *listaMarca,
		int lenMarca) {

	char respuestaContinuar = 'n';
	int respuestaSubMenu;
	int opcion;
	do {
		system("cls");
		respuestaSubMenu =
				utn_getNumeroInt(&opcion,
						"1.Mostrar Electrodomésticos del año(modelo) 2020 \n"
								"2.Mostrar Electrodomésticos de una marca seleccionada \n"
								"3.Mostrar todas las reparaciones efectuadas al Electrodoméstico seleccionado \n"
								"4.SALIR\n"
								"Ingrese una opcion: ",
						"\nLa opcion no es valida. Reingrese \n", 1, 4, 2);

		if (!respuestaSubMenu) {
			switch (opcion) {
			case 1:
				MostrarElec2020(listaElect, lenElec);
				system("pause");
				break;
			case 2:
				MostrarElecDeUnaMarca(listaElect, lenElec, listaMarca,
						lenMarca);
				system("pause");
				break;
			case 3:
				MostrarRepDeElec(listaElect, lenElec, listaMarca, lenMarca,
						listaReparaciones, lenReparaciones);
				system("pause");
				break;
			case 4:
				printf("¿Esta seguro que desea salir?: s/n");
				fflush(stdin);
				scanf("%c", &respuestaContinuar);
				break;
			}

		} else {
			printf("Se terminaron los intentos. Reinicie");
		}
	} while (respuestaContinuar == 'n');

}

int LstReparacionesXcliente(eReparacion *listRep, int lenRep,
		eCliente *listCliente, int lenCliente, eServicio *listServicio,
		int lenServ) {
	int i;
	int j;
	int retorno = -1;
	char bufferDescripcion[26];

	if (listRep != NULL && listCliente != NULL && listServicio != NULL
			&& lenRep > 0 && lenCliente > 0 && lenServ > 0) {

		for (i = 0; i < lenCliente; i++) {

			printf("\nReparaciones de: %s %s \n", listCliente[i].nombre,
					listCliente[i].apellido);
			printf("\t| %10s | %10s | %25s | \n", "Serie", "Fecha",
					"Descripcion del Servicio");

			for (j = 0; j < lenRep; j++) {

				if (listRep[j].idCliente == listCliente[i].id
						&& listRep[j].isEmpty == FALSE
						&& cargarDescServicio(listRep[j].idServicio,
								listServicio, lenServ, bufferDescripcion)
								== 0) {
					printf("\t| %10d | %2d/%2d/%4d | %25s |\n",
							listRep[j].serie, listRep[j].fecha.dia,
							listRep[j].fecha.mes, listRep[j].fecha.anio,
							bufferDescripcion);
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}

int LstReparacionesDeUnCliente(eReparacion *listRep, int lenRep,
		eCliente *listCliente, int lenCliente, eServicio *listServicio,
		int lenServ) {

	int retorno = -1;
	int j;
	int indiceCliente;
	char bufferDescripcion[26];
	int bufferIdcliente;

	if (listRep != NULL && listCliente != NULL && listServicio != NULL
			&& lenRep > 0 && lenCliente > 0 && lenServ > 0) {

		pedirClienteporId(&bufferIdcliente, "Ingrese el ID del cliente: ",
				"El ID del cliente no es valido", listCliente, lenCliente, 2);

		indiceCliente = findClienteById(listCliente, lenCliente,
				bufferIdcliente);

		printf("\nReparaciones de: %s %s \n", listCliente[indiceCliente].nombre,
				listCliente[indiceCliente].apellido);
		printf("\t| %10s | %10s | %25s | \n", "Serie", "Fecha",
				"Descripcion del Servicio");

		for (j = 0; j < lenRep; j++) {

			if (listRep[j].idCliente == listCliente[indiceCliente].id
					&& listRep[j].isEmpty == FALSE
					&& cargarDescServicio(listRep[j].idServicio, listServicio,
							lenServ, bufferDescripcion) == 0) {
				printf("\t| %10d | %2d/%2d/%4d | %25s |\n", listRep[j].serie,
						listRep[j].fecha.dia, listRep[j].fecha.mes,
						listRep[j].fecha.anio, bufferDescripcion);
			}

		}

		retorno = 0;
	}
	return retorno;
}

// Mostrar Reparacion por Serie
int LstReparacionesXserie(eReparacion *listRep, int lenRep,
		eElectrodomestico *listElec, int lenElec, eServicio *listServicio,
		int lenServ) {
	int i;
	int j;
	int retorno = -1;
	char bufferDescripcion[26];

	if (listRep != NULL && listElec != NULL && listServicio != NULL
			&& lenRep > 0 && listElec > 0 && lenServ > 0) {

		for (i = 0; i < lenElec; i++) {

			if (listElec[i].isEmpty == FALSE) {
				printf("\nReparaciones de la serie: %d \n", listElec[i].serie);
				printf("\t| %10s | %10s | %25s | \n", "Serie", "Fecha",
						"Descripcion del Servicio");

				for (j = 0; j < lenRep; j++) {

					if (listRep[j].serie == listElec[i].serie
							&& listRep[j].isEmpty == FALSE
							&& cargarDescServicio(listRep[j].idServicio,
									listServicio, lenServ, bufferDescripcion)
									== 0) {
						printf("\t| %10d | %2d/%2d/%4d | %25s |\n",
								listRep[j].serie, listRep[j].fecha.dia,
								listRep[j].fecha.mes, listRep[j].fecha.anio,
								bufferDescripcion);
					}
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}

// Mostrar Reparacion por UNA Serie

int LstReparacionesDeUnaSerie(eReparacion *listRep, int lenRep,
		eElectrodomestico *listElec, int lenElec, eServicio *listServicio,
		int lenServ, eMarca *listMarca, int lenMarca) {

	int retorno = -1;
	int j;
	int indiceElec;
	char bufferDescripcion[26];
	int bufferserie;

	if (listRep != NULL && listElec != NULL && listServicio != NULL
			&& lenRep > 0 && lenElec > 0 && lenServ > 0) {

		pedirElectrodomesticoporSerie(&bufferserie,
				"\nIngrese la serie del Electrodomestico: ",
				"La serie ingresada no es valida\n", listElec, lenElec,
				listMarca, lenMarca, 2);

		indiceElec = findElectrodomesticoBySerie(listElec, lenElec,
				bufferserie);

		if (listElec[indiceElec].isEmpty == FALSE) {
			printf("\nReparaciones de: %d \n", listElec[indiceElec].serie);
			printf("\t| %10s | %10s | %25s | \n", "Serie", "Fecha",
					"Descripcion del Servicio");

			for (j = 0; j < lenRep; j++) {

				if (listRep[j].serie == listElec[indiceElec].serie
						&& listRep[j].isEmpty == FALSE
						&& cargarDescServicio(listRep[j].idServicio,
								listServicio, lenServ, bufferDescripcion)
								== 0) {
					printf("\t| %10d | %2d/%2d/%4d | %25s |\n",
							listRep[j].serie, listRep[j].fecha.dia,
							listRep[j].fecha.mes, listRep[j].fecha.anio,
							bufferDescripcion);
				}
			}
		}

		retorno = 0;
	}
	return retorno;
}

int LstReparacionesXimporteMayorIgual(eReparacion *listRep, int lenRep,
		eServicio *listServicio, int lenServ) { //usar idServicio

	int i;
	int j;
	int retorno = -1;
	float precio;
	char bufferDescripcion[26];

	utn_getNumeroFlotante(&precio, "Ingrese un importe: ",
			"El importe ingresado no es valido", 1, 1000, 2);

	for (i = 0; i < lenServ; i++) {
		if (listServicio[i].precio >= precio) {

			printf("\nReparaciones con importe: $%.2f \n",
					listServicio[i].precio);

			printf("\t| %10s | %10s | %25s | \n", "Serie", "Fecha",
					"Descripcion del Servicio");

			for (j = 0; j < lenRep; j++) {

				if (listRep[j].idServicio == listServicio[i].id
						&& listRep[j].isEmpty == FALSE
						&& cargarDescServicio(listRep[j].idServicio,
								listServicio, lenServ, bufferDescripcion)
								== 0) {

					printf("\t| %10d | %2d/%2d/%4d | %25s |\n",
							listRep[j].serie, listRep[j].fecha.dia,
							listRep[j].fecha.mes, listRep[j].fecha.anio,
							bufferDescripcion);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

//INFORMAR LA CANTIDAD DE REPARACIONES POR CLIENTE

int ListarCantidadReparacionesXCliente(eReparacion *listRep, int lenRep,
		eCliente *listCliente, int lenCliente, eServicio *listServicio,
		int lenServ) {
	int i;
	int j;
	int retorno = -1;
	int contador = 0;

	if (listRep != NULL && listCliente != NULL && listServicio != NULL
			&& lenRep > 0 && lenCliente > 0 && lenServ > 0) {

		for (i = 0; i < lenCliente; i++) {

			for (j = 0; j < lenRep; j++) {

				if (listRep[j].idCliente
						== listCliente[i].id&& listRep[j].isEmpty == FALSE) {
					contador++;
				}
			}

			printf("\nLas reparaciones de %s %s son %d\n",
					listCliente[i].nombre, listCliente[i].apellido, contador);

			contador = 0;
		}

		retorno = 0;
	}

	return retorno;
}

//INFORMAR LA CANTIDAD DE REPARACIONES POR SERIE DE ELECTRODOMESTICO

int ListarCantidadReparacionesXserie(eReparacion *listRep, int lenRep,
		eElectrodomestico *listElec, int lenElec, eServicio *listServicio,
		int lenServ) {
	int i;
	int j;
	int contador = 0;
	int retorno = -1;

	if (listRep != NULL && listElec != NULL && listServicio != NULL
			&& lenRep > 0 && listElec > 0 && lenServ > 0) {

		for (i = 0; i < lenElec; i++) {

			if (listElec[i].isEmpty == FALSE) {

				for (j = 0; j < lenRep; j++) {

					if (listRep[j].serie
							== listElec[i].serie&& listRep[j].isEmpty == FALSE) {
						contador++;
					}
				}
				printf("\nLa cantidad de reparaciones de la serie %d son %d\n",
						listElec[i].serie, contador);
			}
		}
		contador = 0;
		retorno = 0;
	}

	return retorno;
}

//INFORMAR EL ELECTRODOMESTICO CON MAYOR CANTIDAD DE REPARACIONES

int MostrarElectroConMayorCantidadDeReparaciones(eReparacion *listRep,
		int lenRep, eElectrodomestico *listElec, int lenElec) {
	int i;
	int j;
	int contador = 0;
	int indiceMax;
	int arrayContador[lenElec];
	int max = -1;
	int retorno = -1;

	if (listRep != NULL && listElec != NULL && lenRep > 0 && listElec > 0) {

		for (i = 0; i < lenElec; i++) {

			if (listElec[i].isEmpty == FALSE) {

				for (j = 0; j < lenRep; j++) {

					if (listRep[j].serie
							== listElec[i].serie&& listRep[j].isEmpty == FALSE) {
						contador++;
					}
				}
			}
			arrayContador[i] = contador;
		}
		contador = 0;

		for (i = 0; i < lenElec; i++) {
			if (max < arrayContador[i]) {
				max = arrayContador[i];
				indiceMax = i;
			}
		}

		if (max > 0) {
			printf(
					"\nLa serie con mayor cantidad de reparaciones es %d con %d reparaciones\n\n",
					listElec[indiceMax].serie, max);
		} else {
			printf("\n No hay reparaciones para informar \n\n");
		}
		retorno = 0;
	}

	return retorno;
}

//INFORMAR EL CLIENTE CON MAYOR CANTIDAD DE REPARACIONES

int MostrarClienteConMayorCantidadDeReparaciones(eReparacion *listRep,
		int lenRep, eCliente *listaCliente, int lenCliente) {
	int i;
	int j;
	int contador = 0;
	int indiceMax;
	int arrayContador[lenCliente];
	int max = -1;
	int retorno = -1;

	if (listRep != NULL && listaCliente != NULL && lenRep > 0
			&& lenCliente > 0) {

		for (i = 0; i < lenCliente; i++) {

			for (j = 0; j < lenRep; j++) {

				if (listRep[j].idCliente
						== listaCliente[i].id&& listRep[j].isEmpty == FALSE) {
					contador++;
				}
			}

			arrayContador[i] = contador;
			contador = 0;
		}

		for (i = 0; i < lenCliente; i++) {
			if (max < arrayContador[i]) {
				max = arrayContador[i];
				indiceMax = i;
			}
		}

		if (max > 0) {
			printf(
					"\nEl cliente que realizo la mayor cantidad de reparaciones es %s %s con %d reparaciones\n\n",
					listaCliente[indiceMax].nombre,
					listaCliente[indiceMax].apellido, max);
		} else {
			printf("\n No hay reparaciones para informar \n\n");
		}
		retorno = 0;
	}

	return retorno;
}

//INFORMAR EL PROMEDIO DE REPARACIONES POR ELECTRODOMESTICO

int MostrarPromedioRepXElectrodomesticos(eReparacion *listRep, int lenRep,
		eElectrodomestico *listElec, int lenElec) {

	int retorno = -1;
	int i;
	int j;
	int contadorRep = 0;
	int contadorElec = 0;
	float promedio = 0;

	if (listRep != NULL && listElec != NULL && lenRep > 0 && listElec > 0) {

		for (i = 0; i < lenRep; i++) {

			if (listRep[i].isEmpty == FALSE) {
				contadorRep++;
			}
		}

		for (j = 0; j < lenElec; j++) {

			if (listElec[j].isEmpty == FALSE) {
				contadorElec++;
			}
		}

		if (contadorElec > 0) {
			promedio = (float) contadorRep / contadorElec;
			printf(
					"\n El promedio de reparaciones por electrodomestico es: %.2f.\n ",
					promedio);
		} else {
			printf("\n No hay ningun electrodomestico.\n ");
		}
		retorno = 0;
	}

	system("pause");

	return retorno;
}

//INFORMAR EL PROMEDIO DE REPARACIONES POR CLIENTE

// (1) Mostrar Electrodomésticos del año(modelo) 2020
int MostrarElec2020(eElectrodomestico *listElec, int lenElec) {

	int retorno = -1;
	int i;

	if (listElec != NULL && listElec != NULL) {

		printf("\n\t| %5s | %8s | %8s |\n", "ID", "Serie", "Modelo");
		for (i = 0; i < lenElec; i++) {

			if (listElec[i].modelo == 2020) {

				printf("\t| %5d | %8d | %8d |\n", listElec[i].id,
						listElec[i].serie, listElec[i].modelo);
			}
		}
		retorno = 0;
	}

	return retorno;
}

//(2) Mostrar Electrodomésticos de una marca seleccionada

int MostrarElecDeUnaMarca(eElectrodomestico *listElec, int lenElec,
		eMarca *listaMarca, int lenMarca) {

	int retorno = -1;
	int i;
	int bufferId;

	if (listElec != NULL && listElec != NULL && lenElec > 0 && lenMarca > 0) {

		if (pedirMarcaporId(&bufferId, "Ingrese el ID de marca: \n",
				"El ID no es valido. Reingrese \n", listaMarca, lenMarca, 2)
				== 0) {
			printf("\n\t| %5s | %8s | %8s |\n", "ID", "Serie", "Modelo");
			for (i = 0; i < lenElec; i++) {

				if (listElec[i].idMarca == bufferId) {

					printf("\t| %5d | %8d | %8d |\n", listElec[i].id,
							listElec[i].serie, listElec[i].modelo);
				}
			}
			retorno = 0;
		}
	}

	return retorno;
}

//(3) Mostrar todas las reparaciones efectuadas al Electrodoméstico seleccionado

int MostrarRepDeElec(eElectrodomestico *listElec, int lenElec,
		eMarca *listaMarca, int lenMarca, eReparacion *listaRep, int lenRep) {

	int retorno = -1;
	int i;
	int bufferSerie;

	if (listElec != NULL && listElec != NULL && lenElec > 0 && lenMarca > 0) {

		if (pedirElectrodomesticoporSerie(&bufferSerie,
				"Ingrese la serie del Electrodomestico: ",
				"La serie no es valida. Reingrese", listElec, lenElec,
				listaMarca, lenMarca, 2) == 0) {

			printf("\n\t| %5s | %11s | %11s | %10s |\n", "ID", "Serie",
					"ID-Servicio", "Fecha");
			for (i = 0; i < lenRep; i++) {

				if (listaRep[i].serie == bufferSerie) {

					printf("\t| %5d | %11d | %11d | %2d/%2d/%4d |\n",
							listaRep[i].id, listaRep[i].serie,
							listaRep[i].idServicio, listaRep[i].fecha.dia,
							listaRep[i].fecha.mes, listaRep[i].fecha.anio);
				}
			}
			retorno = 0;
		}
	}
	return retorno;
}

// (4)Listar los Electrodomésticos que no tuvieron reparaciones

/*int MostrarElectSinRep(eElectrodomestico *listElec, int lenElec,
 eReparacion *listaRep, int lenRep) {

 int retorno = -1;
 int i;
 int j;

 if (listElec != NULL && listaRep != NULL && lenElec > 0 && lenRep > 0) {

 printf("\n\t| %5s | %8s | %8s | %8s |\n", "ID", "Serie", "ID-Marca",
 "Modelo");
 for (i = 0; i < lenElec; i++) {

 if (listElec[i].isEmpty == FALSE) {
 for (j = 0; j < lenRep; j++) {

 if (listaRep[j].serie
 == listElec[i].serie && listaRep[j].isEmpty == FALSE) {
 continue;
 } else {
 printf("\t| %5d | %8d | %8d | %8d |\n", listElec[i].id,
 listElec[i].serie, listElec[i].idMarca,
 listElec[i].modelo);
 }
 }
 }
 retorno = 0;
 }
 }

 return retorno;
 }*/

//(5) Informar importe total de las reparaciones realizadas a un Electrodoméstico seleccionado
/*int InformarImpoteTotalDeElec(eElectrodomestico *listElec, int lenElec,
 eReparacion *listaRep, int lenRep, eServicio *listaServicio,
 int lenServ, eMarca *listaMarca, int lenMarca) {

 int retorno = -1;
 int bufferSerie;
 int i;
 int j;

 if (listElec != NULL && listaRep != NULL && listaServicio != NULL
 && lenElec > 0 && lenRep > 0 && lenServ > 0) {

 pedirElectrodomesticoporSerie(&bufferSerie,
 "Ingrese la serie del Electrodomestico: ",
 "La serie no es valida. Reingrese", listElec, lenElec,
 listaMarca, lenMarca, 2)

 for (i = 0; i < lenElec; i++) {
 if (listElec[i].isEmpty == FALSE) {
 for (j = 0; j < lenRep; j++) {
 if (listaRep[j].serie
 == bufferSerie && listaRep[j].isEmpty == FALSE) {

 }
 }
 }
 retorno = 0;
 }
 }

 return retorno;
 }*/

// (8) Mostrar todos los Electrodomésticos que realizaron una garantía y la fecha
/*int MostrarElecGtiaYFecha(eElectrodomestico *listElec, int lenElec,
 eReparacion *listRep, int lenRep) {

 int retorno = -1;
 int i;
 int j;

 for (i = 0; i < lenElec; i++) {

 }

 return retorno;
 }*/

