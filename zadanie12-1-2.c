#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SUCCESS 0
#define FAIL 1


// Funkcia zmeni kodomenu relacie tak, aby bola nova mnozina Zsize_cod.
// Ak sa to neda, vrati FAIL, inac SUCCESS.
 

typedef struct{
	unsigned int m;  // домен (рядки)
	unsigned int n;  // кодомен (стовпці)
	char properties;
	char *matrix;   // матриця розміром m * n
}NURELM;
	
char nurelm_set_codomain(NURELM *to_redef, unsigned int size_cod){
	unsigned int old_n;
	unsigned int new_n;
	unsigned int m;
	unsigned int i;
	unsigned int j;
	unsigned long long total_cells;
	char *new_matrix;
	size_t bytes_needed;
	
	//актуальні розміри
	m = to_redef->m;
	old_n = to_redef->n;
	new_n = size_cod;
	

	if(m==0){
		
		if(to_redef->matrix != NULL){
			free(to_redef->matrix);
		}
		
		if(new_n==0){
			to_redef->matrix = NULL;
			to_redef->n = 0;
			return SUCCESS;
		}
		
		to_redef->matrix = NULL;
		to_redef->n = 0;
		return SUCCESS;
	}
	
};

int main(){
	
	return 0;
}
