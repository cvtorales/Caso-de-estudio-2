





	/* main_retrieve.c */

	/* Programa para altas de productos */

	#include <stdio.h>
	#include <stdlib.h>
	#include "types.h"
	#include "products.h"
	#include "main.h"

	int main (int argc, char *argv[])
	{	
		FILE * f1, *f2;
		product_t record1, record2;
		status_t st;

		if((st = validate_arguments( argc, argv, &f1, &f2)) != OK)
			return st;
	
		if((st = perform_product_retrieve(record1, record2, &f1, f2, argv[CMD_ARG_INVENTORY_FILE_POSITION_NUMBER])) != OK)
			return st;

		fclose(f1);
		fclose(f2);

		if((st = products_record_view(argv[CMD_ARG_INVENTORY_FILE_POSITION_NUMBER])) != OK)
			return st;

		return OK;
	}


status_t validate_arguments(int argc, char *argv[], FILE **fentrada, FILE **fsalida)
{

	if( argv == NULL || fentrada == NULL || fsalida == NULL )
	{
		fprintf(stderr, "%s\n", MSG_ERROR_FILE_NOT_AVAILABLE);
		return ERROR_NULL_POINTER;
	}
	if( argc != MAX_CANT_ARG )
	{
		fprintf(stderr,"%s\n", MSG_ERROR_INVALID_NUMBER_OF_ARGUMENTS);
		return ERROR_CMD_CANT_ARG;
	}
	if( (*fentrada = fopen(argv[CMD_ARG_INVENTORY_FILE_POSITION_NUMBER],"rb")) == NULL)
	{
		fprintf(stderr,"%s\n", MSG_ERROR_NO_OPEN_FILE);
		return ERROR_NO_OPEN_FILE;
	}
	if((*fsalida = fopen(argv[CMD_ARG_NEWS_FILE_POSITION_NUMBER],"rb")) == NULL)
	{
		fprintf(stderr,"%s\n", MSG_ERROR_NO_OPEN_FILE);
		return ERROR_NO_OPEN_FILE;
	}

	return OK;
}
