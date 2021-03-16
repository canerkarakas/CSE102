/*HW06_CANER_KARAKAS_131044061*/

#include<stdio.h>
/*dosyadaki karakterleri arraye atariz*/
void addArr(FILE *file, char *ch){
	int i=0;
	while(feof(file)==NULL){
		ch[i] = fgetc(file);
		i++;
	}
	ch[i] = '\0';
}
/*karakterleri istenilen sekilde ekrana basariz*/
void stdPrint(char *ch, int control, int i, int j){
	if(ch[i]<=122 && ch[i]>=65){							//harf alirsak
		if(control!=0){										//parantez kontrolu
			for(j=0;j<control;j++){
				printf("-");								//acilan parantez kadar tire basar
			}
		}
		printf("%c\n", ch[i]);								//alinan karakter basilir
		stdPrint(ch, control, i+1, j);						//update edilir fonksiyon tekrar cagirilir bu sayede recursion baslar
	}
	if(ch[i]==40){											//acilan parantezlerde arttirilir ve tekrar cagirilir
		stdPrint(ch, control+1, i+1, j);
	}
	if(ch[i]==41){											//kapanan parantezlerde azaltilir ve tekrar cagirilir
		stdPrint(ch, control-1, i+1, j);
	}
	if(ch[i]==','){											//virgullerde tekrar cagirilir
		stdPrint(ch, control, i+1, j);
	}
}

int main(void){
	FILE *inp;
	inp = fopen("input.txt", "r");							//dosya acilir
	char ch[100];
	addArr(inp, ch);										//arraye aktarilir
	int control = 0;
	int i = 0;
	int j;
	stdPrint(ch, control, i, j);							//stdout basilir
	fclose(inp);											//dosya kapanir
}
