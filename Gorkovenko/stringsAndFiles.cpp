#include <string.h>     /* strtok */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */

int main(int argc, char** argv) {
	/* отсюда http://kpolyakov.spb.ru/school/c/faq.htm#rus
	   для русификации добавьте -fexec-charset=cp866 -finput-charset=cp1251
	   в Tools -> Compiler Options -> Add the following commands when calling the compiler:
	   и поставьте там галку
	*/
	printf("\nПрограмма для работы с текстом (.txt файл)");
	/* задаем имя файла для считывания 
	   в той же папке, что и проект!
	   если в другой папке, то пишем полный путь
	*/
	char *filename = "book1.txt";  
	FILE *fp = fopen(filename, "r");
	if(fp == NULL) { 
		printf("\nНе удалось открыть файл %s \n", filename);
		/* надпись Press any key ... будет с новой строки */
	    system("Pause");
		exit(1); /* завершаем программу с ошибкой 1 */        
	}
	printf("\nОткрыт файл %s", filename);
	char stroka [1024] = {"\0"};
	unsigned long int count = 0; /* счетчик слов */
	unsigned long int countGl = 0;
	while(!feof(fp)) /* считываем построчно пока не конец файла */
	{
		if (fgets(stroka, 1024, fp)){ /* считали не пустую строку */
		    char* delimiters = "\" ,.-?:;!"; /*строка разделителей слов */
			char *pch = strtok (stroka,delimiters); /* считываем первое слово */
    		while (pch != NULL)
    		{
    			// printf ("\n%s",pch); /* печатаем слово */
    			if( strcmp(pch, "dog") == 0){
    				count ++;                			
    			}
    			
    			int cnt=0;
				char* p=strstr(pch, "i");
				do
				{
				   if(p != NULL)
				      cnt++;
				   p = strstr( p+1, "i");
				}while( p != NULL );

				if( cnt >= 2 ){
					countGl++;
				}

    			pch = strtok (NULL, delimiters); /* считываем следующее слово */
    		}
		}
	}
	printf("\nНайдено %ld слов"\
		   "\nНайдено %ld слов  содержащих гласные i ", count, countGl);
	fclose(fp);
	printf("\n"); /* надпись Press any key ... будет с новой строки */
	system("Pause");
	return 0;
}
