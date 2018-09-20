#include "math.h"
#include <stdlib.h>

int main(){
	struct matrix *M;

	M = init_square_matrix(3);
	toString_matrix( M );

	free( M );
}
