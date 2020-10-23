#include "marca.h"

#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_
#define TRUE 0
#define FALSE 1

struct{

	int id;
	int serie;
	int idMarca;
	int modelo;
	int isEmpty;

}typedef eElectrodomestico;

/**
 * @brief pone todas las banderas isEmpty en TRUE(0)
 *
 * @param list array de tipo eServicio
 * @param len largo del array
 * @return En caso de exito (0), en caso de error(-1)
 */
int initElectrodomestico(eElectrodomestico*list, int len);

/**
 * @brief Harcodea los datos de un array de datos tipo eElectrodomestico
 *
 * @param list array de tipo eServicio
 * @param tam largo del array
 * @param idElectrodomesticos puntero al ID de electrodomestico
 */
void harcodeoDatosElectrodomestico (eElectrodomestico* list,int tam,int* idElectrodomesticos);

/**
 * @brief Harcodea los datos de un array de datos tipo eElectrodomestico
 *
 * @param list array de tipo eServicio
 * @param largoElectodomestico largo del array
 * @param cantidad de datos a harcodear
 * @return la cantidad de datos harcodeados
 */
int hardcodearElectrodomesticos(eElectrodomestico *list, int largoElectodomestico, int cantidad);

/**
 * @brief Encuentra un electrodomestico por id
 *
 * @param list array de tipo eElectrodomestico
 * @param len largo del array
 * @param id  recibido por copia
 * @return En caso de exito retorna el indice del electrodomestico, en caso de error(-1)
 */
int findElectrodomesticoById(eElectrodomestico *list, int len, int id);

/**
 * @brief  Encuentra un electrodomestico por serie
 *
 * @param list array de tipo eElectrodomestico
 * @param len largo del array
 * @param serie  recibido por copia
 * @return En caso de exito retorna el indice del electrodomestico, en caso de serie (-1)
 */
int findElectrodomesticoBySerie(eElectrodomestico *list, int len, int serie);

/**
 * @brief  imprime el listado de Electrodomesticos
 *
 * @param list array de tipo eElectrodomestico
 * @param len largo del array de tipo eElectrodomestico
 * @param lista  array de tipo eMarca
 * @param tamLista largo del array de tipo eMarca
 * @return En caso de exito (0), en caso de error(-1)
 */
int printElectrodomesticos(eElectrodomestico *list, int len, eMarca* lista, int tamLista);

/**
 * @brief imprime el listado de un Electrodomestico
 *
 * @param list array de tipo eElectrodomestico
 * @param len largo del array de tipo eElectrodomestico
 * @param id identificador del electrodomestico
 * @return En caso de exito (0), en caso de error(-1)
 */
int printElectrodomestico(eElectrodomestico *list, int len, int id);

/**
 * @brief agrega un electrodomestico pidiendo serie, ID de marca y modelo
 *
 * @param list array de tipo eElectrodomestico
 * @param len largo del array de tipo eElectrodomestic
 * @param lista  array de tipo eMarca
 * @param lenMarca largo del array de tipo eMarca
 * @param id identificador del electrodomestico autoincremental
 * @return En caso de exito (0), en caso de error(-1)
 */
int addElectrodomestico(eElectrodomestico *list, int len, eMarca* listaMarca, int lenMarca ,int id);

/**
 * @brief Modifica los campos modelo o serie e imprime
 *
 * @param list array de tipo eElectrodomestico
 * @param len largo del array de tipo eElectrodomestic
 * @return En caso de exito (0), en caso de error(-1)
 */
int updateElectrodomestico(eElectrodomestico *list, int len);

/**
 * @brief baja logica del electrodomestico
 *
 * @param list array de tipo eElectrodomestico
 * @param len largo del array de tipo eElectrodomestic
 * @return En caso de exito (0), en caso de error(-1)
 */
int removeElectrodomestico(eElectrodomestico *list, int len);

/**
 * @brief ordena los electrodomesticos por modelo y serie
 *
 * @param list array de tipo eElectrodomestico
 * @param len largo del array de tipo eElectrodomestico
 * @param order (0) ascendente -(1) descendente
 * @return En caso de exito (0), en caso de error(-1)
 */
int sortElectrodomestico(eElectrodomestico *list, int len, int order);

/**
 * @brief Verifica si hay banderas isEmpty en FALSE (1)
 *
 * @param list array de tipo eElectrodomestico
 * @param len largo del array de tipo eElectrodomestico
 * @return (1) si encontro al menos una bandera en FALSE sino devuelve (0)
 */
int hayAltasElectrodomesticos(eElectrodomestico *list, int len);

/**
 * @brief  valida que exita un electrodomestico dado su ID
 *
 * @param list array de tipo eElectrodomestico
 * @param len largo del array de tipo eElectrodomestico
 * @param id identificador del eElectrodomestico
 * @return En caso de exito (0), en caso de error(-1)
 */
int validarIdElectrodomestico(eElectrodomestico *list, int len, int id);

/**
 * @brief pide y valida un electrodomestico por ID
 *
 * @param serie puntero a la variable serie del electrodomestico
 * @param mensaje pedido de serie del electrodomestico
 * @param mensajeError notificacion de error
 * @param list array de tipo eElectrodomestico
 * @param len largo del array de tipo eElectrodomestico
 * @param lista array de tipo eMarca
 * @param lenMarca largo del array de tipo eMarca
 * @param reintentos cantidad de reintentos
 * @return En caso de exito (0), en caso de error(-1)
 */
int pedirElectrodomesticoporSerie(int *serie, char *mensaje, char *mensajeError,
		eElectrodomestico *list, int len, eMarca* lista, int lenMarca, int reintentos);

#endif /* ELECTRODOMESTICO_H_ */
