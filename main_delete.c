
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "products.h"
#include "validation.h"

int main (int argc, char *argv[])
{	
	FILE * f1, *f2;
	product_t record1, record2;
	status_t st;

	if((st = validate_arguments( argc, argv, &f1, &f2)) != OK)
		return st;
	
	if((st = perform_product_delete(record1, record2, &f1, f2, argv[CMD_ARG_INVENTORY_FILE_POSITION_NUMBER])) != OK)
	{
		fclose(f1);
		fclose(f2);
		return st;
	}

	fclose(f1);
	fclose(f2);

	if((st = products_record_view(argv[CMD_ARG_INVENTORY_FILE_POSITION_NUMBER])) != OK)
		return st;

	return OK;
}
