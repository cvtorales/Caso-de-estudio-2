
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "validation.h"

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
