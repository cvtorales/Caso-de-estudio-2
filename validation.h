


	/* validation.h */

	#ifndef VALIDATION__H
	#define VALIDATION__H

	#include <stdio.h>
	#include "types.h"

	#define CMD_ARG_NAME_PROGRAM_POSITION_NUMBER 0
	#define CMD_ARG_INVENTORY_FILE_POSITION_NUMBER 1
	#define CMD_ARG_NEWS_FILE_POSITION_NUMBER 2

	status_t validate_arguments(int argc, char *argv[], FILE **fentrada, FILE **fsalida);


	#endif