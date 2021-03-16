#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ROW_LEN 250
#define MAX_ROW 100

int row_num(FILE *, char );										//kaç tane satýrdan oluþtuðunu sayacak fonksiyon.

int main(void){
	FILE *inp;
	char ch;
	char **str;
	inp = fopen("input.txt", "r");
	int row = row_num(inp, ch);
	printf("%d", row);
	
	
}

int row_num(FILE *inp, char ch){
	int rows=0;
	int i=0, j=0;
	char str[MAX_ROWS][];
	do{
		ch = getc(inp);
		
		if(ch=='\n'){
			rows++;
		}
	}while(ch!=EOF);
	return rows;
}

