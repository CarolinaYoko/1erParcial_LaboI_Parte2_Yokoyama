/*
 * marca.h
 *
 *  Created on: 15 oct. 2020
 *      Author: Carolina
 */

#ifndef MARCA_H_
#define MARCA_H_
#define LENMARCA 5

struct{

	int id;
	char descripcion [21];

}typedef eMarca;

/**
 * @brief Encuentra una Marca por id
 *
 * @param list array de tipo eMarca
 * @param len largo del array
 * @param id  recibido por copia
 * @return En caso de exito retorna el indice de la marca, en caso de error(-1)
 */
int findMarcaById(eMarca *list, int len, int id);

/**
 * @brief imprime el listado de marcas
 *
 * @param list array de tipo eMarca
 * @param len largo del array
 * @return En caso de exito (0), en caso de error(-1)
 */
int printMarcas(eMarca *list, int len);

/**
 * @brief imprime una marca dado su ID
 *
 * @param list array de tipo eMarca
 * @param len largo del array
 * @param id identificador de la marca
 * @return En caso de exito (0), en caso de error(-1)
 */
int printMarca(eMarca *list, int len, int id);

/**
 * @brief valida que exita la marca dado su ID
 *
 * @param list array de tipo eMarca
 * @param len largo del array
 * @param id identificador de la marca
 * @return En caso de exito (0), en caso de error(-1)
 */
int validarIdMarca(eMarca *list, int len, int id);

/**
 * @brief pide y valida una marca por ID
 *
 * @param id puntero a entero del ID
 * @param mensaje pedido de ingreso de la marca
 * @param mensajeError notificacion de error
 * @param list array de tipo eMarca
 * @param len largo del array
 * @param reintentos cantidad de intentos
 * @return En caso de exito (0), en caso de error(-1)
 */
int pedirMarcaporId(int *id, char *mensaje, char *mensajeError,
		eMarca *list, int len, int reintentos);

/**
 * @brief carga la descripcion de la marca dado el ID
 *
 * @param id identificacion de la marca
 * @param list array de tipo eMarca
 * @param len largo del array
 * @param desMarca puntero a la variable descripcion de marca
 * @return En caso de exito (0), en caso de error(-1)
 */
int cargarDescMarca(int id, eMarca *list, int len, char *desMarca);


#endif /* MARCA_H_ */
