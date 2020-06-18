#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Array Length
#define size 20

int* generateArray() {
  srand(time(NULL));
  static int array[20];
  for (int i = 0; i < size; i++)
    array[i] = rand() % 100 ;

  return array;
}

void printArray (int* array) {
  for(int i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n\n");
}

int bubbleSort(int *array) {
	int aux;

	for (int i = size - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			if (array[j] > array[j + 1]) {
				aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
			}
		}
	}

	return 1;
}

void selectionSort(int* array) { 
  int min, aux;
  for (int i = 0; i < (size - 1); i++) {
     min = i;
     for (int j = (i + 1); j < size; j++) {
       if(array[j] < array[min]) 
         min = j;
     }
     if (array[i] != array[min]) {
       aux = array[i];
       array[i] = array[min];
       array[min] = aux;
     }
  }
}

int main () {
  int* arr = generateArray();
  printArray(arr);

  selection_sort(arr);
  printArray(arr);
  
}
