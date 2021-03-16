#include<stdio.h>
#include<stdlib.h>
#define n1 6					//kubun 6 yuzu icin define edilmistir
int numberOfTrackSquare;

typedef struct{
	char *rotORshi;				//dosyadan alinacak rotate ya da shrink arrayinde tutacak
	int faceID;					//hangi yuzde islem modify yapacagini tutacak
	char *rowORcolumn;			//satir mi sutun mu yapilacak islemler onu tutacak
	int rowORcolumnID;			//bilinen satir ya da sutunun sayisini verecek (6. satir)
	char *move;					//hareket ettirme isleminin ne tarafa nasil olacagini tutacak
}moves;

void printResultFile(FILE *file, int rubi[][numberOfTrackSquare][numberOfTrackSquare]);												/*modify edilmis rubik kubu dosyaya yazar*/
void modifyShrink(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n, moves *a);											/*her yuzeyin ilk satirini ve sutununu siler*/
void modifyRubisRowRight(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n, moves *a);									/*istenilen satirdaki saga donme hareketi*/
void modifyRubisRowLeft(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n, moves *a);										/*istenilen satirdaki sola donme hareketi*/
void modifyRubisColumnUp(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n, moves *a);									/*istenilen sutundaki yukari donme hareketi*/
void modifyRubisColumnDown(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n, moves *a);									/*istenilen sutundaki asagý donme hareketi*/
void modifyRubikCubes(FILE *file, moves *a, int line, int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n);					/*satir satir okunan dosyadan verilerle yapilan islemler*/
int lineCounting(FILE *file);																		/*dosyada kac satir var sayar dondurur (ilk basta alinacak olan satir haric)*/
int resultRowsNumber(int rubi[][numberOfTrackSquare][numberOfTrackSquare]);															/*modify islemlerinden sonra satir sayisini hesaplar*/
void oneLine(FILE *file, moves *a);																	/*dosyadan sadece bir satir okumada ve atamada kullanilir*/
void moveStr(FILE *file, moves *a, char c);															/*struct icindeki move arrayini doldurur*/
void rowStr(FILE *file, moves *a);																	/*struct icindeki rowORcolumn arrayini row ise doldurur*/
void columnStr(FILE *file, moves *a);																/*struct icindeki rowORcolumn arrayini column ise doldurur*/
int fscanf_int(FILE *file);																			/*dosyadan ilk bastaki sayiyi okuyacak*/
void zeroMatrix(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n);														/*olusturulmaya calisilan 6 yuzulu kubun matrisinin icini bosaltýrýz*/
void initialRubikCubesFace(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n);											/*olusturulmaya calisilan kubun icini yuzun sayýsýna gore dolduralým*/


int main(){
	FILE *commands, *result;
	commands = fopen("commands.txt", "r");									//dosyada gerekli bilgiler bulunur. Rubik kubu modify etmek için...
	int line = lineCounting(commands);										//dosyadaki satir sayisi ilk integer haric
	fclose(commands);														//dosya imlecini bastan almak için dosya kapatildi
	
	commands = fopen("commands.txt", "r");									//dosya tekrar acildi bu sayede dosya imleci basa alinabilir
	
	/*dosyadan rubikkubun ne kadar kareden (matris satir sutun sayisi) olusacagini alir*/
	numberOfTrackSquare = fscanf_int(commands);
	int rubi[n1][numberOfTrackSquare][numberOfTrackSquare];
	/*rubik kub olusturulur*/
	zeroMatrix(rubi, numberOfTrackSquare);
	initialRubikCubesFace(rubi, numberOfTrackSquare);
	
	moves *a;
	a = (moves*)malloc(sizeof(moves));
	a->rotORshi = (moves*)malloc(sizeof(char)*6);		//shrink or rotate arrayi en fazla 6 karakterden olusmaktadir bu yuzden malloc yapilir
	a->rowORcolumn = (moves*)malloc(sizeof(char)*6);	//row or column arrayi en fazla 6 karakterden olusmaktadir
	a->move = (moves*)malloc(sizeof(char)*5);			//move arrayi en fazla 5 karakterden olusmaktadir (right)
	modifyRubikCubes(commands, a, line, rubi, numberOfTrackSquare);
	
	result = fopen("result.txt", "w");
	printResultFile(result, rubi);
	fclose(result);
	fclose(commands);
	
}


/*alinan bilgilerle her satirda rubik kub icinde modify yapacak*/
void modifyRubikCubes(FILE *file, moves *a, int line, int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n){
	char c;
	while(line>0){
		fscanf(file, "%c", &c);
		if(c == '\n'){
			oneLine(file, a);
			if(a->rotORshi[0] == 's'){
				modifyShrink(rubi, n, a);
			}
			else{
				if(a->rowORcolumn[0] == 'r'){
					switch(a->move[0]){
						case 'r': modifyRubisRowRight(rubi, n, a);break;
						case 'l': modifyRubisRowLeft(rubi, n, a);break;
						default: break;
					}
				}
				else{
					switch(a->move[0]){
						case 'u': modifyRubisColumnUp(rubi, n, a);break;
						case 'd': modifyRubisColumnDown(rubi, n, a);break;
						default: break;
					}
				}
			}
			line--;
		}
	}
}

/*modify islemlerinden sonra kac satir kaldagini hesaplar*/
int resultRowsNumber(int rubi[][numberOfTrackSquare][numberOfTrackSquare]){
	int rows = 0;
	int i=0;
	int a;
	while(a!='\0'){
		a = rubi[5][i][0];
		i++;
		rows++;
		if(a=='\0'){
			rows--;
		}
	}
	return rows;
}

/*sonucu result dosyasina yazdirma*/
void printResultFile(FILE *file, int rubi[][numberOfTrackSquare][numberOfTrackSquare]){
	int i,j,k;
	int rows = resultRowsNumber(rubi);
	for(i=0;i<n1;i++){
		for(j=0;j<rows;j++){
			for(k=0;k<rows;k++){
				fprintf(file, "%d ", rubi[i][j][k]);
			}
			fprintf(file,"\n");
		}
		fprintf(file, "\n");
	}
}

/*shrink butun yuzeylerin ilk satir ve sutunlarini siler(NULL ATAR)*/
void modifyShrink(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n, moves *a){
	int counter[n1][n-1][n-1];
	int i, j, k;
	for(i=0;i<n1;i++){
		for(j=0;j<n-1;j++){
			for(k=0;k<n-1;k++){
				counter[i][j][k] = rubi[i][j+1][k+1];
			}
		}
	}
	for(i=0;i<n1;i++){
		for(j=0;j<n-1;j++){
			for(k=0;k<n-1;k++){
				rubi[i][j][k] = counter[i][j][k];
			}
		}
	}
	for(i=0;i<n1;i++){
		for(j=0;j<n;j++){
			rubi[i][j][n-1] = '\0';
		}
	}
	for(i=0;i<n1;i++){
		for(k=0;k<n-1;k++){
			rubi[i][n-1][k] = '\0';
		}
	}
}

/*istenilen satirdaki sola donme hareketi*/
void modifyRubisRowLeft(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n, moves *a){
	int counter[n1][n][n];
	int i, j, k;
	for(i=0;i<n1;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				counter[i][j][k] = rubi[i][j][k];
			}
		}
	}
	if(a->faceID == 0){
		for(k=0;k<n;k++){
			rubi[0][a->rowORcolumnID][k] = counter[1][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[3][a->rowORcolumnID][k] = counter[0][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[2][a->rowORcolumnID][k] = counter[3][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[1][a->rowORcolumnID][k] = counter[2][a->rowORcolumnID][k];
		}
	}
	if(a->faceID == 1){
		for(k=0;k<n;k++){
			rubi[1][a->rowORcolumnID][k] = counter[2][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[0][a->rowORcolumnID][k] = counter[1][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[3][a->rowORcolumnID][k] = counter[0][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[2][a->rowORcolumnID][k] = counter[3][a->rowORcolumnID][k];
		}
	}
	if(a->faceID == 2){
		for(k=0;k<n;k++){
			rubi[2][a->rowORcolumnID][k] = counter[3][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[1][a->rowORcolumnID][k] = counter[2][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[0][a->rowORcolumnID][k] = counter[1][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[3][a->rowORcolumnID][k] = counter[0][a->rowORcolumnID][k];
		}
	}
	if(a->faceID == 3){
		for(k=0;k<n;k++){
			rubi[3][a->rowORcolumnID][k] = counter[0][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[2][a->rowORcolumnID][k] = counter[3][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[1][a->rowORcolumnID][k] = counter[2][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[0][a->rowORcolumnID][k] = counter[1][a->rowORcolumnID][k];
		}
	}
	if(a->faceID == 4){
		for(k=0;k<n;k++){
			rubi[4][a->rowORcolumnID][k] = counter[1][k][(n-1) - a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[3][n-1-k][a->rowORcolumnID] = counter[4][k][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[5][(n-1) - a->rowORcolumnID][k] = counter[3][k][(n-1) - a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[1][k][(n-1) - a->rowORcolumnID] = counter[5][(n-1) - a->rowORcolumnID][n-1-k];
		}
	}
	if(a->faceID == 5){
		for(k=0;k<n;k++){
			rubi[5][a->rowORcolumnID][k] = counter[1][n-1-k][a->rowORcolumnID];
		}
		for(k=0;k<n;k++){
			rubi[3][k][(n-1) - a->rowORcolumnID] = counter[5][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[4][(n-1) - a->rowORcolumnID][n-1-k] = counter[3][k][(n-1) - a->rowORcolumnID];
		}
		for(k=0;k<n;k++){
			rubi[1][k][a->rowORcolumnID] = counter[4][(n-1) - a->rowORcolumnID][n-1-k];
		}
	}
}

/*istenilen satirdaki saga donme hareketi*/
void modifyRubisRowRight(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n, moves *a){
	int counter[n1][n][n];
	int i, j, k;
	for(i=0;i<n1;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				counter[i][j][k] = rubi[i][j][k];
			}
		}
	}
	if(a->faceID == 0){
		for(k=0;k<n;k++){
			rubi[0][a->rowORcolumnID][k] = counter[3][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[1][a->rowORcolumnID][k] = counter[0][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[2][a->rowORcolumnID][k] = counter[1][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[3][a->rowORcolumnID][k] = counter[2][a->rowORcolumnID][k];
		}
	}
	if(a->faceID == 1){
		for(k=0;k<n;k++){
			rubi[1][a->rowORcolumnID][k] = counter[0][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[2][a->rowORcolumnID][k] = counter[1][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[3][a->rowORcolumnID][k] = counter[2][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[0][a->rowORcolumnID][k] = counter[3][a->rowORcolumnID][k];
		}
	}
	if(a->faceID == 2){
		for(k=0;k<n;k++){
			rubi[2][a->rowORcolumnID][k] = counter[1][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[3][a->rowORcolumnID][k] = counter[2][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[0][a->rowORcolumnID][k] = counter[3][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[1][a->rowORcolumnID][k] = counter[0][a->rowORcolumnID][k];
		}
	}
	if(a->faceID == 3){
		for(k=0;k<n;k++){
			rubi[3][a->rowORcolumnID][k] = counter[2][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[0][a->rowORcolumnID][k] = counter[3][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[1][a->rowORcolumnID][k] = counter[0][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[2][a->rowORcolumnID][k] = counter[1][a->rowORcolumnID][k];
		}
	}
	if(a->faceID == 4){
		for(k=0;k<n;k++){
			rubi[4][a->rowORcolumnID][k] = counter[3][n-1-k][a->rowORcolumnID];
		}
		for(k=0;k<n;k++){
			rubi[1][k][(n-1) - a->rowORcolumnID] = counter[4][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[5][(n-1) - a->rowORcolumnID][n-1-k] = counter[1][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[3][k][a->rowORcolumnID] = counter[5][(n-1) - a->rowORcolumnID][k];
		}
	}
	if(a->faceID == 5){
		for(k=0;k<n;k++){
			rubi[5][a->rowORcolumnID][k] = counter[3][k][(n-1) - a->rowORcolumnID];
		}
		for(k=0;k<n;k++){
			rubi[1][n-1-k][a->rowORcolumnID] = counter[5][a->rowORcolumnID][k];
		}
		for(k=0;k<n;k++){
			rubi[4][(n-1) - a->rowORcolumnID][k] = counter[1][k][(n-1) - a->rowORcolumnID];
		}
		for(k=0;k<n;k++){
			rubi[3][n-1-k][(n-1) - a->rowORcolumnID] = counter[4][(n-1) - a->rowORcolumnID][k];
		}
	}
}

/*istenilen sutundaki yukari donme hareketi*/
void modifyRubisColumnDown(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n, moves *a){
	int counter[n1][n][n];
	int i, j, k;
	for(i=0;i<n1;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				counter[i][j][k] = rubi[i][j][k];
			}
		}
	}
	if(a->faceID == 0){
		for(j=0;j<n;j++){
			rubi[0][j][a->rowORcolumnID] = counter[4][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[5][j][a->rowORcolumnID] = counter[0][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[2][n-1-j][(n-1) - a->rowORcolumnID] = counter[5][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[4][j][a->rowORcolumnID] = counter[2][n-1-j][(n-1) - a->rowORcolumnID];
		}
	}
	if(a->faceID == 1){
		for(j=0;j<n;j++){
			rubi[1][j][a->rowORcolumnID] = counter[4][(n-1) - a->rowORcolumnID][j];
		}
		for(j=0;j<n;j++){
			rubi[5][a->rowORcolumnID][n-1-j] = counter[1][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[3][j][(n-1) - a->rowORcolumnID] = counter[5][(n-1) - a->rowORcolumnID][j];
		}
		for(j=0;j<n;j++){
			rubi[4][(n-1) - a->rowORcolumnID][n-1-j] = counter[3][j][(n-1) - a->rowORcolumnID];
		}
	}
	if(a->faceID == 2){
		for(j=0;j<n;j++){
			rubi[2][j][a->rowORcolumnID] = counter[4][(n-1) - a->rowORcolumnID][n-1-j];
		}
		for(j=0;j<n;j++){
			rubi[5][n-1-j][(n-1) - a->rowORcolumnID] = counter[2][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[0][j][(n-1) - a->rowORcolumnID] = counter[5][j][(n-1) - a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[4][j][(n-1) - a->rowORcolumnID] = counter[0][j][(n-1) - a->rowORcolumnID];
		}
	}
	if(a->faceID == 3){
		for(j=0;j<n;j++){
			rubi[3][j][a->rowORcolumnID] = counter[4][a->rowORcolumnID][n-1-j];
		}
		for(j=0;j<n;j++){
			rubi[5][(n-1) - a->rowORcolumnID][j] = counter[3][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[1][(n-1) - a->rowORcolumnID][n-1-j] = counter[5][(n-1) - a->rowORcolumnID][j];
		}
		for(j=0;j<n;j++){
			rubi[4][j][0] = counter[1][j][0];
		}
	}
	if(a->faceID == 4){
		for(j=0;j<n;j++){
			rubi[4][j][a->rowORcolumnID] = counter[2][n-1-j][(n-1) - a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[0][j][a->rowORcolumnID] = counter[4][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[5][j][a->rowORcolumnID] = counter[0][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[2][n-1-j][(n-1) - a->rowORcolumnID] = counter[5][j][a->rowORcolumnID];
		}
	}
	if(a->faceID == 5){
		for(j=0;j<n;j++){
			rubi[5][j][a->rowORcolumnID] = counter[0][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[2][n-1-j][(n-1) - a->rowORcolumnID] = counter[5][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[4][j][a->rowORcolumnID] = counter[2][n-1-j][(n-1) - a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[0][j][a->rowORcolumnID] = counter[4][j][a->rowORcolumnID];
		}
	}
}

/*istenilen sutundaki asagý donme hareketi*/
void modifyRubisColumnUp(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n, moves *a){
	int counter[n1][n][n];
	int i, j, k;
	for(i=0;i<n1;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				counter[i][j][k] = rubi[i][j][k];
			}
		}
	}
	if(a->faceID == 0){
		for(j=0;j<n;j++){
			rubi[0][j][a->rowORcolumnID] = counter[5][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[4][j][a->rowORcolumnID] = counter[0][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[2][n-1-j][(n-1) - a->rowORcolumnID] = counter[4][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[5][j][a->rowORcolumnID] = counter[2][n-1-j][(n-1) - a->rowORcolumnID];
		}
	}
	if(a->faceID == 1){
		for(j=0;j<n;j++){
			rubi[1][j][a->rowORcolumnID] = counter[5][a->rowORcolumnID][n-1-j];
		}
		for(j=0;j<n;j++){
			rubi[4][(n-1) - a->rowORcolumnID][j] = counter[1][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[3][n-1-j][(n-1) - a->rowORcolumnID] = counter[4][(n-1) - a->rowORcolumnID][j];
		}
		for(j=0;j<n;j++){
			rubi[5][a->rowORcolumnID][j] = counter[3][j][(n-1) - a->rowORcolumnID];
		}
	}
	if(a->faceID == 2){
		for(j=0;j<n;j++){
			rubi[2][n-1-j][a->rowORcolumnID] = counter[5][j][(n-1) - a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[4][n-1-j][(n-1) - a->rowORcolumnID] = counter[2][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[0][j][(n-1) - a->rowORcolumnID] = counter[4][j][(n-1) - a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[5][j][(n-1) - a->rowORcolumnID] = counter[0][j][(n-1) - a->rowORcolumnID];
		}
	}
	if(a->faceID == 3){
		for(j=0;j<n;j++){
			rubi[3][j][a->rowORcolumnID] = counter[5][(n-1) - a->rowORcolumnID][j];
		}
		for(j=0;j<n;j++){
			rubi[4][a->rowORcolumnID][n-1-j] = counter[3][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[1][(n-1) - a->rowORcolumnID][j] = counter[4][a->rowORcolumnID][j];
		}
		for(j=0;j<n;j++){
			rubi[5][(n-1) - a->rowORcolumnID][n-1-j] = counter[1][(n-1) - a->rowORcolumnID][j];
		}
	}
	if(a->faceID == 4){
		for(j=0;j<n;j++){
			rubi[4][j][a->rowORcolumnID] = counter[0][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[2][n-1-j][(n-1) - a->rowORcolumnID] = counter[4][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[5][j][a->rowORcolumnID] = counter[2][n-1-j][(n-1) - a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[0][j][a->rowORcolumnID] = counter[5][j][a->rowORcolumnID];
		}
	}
	if(a->faceID == 5){
		for(j=0;j<n;j++){
			rubi[5][n-1-j][a->rowORcolumnID] = counter[2][j][(n-1) - a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[0][j][a->rowORcolumnID] = counter[5][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[4][j][a->rowORcolumnID] = counter[0][j][a->rowORcolumnID];
		}
		for(j=0;j<n;j++){
			rubi[2][n-1-j][(n-1) - a->rowORcolumnID] = counter[4][j][a->rowORcolumnID];
		}
	}
}

/*dosyada kac satir var sayar(ilk basta alinan integer haric)*/
int lineCounting(FILE *file){
	int i = 0;
	char c;
	while(!feof(file)){
		fscanf(file, "%c", &c);
		if(c == '\n'){
			i++;
		}
	}
	return i;
}

/*dosyadan bir satir almak*/
void oneLine(FILE *file, moves *a){
	char c;												//dosyadan alinan karakterler tutulur
	int i = 1;											//arraylere atamada kullanilacak olan update
	int control = 0;									//dongu kontrolu
	while(control == 0){
		fscanf(file, "%c", &c);
		if(c == 'r'){
			a->rotORshi[0] = c;
			while(i<7){
				fscanf(file, "%c", &c);
				a->rotORshi[i] = c;
				i++;
			}
			fscanf(file, "%d", &a->faceID);
			fscanf(file, " %c", &c);
			if(c=='r'){
				a->rowORcolumn[0] = c;
				rowStr(file, a);
				fscanf(file, "%d", &a->rowORcolumnID);
				fscanf(file, " %c", &c);
				moveStr(file, a, c);
				control = 1;
			}
			if(c=='c'){
				a->rowORcolumn[0] = c;
				columnStr(file, a);
				fscanf(file, "%d", &a->rowORcolumnID);
				fscanf(file, " %c", &c);
				moveStr(file, a, c);
				control = 1;
			}
		}
		if(c == 's'){
			a->rotORshi[0] = c;
			control = 1;
		}
	}
}

/*struct icindeki rowORcolumn arrayini row ise doldurur*/
void rowStr(FILE *file, moves *a){
	char c;
	int i;
	for(i=1;i<3;i++){
		fscanf(file,"%c", &c);
		a->rowORcolumn[i] = c;
	}
}

/*struct icindeki rowORcolumn arrayini column ise doldurur*/
void columnStr(FILE *file, moves *a){
	char c;
	int i;
	for(i=1;i<6;i++){
		fscanf(file,"%c", &c);
		a->rowORcolumn[i] = c;
	}
}

/*struct icindeki move arrayini doldurur*/
void moveStr(FILE *file, moves *a, char c){
	int i;
	switch(c){
		case 'r': 
			a->move[0] = c;
			for(i=1; i<5; i++){
				fscanf(file, "%c", &c);
				a->move[i] = c;
			};break;
		case 'l': 
			a->move[0] = c;
			for(i=1; i<4; i++){
				fscanf(file, "%c", &c);
				a->move[i] = c;
			};break;
		case 'u': 
			a->move[0] = c;
			fscanf(file, "%c", &c);
			a->move[1] = c;break;
		case 'd': 
			a->move[0] = c;
			for(i=1; i<4; i++){
				fscanf(file, "%c", &c);
				a->move[i] = c;
			};break;
		default: break;
	}
	
}

/*dosyadan bastaki sayiyiyi okuyan fonsiyon*/
int fscanf_int(FILE *file){
	int number;
	fscanf(file, "%d", &number);
	return number;
}

/*olusturulmaya calisilan 6 yuzulu kubun matrisinin icini bosaltýrýz*/
void zeroMatrix(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n){
	int i, j, k;
	for(i=0; i<n1; i++){
		for(j=0; j<n; j++){
			for(k=0; k<n; k++){
				rubi[i][j][k] = '\0';
			}
		}
	}
	rubi[n1][0][0] = '\0';
}

/*olusturulmaya calisilan rubik kubun icini doldur*/
void initialRubikCubesFace(int rubi[][numberOfTrackSquare][numberOfTrackSquare], int n){
	int i, j, k;
	for(i=0; i<n1; i++){
		for(j=0; j<n; j++){
			for(k=0; k<n; k++){
				rubi[i][j][k] = i;
			}
		}
	}
	rubi[n1][0][0] = '\0';
}





