#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

/*getInt fonksiyonu girilen iki deger arasinda kullanicidan sayi almayi saglar*/
int getInt(int mini, int maxi){
	int get_integer;
	int control=0;
	while(control==0){
		scanf("%d", &get_integer);
		if(get_integer<=maxi){
			if(get_integer>=mini){
				control = 1;
			}
			else{
				printf("Not in range!!! Please try again: ");
			}
		}
		else{
			printf("Not in range!!! Please try again: ");
		}
	}
	return get_integer;
}

/*numberGeneratorBetweenRange fonksiyonu girilen iki deger arasinda random sayi uretmeyi saglar*/
int numberGeneratorBetweenRange(int min, int max){
	int random_number;
	int max_min = max - min + 1;		//+1 eklenmesinin sebebi max degerinin ise dahil olmasinin saglanmasi. bu eklenmedigi durumlarda max uretilemez
	random_number = min + rand()%max_min;
	return random_number;
}

void horseRacingGame(void){
	int number_of_horse, user_horse;
	int horse_index=1;
	int horse_time;
	int horse_time_min=21;		//en fazla 20 cizgi kadar zaman surebilecegi icin bize de en az cizgi gerektigi icin 21 degeri atadým
	int no_winner = 0;
	int winner_horse_index;
	number_of_horse = numberGeneratorBetweenRange(3, 5);
	int control = 0;
	while(control==0){
		printf("\nNumber of Horse: %d\n", number_of_horse);
		printf("Horse Number: ");
		user_horse = getInt(1, number_of_horse);
		int count = 0;
		printf("Racing starts...\n");
		while(count<number_of_horse){
			horse_time = numberGeneratorBetweenRange(10, 20);
			if(horse_time<=horse_time_min){
				if(horse_time_min == horse_time){
					no_winner = 1;
				}
				else{
					horse_time_min = horse_time;
					winner_horse_index = horse_index;
					no_winner = 0;
				}
			}
			printf("Horse %d: ", horse_index);
			horse_index++;
			for(int i=0;i<horse_time;++i){
				printf("-");
			}
			printf("\n");
			count++;
		}
		if(no_winner == 1){			//her turlu beraberlikte kazanan olmayacagi icin direk berabere yazdim. tahmin önemsizlesti. sonucta kazanan yok
			printf("No winner!\n");
			control = 1;
		}
		if(user_horse == winner_horse_index && no_winner == 0){		//kazanan olmasi ve kullanicin dogru tahmin etmesi durumunu kontrol ettim
			printf("You win!\n");
			control = 1;
		}
		if(user_horse != winner_horse_index && no_winner != 1){		//kazanan olmasi ve kullanicinin dogru tahmin etmemesi durumunu kontrol ettim
			printf("You lose! Winner is Horse %d. \n", winner_horse_index);
			control = 1;
		}
	}
}

/*occurrence fonksiyonunda kullanmak icin yazdim. girilen sayilarin basamak sayisini kontrol edecek. bu sayede aranan sayiyi bulmaya calisirken basamak sayisi kadar sayiyi kontrol edebilecegiz*/
int numberOfDigits(int number){
	int result=0;
	int i,j;
	int count = 0;
	while(count == 0){
		i = number % 10;
		number = number - i;
		j = number / 10;
		number = j;
		result++;
		if(number<=0){
			count = 1;
		}
	}
	return result;
}

void countOccurrence(void){
	int big_number, search_number, search_number_of_digits;
	int occurrence = 0;
	printf("Big Number: ");
	scanf("%d", &big_number);
	printf("Search Number: ");
	scanf("%d", &search_number);
	if(big_number<0 || search_number<0){
		printf("Please try again with positive integers\n");
	}
	if(big_number<=search_number){
		if(big_number==search_number){
			occurrence = 1;
			if(big_number>=0 && search_number>=0){
				printf("Numbers are same");
			}
		}
		else{
			printf("ERROR!!!");
		}
	}
	else{
		search_number_of_digits = numberOfDigits(search_number);		//basamak sayisini buldum
		int i,k;
		while(big_number != 0){			//updateler sonrasinda sifirlayana kadar surdurmem gerekli
			k = pow(10, search_number_of_digits);
			i = big_number % k;
			if(i==search_number){		//aranan sayinin basamak sayisi kadar sondan sayi alip kiyasladim. dogru durumunda occur update
				occurrence += 1;
			}
			big_number = (big_number - (big_number%10)) / 10;		//her bir kontrolden sonra bignumber guncelledim. bunu sondaki sayiyi yok ederek yaptim
		}
		printf("Occurrence = %d\n", occurrence);
	}
}

void triangleOfSequences(void){
	int number;
	number = numberGeneratorBetweenRange(2, 10);
	int i,k;
	for(i=1;i<=number;++i){
		for(k=1;k<=i;++k){
			printf("%d ", k*i);
		}
		printf("\n");
	}
}

void menu(void){
	srand(time(NULL));
	int choice;
	int control = 0;
	do{
		printf("1. Horse Racing Game\n");
		printf("2. Occurrence Counter\n");
		printf("3. Triangle of Sequences\n");
		printf("0. Exit\n");
		choice = getInt(0, 3);
		switch(choice){
			case 1: horseRacingGame();break;
			case 2: countOccurrence();break;
			case 3: triangleOfSequences();break;
			default: printf("Closing..."); control = 1; ;break;
		}
		printf("\n");
	}while(control==0);
}

int main(void){
	menu();
}
