#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

typedef enum{
	P=0, S=1, M=2, B=3, T=4
}types;

typedef struct{
	char *text;
	int data;
	types type;
	int pos_x;
	int pos_y;
	int jump_x;
	int jump_y;
}block;

void define_board(block board[][10]){
	board[9][9].pos_x = 9;
	board[9][9].pos_y = 9;
	board[9][9].jump_x = 9;
	board[9][9].jump_y = 9;
	board[9][9].data = 1;
	board[9][9].text = "1(Start)";
	
	board[0][9].pos_x = 0;
	board[0][9].pos_y = 9;
	board[0][9].jump_x = 0;
	board[0][9].jump_y = 9;
	board[0][9].data = 100;
	board[0][9].text = "100(Finish)";
	
	board[9][4].pos_x = 9;
	board[9][4].pos_y = 4;
	board[9][4].jump_x = 9;
	board[9][4].jump_y = 9;
	board[9][4].data = 6;
	board[9][4].text = "S{1}";
	
	board[9][3].pos_x = 9;
	board[9][3].pos_y = 5;
	board[9][3].jump_x = 8;
	board[9][3].jump_y = 0;
	board[9][3].data = 7;
	board[9][3].text = "M{11}";
	
	board[8][2].pos_x = 8;
	board[8][2].pos_y = 2;
//	board[8][2].jump_x = 8;
//	board[8][2].jump_y = 1;
	board[8][2].data = 13;
	board[8][2].text = "P";
	
	board[8][6].pos_x = 8;
	board[8][6].pos_y = 6;
	board[8][6].jump_x = 7;
	board[8][6].jump_y = 2;
	board[8][6].data = 17;
	board[8][6].text = "M{28}";
	
	board[7][5].pos_x = 7;
	board[7][5].pos_y = 5;
	board[7][5].jump_x = 8;
	board[7][5].jump_y = 1;
	board[7][5].data = 25;
	board[7][5].text = "S{12}";
	
	board[7][1].pos_x = 7;
	board[7][1].pos_y = 1;
	board[7][1].jump_x = 6;
	board[7][1].jump_y = 3;
	board[7][1].data = 29;
	board[7][1].text = "B";
	
	board[6][9].pos_x = 6;
	board[6][9].pos_y = 9;
	board[6][9].jump_x = 6;
	board[6][9].jump_y = 4;
	board[6][9].data = 40;
	board[6][9].text = "T";
	
	board[6][5].pos_x = 6;
	board[6][5].pos_y = 5;
	board[6][5].jump_x = 5;
	board[6][5].jump_y = 9;
	board[6][5].data = 36;
	board[6][5].text = "B";
	
	board[6][1].pos_x = 6;
	board[6][1].pos_y = 1;
	board[6][1].jump_x = 4;
	board[6][1].jump_y = 1;
	board[6][1].data = 32;
	board[6][1].text = "M{52}";
	
	board[5][5].pos_x = 5;
	board[5][5].pos_y = 5;
	board[5][5].jump_x = 7;
	board[5][5].jump_y = 8;
	board[5][5].data = 45;
	board[5][5].text = "S{22}";
	
	board[5][2].pos_x = 5;
	board[5][2].pos_y = 2;
//	board[5][2].jump_x = 8;
//	board[5][2].jump_y = 1;
	board[5][2].data = 48;
	board[5][2].text = "P";
	
	board[5][0].pos_x = 5;
	board[5][0].pos_y = 0;
	board[5][0].jump_x = 4;
	board[5][0].jump_y = 4;
	board[5][0].data = 50;
	board[5][0].text = "B";
	
	board[4][9].pos_x = 4;
	board[4][9].pos_y = 9;
	board[4][9].jump_x = 5;
	board[4][9].jump_y = 6;
	board[4][9].data = 60;
	board[4][9].text = "S{44}";
	
	board[4][6].pos_x = 4;
	board[4][6].pos_y = 6;
	board[4][6].jump_x = 2;
	board[4][6].jump_y = 6;
	board[4][6].data = 57;
	board[4][6].text = "M{77}";

	board[4][3].pos_x = 4;
	board[4][3].pos_y = 3;
	board[4][3].jump_x = 5;
	board[4][3].jump_y = 1;
	board[4][3].data = 54;
	board[4][3].text = "T";
	
	board[3][7].pos_x = 3;
	board[3][7].pos_y = 7;
	board[3][7].jump_x = 4;
	board[3][7].jump_y = 1;
	board[3][7].data = 63;
	board[3][7].text = "S{52}";
	
	board[3][4].pos_x = 3;
	board[3][4].pos_y = 4;
	board[3][4].jump_x = 2;
	board[3][4].jump_y = 0;
	board[3][4].data = 66;
	board[3][4].text = "B";
	
	board[3][1].pos_x = 3;
	board[3][1].pos_y = 1;
	board[3][1].jump_x = 2;
	board[3][1].jump_y = 6;
	board[3][1].data = 69;
	board[3][1].text = "M{77}";
	
	board[2][8].pos_x = 2;
	board[2][8].pos_y = 8;
	board[2][8].jump_x = 2;
	board[2][8].jump_y = 3;
	board[2][8].data = 79;
	board[2][8].text = "T";
	
	board[2][5].pos_x = 2;
	board[2][5].pos_y = 5;
	board[2][5].jump_x = 1;
	board[2][5].jump_y = 7;
	board[2][5].data = 76;
	board[2][5].text = "M{83}";
	
	board[2][2].pos_x = 2;
	board[2][2].pos_y = 2;
	board[2][2].jump_x = 3;
	board[2][2].jump_y = 2;
	board[2][2].data = 73;
	board[2][2].text = "S{68}";
	
	board[1][1].pos_x = 1;
	board[1][1].pos_y = 1;
	board[1][1].jump_x = 0;
	board[1][1].jump_y = 3;
	board[1][1].data = 89;
	board[1][1].text = "M{94}";
	
	board[1][5].pos_x = 1;
	board[1][5].pos_y = 5;
//	board[1][5].jump_x = 8;
//	board[1][5].jump_y = 1;
	board[1][5].data = 85;
	board[1][5].text = "P";
	
	board[1][8].pos_x = 1;
	board[1][8].pos_y = 8;
	board[1][8].jump_x = 1;
	board[1][8].jump_y = 3;
	board[1][8].data = 82;
	board[1][8].text = "B";
	
	board[0][2].pos_x = 0;
	board[0][2].pos_y = 2;
	board[0][2].jump_x = 1;
	board[0][2].jump_y = 2;
	board[0][2].data = 93;
	board[0][2].text = "T";
	
	board[0][7].pos_x = 0;
	board[0][7].pos_y = 7;
	board[0][7].jump_x = 3;
	board[0][7].jump_y = 1;
	board[0][7].data = 98;
	board[0][7].text = "S{72}";
	
	board[0][8].pos_x = 0;
	board[0][8].pos_y = 8;
	board[0][8].jump_x = 4;
	board[0][8].jump_y = 5;
	board[0][8].data = 99;
	board[0][8].text = "S{56}";
	
	int i;
	for(i=2;i<6;i++){
		board[9][10-i].data = i;
		board[9][10-i].pos_x = 9;
		board[9][10-i].pos_y = 10-i;
		board[9][10-i].jump_x = 9;
		board[9][10-i].jump_y = 10-i;
		board[9][10-i].text = NULL;
	}
	
	for(i=8;i<11;i++){
		board[9][10-i].data = i;
		board[9][10-i].pos_x = 9;
		board[9][10-i].pos_y = 10-i;
		board[9][10-i].jump_x = 9;
		board[9][10-i].jump_y = 10-i;
		board[9][10-i].text = NULL;
	}
	
	int j=0;
	for(i=11;i<13;i++){
		board[8][j].data = i;
		board[8][j].pos_x = 8;
		board[8][j].pos_y = j;
		board[8][j].jump_x = 8;
		board[8][j].jump_y = j;
		board[8][j].text = NULL;
		j++;
	}
	
	j=3;
	for(i=14;i<17;i++){
		board[8][j].data = i;
		board[8][j].pos_x = 8;
		board[8][j].pos_y = j;
		board[8][j].jump_x = 8;
		board[8][j].jump_y = j;
		board[8][j].text = NULL;
		j++;
	}
	
	j=7;
	for(i=18;i<21;i++){
		board[8][j].data = i;
		board[8][j].pos_x = 8;
		board[8][j].pos_y = j;
		board[8][j].jump_x = 8;
		board[8][j].jump_y = j;
		board[8][j].text = NULL;
		j++;
	}
	
	j=9;
	for(i=21;i<25;i++){
		board[7][j].data = i;
		board[7][j].pos_x = 7;
		board[7][j].pos_y = j;
		board[7][j].jump_x = 7;
		board[7][j].jump_y = j;
		board[7][j].text = NULL;
		j--;
	}
	
	j=4;
	for(i=26;i<29;i++){
		board[7][j].data = i;
		board[7][j].pos_x = 7;
		board[7][j].pos_y = j;
		board[7][j].jump_x = 7;
		board[7][j].jump_y = j;
		board[7][j].text = NULL;
		j--;
	}
	
	j=0;
	for(i=30;i<31;i++){
		board[7][j].data = i;
		board[7][j].pos_x = 7;
		board[7][j].pos_y = j;
		board[7][j].jump_x = 7;
		board[7][j].jump_y = j;
		board[7][j].text = NULL;
		j--;
	}
	
	j=0;
	for(i=31;i<32;i++){
		board[6][j].data = i;
		board[6][j].pos_x = 6;
		board[6][j].pos_y = j;
		board[6][j].jump_x = 6;
		board[6][j].jump_y = j;
		board[6][j].text = NULL;
		j++;
	}
	
	j=2;
	for(i=33;i<36;i++){
		board[6][j].data = i;
		board[6][j].pos_x = 6;
		board[6][j].pos_y = j;
		board[6][j].jump_x = 6;
		board[6][j].jump_y = j;
		board[6][j].text = NULL;
		j++;
	}
	
	j=6;
	for(i=37;i<40;i++){
		board[6][j].data = i;
		board[6][j].pos_x = 6;
		board[6][j].pos_y = j;
		board[6][j].jump_x = 6;
		board[6][j].jump_y = j;
		board[6][j].text = NULL;
		j++;
	}
	
	j=9;
	for(i=41;i<45;i++){
		board[5][j].data = i;
		board[5][j].pos_x = 5;
		board[5][j].pos_y = j;
		board[5][j].jump_x = 5;
		board[5][j].jump_y = j;
		board[5][j].text = NULL;
		j--;
	}
	
	j=4;
	for(i=46;i<48;i++){
		board[5][j].data = i;
		board[5][j].pos_x = 5;
		board[5][j].pos_y = j;
		board[5][j].jump_x = 5;
		board[5][j].jump_y = j;
		board[5][j].text = NULL;
		j--;
	}
	
	j=1;
	for(i=49;i<50;i++){
		board[5][j].data = i;
		board[5][j].pos_x = 5;
		board[5][j].pos_y = j;
		board[5][j].jump_x = 5;
		board[5][j].jump_y = j;
		board[5][j].text = NULL;
		j--;
	}
	
	j=0;
	for(i=51;i<54;i++){
		board[4][j].data = i;
		board[4][j].pos_x = 4;
		board[4][j].pos_y = j;
		board[4][j].jump_x = 4;
		board[4][j].jump_y = j;
		board[4][j].text = NULL;
		j++;
	}
	
	j=4;
	for(i=55;i<57;i++){
		board[4][j].data = i;
		board[4][j].pos_x = 4;
		board[4][j].pos_y = j;
		board[4][j].jump_x = 4;
		board[4][j].jump_y = j;
		board[4][j].text = NULL;
		j++;
	}
	
	j=7;
	for(i=58;i<60;i++){
		board[4][j].data = i;
		board[4][j].pos_x = 4;
		board[4][j].pos_y = j;
		board[4][j].jump_x = 4;
		board[4][j].jump_y = j;
		board[4][j].text = NULL;
		j++;
	}
	
	j=9;
	for(i=61;i<63;i++){
		board[3][j].data = i;
		board[3][j].pos_x = 3;
		board[3][j].pos_y = j;
		board[3][j].jump_x = 3;
		board[3][j].jump_y = j;
		board[3][j].text = NULL;
		j--;
	}
	
	j=6;
	for(i=64;i<66;i++){
		board[3][j].data = i;
		board[3][j].pos_x = 3;
		board[3][j].pos_y = j;
		board[3][j].jump_x = 3;
		board[3][j].jump_y = j;
		board[3][j].text = NULL;
		j--;
	}
	
	j=3;
	for(i=67;i<69;i++){
		board[3][j].data = i;
		board[3][j].pos_x = 3;
		board[3][j].pos_y = j;
		board[3][j].jump_x = 3;
		board[3][j].jump_y = j;
		board[3][j].text = NULL;
		j--;
	}
	
	j=0;
	for(i=70;i<71;i++){
		board[3][j].data = i;
		board[3][j].pos_x = 3;
		board[3][j].pos_y = j;
		board[3][j].jump_x = 3;
		board[3][j].jump_y = j;
		board[3][j].text = NULL;
		j--;
	}
	
	j=0;
	for(i=71;i<73;i++){
		board[2][j].data = i;
		board[2][j].pos_x = 2;
		board[2][j].pos_y = j;
		board[2][j].jump_x = 2;
		board[2][j].jump_y = j;
		board[2][j].text = NULL;
		j++;
	}
	
	j=3;
	for(i=74;i<76;i++){
		board[2][j].data = i;
		board[2][j].pos_x = 2;
		board[2][j].pos_y = j;
		board[2][j].jump_x = 2;
		board[2][j].jump_y = j;
		board[2][j].text = NULL;
		j++;
	}
	
	j=6;
	for(i=77;i<79;i++){
		board[2][j].data = i;
		board[2][j].pos_x = 2;
		board[2][j].pos_y = j;
		board[2][j].jump_x = 2;
		board[2][j].jump_y = j;
		board[2][j].text = NULL;
		j++;
	}
	
	j=9;
	for(i=80;i<81;i++){
		board[2][j].data = i;
		board[2][j].pos_x = 2;
		board[2][j].pos_y = j;
		board[2][j].jump_x = 2;
		board[2][j].jump_y = j;
		board[2][j].text = NULL;
		j++;
	}
	
	j=9;
	for(i=81;i<82;i++){
		board[1][j].data = i;
		board[1][j].pos_x = 1;
		board[1][j].pos_y = j;
		board[1][j].jump_x = 1;
		board[1][j].jump_y = j;
		board[1][j].text = NULL;
		j--;
	}
	
	j=7;
	for(i=83;i<85;i++){
		board[1][j].data = i;
		board[1][j].pos_x = 1;
		board[1][j].pos_y = j;
		board[1][j].jump_x = 1;
		board[1][j].jump_y = j;
		board[1][j].text = NULL;
		j--;
	}
	
	j=4;
	for(i=86;i<89;i++){
		board[1][j].data = i;
		board[1][j].pos_x = 1;
		board[1][j].pos_y = j;
		board[1][j].jump_x = 1;
		board[1][j].jump_y = j;
		board[1][j].text = NULL;
		j--;
	}
	
	j=0;
	for(i=90;i<91;i++){
		board[1][j].data = i;
		board[1][j].pos_x = 1;
		board[1][j].pos_y = j;
		board[1][j].jump_x = 1;
		board[1][j].jump_y = j;
		board[1][j].text = NULL;
		j--;
	}
	
	j=0;
	for(i=91;i<93;i++){
		board[0][j].data = i;
		board[0][j].pos_x = 0;
		board[0][j].pos_y = j;
		board[0][j].jump_x = 0;
		board[0][j].jump_y = j;
		board[0][j].text = NULL;
		j++;
	}
	
	j=3;
	for(i=94;i<98;i++){
		board[0][j].data = i;
		board[0][j].pos_x = 0;
		board[0][j].pos_y = j;
		board[0][j].jump_x = 0;
		board[0][j].jump_y = j;
		board[0][j].text = NULL;
		j++;
	}
}

void print_board(block board[][10]){
	int i, j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(board[i][j].text!=NULL){
				printf("%s  ", board[i][j].text);
			}
			else{
				printf("%d  ", board[i][j].data);
			}
		}
		printf("\n");
	}
}

block ass(block board[][10], block temp){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(board[i][j].data==temp.data){
				temp.pos_x = board[i][j].pos_x;
				temp.pos_y = board[i][j].pos_y;
				temp.text = board[i][j].text;
				temp.type = board[i][j].type;
				temp.jump_x = board[i][j].jump_x;
				temp.jump_y = board[i][j].jump_y;
				temp.data = board[i][j].data;
			}
		}
	}
	return temp;
}

block jump(block board[][10], block temp){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(board[i][j].pos_x == temp.jump_x && board[i][j].pos_y == temp.jump_y){
				temp.pos_x = board[i][j].pos_x;
				temp.pos_y = board[i][j].pos_y;
				temp.text = board[i][j].text;
				temp.type = board[i][j].type;
				temp.jump_x = board[i][j].jump_x;
				temp.jump_y = board[i][j].jump_y;
				temp.data = board[i][j].data;
			}
		}
	}
	return temp;
}

int f(block board[][10], int cursor, int dice_rol, int *move){
	block temp;
	temp.data = cursor + dice_rol;
	printf("%d ", temp.data);
	*move = *move+1;
	
	if(temp.data==100){
		printf("\n<<<Congratulations!!!>>>");
		return temp.data;
	}
	
	if(temp.data==13){			//P block
		temp.data = temp.data - dice_rol;
		dice_rol = rand()%6+1;
		temp.data = f(board, temp.data,dice_rol, move);
	}
	if(temp.data==48){			//P block
		temp.data = temp.data - dice_rol;
		dice_rol = rand()%6+1;
		temp.data = f(board, temp.data,dice_rol, move);
	}
	if(temp.data==85){			//P block
		temp.data = temp.data - dice_rol;
		dice_rol = rand()%6+1;
		temp.data = f(board, temp.data,dice_rol, move);
	}
	if(temp.data != 13 && temp.data != 48 && temp.data != 85 && temp.data<95){
		temp = ass(board, temp);
		temp = jump(board, temp);
		dice_rol = rand()%6+1;
		temp.data = f(board, temp.data, dice_rol, move);
	}
	//rastgele atilacak olan zar 6 gelmesin 100 u gecmesin diye alinmis onlemler
	if(temp.data == 95){
		temp = ass(board, temp);
		temp = jump(board, temp);
		dice_rol = rand()%5+1;
		temp.data = f(board, temp.data, dice_rol, move);
	}
	if(temp.data == 96){
		temp = ass(board, temp);
		temp = jump(board, temp);
		dice_rol = rand()%4+1;
		temp.data = f(board, temp.data, dice_rol, move);
	}
	if(temp.data == 97){
		temp = ass(board, temp);
		temp = jump(board, temp);
		dice_rol = rand()%3+1;
		temp.data = f(board, temp.data, dice_rol, move);
	}
	if(temp.data>97 && temp.data<100){
		temp = ass(board, temp);
		temp = jump(board, temp);
		dice_rol = rand()%6+1;
		temp.data = f(board, temp.data, dice_rol, move);
	}
	return temp.data;
}

void f_versus(block board[][10]){
//	int cursor = 1;
	int dice_rol;
	dice_rol = rand()%6+1;
	int move1=0;
	int move2=0;
	
	printf("\n\n");
	f(board, 1, dice_rol, &move1);
	printf("\n\n");
	dice_rol = rand()%6+1;
	f(board, 1, dice_rol, &move2);
	printf("\n\n");
	printf("player1 = %d, player2 = %d\n", move1, move2);
	if(move1>move2){
		printf("<<<Second player won!!!>>>");
	}
	if(move1<move2){
		printf("<<<First player won!!!>>>");
	}
	if(move1==move2){
		printf("<<<Draw!!!>>>");
	}
	
}

int main(void){
	block board[10][10];
	define_board(board);
	print_board(board);
	printf("\n");
	srand(time(NULL));
	int dice_rol;
	dice_rol = rand()%6+1;
	int move = 0;
	f(board, 1, dice_rol, &move);
	printf("\nmove--->%d", move);
	printf("\n\n\n");
	f_versus(board);
}
