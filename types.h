


	/* types.h */

	#ifndef TYPES__H
	#define TYPES__H

	#include <stdio.h>

	#define MAX_DESCRIPTION 100
    #define MAX_CANT_ARG 3

    #define MSG_PRODUCTS_VIEW "Los productos leidos son:"
	#define MSG_ERROR_FILE_NOT_AVAILABLE "Los archivos no estan disponibles."
	#define MSG_ERROR_INVALID_NUMBER_OF_ARGUMENTS "Cantidad de argumentos invalida."
	#define MSG_ERROR_NO_OPEN_FILE "No se pudo abrir el archivo."
    #define MSG_ERROR_DELETE_PRODUCT "No se realizo la baja, producto no existente en el inventario."
    #define MSG_ERROR_INVENTORY_PRODUCT_NO_AVAILABLE "El producto que desea eliminar no existe."
    #define MSG_ERROR_FILE_EMPTY "El archivo de novedades esta vacio o corrupto."
	


	typedef enum {
					OK = 0,
					ERROR_NULL_POINTER,
					ERROR_NO_MEMORY,
					ERROR_NO_OPEN_FILE,

					ERROR_CMD_CANT_ARG,
					ERROR_INVALID_DATA,
					ERROR_NO_DELETE_PRODUCT,
					ERROR_NO_CHANGE_FILE_NAME,
					ERROR_INVENTORY_PRODUCT_NO_AVAILABLE,
					ERROR_FILE_DELETE_EMPTY,
					ERROR_NO_REMOVE_FILE

				 }status_t;









	#endif