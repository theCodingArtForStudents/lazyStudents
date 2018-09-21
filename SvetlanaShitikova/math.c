#include "math.h"

#include <malloc.h>
#include <errno.h>

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


struct matrix* fill_item_matrix(struct matrix* A, double item, 
				unsigned int tokenN, unsigned int tokenM){

	if( A == NULL ){
                perr("fill_item_matrix:Matrix does not exist");
                exit(1);
        }

	if( tokenN > A->raw || tokenM > A->col ){
		perror("Invalid token");
		exit( 2000 );
	}

	A->item[tokenN][tokenM] = item;

	return A;
}

struct matrix* minor_matrix(struct matrix* A, unsigned int n, unsigned int m){

	if( A == NULL ){
                perr("minor_matrix:Matrix does not exist");
                exit(1);
        }

	if( A->raw != A->col ){
		perr("minor_matrix: Matrix does not square");
		exit(2020);
	}

        if( n > A->raw || m > A->col ){
                perror("minor_matrix:Invalid token");
                exit( 2001 );
        }

	struct matrix* minor = init_square_matrix( A->raw - 1 );

        for(int i = 0; i < A->raw; i++){
		int di = 0;
		if( i == n ) 
			di = 1;

		int dj = 0;

		for(int j = 0; j < A->raw; j++){
			if( j == m )
				dj = 1;

			minor->item[i][j] = A->item[i + di][j + dj];
		}
	}

        return minor;
}


// matrix math

double determinant_M(const struct matrix* A){

	if( A == NULL ){
                perr("determinant_M: Matrix does not exist");
                exit(1);
        }

	double det = 0;
	short k = 1;

	if( A->raw == 1 )
		return A->item[0][0];
	else
	if( A->raw == 2 )
		return A->item[0][0] * A->item[1][1] - A-item[1][0] * A->item[0][1];
	else if( A->raw > 2 ){
		for(int i = 0; i < A->raw; i++){
			struct matrix* minor = minor_matrix( A, i, 0 );

			det += k * A->item[i][0] * determinant_M( minor );

			k *= -1;

			free( minor );
		}
	}else{
		perr("determinant_M: Invalid matrix");
		exit(2);
	}

	return det;
}

struct matrix* add_M(const struct matrix* A, const struct matrix* B){
	if( A == NULL || B == NULL ){
        	perr("add_M:Matrix does not exist");
        	exit(1);
        }

	if( A->raw != B->raw || A->col != B->col ){
		perr("add_M:Incorrect size of matrices");
                exit(2011);

	}

	struct matrix* RES = init_matrix(A->raw, B->col);

	for(int i = 0; i < A->raw; i++){
                for(int j = 0; j < A->col; j++){
                        RES->item[i][j] = A->item[i][j] + B->item[i][j];
                }
        }

	return RES;
}

struct matrix* sub_M(const struct matrix* A, const struct matrix* B){
        if( A == NULL || B == NULL ){
                perr("sub_M:Matrix does not exist");
                exit(1);
        }

        if( A->raw != B->raw || A->col != B->col ){
                perr("sub_M:Incorrect size of matrices");
                exit(2012);

        }

        struct matrix* RES = init_matrix(A->raw, B->col);

        for(int i = 0; i < A->raw; i++){
                for(int j = 0; j < A->col; j++){
                        RES->item[i][j] = A->item[i][j] - B->item[i][j];
                }
        }

        return RES;
}


struct matrix* mul_M(const struct matrix* A, const struct matrix* B){

	if( A == NULL || B == NULL ){
		perr("mul_M:Matrix does not exist");
		exit(1);
	}

	if(A->raw !=  B->col){
		perr("mul_M:Incorrect size of matrices");
		exit(2013);
	}

	struct matrix* RES = init_matrix(A->raw, B->col);

	for(int i = 0; i < A->raw; i++){
		for(int j = 0; j < B->col; j++){
			RES->item[i][j] += A->item[i][j] * B->item[j][i];
		}
	}

	return RES;
}
struct matrix* mul_d_M(const struct matrix* A, const double b){

	if( A == NULL ){
                perr("mul_d_M:Matrix does not exist");
                exit(1);
        }

	struct matrix* RES = init_matrix(A->raw, A->col);

	for(int i = 0; i < A->raw; i++){
		for(int j = 0; j < A->col; j++){
			RES->item[i][j] = A->item[i][j] * b;
		}
	}

	return RES;
}

struct matrix* div_M(const struct matrix* A, const struct matrix* B){

        if( A == NULL || B == NULL ){
                perr("div_M:Matrix does not exist");
                exit(1);
        }

        if(A->raw !=  B->col){
                perr("div_M:Incorrect size of matrices");
                exit(2014);
        }

        struct matrix* RES = init_matrix(A->raw, B->col);

        for(int i = 0; i < A->raw; i++){
                for(int j = 0; j < B->col; j++){
                        RES->item[i][j] += A->item[i][j] * /* /todo B^-1*/B->item[j][i];
                }
        }

        return RES;
}

struct matrix* invers_M(const struct matrix* A);

// /matrix math




char* toString_matrix(const struct matrix* A){
	char *c_matrix = calloc( (A->raw * A->col * 2), sizeof(char));

	for(int i = 0; i < A->raw; i++){
		for(int j = 0; j < A->col; j++){
			sprintf(c_matrix, "%.4f ", A->item[i][j]);
		}
		sprintf(c_matrix, "\n");
	}

	return c_matrix;
}

void print_matrix(const struct matrix*){
	printf("%s", sprintf(matrix));
}
