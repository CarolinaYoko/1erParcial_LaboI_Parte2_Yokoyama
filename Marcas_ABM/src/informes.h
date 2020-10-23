/*
 * informes.h
 *
 *  Created on: 18 oct. 2020
 *      Author: Carolina
 */

#include "servicio.h"
#include "cliente.h"
#include "electrodomestico.h"
#include "reparacion.h"

#ifndef INFORMES_H_
#define INFORMES_H_

#define TRUE 0
#define FALSE 1

int MostrarElectSinRep(eElectrodomestico *listElec, int lenElec,eReparacion *listaRep, int lenRep);

/**
 * @brief Muestra todas las reparaciones efectuadas a un electodomestico
 *
 * @param listElec array de tipo eElectrodomestico
 * @param lenElec largo del array de tipo eElectrodomestico
 * @param listaMarca array de tipo eMarca
 * @param lenMarca largo del array de tipo eMarca
 * @param listaRep array de tipo eReparacion
 * @param lenRep largo del array de tipo eReparacion
 * @return En caso de exito (0), en caso de error(-1)
 */
int MostrarRepDeElec(eElectrodomestico *listElec, int lenElec,
		eMarca *listaMarca, int lenMarca, eReparacion *listaRep, int lenRep);
/**
 * @brief Lista los electrodomesticos del 2020
 *
 * @param listElec array de tipo eElectrodomestico
 * @param lenElec largo del array de tipo eElectrodomestico
 * @return En caso de exito (0), en caso de error(-1)
 */
int MostrarElec2020(eElectrodomestico *listElec, int lenElec);

/**
 * @brief Lista los elecetrodomesticos de una marca
 *
 * @param listElec array de tipo eElectrodomestico
 * @param lenElec largo del array de tipo eElectrodomestico
 * @param listaMarca array de tipo eMarca
 * @param lenMarca largo del array de tipo eMarca
 * @return En caso de exito (0), en caso de error(-1)
 */
int MostrarElecDeUnaMarca(eElectrodomestico *listElec, int lenElec, eMarca* listaMarca, int lenMarca);

/**
 * @brief Muestra el Menu de informes y ejecuta el seleccionado *
 *
 * @param listaElect
 * @param lenElec
 * @param listaClientes
 * @param lenClientes
 * @param listaReparaciones
 * @param lenReparaciones
 * @param listaServicios
 * @param lenServicio
 * @param listaMarca
 * @param lenMarca
 */
void MenuInformes(eElectrodomestico *listaElect, int lenElec, eCliente *listaClientes, int lenClientes,
		eReparacion *listaReparaciones, int lenReparaciones,
		eServicio *listaServicios, int lenServicio, eMarca *listaMarca,
		int lenMarca);

/**
 * @brief lista las reparaciones por cliente
 *
 * @param listRep array de tipo eReparacion
 * @param lenRep largo del array de tipo eReparacion
 * @param listCliente array de tipo eCliente
 * @param lenCliente largo del array de tipo eCliente
 * @param listServicio array de tipo eServicio
 * @param lenServ largo del array de tipo eServicio
 * @return En caso de exito (0), en caso de error(-1)
 */
int LstReparacionesXcliente(eReparacion *listRep, int lenRep, eCliente *listCliente,
		int lenCliente, eServicio* listServicio, int lenServ);

/**
 * @brief Lista las reparaciones de un cliente
 *
 * @param listRep array de tipo eReparacion
 * @param lenRep largo del array de tipo eReparacion
 * @param listCliente array de tipo eCliente
 * @param lenCliente largo del array de tipo eCliente
 * @param listServicio array de tipo eServicio
 * @param lenServ largo del array de tipo eServicio
 * @return En caso de exito (0), en caso de error(-1)
 */
int LstReparacionesDeUnCliente(eReparacion *listRep, int lenRep,
		eCliente *listCliente, int lenCliente, eServicio *listServicio,
		int lenServ);

/**
 * @brief lista las reparaciones por serie de electrodomestico
 *
 * @param listRep array de tipo eReparacion
 * @param lenRep largo del array de tipo eReparacion
 * @param listElec array de tipo eElectrodomestico
 * @param lenElec largo del array de tipo eElectrodomestico
 * @param listServicio array de tipo eServicio
 * @param lenServ largo del array de tipo eServicio
 * @return En caso de exito (0), en caso de error(-1)
 */
int LstReparacionesXserie(eReparacion *listRep, int lenRep,
		eElectrodomestico *listElec, int lenElec, eServicio *listServicio,
		int lenServ);

/**
 * @brief lista las reparaciones de una serie de electrodomesticos
 *
 * @param listRep array de tipo eReparacion
 * @param lenRep largo del array de tipo eReparacion
 * @param listElec array de tipo eElectrodomestico
 * @param lenElec largo del array de tipo eElectrodomestico
 * @param listServicio array de tipo eServicio
 * @param lenServ largo del array de tipo eServicio
 * @param listMarca array de tipo eMarca
 * @param lenMarca largo del array de tipo eMarca
 * @return En caso de exito (0), en caso de error(-1)
 */
int LstReparacionesDeUnaSerie(eReparacion *listRep, int lenRep,
		eElectrodomestico *listElec, int lenElec, eServicio *listServicio,
		int lenServ, eMarca *listMarca, int lenMarca);

/**
 * @brief lista las reparaciones de un importe mayor o igual al dado
 *
 * @param listRep array de tipo eReparacion
 * @param lenRep largo del array de tipo eReparacion
 * @param listServicio array de tipo eServicio
 * @param lenServ largo del array de tipo eServicio
 * @return En caso de exito (0), en caso de error(-1)
 */
int LstReparacionesXimporteMayorIgual(eReparacion *listRep, int lenRep,
		eServicio *listServicio, int lenServ);

/**
 * @brief lista la cantidad de reparaciones por cliente
 *
 * @param listRep array de tipo eReparacion
 * @param lenRep largo del array de tipo eReparacion
 * @param listCliente array de tipo eCliente
 * @param lenCliente largo del array de tipo eCliente
 * @param listServicio array de tipo eServicio
 * @param lenServ largo del array de tipo eServicio
 * @return En caso de exito (0), en caso de error(-1)
 */
int ListarCantidadReparacionesXCliente(eReparacion *listRep, int lenRep,
		eCliente *listCliente, int lenCliente, eServicio *listServicio,
		int lenServ);

/**
 * @brief lista la cantidad de reparaciones por serie de electrodomestico
 *
 * @param listRep array de tipo eReparacion
 * @param lenRep largo del array de tipo eReparacion
 * @param listElec array de tipo eElectrodomestico
 * @param lenElec largo del array de tipo eElectrodomestico
 * @param listServicio array de tipo eServicio
 * @param lenServ largo del array de tipo eServicio
 * @return En caso de exito (0), en caso de error(-1)
 */
int ListarCantidadReparacionesXserie(eReparacion *listRep, int lenRep,
		eElectrodomestico *listElec, int lenElec, eServicio *listServicio,
		int lenServ);

/**
 * @brief muestra la serie de electrodomestico con mayor cantidad de reparaciones
 *
 * @param listRep array de tipo eReparacion
 * @param lenRep largo del array de tipo eReparacion
 * @param listElec array de tipo eElectrodomestico
 * @param lenElec largo del array de tipo eElectrodomestico
 * @return En caso de exito (0), en caso de error(-1)
 */
int MostrarElectroConMayorCantidadDeReparaciones(eReparacion *listRep,
		int lenRep, eElectrodomestico *listElec, int lenElec);


/**
 * @brief
 *
 * @param listRep
 * @param lenRep
 * @param listElec
 * @param lenElec
 * @return
 */
int MostrarClienteConMayorCantidadDeReparaciones(eReparacion *listRep,
		int lenRep, eCliente *listaCliente, int lenCliente);


/**
 * @brief
 *
 * @param listRep
 * @param lenRep
 * @param listElec
 * @param lenElec
 * @return
 */
int MostrarPromedioRepXElectrodomesticos(eReparacion *listRep, int lenRep, eElectrodomestico *listElec, int lenElec);






#endif /* INFORMES_H_ */
