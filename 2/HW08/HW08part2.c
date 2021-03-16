#include <stdio.h>
#include <stdlib.h>

char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current){
  
  char *temp;// = (char *)malloc(100*sizeof(char));
  int temp2;
  
  if(cursor == arr_len - 1){
    
    temp2 = current + arr[cursor+1];
    operations[cursor] = '+';
    if(temp2 == expected_val){
    	return operations;
	}
    
    temp2 = current - arr[cursor+1];
    operations[cursor] = '-';
    if(temp2 == expected_val){
    	return operations;
	}
    
    temp2 = current * arr[cursor+1];
    operations[cursor] = '*';
    if(temp2 == expected_val){
    	return operations;
	}
      
    return NULL;
  }
  
  temp2 = current + arr[cursor+1];
  operations[cursor] = '+';
  temp = find_operations(arr, expected_val, operations, arr_len, cursor + 1, temp2);
  if(temp != NULL){
  	return temp;
  }
  
  temp2 = current - arr[cursor+1];
  operations[cursor] = '-';
  temp = find_operations(arr, expected_val, operations, arr_len, cursor + 1, temp2);
  if(temp != NULL){
  	return temp;
  }
  
  temp2 = current * arr[cursor+1];
  operations[cursor] = '*';
  temp = find_operations(arr, expected_val, operations, arr_len, cursor + 1, temp2);
  if(temp != NULL){
  	return temp;
  }
  
  return NULL;
}

int main(void) {
  int arr[] = {25, 12, 6, 10, 32, 8};
  char op[5] = "     ";
  
  printf("%s\n", find_operations(arr, 44, op, 5, 0, arr[0]));
  return 0;
}
