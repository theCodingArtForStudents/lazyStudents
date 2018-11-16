#include <string.h>     /* strtok */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */

int main(int argc, char** argv) {
	/* ������ http://kpolyakov.spb.ru/school/c/faq.htm#rus
	   ��� ����������� �������� -fexec-charset=cp866 -finput-charset=cp1251
	   � Tools -> Compiler Options -> Add the following commands when calling the compiler:
	   � ��������� ��� �����
	*/
	printf("\n��������� ��� ������ � ������� (.txt ����)");
	/* ������ ��� ����� ��� ���������� 
	   � ��� �� �����, ��� � ������!
	   ���� � ������ �����, �� ����� ������ ����
	*/
	char *filename = "book1.txt";  
	FILE *fp = fopen(filename, "r");
	if(fp == NULL) { 
		printf("\n�� ������� ������� ���� %s \n", filename);
		/* ������� Press any key ... ����� � ����� ������ */
	    system("Pause");
		exit(1); /* ��������� ��������� � ������� 1 */        
	}
	printf("\n������ ���� %s", filename);
	char stroka [1024] = {"\0"};
	unsigned long int count = 0; /* ������� ���� */
	while(!feof(fp)) /* ��������� ��������� ���� �� ����� ����� */
	{
		if (fgets(stroka, 1024, fp)){ /* ������� �� ������ ������ */
		    char* delimiters = "\" ,.-?:;!"; /*������ ������������ ���� */
			char *pch = strtok (stroka,delimiters); /* ��������� ������ ����� */
    		while (pch != NULL)
    		{
    			printf ("\n%s",pch); /* �������� ����� */
    			count ++;             
    			pch = strtok (NULL, delimiters); /* ��������� ��������� ����� */
    		}
		}
	}
	printf("\n������� %ld ����", count);
	fclose(fp);
	printf("\n"); /* ������� Press any key ... ����� � ����� ������ */
	system("Pause");
	return 0;
}
