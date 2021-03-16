#include<stdio.h>
#include<stdlib.h>

double avarage(double **);																					//verilen arrayin ortalamas�n� bulan fonksiyon
void sorting(double **arr, int num);																		//iki boyutlu arrayde ortalamaya g�re s�ralama yapan fonksiyon

int main(void){
	FILE *inp, *outp;																						//dosyalar�m�z� tan�mlad�k
	inp=fopen("input.txt", "r");
	outp=fopen("output.txt", "w");
	double inpArr[1000];																					//dosyadaki say�lar� atabilece�imiz array olu�turduk
	int sayac=0;
	while(!feof(inp)){
		fscanf(inp, "%lf", &inpArr[sayac]);																	//dosyadan say�lar� okuyup arrayin i�ine att�k
		//printf("%.2f \n", inpArr[sayac]);																	//kontrol edildi
		sayac++;																							//saya� sayesinde dosyada ka� say� oldu�u ��renildi
	}
	double **chunks = (double*)malloc(sizeof(double)*sayac);												//iki boyutlu memory aloc yap�lan dizi olu�turuldu. bu dizi chunkslar�m�z� tutacak
	double **saved = (double*)malloc(sizeof(double)*sayac);													//ayn� �ekilde dizi olu�turuldu. burada s�ralama yap�l�p tutulacak
	double avarages=0;																						//saved dizisinin s�ralamas�n�n yap�lmas� i�in tan�mland�. bu de�i�ken dizilerin ortalamas�n� g�ncelleyecek
	int i=0, j=0, k=0;
	while(inpArr[i]!='\0'){																					//ilk olu�turdu�umuz array ba�tan a�a�� taranacak
		if(inpArr[i]==0){																					//s�f�rla kar��la��l�nca yan�ndakine ve onun da yan�ndakine bak�l�p ayra� tespiti yap�lacak
			if(inpArr[i+1]==0){
				if(inpArr[i+2]==0){
					i=i+3;																					//ayrca� oldu�u zaman 3 s�ra atlayacak
					avarages = avarage(chunks);																//ayraca kadar olu�turulan dizinin ortalamas� hesaplan�p de�i�kene atanacak
					saved[k][j]= avarages;																	//ortalamalar kay�t dizisinde 1 s�t�nlara yerle�tirilecek
					k++;																					//yeni dizi i�in alt s�t�na ge�ilecek
					j=0;																					//sat�r s�f�rlanacak
				}
				else{																						//di�er i�lemler ayra� olmad���nda chunks arrayine ordan da s�t�nlara dokunmadan saved arrayine atanacak
					chunks[k][j]=inpArr[i];
					chunks[k][j+1]=inpArr[i+1];
					chunks[k][j+2]=inpArr[i+2];
					saved[k][j+1]=chunks[k][j];
					saved[k][j+2]=chunks[k][j+1];
					saved[k][j+3]=chunks[k][j+1];
					i=i+3;																					//s�f�r kontrollerinde atlanacak say�lar i�in +2 ve +3 ler kullan�ld�
					j=j+3;
				}
			}
			else{
				chunks[k][j]=inpArr[i];
				chunks[k][j+1]=inpArr[i+1];
				saved[k][j+1]=chunks[k][j];
				saved[k][j+2]=chunks[k][j];
				j=j+2;
				i=i+2;
			}
		}
		else{
			chunks[k][j]=inpArr[i];																			//chunks ve saved dizilerine atan�r. atan�rken saved dizisinin ilk s�t�nuna dokunulmaz. orada ortalamalar saklanacak
			saved[k][j+1]=chunks[k][j];
			i++;
			j++;
		}
	}
	sorting(&saved, j);																						//saved dizisinin ilk s�t�nuna g�re s�ralama yap�l�r
	int c, d;
	double son[c][d];																						//yeni bir array tan�mlan�r(sabit)
	c=0;
	d=0;
	while(c<1000){
		while(d<1005){
			son[c][d] = saved[c][d];																		//saved dizisi sabit diziye aktar�l�r
			d++;
		}
		c++;
	}
	int a=0, b=0;
	while(a<1000){
		while(b<1005){
			fprintf(outp,"%lf", son[a][b]);																	//sabit olan dizi output.txt dosyas�na yaz�l�r
			b++;
		}
		a++;
	}
	fclose(inp);																							//�al��an dosyalar kapat�l�r
	fclose(outp);
	return 0;
}

double avarage(double **arr){																				//ortalama hesab�
	int i=0, j=1;
	double ort=0;
	double sum =0;
	while(i<1000){
		while(j<1001){
			sum = sum + arr[i][j-1];
			j++;
		}
		ort = ort + (sum/j);
		j=1;
		i++;
	}
	return ort;
}

void sorting(double **arr, int num){																		//ilk s�t�na g�re sat�rlar� s�ralama(bouble sort)
	int cont;
	int i, j;
	for(i=1;i<num;i++){
		for(j=1;j<num-i;j++){
			if(arr[j][0]>arr[j+1][0]){
				cont = arr[j][0];
				arr[j][0] = arr[j+1][0];
				arr[j+1][0] = cont;
			}
		}
	}
}
