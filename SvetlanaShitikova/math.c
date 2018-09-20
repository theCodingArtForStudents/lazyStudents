#include "math.h"

#include <malloc.h>


int n_add(int a, int b){
	return a + b;
}
int n_sub(int a, int b){
	return a - b;
}
int n_mul(int a, int b){
	return a * b;
}
int n_div(int a, int b){
	return a / b;
}
int n_mod(int a, int b){
	return a % b;
}

// matrix 

struct matrix* init_matrix(int n, int m){
	struct matrix *A = malloc(sizeof( struct matrix ) );
	
	A->raw = n;
	A->col = m;
	A->item = calloc(n, sizeof(double));
	for(int i = 0; i < n; i++){
		A->item[i] = calloc(m, sizeof(double));
		for(int j = 0; j < m; j++){
			A->item[i][j] = 0;
		}
	}

	return A; 
}
struct matrix* init_square_matrix(int nm){
	return init_matrix(nm, nm);
}




void toString_matrix(const struct matrix* A){
	for(int i = 0; i < A->raw; i++){
		for(int j = 0; j < A->col; j++){
			printf("%.4f ", A->item[i][j]);
		}
		printf("\n");
	}
}

