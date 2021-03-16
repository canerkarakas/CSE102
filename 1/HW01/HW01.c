
#include<stdio.h>

int intersection_points(double x, double y, double mark_x1, double mark_x2, double mark_y1, double mark_y2);			//kesi�im noktalar� var m� yok mu kontrol edecek ve olan noktay� sayacak
int dedecInOutControl(double x, double y, double board_x, double board_y);												//dedekt�r oyun tahtas�n�n i�inde olup olmad���na bakacak
int intersection_region(double x, double y, double mark_x1, double mark_x2, double mark_y1, double mark_y2);			//kesi�en nokta say�s�ndan ka� birim alan kesi�ti�ini hesaplar. kazan�l�rsa oyunu bitirir

int main(void){
	double board_x=400, board_y=400;																					//tahtan�n x ve y eksenlerindeki uzunlu�u
	double region_size_x=40, region_size_y=20;																			//i�aretli alan�n x ve y eksenlerindeki uzunlu�u
	double dedector_size_x=60, dedector_size_y=20;																		//dedekt�r�n x ve y eksenlerindeki uzunlu�u
	double marked_region_x1=80, marked_region_x2=120, marked_region_y1=120, marked_region_y2=140;						//i�aretli alan�n koordinatlar�
	double dedector_x, dedector_y;																						//kullan�c�dan al�nacak koordinatlar� tutmak i�in tan�mlanm��t�r
	int moves=1;																										//ne kadar hamle yapt���n� tutmak i�in tan�mlanm��t�r
	double units=0;																										//kesi�en alanlar� kay�tta tutmak i�in tan�mlanm��t�r
	int attempts=10;																									//ne kadar hakk�n� s�ylemek i�in tan�mlanm��t�r
	printf(" Hi! Let's Play...\n You have a dedector and its dimensions are [60*20].\n");
	printf(" We also have one game board. Its dimensions are [400*400].\n Also a hidden rectangular region is marked on a 2D plane.The region's dimensions are [40*20].\n");
	printf(" The coordinates we want from you are in the middle of the dedector.\n GOOD LUCK!!!\n");
	while(moves<11){																									//kullan�c�ya 11 hak sunulmu� ve her fonksiyon d�ng�ye sokulmu�tur
		printf("\n Enter the x =");
		scanf("%lf", &dedector_x);
		printf(" Enter the y =");
		scanf("%lf", &dedector_y);
		if(dedecInOutControl(dedector_x, dedector_y, board_x, board_y)==1){
			if(intersection_points(dedector_x, dedector_y, marked_region_x1, marked_region_x2, marked_region_y1, marked_region_y2)==1){
					if(intersection_region(dedector_x, dedector_y, marked_region_x1, marked_region_x2, marked_region_y1, marked_region_y2)!=1){
						units = intersection_region(dedector_x, dedector_y, marked_region_x1, marked_region_x2, marked_region_y1, marked_region_y2);
						attempts--;
						printf(" The marked area and dedector intersected in %.2f units. Attempts remainig: %d. Please try again!", units, attempts);
						moves++;
					}
					else{
						printf(" Congratulations!! YOU WON  YOUR %dTH RIGHT!!!!\n", moves);
						moves=11;
						break;
					}
			}
			else{
				marked_region_x2=marked_region_x2-(region_size_x/2);
				marked_region_y2=marked_region_y2-(region_size_y/2);
				region_size_x=region_size_x/2;
				region_size_y=region_size_y/2;
				dedector_size_x=dedector_size_x/2;
				dedector_size_y=dedector_size_y/2;
				attempts--;
				printf(" Partial hit! Marked region was shirked to [%.2f*%.2f], dedector was shirked to [%.2f*%.2f] attempts remaining: %d", region_size_x, region_size_y, dedector_size_x, dedector_size_y, attempts);
				moves++;
			}
		}
		else{
			attempts--;
			printf(" Error, move is not valid. Try again. Attempts remaining: %d", attempts);
			moves++;
			if(attempts<=1){
				moves=11;
				printf("You have no rights...");
				break;
			}
		}
	}
}

int dedecInOutControl(double x, double y, double board_x, double board_y){
	if((x-30)>=0 && (x+30)<=board_x){																						//kullan�c�dan al�nan koordinatlar�n sol taraf�ndan ve sa� taraf�ndan �izgiler �ekilir
		if((y-10)>=0 && (y+10)<=board_y){																					//ayn� zamanda a�a��dan ve yukar�dan
			return 1;																										//tahtan�n i�inde olup olmad��� kontrol edilir
		}
		else return -1;																										//i�inde olmad��� her durum i�in -1 d�nd�r�l�r
	}
	else return -1;
}

int intersection_points(double x, double y, double mark_x1, double mark_x2, double mark_y1, double mark_y2){
	double i=mark_x1, j=(x-30), k=mark_y1, l=(y-10);																		//kullan�c�dan al�nan koordinatlarla tekrar s�n�rlar belirlenir
	int points=0;
	while(i<=mark_x2){
		while(j<=(x+30)){
			if(i==j){
				while(k<=mark_y2){
					while(l<=y+10){
						if(k==l){
							points++;																						//olu�an s�n�rlarda kesi�en her bir nokta points ifadesinde tutulur
							l++;
						}
						else l++;
					}
					l=y-10;
					k++;
				}
				j++;
			}
			else j++;
		}
		j=x-30;
		i++;
	}
	if(points>0){																											//kesi�en nokta varsa yani s�f�rdan b�y�kse 1 d�nd�r�l�r. Yoksa -1
		return 1;
	}
	else return -1;
}

int intersection_region(double x, double y, double mark_x1, double mark_x2, double mark_y1, double mark_y2){
	double i = mark_x1, j=(x-30), k=mark_y1, l=(y-10);																		//intersection_points fonksiyonundaki i�lemlerle alanlar say�l�r
	double x_save = 0;
	double y_save = 0;
	double control_units = 0;
	while(i<=mark_x2){
		while(j<=(x+30)){
			if(i==j){
				x_save++;
				j++;
			}
			else j++;
		}
		j=x-30;
		i++;
	}
	while(k<=mark_y2){
		while(l<=(y+10)){
			if(k==l){
				y_save++;
				l++;
			}
			else l++;
		}
		l=y-10;
		k++;
	}
	if(x_save>=41 && y_save>=21){																							//tam olarak kesi�ti�i durum i�in 1 d�nd�r�l�r
		return 1;
	}
	else{
		return control_units = (x_save-1)*(y_save-1);																		//tam olarak kesi�miyorsa kesi�en alan� d�nd�r�r
	}
}








