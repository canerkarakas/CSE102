/*HW04_Caner_Karakas_131044061*/
#include<stdio.h>
#include<math.h>
#include<string.h>

int main(void){
	FILE *values, *polynomial, *createFile;
	values = fopen("values.txt", "r");
	polynomial = fopen("polynomial.txt", "r");
	createFile = fopen("evaluations.txt", "a+");
	//deger dosyasindakileri arraye atariz
	double inp;
	double value[100];
	int i =0;
	while(fscanf(values, "%lf", &inp)!=EOF){
		value[i] = inp;
	}
	fclose(values);
	//polinomu poly arrayine atarýz
	char poly[1000];
	while(fscanf(polynomial,"%s", poly)!=EOF){
		printf("%s", poly);
	}
	fclose(polynomial);
	
	char result[1000];
	double result_first = 0;
	double result_control = 0;
	int result_x1 = 1;
	double result_x2 = 1;
	double result_x = 0;
	int j, k, l, res=0;
	for(i=0; i<strlen(poly); i++){
		if(pol[i] == 'x' && pol[i+1] == '^'){
			for(j=0; j<10; j++){
				if(pol[i-3]=='.'){
					k = i-4;
					l = 0;
					while(-1){
						if(pol[k]=='+' || pol[k]=='-' || pol[k]=='x'){
							break;
						}
						else{
							result_x1 = (pol[k]-'0') * pow(10, l);
							result_x = result_x + result_x1;
							result_x1 = 1;
							k--;
							l++;
						}
					}
					result_x = 0;
					k = i-2;
					l = 1;
					while(pol[k]!='x'){
						result_x2 = (pol[k]-'0') * (1 / (pow(10, l)));
						result_x = result_x + result_x2;
						result_x2 = 1;
						k++;
						l++;
					}
					result_x = 0;
				}
				if(pol[i-2]=='.'){
					k = i-3;
					l = 0;
					while(-1){
						if(pol[k]=='+' || pol[k]=='-' || pol[k]=='x'){
							break;
						}
						else{
							result_x1 = (pol[k]-'0') * pow(10, l);
							result_x = result_x + result_x1;
							result_x1 = 1;
							k--;
							l++;
						}
					}
					result_x = 0;
					k = i-1;
					l = 1;
					while(pol[k]!='x'){
						result_x2 = (pol[k]-'0') * (1 / (pow(10, l)));
						result_x = result_x + result_x2;
						result_x2 = 1;
						k++;
						l++;
					}
					result_x = 0;
				}
			}
			result[res] = (result_x1 * pow(x, pol[i+1]));
			res++;
		}
		if(pol[i] == 'x' && pol[i+1] != '^'){
			for(j=0; j<strlen(pol); j++){
				if(pol[i-3]=='.'){
					k = i-4;
					l = 0;
					while(-1){
						if(pol[k]=='+' || pol[k]=='-' || pol[k]=='x'){
							break;
						}
						else{
							result_x1 = (pol[k]-'0') * pow(10, l);
							result_x = result_x + result_x1;
							result_x1 = 1;
							k--;
							l++;
						}
					}
					result_x = 0;
					k = i-2;
					l = 1;
					while(pol[k]!='x'){
						result_x2 = (pol[k]-'0') * (1 / (pow(10, l)));
						result_x = result_x + result_x2;
						result_x2 = 1;
						k++;
						l++;
					}
					result_x = 0;
				}
				if(pol[i-2]=='.'){
					k = i-2;
					l = 1;
					while(-1){
						if(pol[k]=='+' || pol[k]=='-' || pol[k]=='x'){
							break;
						}
						else{
							result_x1 = (pol[k]-'0') * pow(10, l);
							result_x = result_x + result_x1;
							result_x1 = 1;
							k--;
							l++;
						}
					}
					result_x = 0;
					k = i-1;
					l = 1;
					while(pol[k]!='x'){
						result_x2 = (pol[k]-'0') * (1 / (pow(10, l)));
						result_x = result_x + result_x2;
						result_x2 = 1;
						k++;
						l++;
					}
					result_x = 0;
				}
			}
			result[res] = (result_x1 * pow(x, pol[i+1]));
			res++;
		}
	}
	result_first = result[0];
	
	
	
}
