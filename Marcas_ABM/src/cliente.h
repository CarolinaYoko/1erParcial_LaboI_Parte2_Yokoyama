
#ifndef CLIENTE_H_
#define CLIENTE_H_

#define TRUE 0
#define FALSE 1


struct{

	 int id;
	 char nombre[51];
	 char apellido[51];

}typedef eCliente;


/**
 * @brief Encuentra un Cliente por id
 *
 * @param list array de tipo eCliente
 * @param len largo del array
 * @param id  recibido por copia
 * @return En caso de exito retorna el indice del Cliente, en caso de error(-1)
 */
int findClienteById(eCliente *list, int len, int id);

/**
 * @brief Harcodea los datos de un array de datos tipo eCliente
 *
 * @param list array de tipo eCliente
 * @param tam largo del array
 * @param idCliente puntero al ID de Cliente
 */
void harcodeoDatosCliente(eCliente *list, int tam, int *idCliente);

/**
 * @brief Harcodea los datos de un array de datos tipo eCliente
 *
 * @param list array de tipo eCliente
 * @param largoCliente largo del array
 * @param cantidad de datos a harcodear
 * @return la cantidad de datos harcodeados
 */
int hardcodearCliente(eCliente *list, int largoCliente, int cantidad);

/**
 * @brief imprime el listado de Clientes
 *
 * @param list array de tipo eCliente
 * @param len largo del array de tipo eCliente
 * @return En caso de exito (0), en caso de error(-1)
 */
int printClientes(eCliente *list, int len);

/**
 * @brief imprime el listado de un Cliente
 *
 * @param list array de tipo eCliente
 * @param len largo del array de tipo eCliente
 * @param id identificador del Cliente
 * @return En caso de exito (0), en caso de error(-1)
 */
int printCliente(eCliente *list, int len, int id);

/**
 * @brief valida que exita un Cliente dado su ID
 *
 * @param list array de tipo eCliente
 * @param len largo del array de tipo eCliente
 * @param id identificador del eCliente
 * @return En caso de exito (0), en caso de error(-1)
 */
int validarIdCliente(eCliente *list, int len, int id);

/**
 * @brief pide y valida un Cliente por ID
 *
 * @param id puntero a entero del ID
 * @param mensaje pedido de ID del Cliente
 * @param mensajeError notificacion de error
 * @param list array de tipo eCliente
 * @param len largo del array de tipo eCliente
 * @param reintentos cantidad de reintentos
 * @return En caso de exito (0), en caso de error(-1)
 */
int pedirClienteporId(int *id, char *mensaje, char *mensajeError, eCliente *list, int len, int reintentos);

/**
 * @brief carga el nombre y apellido del cliente dado el ID
 *
 * @param id identificacion del Cliente
 * @param list array de tipo eCliente
 * @param len largo del array de tipo eCliente
 * @param nombreCliente puntero a la variable que almacenara el nombre del cliente
 * @param apellidoCliente puntero a la variable que almacenara el apellido del cliente
 * @return En caso de exito (0), en caso de error(-1)
 */
int cargarDescCliente(int id, eCliente *list, int len, char *nombreCliente, char *apellidoCliente);

#endif /* CLIENTE_H_ */
