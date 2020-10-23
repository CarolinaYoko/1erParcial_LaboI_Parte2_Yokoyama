
#include "servicio.h"
#include "cliente.h"
#include "electrodomestico.h"
#ifndef REPARACION_H_
#define REPARACION_H_

struct{

	int dia;
	int mes;
	int anio;

}typedef eFecha;

struct{

	int id;
	int serie;
	int idServicio;
	int idCliente;
	eFecha fecha;
	int isEmpty;

}typedef eReparacion;

/**
 * @brief pone todas las banderas isEmpty en TRUE(0)
 *
 * @param array de tipo eReparacion
 * @param len largo del array
 * @return En caso de exito (0), en caso de error(-1)
 */
int initReparacion(eReparacion*list, int len);

/**
 * @brief Harcodea los datos de un array de datos tipo eReparacion
 *
 * @param list array de tipo eReparacion
 * @param tam largo del array
 * @param idReparaciones puntero al ID de Reparaciones
 */
void harcodeoDatosReparacion(eReparacion* list,int tam,int* idReparaciones);

/**
 * @brief Harcodea los datos de un array de datos tipo eReparacion
 *
 * @param listaReparacion array de tipo eReparacion
 * @param largoReparacion largo del array
 * @param cantidad de datos a harcodear
 * @return la cantidad de datos harcodeados
 */
int hardcodearReparaciones(eReparacion *listaReparacion, int largoReparacion, int cantidad);

/**
 * @brief Encuentra un servicio por id
 *
 * @param list array de tipo eReparacion
 * @param len largo del array
 * @param id recibido por copia
 * @return En caso de exito retorna el indice del electrodomestico, en caso de error(-1)
 */
int findReparacionById(eReparacion *list, int len, int id);

/**
 * @brief
 *
 * @param list array de tipo eReparacion
 * @param len largo del array tipo eReparacion
 * @param listaServicio array de tipo eServicio
 * @param lenServ largo del array tipo eServicio
 * @return En caso de exito retorna el indice del electrodomestico, en caso de error(-1)
 */
int printReparaciones(eReparacion *list, int len, eServicio* listaServicio, int lenServ);

/**
 * @brief imprime el listado de una Reparacion
 *
 * @param list array de tipo eReparacion
 * @param len largo del array tipo eReparacion
 * @param listaServicio array de tipo eServicio
 * @param lenServ largo del array tipo eServicio
 * @param id identificador del electrodomestico
 * @return En caso de exito (0), en caso de error(-1)
 */
int printReparacion(eReparacion *list, int len, eServicio* listaServicio, int lenServ, int id);

/**
 * @brief agrega una reparacion pidiendo serie, ID de servicio, ID de cliente y fecha de ingreso
 *
 * @param list array de tipo eReparacion
 * @param len largo del array tipo eReparacion
 * @param id identificador de la reparacion autoincremental
 * @param lista array de tipo eElectrodomestico
 * @param lenElec largo del array tipo eElectrodomestico
 * @param servicios array de tipo eServicio
 * @param lenServ  largo del array tipo eServicio
 * @param listaMarca array de tipo eMarca
 * @param lenMarca largo del array tipo eMarca
 * @param listaCliente array de tipo eCliente
 * @param tamCliente largo del array tipo eCliente
 * @return En caso de exito (0), en caso de error(-1)
 */
int addReparacion(eReparacion *list, int len, int id, eElectrodomestico *lista, int lenElec, eServicio *servicios, int lenServ, eMarca*listaMarca, int lenMarca, eCliente* listaCliente, int tamCliente);

/**
 * @brief Modifica los campos serie, ID servicio o fecha del la reparacion e imprime
 *
 * @param list array de tipo eReparacion
 * @param len largo del array tipo eReparacion
 * @param listaServicio array de tipo eServicio
 * @param lenServ  largo del array tipo eServicio
 * @return En caso de exito (0), en caso de error(-1)
 */
int updateReparacion(eReparacion *list, int len, eServicio* listaServicio, int lenServ);

/**
 * @brief baja logica de la repacion
 *
 * @param list array de tipo eReparacion
 * @param len largo del array tipo eReparacion
 * @return En caso de exito (0), en caso de error(-1)
 */
int removeReparacion(eReparacion *list, int len);



#endif /* REPARACION_H_ */
