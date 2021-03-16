#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct linked_list{
	int data;
	struct linked_list *next;
}n;

void read_file(FILE *file, int *arr);
void add_linked(int number);
int sizeof_file(FILE *file);
int is_prime(int number);
void output_dyn_arr_3(FILE *file, int *arr, int arr_len);


n *start = NULL; //linked listin ilk yapisi baslangici
n *temp; //genel gecici yapi

//dosya okunup array ve linked list oluþturulur
void read_file(FILE *file, int *arr){
	int number;
	int i=0;
	while(!feof(file)){
		if(!feof(file)){
			fscanf(file,"%d,00\n", &number);
			add_linked(number);
			arr[i] = number;
			printf("%d ", arr[i]);
			i++;
		}
	}
}

//linked listin sonuna ekleme yapacak fonksiyon
void add_linked(int number){
	n *temp;
	n *new_n = (n*)malloc(sizeof(n));
	new_n->data = number;
	new_n->next = NULL;
	if(start == NULL){
		start = new_n;
	}
	else{
		temp = start;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new_n;
	}
	
}

//dosyanin boyutunu bulacka fonksiyon
int sizeof_file(FILE *file){
	int n=1;
	char c;
	while(!feof(file)){
		fscanf(file, "%c", &c);
		if(c=='\n'){
			n++;
		}
	}
	return n;
}

//sayi asal degilse -1 dondur
int is_prime(int number){
	int i, result, k=0;
	for(i=2;i<=number;i++){
		if(number%i==0){
			k++;
		}
	}
	if(k>1){
		result = -1;
	}
	if(k==1){
		result = number;
	}
	return result;
}

//1-1.000.000
void output_dyn_arr_3(FILE *file, int *arr, int arr_len){
	fprintf(file, "\n\n<<<1-1.000.000>>>\n\n");
	int i=0;
	int control;
	time_t start, end, total;
	time(&start);
	while(i<arr_len){
		control = is_prime(arr[i]);
		if(control!=-1){
			fprintf(file, "%d\n", arr[i]);
			i++;
		}
		else{
			i++;
		}
	}
	time(&end);
	total = difftime(end, start);
	fprintf(file, "1-1.000.000%.2lf", total);
}

//1-750.000
void output_dyn_arr_2(FILE *file, int *arr, int arr_len){
	fprintf(file, "\n\n<<<1-750.000>>>\n\n");
	int i=0;
	int control;
	time_t start, end, total;
	time(&start);
	while(arr[i]<=750000){
		control = is_prime(arr[i]);
		if(control!=-1){
			fprintf(file, "%d\n", arr[i]);
			i++;
		}
		else{
			i++;
		}
	}
	time(&end);
	total = difftime(end, start);
	fprintf(file, "1-750.000>>>%.2lf", total);
}

//1-500.000
void output_dyn_arr_1(FILE *file, int *arr, int arr_len){
	fprintf(file, "\n\n<<<1-1.000.000>>>\n\n");
	int i=0;
	int control;
	time_t start, end, total;
	time(&start);
	while(arr[i]<=500000){
		control = is_prime(arr[i]);
		if(control!=-1){
			fprintf(file, "%d\n", arr[i]);
			i++;
		}
		else{
			i++;
		}
	}
	time(&end);
	total = difftime(end, start);
	fprintf(file, "1-500.000>>>%.2lf", total);
}

int main(void){
	FILE *file;
	file = fopen("data.txt", "r");
	int len_file = sizeof_file(file);
	fclose(file);
	
	file = fopen("data.txt", "r");
	int *numbers;
	numbers = (int*)calloc(len_file, sizeof(int));
	read_file(file, numbers);
	fclose(file);
	
	file = fopen("output_prime_dynamic_array.txt", "w");
	output_dyn_arr_1(file, numbers, len_file);
	output_dyn_arr_2(file, numbers, len_file);
	output_dyn_arr_3(file, numbers, len_file);
	fclose(file);
}
