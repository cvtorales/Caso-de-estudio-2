	/* main.h */

	#ifndef MAIN__H
	#define MAIN__H

	#include <stdio.h>
	#include "types.h"

    #define CMD_ARGS 3
	#define CMD_ARG_NAME_PROGRAM_POSITION_NUMBER 0
	#define CMD_ARG_INVENTORY_FILE_POSITION_NUMBER 1
	#define CMD_ARG_NEWS_FILE_POSITION_NUMBER 2

	status_t validate_arguments(int argc, char *argv[]);


	#endif