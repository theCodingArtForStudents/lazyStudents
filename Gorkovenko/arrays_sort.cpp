// arrays_sort.cpp  
// Encoding  UTF-8

#include <iostream>  /* cin, cout    */
#include <stdlib.h>  /* srand, rand  */

using namespace std; /* для cin, cout */

int main(int argc, char** argv) 
{	
	int a[200] = {0};
       
        /* Задаем начальное значение в генераторе случайных чисел */
        srand(666);   

        /* 
           Генерируем массив из случайных чисел в диапазоне 
           (-RAND_MAX/2; +RAND_MAX/2)
        */
        for (int i = 0; i<200; i++){
			a[i] = rand() - (int)(RAND_MAX/2.0);
			//cout << a[i] << "  ";	
		}

	/* 
        Здесь вставляйте свой код! 
        */

	int div19count = 0;
	int sumOfEvery30th = 0;

	for( int i = 0; i < 200; i++){
		if( a[i] % 19 == 0 ){ // if item is dividend for 19 
			div19count++; // increment this counter
		}
			// the items of array numbers from 0, them 30-th item numbers as 29
		if( i % 29 == 0 ){ // if i equals 29*n 
			sumOfEvery30th += a[i]; // this item of the array adds to summ of 
		}
	}
	int buf;
	char swap = 0;

	int array_size = 200;
	int i = 0;
	while (i < array_size){
		if (i + 1 != array_size && a[i] > a[i + 1]){
			buf = a[i];
			a[i] = a[i + 1];
			a[i + 1] = buf;
			swap = 1;
		}
		i++;
		if (i == array_size && swap == 1){
			swap = 0;
			i = 0;
		}
	}

	printf(" the maximum item: %d " \
		   "\n count of items are divides on 19: %d " \
		   "\n sum of every 30th: %d\n", a[199], div19count, sumOfEvery30th);

	printf("sorted array:\n");

	for (int i = 0; i < 200; ++i)
	{
		printf("\t #%d:\t%d \n", i, a[i]);
	}


//////////////////////////////////////////////////////////

  	// int b[100][100] = {0}; /* инициализируем нулями */
	
	/* Задаем начальное значение в генераторе случайных чисел */
	// srand(666);
	 
	/* 
        Генерируем массив из случайных чисел в диапазоне 
		[-500; 499] 
	*/
		 
	// for (int i = 0; i<100; i++){
	// 	for (int j = 0; j<100; j++){
	// 		a[i][j] = rand()%1000 - 500;
	// 	}
	// }

        /* 
        Здесь вставляйте свой код! 
        */

	system("Pause");
	return 0;
}