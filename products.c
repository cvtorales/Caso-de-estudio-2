

	/* products.c */

	#include <stdio.h>
	#include <stdlib.h>
	#include "types.h"
	#include "products.h"

	/*
	 	Esta funcion se utiliza para leer un archivo binario y mostrar su contenido en pantalla,
	 	para esto, el archivo debe estar cerrado, ya que esta funcion se encarga de abrirlo en modo
	 	lectura y luego cerrarlo.
		-----------------------------------------
		Se realizaron las siguientes modificaciones:
		Saqué la apertura y cierre del archivo de lectura.
		Cambié el nombre de la función
		
		
		
	*/

	status_t products_record_view(FILE * archivo)
	{
		product_t record;
		/*
		if((archivo = fopen(file_name,"rb")) == NULL)
		{
			fprintf(stderr,"%s\n", MSG_ERROR_NO_OPEN_FILE);
			return ERROR_NO_OPEN_FILE;
		}
		*/

		while(fread(&record, sizeof(record), 1, archivo))
			printf("%s\n%lu\n%lu\n%s\n%lu\n", MSG_PRODUCTS_VIEW,record.id, record.cod_barras, record.description, record.precio);
		/*
		fclose(archivo);
		*/

		return OK;

	}

	status_t perform_product_retrieve(product_t record1, product_t record2, FILE ** f1, FILE *f2, char * nuevo)
	{
	    size_t m1, m2;
	    FILE * f_temp;

	    m1 = fread(&record1, sizeof(record1), 1, *f1);
		m2 = fread(&record2, sizeof(record2), 1, f2);
	
		f_temp = fopen(TEMPORAL_FILE,"wb");

		while(m1 && m2)
		{
	
			if(record1.id < record2.id)
			{
				fwrite(&record1, sizeof(record1), 1, f_temp);
				m1 = fread(&record1, sizeof(record1), 1, *f1);
			}else{
				fwrite(&record2, sizeof(record2), 1, f_temp);
				m2 = fread(&record2, sizeof(record2), 1, *f1);
			}
		}

		while(m1)
		{
	
			fwrite(&record1, sizeof(record1), 1, f_temp);
			m1 = fread(&record1, sizeof(record1), 1, *f1);
		}
		while(m2)
		{
			fwrite(&record2, sizeof(record2), 1, f_temp);
			m2 = fread(&record2, sizeof(record2), 1, f2);
		}

		if(rename( TEMPORAL_FILE, nuevo))
		{
			fclose(f_temp);
			return ERROR_NO_CHANGE_FILE_NAME;
		}

		fclose(f_temp);

		if(!remove(TEMPORAL_FILE))
			return ERROR_NO_REMOVE_FILE;

		return OK;
	}


	status_t perform_product_delete(product_t record1, product_t record2, FILE ** f1, FILE *f2, char * nuevo)
	{
	    size_t m1, m2;
	    FILE * f_temp;
	    size_t acum = 0;

	    m1 = fread(&record1, sizeof(record1), 1, *f1);
		m2 = fread(&record2, sizeof(record2), 1, f2);

		if( m2 == 0 )
		{
			fprintf(stderr, "%s\n", MSG_ERROR_FILE_EMPTY );
			return ERROR_FILE_DELETE_EMPTY;
		}

		f_temp = fopen(TEMPORAL_FILE,"wb");

		while(m1 && m2)
		{

			if(record1.id == record2.id)
				{
					m1 = fread(&record1, sizeof(record1), 1, *f1);
					m2 = fread(&record2, sizeof(record2), 1, f2);
					acum++;
					continue;
				}
			if(record1.id < record2.id)
			{
				fwrite(&record1, sizeof(record1), 1, f_temp);
				m1 = fread(&record1, sizeof(record1), 1, *f1);
			}else{
					fwrite(&record2, sizeof(record2), 1, f_temp);
					m2 = fread(&record2, sizeof(record2), 1, *f1);	
			}
		}
		if(!acum)
		{
			fprintf(stderr, "%s\n", MSG_ERROR_INVENTORY_PRODUCT_NO_AVAILABLE );
		    fclose(f_temp);
			return ERROR_INVENTORY_PRODUCT_NO_AVAILABLE;
		}

		while(m1)
		{
			fwrite(&record1, sizeof(record1), 1, f_temp);
			m1 = fread(&record1, sizeof(record1), 1, *f1);
		}
		if(m2)
		{
			fprintf(stderr, "%s\n", MSG_ERROR_DELETE_PRODUCT);
			fclose(f_temp);
			return ERROR_NO_DELETE_PRODUCT;
		}

		if(rename(TEMPORAL_FILE, nuevo))
		{
			fclose(f_temp);
			return ERROR_NO_CHANGE_FILE_NAME;
		}

		fclose(f_temp);

		if(!remove(TEMPORAL_FILE))
			return ERROR_NO_REMOVE_FILE;

		return OK;
	}
