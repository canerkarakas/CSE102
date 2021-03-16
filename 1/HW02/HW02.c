#include<stdio.h>
#include<stdlib.h>

double avarage(double **);																					//verilen arrayin ortalamasýný bulan fonksiyon
void sorting(double **arr, int num);																		//iki boyutlu arrayde ortalamaya göre sýralama yapan fonksiyon

int main(void){
	FILE *inp, *outp;																						//dosyalarýmýzý tanýmladýk
	inp=fopen("input.txt", "r");
	outp=fopen("output.txt", "w");
	double inpArr[1000];																					//dosyadaki sayýlarý atabileceðimiz array oluþturduk
	int sayac=0;
	while(!feof(inp)){
		fscanf(inp, "%lf", &inpArr[sayac]);																	//dosyadan sayýlarý okuyup arrayin içine attýk
		//printf("%.2f \n", inpArr[sayac]);																	//kontrol edildi
		sayac++;																							//sayaç sayesinde dosyada kaç sayý olduðu öðrenildi
	}
	double **chunks = (double*)malloc(sizeof(double)*sayac);												//iki boyutlu memory aloc yapýlan dizi oluþturuldu. bu dizi chunkslarýmýzý tutacak
	double **saved = (double*)malloc(sizeof(double)*sayac);													//ayný þekilde dizi oluþturuldu. burada sýralama yapýlýp tutulacak
	double avarages=0;																						//saved dizisinin sýralamasýnýn yapýlmasý için tanýmlandý. bu deðiþken dizilerin ortalamasýný güncelleyecek
	int i=0, j=0, k=0;
	while(inpArr[i]!='\0'){																					//ilk oluþturduðumuz array baþtan aþaðý taranacak
		if(inpArr[i]==0){																					//sýfýrla karþýlaþýlýnca yanýndakine ve onun da yanýndakine bakýlýp ayraç tespiti yapýlacak
			if(inpArr[i+1]==0){
				if(inpArr[i+2]==0){
					i=i+3;																					//ayrcaç olduðu zaman 3 sýra atlayacak
					avarages = avarage(chunks);																//ayraca kadar oluþturulan dizinin ortalamasý hesaplanýp deðiþkene atanacak
					saved[k][j]= avarages;																	//ortalamalar kayýt dizisinde 1 sütünlara yerleþtirilecek
					k++;																					//yeni dizi için alt sütüna geçilecek
					j=0;																					//satýr sýfýrlanacak
				}
				else{																						//diðer iþlemler ayraç olmadýðýnda chunks arrayine ordan da sütünlara dokunmadan saved arrayine atanacak
					chunks[k][j]=inpArr[i];
					chunks[k][j+1]=inpArr[i+1];
					chunks[k][j+2]=inpArr[i+2];
					saved[k][j+1]=chunks[k][j];
					saved[k][j+2]=chunks[k][j+1];
					saved[k][j+3]=chunks[k][j+1];
					i=i+3;																					//sýfýr kontrollerinde atlanacak sayýlar için +2 ve +3 ler kullanýldý
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
			chunks[k][j]=inpArr[i];																			//chunks ve saved dizilerine atanýr. atanýrken saved dizisinin ilk sütünuna dokunulmaz. orada ortalamalar saklanacak
			saved[k][j+1]=chunks[k][j];
			i++;
			j++;
		}
	}
	sorting(&saved, j);																						//saved dizisinin ilk sütünuna göre sýralama yapýlýr
	int c, d;
	double son[c][d];																						//yeni bir array tanýmlanýr(sabit)
	c=0;
	d=0;
	while(c<1000){
		while(d<1005){
			son[c][d] = saved[c][d];																		//saved dizisi sabit diziye aktarýlýr
			d++;
		}
		c++;
	}
	int a=0, b=0;
	while(a<1000){
		while(b<1005){
			fprintf(outp,"%lf", son[a][b]);																	//sabit olan dizi output.txt dosyasýna yazýlýr
			b++;
		}
		a++;
	}
	fclose(inp);																							//çalýþan dosyalar kapatýlýr
	fclose(outp);
	return 0;
}

double avarage(double **arr){																				//ortalama hesabý
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

void sorting(double **arr, int num){																		//ilk sütüna göre satýrlarý sýralama(bouble sort)
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
