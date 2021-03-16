#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node_r{
	int room_num, capacity, floor;
	struct node_s *linkp;
}rooms;

typedef struct node_c{
	char *name, *surname, *gender;
	int room_num, age;
	struct node_c *link;
}customers;

void create_room(rooms *r, int room_num, int capacity, int floor){
	r->room_num = room_num;
	r->capacity = capacity;
	r->floor = floor;
}

void create_customers(customers *c, char *name, char *surname, char *gender, int room_num, int age){
	c->name = (char*)calloc(12, sizeof(char));
	c->surname = (char*)calloc(12, sizeof(char));
	c->gender = (char*)calloc(6, sizeof(char));
	strcpy(c->name, name);
	strcpy(c->surname, surname);
	strcpy(c->gender, gender);
	c->room_num = room_num;
	c->age = age;
}

void add_room_to_end(rooms *r, int room_num, int capacity, int floor){
	while(r->linkp!=NULL){
		r = r->linkp;
	}
	r->linkp = (rooms*)calloc(1, sizeof(rooms));
	create_room(r->linkp, room_num, capacity, floor);
}

void add_customer_to_end(customers *c, char *name, char *surname, char *gender, int room_num, int age){
	while(c->link!=NULL){
		c = c->link;
	}
	c->link = (customers*)calloc(1, sizeof(customers));
	create_customers(c->link, name, surname, gender, room_num, age);
}

void print(rooms *r){
	while(r!=NULL){
		printf("%d,%d,%d\n", r->room_num, r->capacity, r->floor);
		r = r->linkp;
	}
}

void print2(customers *c){
	while(c!=NULL){
		printf("%d, %s %s, %d, %s\n", c->room_num, c->name, c->surname, c->age, c->gender);
		c = c->link;
	}
}

void reading_customers_txt(FILE *file, char *name, char *surname, char *gender, int *age, int *room_num){
	fscanf(file, "%d", room_num);
	char c;
	int i = 0;
	fscanf(file, "%c", &c);
	while(c!=' '){
		if(c==' '){
			name[i-2] = NULL;
		}
		else{
			fscanf(file, "%c", &c);
			name[i] = c;
			i++;
		}
	}
	name[i-1] = NULL;
	i=0;
	while(c!=','){
		if(c==','){
			surname[i-1] = NULL;
		}
		else{
			fscanf(file, "%c", &c);
			if(c!=',' && c!=' '){
				surname[i] = c;
				i++;
			}
		}
	}
	surname[i] = NULL;
	fscanf(file, "%d,%s", age, gender);
}

int main(void){
	FILE *file;
	file = fopen("rooms.txt", "r");
	rooms *root;
	root = (rooms*)calloc(1,sizeof(rooms));
	int room_num, capacity, floor;
	fscanf(file, "%d,%d,%d\n", &room_num, &capacity, &floor);
	create_room(root, room_num, capacity, floor);
	rooms *iter;
	iter = (rooms*)calloc(1, sizeof(rooms));
	iter = root;
	while(!feof(file)){
		fscanf(file, "%d,%d,%d\n", &room_num, &capacity, &floor);
		add_room_to_end(iter, room_num, capacity, floor);
		iter = iter->linkp;
	}
	print(root);
	free(iter);
	fclose(file);
	
	file = fopen("customers.txt", "r");
	customers *root2;
	root2 = (customers*)calloc(1, sizeof(customers));
	root2->name = (char*)calloc(12, sizeof(char));
	root2->surname = (char*)calloc(12, sizeof(char));
	root2->gender = (char*)calloc(6, sizeof(char));
	char *name, *surname, *gender;
	int age;
	name = (char*)calloc(12, sizeof(char));
	surname = (char*)calloc(12, sizeof(char));
	gender = (char*)calloc(6, sizeof(char));
	reading_customers_txt(file, name, surname, gender, &age, &room_num);
	create_customers(root2, name, surname, gender, room_num, age);
	customers *iter2;
	iter2 = (customers*)calloc(1,sizeof(customers));
	iter2 = root2;
	while(!feof(file)){
		reading_customers_txt(file, name, surname, gender, &age, &room_num);
		add_customer_to_end(iter2, name, surname, gender, room_num, age);
		iter2 = iter2->link;
	//	printf("%d %s %s %d %s\n", room_num, name, surname, age, gender);
	}
	print2(root2);
	free(iter2);
	fclose(file);
	
}









