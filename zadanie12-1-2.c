#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SUCCESS 0
#define IMPOSSIBLE 1


// Funkcia zmeni kodomenu relacie tak, aby bola nova mnozina Zsize_cod.
// Ak sa to neda, vrati IMPOSSIBLE, inac SUCCESS.
 

typedef struct{
	unsigned int m;  // домен (рядки)
	unsigned int n;  // кодомен (стовпці)
	char properties;
	char *matrix;   // матриця розміром m * n
} NURELM;
	
char nurelm_set_codomain(NURELM *to_redef, unsigned int size_cod){
	unsigned int old_n;
	unsigned int new_n;
	unsigned int m;
	unsigned int i, j;
	unsigned long long total_cells;
	char *new_matrix;
	size_t bytes_needed;
	
	//актуальні розміри
	m = to_redef->m;
	old_n = to_redef->n;
	new_n = size_cod;
	
    //окремий випадок
	if(m == 0){
		
		if(to_redef->matrix != NULL){
			free(to_redef->matrix);
		}
		
		if(new_n == 0){
			to_redef->matrix = NULL;
			to_redef->n = 0;
			return SUCCESS;
		}
		
		to_redef->matrix = NULL;
		to_redef->n = new_n;
		return SUCCESS;
	}
	
	//перевірка переповнення
	total_cells = (unsigned long long)m * (unsigned long long)new_n;
	
	if(new_n != 0 && (total_cells / new_n) != m)
	return IMPOSSIBLE;
	
	//виділення місця
	bytes_needed = (size_t)(total_cells * sizeof(char));
	
	new_matrix = (char*) malloc(bytes_needed);
	
	if(bytes_needed != 0 && new_matrix == NULL)
	return IMPOSSIBLE;
	
	//ініциалізація (візсутність нових звязків)
	for(i = 0; i < m; ++i){
		for(j = 0; j < new_n; ++j){
			new_matrix[i * new_n + j] = 0;
		}
	}
	
	//копіювання даних в нову матрицю
	if(to_redef->matrix != NULL){
		unsigned int limit = (old_n < new_n ? old_n : new_n);
		for(i = 0; i < m; ++i){
			for(j = 0; j < limit; ++j)
			new_matrix[i * new_n + j] = to_redef->matrix[i * old_n + j];
		}
		free(to_redef->matrix);
	}
	
	//закріплення нових значень
	to_redef->n = new_n;
	to_redef->matrix = new_matrix;
	
	return SUCCESS;
};

void print_matrix (NURELM *rel){
	unsigned int i, j;
	printf("Matrix %u x %u:\n", rel->m, rel->n);
	for (i = 0; i < rel->m; ++i) {
        for (j = 0; j < rel->n; ++j) {
            // Звернення як до одновимірного масиву
            printf("%d ", rel->matrix[i * rel->n + j]);
        }
        printf("\n");
    }
}

int main(){
	
	return 0;
}
