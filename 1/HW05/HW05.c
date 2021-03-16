#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*dosyadaki karakter sayisini hesaplayan fonksiyon*/
int lenFile(FILE *file){
	char ch;
	int i=0;
	while(feof(file)==NULL){
		ch = fgetc(file);
		i++;
	}
	return i;
}


/*dosyadan n gram (bi-gram) hesabini yapmak icin n(n==2) kadar karakter alacak fonksiyon*/
void bies(FILE *file, char *ch, char letter, int n){
	letter = getc(file);
	if(letter=='\n' && n==2){
		letter = getc(file);
		bies(file, ch, letter, n);
	}
	if(letter=='\n' && n==1 && ch[0]==' '){
		ch[0] = '\0';
		n=2;
		letter = getc(file);
		bies(file, ch, letter, n);
	}
	if(letter=='\n' && n==1 && 'a'<=ch[0] && ch[0]<='z'){
		ch[1] = ' ';
		n=2;
		letter = getc(file);
		bies(file, ch, letter, n);
	}
	if(letter==' ' && n==2){
		ch[0] = letter;
		n=1;
		letter = getc(file);
		bies(file, ch, letter, n);
	}
	if(letter==' ' && n==1 && ch[0]==' '){
		letter = getc(file);
		bies(file, ch, letter, n);
	}
	if(letter==' ' && n==1 && 'a'<=ch[0] && ch[0]<='z'){
		ch[1] = letter;
		n=0;
	}
	if('a'<=letter && letter<='z' && n==2){
		ch[0] = letter;
		n=1;
		letter = getc(file);
		bies(file, ch, letter, n);
	}
	if('a'<=letter && letter<='z' && n==1){
		ch[1] = letter;
		n=0;
	}
}


int ngram(FILE *file, char *ch){
	int n = 2, n1 = 2;
	char letter1, letter2;
	int count1=0;
	int count2=0;
	char *counter;
	int len = lenFile(file);
	while(feof(file)==NULL){
		bies(file, ch, letter1, n);
		printf("%c%c\n", ch[0],ch[1]);
		while(feof(file)==NULL){
			bies(file, counter, letter2, n1);
			if(counter[0]==ch[0] && counter[1]==ch[1]){
				count1++;
				count2=count2+count1;
			}
			else{
				count1=0;
			}
		}
	}
	return count2;
}







int main(void){
	FILE *language_1, *language_2, *language_3, *language_4, *language_5, *language_x;
	language_1 = fopen("*language_1.txt", "r");
	language_2 = fopen("*language_2.txt", "r");
	language_3 = fopen("*language_3.txt", "r");
	language_4 = fopen("*language_4.txt", "r");
	language_5 = fopen("*language_5.txt", "r");
	language_x = fopen("*language_x.txt", "r");
	
	char *ch;
	int a = ngram(language_1, ch);
	printf("%d", a);
	fclose(language_1);
	
}


