
#ifndef SERVICIO_H_
#define SERVICIO_H_

struct{

	int id;
	char descripcion[26];
	float precio;


}typedef eServicio;


/**
 * @brief Encuentra una Servicio por id
 *
 * @param list array de tipo eServicio
 * @param len largo del array
 * @param id  recibido por copia
 * @return En caso de exito retorna el indice de la marca, en caso de error(-1)
 */
int findServicioById(eServicio *list, int len, int id);

/**
 * @brief imprime el listado de Servicios
 *
 * @param list array de tipo eServicio
 * @param len largo del array
 * @return En caso de exito (0), en caso de error(-1)
 */
int printServicios(eServicio *list, int len);

/**
 * @brief imprime un servicio dado su ID
 *
 * @param list array de tipo eServicio
 * @param len largo del array
 * @param id identificador del servicio
 * @return En caso de exito (0), en caso de error(-1)
 */
int printServicio(eServicio *list, int len, int id);

/**
 * @brief valida que exita un servicio dado su ID
 *
 * @param list array de tipo eServicio
 * @param len largo del array
 * @param id identificador del servicio
 * @return En caso de exito (0), en caso de error(-1)
 */
int validarIdServicio(eServicio *list, int len, int id);

/**
 * @brief pide y valida un servicio por ID
 *
 * @param id puntero a entero del ID
 * @param mensaje pedido de ingreso del servicio
 * @param mensajeError notificacion de error
 * @param list array de tipo eServicio
 * @param len largo del array
 * @param reintentos cantidad de intentos
 * @return En caso de exito (0), en caso de error(-1)
 */
int pedirServicioporId(int *id, char *mensaje, char *mensajeError,
		eServicio *list, int len, int reintentos);

/**
 * @brief carga la descripcion de un servicio dado el ID
 *
 * @param id identificacion del servicio
 * @param list array de tipo eMarca
 * @param len largo del array
 * @param desMarca puntero a la variable descripcion del servicio
 * @return En caso de exito (0), en caso de error(-1)
 */
int cargarDescServicio(int id, eServicio *list, int len, char *desServicio);

#endif /* SERVICIO_H_ */
