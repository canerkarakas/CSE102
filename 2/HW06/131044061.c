#include<stdio.h>
#include<stdlib.h>

int find_size_of_line(char line[]){
	int i=0;
	int result=0;
	while(line[i]!='\0'){
		if(line[i]=='\n'){
			result++;
			i++;
		}
		else{
			i++;
		}
	}
	return result+1;
}

void reverse_line(char line[], int line_lenght[]){
	int lines = find_size_of_line(line);
	char temp[lines][1024];
	char ch;
	char count;
	int i=0, j=0, k=0;
	while(line[i]!='\0'){
		if(line[i]=='\n'){
			ch = line[i];
			temp[j][k] = ch;
			k=0;
			j++;
			i++;
		}
		else{
			ch = line[i];
			temp[j][k] = ch;
			k++;
			i++;
		}
	}
	temp[j][k] = '\0';
//	printf("reverse i=%d, j=%d, k=%d", i,j,k);
//	printf("\n\n");
	i=0;
	j=0;
	k=0;
	while(i<lines){
		if(line_lenght[k]%2==0){
			while(j<line_lenght[k]/2-1){
				ch = temp[i][line_lenght[k]-j-1];
				count = temp[i][j];
				temp[i][line_lenght[k]-j-1] = count;
				temp[i][j] = ch;
				j++;
			}
		//	temp[i][line_lenght[k]]='\n';
			i++;
			k++;
			j=0;
			}
		else{
			while(j<(line_lenght[k]-1)/2){
				ch = temp[i][line_lenght[k]-j-1];
				count = temp[i][j];
				temp[i][line_lenght[k]-j-1] = count;
				temp[i][j] = ch;
				j++;
			}
		//	temp[i][line_lenght[k]]='\n';
			i++;
			k++;
			j=0;
		}
	}
	temp[i-1][line_lenght[k-1]]='\0';
	i=0;j=0;k=0;
	int l=0;
	while(temp[i][j]!='\0'){
		while(j<=line_lenght[l]){
			ch = temp[i][j];
			line[k] = ch;
			j++;
			k++;
		}
		i++;
		j=0;
		l++;
	}
}

void encrypt_open_msg(){
	FILE *file, *file_2;
	file = fopen("open_msg.txt", "r");
	file_2 = fopen("secret_msg.txt", "w");
	char text[1024];
	int i;
	int j=0;
	char ch;
	int line_lenght[100];
	for(i=0;i<100;i++){
		line_lenght[i]=0;
	}
	i=0;
	int key;
	printf("Key: ");
	scanf("%d", &key);
	printf("\n");
	while(!feof(file)){
		fscanf(file, "%c", &ch);
		if(!feof(file)){
			if(ch=='\n'){
				text[i] = ch;
				j++;
				i++;
			}
			else{
				text[i] = ch;
				line_lenght[j] = line_lenght[j] + 1;
				i++;
			}
		}
		else{
			text[i] = '\0';
			line_lenght[j+1]='\0';
		}
	}
	i=0;
	while(text[i]!='\0'){
		printf("%c", text[i]);
		i++;
	}
	printf("\n\n");
	i=0;
	while(line_lenght[i]!='\0'){
		i++;
	}
	int lines = find_size_of_line(text);
	reverse_line(text, line_lenght);
	i=0;
	while(text[i]!='\0'){
		printf("%c", text[i]);
		i++;
	}
	printf("\n\n");
	int sum = 0;
	int k=0;
	for(i=0;i<lines;i++){
		sum = sum + line_lenght[k]+1;
		k++;
	}
	sum = sum - 1;
//	printf("sum=%d\n", sum);
	char count;
	for(i=0;i<sum;i++){
		ch=text[i];
		if(ch=='\n'){
			fprintf(file_2, "%c", ch);
		}
		if(ch!='\n' && ((ch-key<'a') && (ch!=' ' && ch != '.'))){
			count = ch;
			count = (count-key) + 26;
			text[i] = count;
			fprintf(file_2, "%c", text[i]);
		}
		if(ch!='\n' && ch==' '){
			text[i] = '_';
			fprintf(file_2, "%c", text[i]);
		}
		if(ch!='\n' && ch=='.'){
			text[i] = '*';
			fprintf(file_2, "%c", text[i]);
		}
		if(ch!='\n' && ((ch-key>='a') && (ch!=' ' && ch!='.'))){
			count = ch;
			count = count - key;
			text[i] = count;
			fprintf(file_2, "%c", text[i]);
		}
	}
	fclose(file);
	fclose(file_2);
}

void decrypt_secret_msg(){
	FILE *file, *file_2;
	file = fopen("secret_msg.txt", "r");
	file_2 = fopen("open_msg.txt", "w");
	char text[1024];
	int i;
	int j=0;
	char ch;
	int line_lenght[100];
	for(i=0;i<100;i++){
		line_lenght[i]=0;
	}
	i=0;
	int key;
	printf("Key: ");
	scanf("%d", &key);
	printf("\n");
	while(!feof(file)){
		fscanf(file, "%c", &ch);
		if(!feof(file)){
			if(ch=='\n'){
				text[i] = ch;
				j++;
				i++;
			}
			else{
				text[i] = ch;
				line_lenght[j] = line_lenght[j] + 1;
				i++;
			}
		}
		else{
			text[i] = '\0';
			line_lenght[j+1]='\0';
		}
	}
	i=0;
	while(text[i]!='\0'){
		printf("%c", text[i]);
		i++;
	}
	printf("\n\n");
	i=0;
	while(line_lenght[i]!='\0'){
		i++;
	}
	int lines = find_size_of_line(text);
	reverse_line(text, line_lenght);
	i=0;
	while(text[i]!='\0'){
		printf("%c", text[i]);
		i++;
	}
	printf("\n\n");
	int sum = 0;
	int k=0;
	for(i=0;i<lines;i++){
		sum = sum + line_lenght[k]+1;
		k++;
	}
	sum = sum - 1;
	char count;
	for(i=0;i<sum;i++){
		ch=text[i];
		if(ch=='\n'){
			fprintf(file_2, "%c", ch);
		}
		if(ch!='\n' && ((ch+key>'z') && (ch!='_' && ch != '*'))){
			count = ch;
			count = (count+key) - 26;
			text[i] = count;
			fprintf(file_2, "%c", text[i]);
		}
		if(ch!='\n' && ch=='_'){
			text[i] = ' ';
			fprintf(file_2, "%c", text[i]);
		}
		if(ch!='\n' && ch=='*'){
			text[i] = '.';
			fprintf(file_2, "%c", text[i]);
		}
		if(ch!='\n' && ((ch+key<='z') && (ch!='_' && ch != '*'))){
			count = ch;
			count = count + key;
			text[i] = count;
			fprintf(file_2, "%c", text[i]);
		}
	}
	fclose(file);
	fclose(file_2);
}

/*
 * 0: stops
 * 1: encrypt
 * 2: decrypt
 */
void menu(){
	int choice;
	int control = 0;
	do{
		printf("1. Encrypt\n2. Decrypt\n0. Exit\nChoice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:encrypt_open_msg();break;
			case 2:decrypt_secret_msg();break;
			case 0:control=1;break;
			default:;break;
		}
	}while(control==0);
}

int main(void){
	menu();
	return 0;
}
