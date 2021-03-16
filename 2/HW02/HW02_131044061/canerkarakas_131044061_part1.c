#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int number_of_students(void){																//kullanicidan kac ogrenci olacaginin bilgisi alinir. Ýstenilen aralikta olup olmadigi kontrol edilir ve istenilen sayi return yapilir
	int num;
	int control = 0;
	while(control==0){
		printf("Enter student count:");
		scanf("%d", &num);
		if(3<=num){
			if(num<=50){
				control = 1;
			}
			else{
				printf("\nNot in Range!!!\n");
			}
		}
		else{
			printf("\nNot in Range!!!\n\n");
		}
	}
	return num;
}

char letter_grades(int grade){																//harf notu bilinmek istenilen puan gonderilir, araligi hesaplanip harf notu return edilir
	char letter_grade;
	if(grade>=90){
		letter_grade = 'A';
	}
	if(grade>=80 && grade<=89){
		letter_grade = 'B';
	}
	if(grade>=70 && grade<=79){
		letter_grade = 'C';
	}
	if(grade>=60 && grade<=69){
		letter_grade = 'D';
	}
	if(grade<=59){
		letter_grade = 'F';
	}
	return letter_grade;
}

double calculate_average(int sum, int num){													//puanlarin toplami ve ogrenci sayisi gonderilir, ortalamasi hesap edilir ve ortalama deger return edilir
	double result;
	result = (double)sum / num;
	return result;
}

void menu(int num){
	srand(time(NULL));		//program farkli sayilar uretebilmesi icin kullanilir
	int i;
	int grade;
	int most_succcessfully_student_score, most_successfully_student_index;
	int most_unsuccessfully_student_score, most_unsuccessfully_student_index;
	char most_successfully_student_letter, most_unsuccessfully_student_letter;
	char letter;
	
	most_succcessfully_student_score = 0;		//en yuksek notu bulmak icin en dusuk puan atanir
	most_unsuccessfully_student_score=101;		//en dusuk notu bulmak icin aralik disi yuksek puan atanir
	
	int a,b,c,d,f;		//harf notlarinin istatistigi icin kullanilir
	a=0;
	b=0;
	c=0;
	d=0;
	f=0;
	int sum = 0;		//puanlarin toplami tutulur
	double average;		//ortalama tutulur
	for(i=0;i<num;++i){
		grade = rand()%100;		//random sayi atmak icin kullanilir
		printf(" %d", grade);
		sum = sum + grade;		//toplam her girilen sayi ile update edilir
		letter = letter_grades(grade);		//her girilen sayinin harf notu belirlenir
		if(grade>most_succcessfully_student_score){		//en basarili ogrenci bilgilerini bulmak ve tutmak icin kontrol edilir
			most_succcessfully_student_score = grade;		//en basarili ogrenci notu update edilir
			most_successfully_student_index = i;		//ogrencinin yeri update edilir.
			most_successfully_student_letter = letter_grades(most_succcessfully_student_score);		//ogrencinin harf notu update edilir
		}
		if(grade<most_unsuccessfully_student_score){		//en basarisiz ogrenci bilgilerini bulmak ve tutmak icin kontrol edilir(en basarili ogrenciyi bulmak icin kullandigimiz islemleri kullaniriz)
			most_unsuccessfully_student_score = grade;
			most_unsuccessfully_student_index = i;
			most_unsuccessfully_student_letter = letter_grades(most_unsuccessfully_student_score);
		}
		switch(letter){		//harf notlarinin istatistigi guncellenir
			case 'A': a++;break;
			case 'B': b++;break;
			case 'C': c++;break;
			case 'D': d++;break;
			default: f++;
		}
	}
	average = calculate_average(sum, num);		//ortalama bulunur
	
	int choice;		//menuden secimi icin kullanilir
	while(-1){		//menu surekli acilmasi herhangi bir sekilde kapanmamasi icin sonsuz dongu olusturlur
		printf("\n\n-------------------------------------\n\n");
		printf("\nStudent Score Calculator Menu for %d Student\n\n", num);
		printf("1) Most Successful Student\n");
		printf("2) Most Unsuccessful Student\n");
		printf("3) Letter Grade Statistics\n");
		printf("4) Calculate Average\n");
		printf("5) Show all Data\n");
		printf("		Make Selection: ");
		scanf("%d", &choice);
		if (choice == 1){
			printf("\nMost Successfully student: \n");
			printf("Index %d: \n", most_successfully_student_index);
			printf("Score %d: \n", most_succcessfully_student_score);
			printf("Letter grade: %c", most_successfully_student_letter);
			printf("\n");
		}
		if (choice == 2){
			printf("\nMost Unsuccessfully student: \n");
			printf("Index %d: \n", most_unsuccessfully_student_index);
			printf("Score %d: \n", most_unsuccessfully_student_score);
			printf("Letter grade: %c", most_unsuccessfully_student_letter);
			printf("\n");
		}
		if(choice == 3){
			printf("\n%d student got letter grade 'A'\n", a);
			printf("\n%d student got letter grade 'B'\n", b);
			printf("\n%d student got letter grade 'C'\n", c);
			printf("\n%d student got letter grade 'D'\n", d);
			printf("\n%d student got letter grade 'F'\n", f);
		}
		if(choice == 4){
			printf("\nThe avarage Score of %d Student is %.2f\n", num, average);
		}
		if(choice == 5){
			printf("\nMost Successfully student: \n");
			printf("Index %d: \n", most_successfully_student_index);
			printf("Score %d: \n", most_succcessfully_student_score);
			printf("Letter grade: %c", most_successfully_student_letter);
			printf("\n");
			printf("\nMost Unsuccessfully student: \n");
			printf("Index %d: \n", most_unsuccessfully_student_index);
			printf("Score %d: \n", most_unsuccessfully_student_score);
			printf("Letter grade: %c", most_unsuccessfully_student_letter);
			printf("\n");
			printf("\n%d student got letter grade 'A'\n", a);
			printf("\n%d student got letter grade 'B'\n", b);
			printf("\n%d student got letter grade 'C'\n", c);
			printf("\n%d student got letter grade 'D'\n", d);
			printf("\n%d student got letter grade 'F'\n", f);
			printf("\nThe avarage Score of %d Student is %.2f\n", num, average);
		}
		if(choice == -1){
			printf("\nShutting down...");
			exit(0);
		}
		if(choice>5 || choice<=0){		//yanlis girilen secimlerde hata verir
			printf("\nFalse Selection!!!\n");
		}
	}
}

int main(void){
	int num;
	num = number_of_students();
	menu(num);
	return(0);
}





