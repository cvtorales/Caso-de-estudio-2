


	/* products.h */

	#ifndef PRODUCTS__H
	#define PRODUCTS__H

	#include <stdio.h>
	#include "types.h"

	#define TEMPORAL_FILE "temp.bin"

		typedef struct {
						size_t id;
						size_t cod_barras;
						char description[MAX_DESCRIPTION];
						size_t precio;

					}product_t;


	status_t perform_product_retrieve(product_t record1, product_t record2, FILE ** f1, FILE *f2, char * nuevo);
	status_t perform_product_delete(product_t record1, product_t record2, FILE **f1, FILE *f2, char * nuevo);
	status_t products_record_view(char * file_name);

	#endif