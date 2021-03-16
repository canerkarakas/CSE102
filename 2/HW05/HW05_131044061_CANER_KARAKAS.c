#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef enum{
	white_man, black_man, white_king, black_king, empty
}piece;

typedef enum{white = 10, black = 20
} player;

void init_board(piece board[][8]){
	int i;
	for(i=0;i<8;++i){
		board[0][i] = empty;
	}
	for(i=0;i<8;++i){
		board[1][i] = black_man;
	}
	for(i=0;i<8;++i){
		board[2][i] = black_man;
	}
	for(i=0;i<8;++i){
		board[3][i] = empty;
	}
	for(i=0;i<8;++i){
		board[4][i] = empty;
	}
	for(i=0;i<8;++i){
		board[5][i] = white_man;
	}
	for(i=0;i<8;++i){
		board[6][i] = white_man;
	}
	for(i=0;i<8;++i){
		board[7][i] = empty;
	}
}

/*
 *normal tasa king gibi davranip cok kare atlatmayi kontrol edecek fonksiyon
*/
int as_king_as_man(int from_x, int from_y, int to_x, int to_y){
	int dif_x = fabs(from_x-to_x);
	int dif_y = fabs(from_y-to_y);
	if(dif_x>1 || dif_y>1){
		return -2;
	}
	else{
		return 0;
	}
}
/*
 *oynayacak tarafa göre gidilmek istenilen yerde olaný kontrol eden fonk
 *beyaz icin: siyah adam ustune atlamak istenirse 1, siyah kral ustune 1, bos kareye 0
 *siyah icin: beyaz adam ustune atlama istenirse 2, siyah kral ustune 2, bos kare 0
 *hata durumlari icin -2(harekete izin verilmeyecegi durum)
*/
int move_control(piece board[][8], int to_x, int to_y, player p){
	int result;
	if(p==white){
		switch(board[to_x][to_y]){
			case black_man:result=1;break;
			case black_king:result =1;break;
			case empty:result=0;break;
			default:result=-2;break;
		}
	}
	if(p==black){
		switch(board[to_x][to_y]){
			case white_man:result=2;break;
			case white_king:result =2;break;
			case empty:result=0;break;
			default:result=-2;break;
		}
	}
	return result;
}

/*
 *oynanmak istenilen tasin konumunu kontrol eden fonksiyon: beyaz tas oynanmak istenirse ve beyaz tasa ulasilirsa 1
 *siyah tas oynanmak istenirse ve siyah tasa ulasilirsa 2
 *istenilen tasa ulasilmazsa -1
*/
int position_control(piece board[][8], int from_x, int from_y, player p){
	int result;
	if(p==white){
		if(board[from_x][from_y]==white_man || board[from_x][from_y]==white_king){
			result = 1;
		}
		else{
			result = -1;
		}
	}
	if(p==black){
		if(board[from_x][from_y]==black_man || board[from_x][from_y]==black_king){
			result = 2;
		}
		else{
			result = -1;
		}
	}
	return result;
}

/*
 *gitmek istenilen tasin ustunden atlarken arkasini kontrol eden fonksiyon: bosluksa 1
 *doluysa -1;
*/
int control_man_behind(piece board[][8], int to_x, int to_y){
	int result;
	if(board[to_x][to_y]==empty){
		result = 1;
	}
	else{
		result = -1;
	}
	return result;
}

/*
 *yonu bilmek icin kullanilan fonksiyon: dikeyde hareket yokken yatayda hareket varsa 1 ya da 2 dondurecek
 *yatayda hareket yokken dikeyde hareket varsa 3 ya da 4 dondurecek
*/
int row_column_move_control(piece board[][8], int from_x, int from_y, int to_x, int to_y){
	int result;
	int dif_x = from_x - to_x;
	int dif_y = from_y - to_y;
	if(dif_x==0){
		if(dif_y<0){
			result = 1;
		}
		if(dif_y>0){
			result = 2;
		}
	}
	if(dif_y==0){
		if(dif_x<0){
			result = 3;
		}
		if(dif_x>0){
			result = 4;
		}
	}
	return result;
}

/*
 *-2 hareket engelleyecek, 1 hareketi yapacak
 *hareketleri gerceklestirir
 *w ve b icin hamle yaptiktan sonra arkasýndan gelebilecek hamleleri de kontrol eder
 *W ve B icin hamleleri yaparken arada kalabilecek art arda olan taslari kontrol eder, hamlesini yapar, sonrasinda yapilabilecek hamleleri kontrol etmez
*/
int moving(piece board[][8], int from_x, int from_y, int to_x, int to_y, int mov_con){
	int result = 1;
	int yon = row_column_move_control(board, from_x, from_y, to_x, to_y);
	int behind_man;
	int king_or_man = as_king_as_man(from_x, from_y, to_x, to_y);
	if(board[from_x][from_y]==white_man && king_or_man==0){
		if(mov_con==1){
			if(yon==1){
				behind_man = control_man_behind(board, to_x, to_y+1);
				if(behind_man==1){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=empty;
					board[to_x][to_y+1]=white_man;
					int control = 0;
					int i = to_x;
					int j = to_y+1;
					while(control==0){
						if(board[i][j+1]==black_man || board[i][j+1]==black_king){
							behind_man = control_man_behind(board,i,j+2);
							if(behind_man==1){
								board[i][j]=empty;
								board[i][j+1]=empty;
								board[i][j+2]=white_man;
								j++;
							}
							else{
								control = 1;
							}
						}
						else{
							control = 1;
						}
					}
				}
				else{
					result = -2;
				}
			}
			if(yon==2){
				behind_man = control_man_behind(board,to_x, to_y-1);
				if(behind_man==1){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=empty;
					board[to_x][to_y-1]=white_man;
					int control = 0;
					int i = to_x;
					int j = to_y-1;
					while(control==0){
						if(board[i][j-1]==black_man || board[i][j-1]==black_king){
							behind_man = control_man_behind(board,i,j-2);
							if(behind_man==1){
								board[i][j]=empty;
								board[i][j-1]=empty;
								board[i][j-2]=white_man;
								j--;
							}
							else{
								control = 1;
							}
						}
						else{
							control = 1;
						}
					}
				}
				else{
					result = -2;
				}
			}
			if(yon==3){
				result = -2;
			}
			if(yon==4){
				behind_man = control_man_behind(board,to_x-1, to_y);
				if(behind_man==1){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=empty;
					board[to_x-1][to_y]=white_man;
					if(to_x-1==0){
						board[to_x-1][to_y]=white_king;
					}
					else{
						int control = 0;
						int i = to_x-1;
						int j = to_y;
						while(control==0){
							if(board[i-1][j]==black_man || board[i-1][j]==black_king){
								behind_man = control_man_behind(board,i-2,j);
								if(behind_man==1){
									board[i][j]=empty;
									board[i-1][j]=empty;
									board[i-2][j]=white_man;
									if((i-2) == 0){
										board[i-2][j]=white_king;
										control = 1;
									}
									else{
										i++;
									}
								}
								else{
									control = 1;
								}
							}
							else{
								control = 1;
							}
						}
					}
				}
				else{
					result = -2;
				}
			}
		}
		if(mov_con==0){
			if(yon==3){
				result = -2;
			}
			else{
				board[from_x][from_y]=empty;
				board[to_x][to_y]=white_man;
				if(to_x==0){
					board[to_x][to_y]=white_king;
				}
			}
		}
	}
	if(board[from_x][from_y]==white_king){
		if(mov_con==1){
			if(yon==1){
				behind_man = control_man_behind(board,to_x, to_y+1);
				if(behind_man==1){
					int control = 0;
					int i = from_x;
					int j = from_y+1;
					while(control==0){
						if((board[i][j]==black_man || board[i][j]==black_king) && j!=to_y){
							if(board[i][j+1]==black_man || board[i][j+1]==black_king){
								result = -2;
								control = 1;
							}
							else{
								j++;
							}
						}
						if(j==to_y){
							board[from_x][from_y]=empty;
							board[to_x][to_y]=empty;
							board[to_x][to_y+1]=white_king;
							for(i=from_y;i<to_y+1;++i){
								board[from_x][i] = empty;
							}
							control = 1;
						}
						else{
							j++;
						}
					}
				}
				else{
					result = -2;
				}
			}
			if(yon==2){
				behind_man = control_man_behind(board,to_x, to_y-1);
				if(behind_man==1){
					int control = 0;
					int i = from_x;
					int j = from_y-1;
					while(control==0){
						if((board[i][j]==black_man || board[i][j]==black_king) && j!=to_y){
							if(board[i][j-1]==black_man || board[i][j-1]==black_king){
								result = -2;
								control = 1;
							}
							else{
								j--;
							}
						}
						if(j==to_y){
							board[from_x][from_y]=empty;
							board[to_x][to_y]=empty;
							board[to_x][to_y-1]=white_king;
							for(i=from_y;i>to_y-1;i--){
								board[from_x][i]=empty;
							}
							control = 1;
						}
						else{
							j--;
						}
					}
				}
				else{
					result = -2;
				}
			}
			if(yon==3){
				behind_man = control_man_behind(board,to_x+1, to_y);
				if(behind_man==1){
					int control = 0;
					int i = from_x+1;
					int j = from_y;
					while(control==0){
						if((board[i][j]==black_man || board[i][j]==black_king) && i!=to_x){
							if(board[i+1][j]==black_man || board[i+1][j]==black_king){
								result = -2;
								control = 1;
							}
							else{
								i++;
							}
						}
						if(i==to_x){
							board[from_x][from_y]=empty;
							board[to_x][to_y]=empty;
							board[to_x+1][to_y]=white_king;
							for(i=from_x;i<to_x+1;i++){
								board[i][from_y] = empty;
							}
							control = 1;
						}
						else{
							i++;
						}
					}
				}
				else{
					result = -2;
				}
			}
			if(yon==4){
				behind_man = control_man_behind(board,to_x-1, to_y);
				if(behind_man==1){
					int control = 0;
					int i = from_x-1;
					int j = from_y;
					while(control==0){
						if((board[i][j]==black_man || board[i][j]==black_king) && i!=to_x){
							if(board[i-1][j]==black_man || board[i-1][j]==black_king){
								result = -2;
								control = 1;
							}
							else{
								i--;
							}
						}
						if(i==to_x){
							board[from_x][from_y]=empty;
							board[to_x][to_y]=empty;
							board[to_x-1][to_y]=white_king;
							for(i=from_x;i>to_x-1;--i){
								board[i][from_y]=empty;
							}
							control = 1;
						}
						else{
							i--;
						}
					}
				}
				else{
					result = -2;
				}
			}
		}
		if(mov_con==0){
			if(yon==1){
				int control = 0;
				int i = from_x;
				int j = from_y+1;
				while(control==0){
					if((board[i][j]==black_man || board[i][j]==black_king) && j!=to_y){
						if(board[i][j+1]==black_man || board[i][j+1]==black_king){
							result = -2;
							control = 1;
						}
						else{
							j++;
						}
					}
					if(j==to_y){
						board[from_x][from_y]=empty;
						board[to_x][to_y]=white_king;
						for(i=from_y;i<to_y;i++){
							board[from_x][i]=empty;
						}
						control = 1;
					}
					else{
						j++;
					}
				}
			}
			if(yon==2){
				int control = 0;
				int i = from_x;
				int j = from_y-1;
				while(control==0){
					if((board[i][j]==black_man || board[i][j]==black_king) && j!=to_y){
						if(board[i][j-1]==black_man || board[i][j-1]==black_king){
							result = -2;
							control = 1;
						}
						else{
							j--;
						}
					}
					if(j==to_y){
						board[from_x][from_y]=empty;
						board[to_x][to_y]=white_king;
						for(i=from_y;i>to_y;i--){
							board[from_x][i]=empty;
						}
						control = 1;
					}
					else{
						j--;
					}
				}
			}
			if(yon==3){
				int control = 0;
				int i = from_x+1;
				int j = from_y;
				while(control==0){
					if((board[i][j]==black_man || board[i][j]==black_king) && i!=to_x){
						if(board[i+1][j]==black_man || board[i+1][j]==black_king){
							result = -2;
							control = 1;
						}
						else{
							i++;
						}
					}
					if(i==to_x){
						board[from_x][from_y]=empty;
						board[to_x][to_y]=white_king;
						for(i=from_x;i<to_x;i++){
							board[i][from_y]=empty;
						}
						control = 1;
					}
					else{
						i++;
					}
				}
			}
			if(yon==4){
				int control = 0;
				int i = from_x-1;
				int j = from_y;
				while(control==0){
					if((board[i][j]==black_man || board[i][j]==black_king) && i!=to_x){
						if(board[i-1][j]==black_man || board[i-1][j]==black_king){
							result = -2;
							control = 1;
						}
						else{
							i--;
						}
					}
					if(i==to_x){
						board[from_x][from_y]=empty;
						board[to_x][to_y]=white_king;
						for(i=from_x;i>to_x;--i){
							board[i][from_y]=empty;
						}
						control = 1;
					}
					else{
						i--;
					}
				}
			}
		}
	}
	if(board[from_x][from_y]==black_man && king_or_man==0){
		if(mov_con==2){
			if(yon==1){
				behind_man = control_man_behind(board,to_x, to_y+1);
				if(behind_man==1){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=empty;
					board[to_x][to_y+1]=black_man;
					int control = 0;
					int i = to_x;
					int j = to_y+1;
					while(control==0){
						if(board[i][j+1]==white_man || board[i][j+1]==white_king){
							behind_man = control_man_behind(board,i,j+2);
							if(behind_man==1){
								board[i][j]=empty;
								board[i][j+1]=empty;
								board[i][j+2]=black_man;
								j++;
							}
							else{
								control = 1;
							}
						}
						else{
							control = 1;
						}
					}
				}
				else{
					result = -2;
				}
			}
			if(yon==2){
				behind_man = control_man_behind(board,to_x, to_y-1);
				if(behind_man==1){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=empty;
					board[to_x][to_y-1]=black_man;
					int control = 0;
					int i = to_x;
					int j = to_y-1;
					while(control==0){
						if(board[i][j-1]==white_man || board[i][j-1]==white_king){
							behind_man = control_man_behind(board,i,j-2);
							if(behind_man==1){
								board[i][j]=empty;
								board[i][j-1]=empty;
								board[i][j-2]=black_man;
								j--;
							}
							else{
								control = 1;
							}
						}
						else{
							control = 1;
						}
					}
				}
				else{
					result = -2;
				}
			}
			if(yon==3){
				behind_man = control_man_behind(board,to_x+1, to_y);
				if(behind_man==1){
					board[from_x][from_y]=empty;
					board[to_x][to_y]=empty;
					board[to_x+1][to_y]=black_man;
					if(to_x+1==7){
						board[to_x+1][to_y]=black_king;
					}
					else{
						int control = 0;
						int i = to_x+1;
						int j = to_y;
						while(control==0){
							if(board[i+1][j]==white_man || board[i+1][j]==white_king){
								behind_man = control_man_behind(board,i+2,j);
								if(behind_man==1){
									board[i][j]=empty;
									board[i+1][j]=empty;
									board[i+2][j]=black_man;
									if(i+2==7){
										board[i+2][j]=black_king;
									}
									else{
										i++;
									}
								}
								else{
									control = 1;
								}
							}
							else{
								control = 1;
							}
						}
					}
				}
				else{
					result = -2;
				}
			}
			if(yon==4){
				result = -2;
			}
		}
		if(mov_con==0){
			if(yon==4){
				result = -2;
			}
			else{
				board[from_x][from_y]=empty;
				board[to_x][to_y]=black_man;
			}
		}
	}
	if(board[from_x][from_y]==black_king){
		if(mov_con==2){
			if(yon==1){
				behind_man = control_man_behind(board,to_x, to_y+1);
				if(behind_man==1){
					int control = 0;
					int i = from_x;
					int j = from_y+1;
					while(control==0){
						if((board[i][j]==white_man || board[i][j]==white_king) && j!=to_y){
							if(board[i][j+1]==white_man || board[i][j+1]==white_king){
								result = -2;
								control = 1;
							}
							else{
								j++;
							}
						}
						if(j==to_y){
							board[from_x][from_y]=empty;
							board[to_x][to_y]=empty;
							board[to_x][to_y+1]=black_king;
							for(i=from_y;i<to_y+1;i++){
								board[from_x][i]=empty;
							}
							control = 1;
						}
						else{
							j++;
						}
					}
				}
				else{
					result = -2;
				}
			}
			if(yon==2){
				behind_man = control_man_behind(board,to_x, to_y-1);
				if(behind_man==1){
					int control = 0;
					int i = from_x;
					int j = from_y-1;
					while(control==0){
						if((board[i][j]==white_man || board[i][j]==white_king) && j!=to_y){
							if(board[i][j-1]==white_man || board[i][j-1]==white_king){
								result = -2;
								control = 1;
							}
							else{
								j--;
							}
						}
						if(j==to_y){
							board[from_x][from_y]=empty;
							board[to_x][to_y]=empty;
							board[to_x][to_y-1]=black_king;
							for(i=from_y;i>to_y-1;i--){
								board[from_x][i]=empty;
							}
							control = 1;
						}
						else{
							j--;
						}
					}
				}
				else{
					result = -2;
				}
			}
			if(yon==3){
				behind_man = control_man_behind(board,to_x+1, to_y);
				if(behind_man==1){
					int control = 0;
					int i = from_x+1;
					int j = from_y;
					while(control==0){
						if((board[i][j]==white_man || board[i][j]==white_king) && i!=to_x){
							if(board[i+1][j]==white_man || board[i+1][j]==white_king){
								result = -2;
								control = 1;
							}
							else{
								i++;
							}
						}
						if(i==to_x){
							board[from_x][from_y]=empty;
							board[to_x][to_y]=empty;
							board[to_x+1][to_y]=black_king;
							for(i=from_x;i<to_x+1;i++){
								board[i][from_y]=empty;
							}
							control = 1;
						}
						else{
							i++;
						}
					}
				}
				else{
					result = -2;
				}
			}
			if(yon==4){
				behind_man = control_man_behind(board,to_x-1, to_y);
				if(behind_man==1){
					int control = 0;
					int i = from_x-1;
					int j = from_y;
					while(control==0){
						if((board[i][j]==white_man || board[i][j]==white_king) && i!=to_x){
							if(board[i-1][j]==white_man || board[i-1][j]==white_king){
								result = -2;
								control = 1;
							}
							else{
								i--;
							}
						}
						if(i==to_x){
							board[from_x][from_y]=empty;
							board[to_x][to_y]=empty;
							board[to_x-1][to_y]=black_king;
							for(i=from_x;i>to_x-1;i--){
								board[i][from_y]=empty;
							}
							control = 1;
						}
						else{
							i--;
						}
					}
				}
				else{
					result = -2;
				}
			}
		}
		if(mov_con==0){
			if(yon==1){
				int control = 0;
				int i = from_x;
				int j = from_y+1;
				while(control==0){
					if((board[i][j]==white_man || board[i][j]==white_king) && j!=to_y){
						if(board[i][j+1]==white_man || board[i][j+1]==white_king){
							result = -2;
							control = 1;
						}
						else{
							j++;
						}
					}
					if(j==to_y){
						board[from_x][from_y]=empty;
						board[to_x][to_y]=black_king;
						for(i=from_y;i<to_y;i++){
							board[from_x][i]=empty;
						}
						control = 1;
					}
					else{
						j++;
					}
				}
			}
			if(yon==2){
				int control = 0;
				int i = from_x;
				int j = from_y-1;
				while(control==0){
					if((board[i][j]==white_man || board[i][j]==white_king) && j!=to_y){
						if(board[i][j-1]==white_man || board[i][j-1]==white_king){
							result = -2;
							control = 1;
						}
						else{
							j--;
						}
					}
					if(j==to_y){
						board[from_x][from_y]=empty;
						board[to_x][to_y]=black_king;
						for(i=from_y;i>to_y;i--){
							board[from_x][i]=empty;
						}
						control = 1;
					}
					else{
						j--;
					}
				}
			}
			if(yon==3){
				int control = 0;
				int i = from_x+1;
				int j = from_y;
				while(control==0){
					if((board[i][j]==white_man || board[i][j]==white_king) && i!=to_x){
						if(board[i+1][j]==white_man || board[i+1][j]==white_king){
							result = -2;
							control = 1;
						}
						else{
							i++;
						}
					}
					if(i==to_x){
						board[from_x][from_y]=empty;
						board[to_x][to_y]=black_king;
						for(i=from_x;i<to_x;i++){
							board[i][from_y]=empty;
						}
						control = 1;
					}
					else{
						i++;
					}
				}
			}
			if(yon==4){
				int control = 0;
				int i = from_x-1;
				int j = from_y;
				while(control==0){
					if((board[i][j]==white_man || board[i][j]==white_king) && i!=to_x){
						if(board[i-1][j]==white_man || board[i-1][j]==white_king){
							result = -2;
							control = 1;
						}
						else{
							i--;
						}
					}
					if(i==to_x){
						board[from_x][from_y]=empty;
						board[to_x][to_y]=black_king;
						for(i=from_x;i>to_x;i--){
							board[i][from_y]=empty;
						}
						control = 1;
					}
					else{
						i--;
					}
				}
			}
		}
	}
	if(king_or_man==-2){
		result=-2;
	}
	return result;
}

int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){
	int result;
	int pos_con = position_control(board, from_x, from_y, p);
	int move_con = move_control(board, to_x, to_y, p);
	int n;
	if(pos_con!=-1){
		if(p==white){
			if(move_con==1){
				n = moving(board, from_x, from_y, to_x, to_y, move_con);
			}
			if(move_con==0){
				n = moving(board, from_x, from_y, to_x, to_y, move_con);
			}
			if(move_con==-2){
				result = -2;
			}
		}
		if(p==black){
			if(move_con==2){
				n = moving(board, from_x, from_y, to_x, to_y, move_con);
			}
			if(move_con==0){
				n = moving(board, from_x, from_y, to_x, to_y, move_con);
			}
			if(move_con==-2){
				result = -2;
			}
		}
	}
	else{
		result = pos_con;
	}
	return result;
}

int check_end_of_game(piece board[][8]){
	int i,j;
	int result;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(board[i][j]==white_man || board[i][j]==white_king){
				result = -1;
				i = 8;
				j = 8;
			}
			else{
				result = black;
			}
		}
	}
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(board[i][j]==black_man || board[i][j]==black_king){
				result = -1;
				i = 8;
				j = 8;
			}
			else{
				result = white;
			}
		}
	}
	return result;
}

void display_board(piece board[][8]){
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			switch(board[i][j]){
				case white_man: printf("w");break;
				case black_man: printf("b");break;
				case empty: printf("-");break;
				case black_king: printf("B");break;
				case white_king: printf("W");break; 
				default:;break;
			}
		}
		printf("\n");
	}
}

void sample_game_1(){
	piece board[8][8];
	init_board(board);
	display_board(board);
	int winner;
	player p;
	int from_x, from_y, to_x, to_y, n;
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>");
	p = white;
	from_x=5, from_y=3, to_x=4, to_y=3;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=2, from_y=3, to_x=3, to_y=3;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=4, from_y=3, to_x=3, to_y=3;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=2, from_y=2, to_x=3, to_y=2;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=5, from_y=1, to_x=4, to_y=1;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=2, from_y=0, to_x=3, to_y=0;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=4, from_y=1, to_x=4, to_y=2;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=2, from_y=4, to_x=3, to_y=4;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=4, from_y=2, to_x=3, to_y=2;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=2, from_y=6, to_x=3, to_y=6;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=6, from_y=1, to_x=5, to_y=1;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=2, from_y=7, to_x=3, to_y=7;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=5, from_y=1, to_x=4, to_y=1;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=2, from_y=1, to_x=3, to_y=1;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=4, from_y=1, to_x=3, to_y=1;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=2, from_y=5, to_x=3, to_y=5;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=0, from_y=3, to_x=0, to_y=7;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=3, from_y=4, to_x=4, to_y=4;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=0, from_y=7, to_x=4, to_y=7;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=3, from_y=0, to_x=4, to_y=0;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=5, from_y=0, to_x=4, to_y=0;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=1, from_y=0, to_x=2, to_y=0;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=3, from_y=0, to_x=2, to_y=0;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=4, from_y=4, to_x=4, to_y=5;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=0, from_y=2, to_x=0, to_y=6;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=4, from_y=5, to_x=4, to_y=4;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=0, from_y=6, to_x=4, to_y=6;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=4, from_y=4, to_x=4, to_y=3;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=0, from_y=1, to_x=0, to_y=5;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=4, from_y=3, to_x=4, to_y=2;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=0, from_y=5, to_x=4, to_y=5;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=1, from_y=4, to_x=2, to_y=4;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=4, from_y=5, to_x=4, to_y=1;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=2, from_y=4, to_x=2, to_y=5;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=4, from_y=7, to_x=2, to_y=7;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = black;
	from_x=2, from_y=5, to_x=2, to_y=6;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
	p = white;
	from_x=2, from_y=7, to_x=2, to_y=5;
	n = move(board, from_x, from_y, to_x, to_y, p);
	printf("\n\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>>\n\n");
	display_board(board);
	winner = check_end_of_game(board);
	if(winner!=-1){
		if(winner==white){
			printf("winner =>> white");
			exit(0);
		}
		if(winner==black){
			printf("winner =>> black");
			exit(0);
		}
	}
}

void sample_game_2(){
	
}

int main(void){
	sample_game_1();
	return 0;
	
}

