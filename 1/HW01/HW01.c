
#include<stdio.h>

int intersection_points(double x, double y, double mark_x1, double mark_x2, double mark_y1, double mark_y2);			//kesiþim noktalarý var mý yok mu kontrol edecek ve olan noktayý sayacak
int dedecInOutControl(double x, double y, double board_x, double board_y);												//dedektör oyun tahtasýnýn içinde olup olmadýðýna bakacak
int intersection_region(double x, double y, double mark_x1, double mark_x2, double mark_y1, double mark_y2);			//kesiþen nokta sayýsýndan kaç birim alan kesiþtiðini hesaplar. kazanýlýrsa oyunu bitirir

int main(void){
	double board_x=400, board_y=400;																					//tahtanýn x ve y eksenlerindeki uzunluðu
	double region_size_x=40, region_size_y=20;																			//iþaretli alanýn x ve y eksenlerindeki uzunluðu
	double dedector_size_x=60, dedector_size_y=20;																		//dedektörün x ve y eksenlerindeki uzunluðu
	double marked_region_x1=80, marked_region_x2=120, marked_region_y1=120, marked_region_y2=140;						//iþaretli alanýn koordinatlarý
	double dedector_x, dedector_y;																						//kullanýcýdan alýnacak koordinatlarý tutmak için tanýmlanmýþtýr
	int moves=1;																										//ne kadar hamle yaptýðýný tutmak için tanýmlanmýþtýr
	double units=0;																										//kesiþen alanlarý kayýtta tutmak için tanýmlanmýþtýr
	int attempts=10;																									//ne kadar hakkýný söylemek için tanýmlanmýþtýr
	printf(" Hi! Let's Play...\n You have a dedector and its dimensions are [60*20].\n");
	printf(" We also have one game board. Its dimensions are [400*400].\n Also a hidden rectangular region is marked on a 2D plane.The region's dimensions are [40*20].\n");
	printf(" The coordinates we want from you are in the middle of the dedector.\n GOOD LUCK!!!\n");
	while(moves<11){																									//kullanýcýya 11 hak sunulmuþ ve her fonksiyon döngüye sokulmuþtur
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
	if((x-30)>=0 && (x+30)<=board_x){																						//kullanýcýdan alýnan koordinatlarýn sol tarafýndan ve sað tarafýndan çizgiler çekilir
		if((y-10)>=0 && (y+10)<=board_y){																					//ayný zamanda aþaðýdan ve yukarýdan
			return 1;																										//tahtanýn içinde olup olmadýðý kontrol edilir
		}
		else return -1;																										//içinde olmadýðý her durum için -1 döndürülür
	}
	else return -1;
}

int intersection_points(double x, double y, double mark_x1, double mark_x2, double mark_y1, double mark_y2){
	double i=mark_x1, j=(x-30), k=mark_y1, l=(y-10);																		//kullanýcýdan alýnan koordinatlarla tekrar sýnýrlar belirlenir
	int points=0;
	while(i<=mark_x2){
		while(j<=(x+30)){
			if(i==j){
				while(k<=mark_y2){
					while(l<=y+10){
						if(k==l){
							points++;																						//oluþan sýnýrlarda kesiþen her bir nokta points ifadesinde tutulur
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
	if(points>0){																											//kesiþen nokta varsa yani sýfýrdan büyükse 1 döndürülür. Yoksa -1
		return 1;
	}
	else return -1;
}

int intersection_region(double x, double y, double mark_x1, double mark_x2, double mark_y1, double mark_y2){
	double i = mark_x1, j=(x-30), k=mark_y1, l=(y-10);																		//intersection_points fonksiyonundaki iþlemlerle alanlar sayýlýr
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
	if(x_save>=41 && y_save>=21){																							//tam olarak kesiþtiði durum için 1 döndürülür
		return 1;
	}
	else{
		return control_units = (x_save-1)*(y_save-1);																		//tam olarak kesiþmiyorsa kesiþen alaný döndürür
	}
}








