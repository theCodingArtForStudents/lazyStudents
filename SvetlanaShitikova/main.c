#include "math.h"
#include <stdlib.h>

int main(){
	struct matrix *M;

	A = init_square_matrix(3);
	B = init_square_matrix(3);
	A->item = {{3,3,3},
		       {3,3,3},
		       {3,3,3}
		  	  };

	B->item = {{4,4,4},
               {4,4,4},
               {4,4,4}
              };

	print_matrix( M );

	free( M );
}
