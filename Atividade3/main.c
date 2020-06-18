#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Array Length
#define size 20

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
}

int main () {
  int* arr = generateArray();
  printArray(arr);
  
}
