#include "math.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	struct matrix *A, *B, *C;

	A = init_square_matrix(3);
	B = init_square_matrix(3);	

	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			A->item[i][j] = 3;
			B->item[i][j] = 4;
		}
	}

    printf("matrix A:\n");
	print_matrix( A );
	printf("matrix B:\n");
	print_matrix( B );
    
    C = add_M(A, B);
    printf("matrix C are summ of A and B:\n");
    print_matrix( C );
    free_matrix( C );

	C = mul_M(A, B);
    printf("matrix C are multiplex of A and B:\n");
    print_matrix( C );
    free_matrix( C );

    C = sub_M(A, B);
    printf("matrix C are substraction of A and B:\n");
    print_matrix( C );
    free_matrix( C );

	free_matrix( A );
	free_matrix( B );
	free_matrix( C );
}
