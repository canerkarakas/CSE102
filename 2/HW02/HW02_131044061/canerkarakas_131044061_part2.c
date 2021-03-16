#include<stdio.h>

int input_number(void){																			//istenilen aralikta sayi girip girilmedigini kontrol eder ve dogru sayilari return eder
	int number;
	int control = 0;
	printf("Enter the number: ");
	scanf("%d", &number);
	while(control == 0){
		if(23>number || number>98760){
			printf("You must enter a number between 23 and 98760\n");
			printf("Please try again: ");
			scanf("%d", &number);
		}
		else{
			control = 1;
		}
	}
	return number;
}

void output_screen(int number){															//yapilan islemler sonucu ekrana cikti verir. girilen sayilari basamaklarina ayirir
	if(number<100){
		int first, second;
		first = number % 10;
		number = number - first;
		second = number / 10;
		printf("The second digit is %d\n", second);
		printf("The first digit is %d\n", first);
	}
	if(number<1000 && number>=100){
		int first, second, third, counter;
		counter = number % 100;
		first = counter % 10;
		second = (counter - first) / 10;
		number = number - counter;
		third = number / 100;
		printf("The third digit is %d\n", third);
		printf("The second digit is %d\n", second);
		printf("The first digit is %d\n", first);
	}
	if(number<10000 && number>=1000){
		int first, second, third, fourth, counter1, counter2;
		counter1 = number % 1000;
		counter2 = counter1 % 100;
		first = counter2 % 10;
		second = (counter2 - first) / 10;
		third = (counter1 - counter2) / 100;
		fourth = (number - counter1) / 1000;
		printf("The fourth digit is %d\n", fourth);
		printf("The third digit is %d\n", third);
		printf("The second digit is %d\n", second);
		printf("The first digit is %d\n", first);
	}
	if(number>=10000 && number<=98760){
		int first, second, third, fourth, fifth, counter1, counter2, counter3;
		counter1 = number % 10000;
		counter2 = counter1 % 1000;
		counter3 = counter2 % 100;
		first = counter3 % 10;
		second = (counter3 - first) / 10;
		third = (counter2 - counter3) / 100;
		fourth = (counter1 - counter2) / 1000;
		fifth = (number - counter1) / 10000;
		printf("The fifth digit is %d\n", fifth);
		printf("The fourth digit is %d\n", fourth);
		printf("The third digit is %d\n", third);
		printf("The second digit is %d\n", second);
		printf("The first digit is %d\n", first);
	}
}

int main(void){
	int number;
	number = input_number();
	output_screen(number);
	return(0);
}
