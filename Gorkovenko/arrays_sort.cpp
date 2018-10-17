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
////////////////////
	int div19count = 0;
	int sumOfEvery50th = 0;

	for( int i = 0; i < 200; i++){
		if( a[i] % 19 == 0 ){ // if item is dividend for 19 
			div19count++; // increment this counter
		}
			// the items of array numbers from 0, them 30-th item numbers as 29
		if( i % 49 == 0 ){ // if i equals 29*n 
			sumOfEvery50th += a[i]; // this item of the array adds to summ of 
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

	printf(" the minimum item: %d " \
		   "\n count of items are divides on 19: %d " \
		   "\n sum of every 50th: %d\n" \
		   "\n item 100: %d\n", a[0], div19count
		   					, sumOfEvery50th, a[100]);

	printf("sorted array:\n");

	for (int i = 0; i < 200; ++i)
	{
		printf("\t #%d:\t%d \n", i, a[i]);
	}


//////////////////////////////////////////////////////////

  	int b[100][100] = {0}; /* инициализируем нулями */
	
	/* Задаем начальное значение в генераторе случайных чисел */
	srand(666);
	 
	/* 
        Генерируем массив из случайных чисел в диапазоне 
		[-500; 499] 
	*/
		 
	for (int i = 0; i<100; i++){
		for (int j = 0; j<100; j++){
			b[i][j] = rand()%1000 - 500;
		}
	}

        /* 
        Здесь вставляйте свой код! 
        */

	int min = b[0][0];
	int lastMinNum_I = 0,
		lastMinNum_j = 0;

	int sumOf_sideDiog = 0;

	swap = 0;
	array_size = 100;

	for (int i = 0; i < array_size; ++i){
		for (int j = 0; j < array_size; ++j)
		{
			if( i + 1 != array_size && b[i][j] > b[i+1][j]){
				lastMinNum_I = i+1;
				lastMinNum_j = j;
				swap = 1;
			}				
			else if(j + 1 != array_size && b[i][j] > b[i][j+1]){
				lastMinNum_I = i;
				lastMinNum_j = j+1;
				swap = 1;
			}
			else if (i + 1 != array_size 
					 && j + 1 != array_size 
					 && b[i][j] > b[i+1][j+1] 
					){
				
				lastMinNum_I = i+1;
				lastMinNum_j = j+1;	
				swap = 1;
			}

			if (i == array_size && j == array_size && swap == 1){
				swap = 0;
				i = 0;
				j = 0;
			}

			if( i == array_size - 1 - j ){

				sumOf_sideDiog += b[i][j];
				
			}
		}
	}

	cout << "minimum item num: " << lastMinNum_I << "; " << lastMinNum_j << endl
		 << "summ: " << sumOf_sideDiog << endl;

	system("Pause");
	return 0;
}