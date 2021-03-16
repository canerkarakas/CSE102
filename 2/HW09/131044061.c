#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
	char **map;
	int width;
	int height;
	int flower_x;
	int flower_y;
}Forest;

typedef struct{
	int coord_x;
	int coord_y;
	int water_bottle_size;//this is the volume of water bottle in mL.
}Botanist;

typedef enum{
	up=0, down=1, left=2, right=3
}moves;

void print_map(Forest *forest){
	int i,j;
	for(i=0;i<forest->height;i++){
		for(j=0;j<forest->width;j++){
			printf("%c ", forest->map[i][j]);
		}
		printf("\n");
	}
}

void init_game(Forest *forest, Botanist *botanist){
	FILE *file;
	file = fopen("init.txt", "r");
	fscanf(file, "%d", &botanist->water_bottle_size);
	char c;
	fscanf(file, "%d%c%d", &forest->height, &c, &forest->width);
	fscanf(file, "%c", &c);
	int i, j;
	forest->map = (char **)malloc(forest->height * sizeof(char*));
	if(forest->map == NULL)
		printf("-1");
	for(i=0;i<forest->height;i++)
		forest->map[i] = malloc(forest->width * sizeof(char));
	i=0;j=0;
	while(!feof(file)){
		fscanf(file, "%c", &c);
		if(!feof(file)){
			if(c!='\n' && c!=','){
				forest->map[i][j] = c;
				if(c=='B'){
					botanist->coord_x = i;
					botanist->coord_y = j;
				}
				j++;
			}
			if(c=='F'){
				forest->flower_x = i;
				forest->flower_y = j-1;
			}
			if(c=='\n'){
				j=0;
				i++;
			}
		}
		else{
			forest->map[i][j] = '\0';
		}
	}
	print_map(forest);
	fclose(file);
}

void search(Forest *forest, Botanist *botanist, int water_bottle_size){
//	printf("\n<<<%d>>>\n", water_bottle_size);
	moves move;
	if((botanist->coord_x==forest->flower_x && botanist->coord_y==forest->flower_y)){
	//	print_map(forest);
	//	printf("I have found it on (%d,%d)!", forest->flower_x, forest->flower_y);
	}
	if(water_bottle_size == 0 && (botanist->coord_x!=forest->flower_x || botanist->coord_y!=forest->flower_y)){
	//	print_map(forest);
	//	printf("Help! I am on (%d,%d)", botanist->coord_x, botanist->coord_y);
	}
	if(water_bottle_size>0 && (botanist->coord_x!=forest->flower_x || botanist->coord_y!=forest->flower_y)){
		move = rand()%4;
		if(move==3){ //right
		//	printf("\nRight\n");
			if(forest->map[botanist->coord_x][botanist->coord_y+1] == ' '){
				botanist->coord_y = botanist->coord_y + 1;
				forest->map[botanist->coord_x][botanist->coord_y-1] = ' ';
				forest->map[botanist->coord_x][botanist->coord_y] = 'B';
		//		print_map(forest);
				water_bottle_size = water_bottle_size-1;
				search(forest, botanist, water_bottle_size);
			}
			else if(forest->map[botanist->coord_x][botanist->coord_y+1] == 'F'){
				botanist->coord_y = botanist->coord_y + 1;
				forest->map[botanist->coord_x][botanist->coord_y-1] = ' ';
				water_bottle_size = water_bottle_size-1;
				search(forest, botanist, water_bottle_size);
			}
			else{
			//	printf("You can not move");
				search(forest, botanist, water_bottle_size);
			}
		}
		if(move==2){ //left
		//	printf("\nLeft\n");
			if(forest->map[botanist->coord_x][botanist->coord_y-1] == ' '){
				botanist->coord_y = botanist->coord_y -1;
				forest->map[botanist->coord_x][botanist->coord_y+1] = ' ';
				forest->map[botanist->coord_x][botanist->coord_y] = 'B';
			//	print_map(forest);
				water_bottle_size = water_bottle_size-1;
				search(forest, botanist, water_bottle_size);
			}
			else if(forest->map[botanist->coord_x][botanist->coord_y-1] == 'F'){
				botanist->coord_y = botanist->coord_y - 1;
				forest->map[botanist->coord_x][botanist->coord_y+1] = ' ';
				water_bottle_size = water_bottle_size-1;
				search(forest, botanist, water_bottle_size);
			}
			else{
			//	printf("You can not move");
				search(forest, botanist, water_bottle_size);
			}
		}
		if(move==1 && botanist->coord_x != forest->height-1){ //down
		//	printf("\nDown\n");
			if(forest->map[botanist->coord_x+1][botanist->coord_y] == ' '){
				botanist->coord_x = botanist->coord_x + 1;
				forest->map[botanist->coord_x-1][botanist->coord_y] = ' ';
				forest->map[botanist->coord_x][botanist->coord_y] = 'B';
			//	print_map(forest);
				water_bottle_size = water_bottle_size-1;
				search(forest, botanist, water_bottle_size);
			}
			else if(forest->map[botanist->coord_x+1][botanist->coord_y] == 'F'){
				botanist->coord_x = botanist->coord_x + 1;
				forest->map[botanist->coord_x-1][botanist->coord_y] = ' ';
				water_bottle_size = water_bottle_size-1;
				search(forest, botanist, water_bottle_size);
			}
			else{
			//	printf("You can not move");
				search(forest, botanist, water_bottle_size);
			}
		}
		if(move == 1 && botanist->coord_x == forest->height-1){
		//	printf("At the bottom, You can not go further down!!!");
			search(forest,botanist, water_bottle_size);
		}
		if(move==0){ //up
		//	printf("\nUp\n");
			if(forest->map[botanist->coord_x-1][botanist->coord_y] == ' '){
				botanist->coord_x = botanist->coord_x - 1;
				forest->map[botanist->coord_x+1][botanist->coord_y] = ' ';
				forest->map[botanist->coord_x][botanist->coord_y] = 'B';
			//	print_map(forest);
				water_bottle_size = water_bottle_size-1;
				search(forest, botanist, water_bottle_size);
			}
			else if(forest->map[botanist->coord_x-1][botanist->coord_y] == 'F'){
				botanist->coord_x = botanist->coord_x - 1;
				forest->map[botanist->coord_x+1][botanist->coord_y] = ' ';
				water_bottle_size = water_bottle_size-1;
				search(forest, botanist, water_bottle_size);
			}
			else{
			//	printf("You can not move");
				search(forest, botanist, water_bottle_size);
			}
		}
	}
}

int main(void){
	Forest forest;
	Botanist botanist;
	srand(time(NULL));
	init_game(&forest, &botanist);
//	printf("%d, %d, %d", botanist.coord_x, botanist.coord_y, botanist.water_bottle_size);
	printf("\n\nSearching...\n\n");
	search(&forest, &botanist, botanist.water_bottle_size);
	if(botanist.coord_x==forest.flower_x && botanist.coord_y==forest.flower_y){
		print_map(&forest);
		printf("I have found it on (%d,%d)!", botanist.coord_x, botanist.coord_y);
	}
	else{
		print_map(&forest);
		printf("Help! I am on (%d,%d)", botanist.coord_x, botanist.coord_y);
	}
	return 0;
}
