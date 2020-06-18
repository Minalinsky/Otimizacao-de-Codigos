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
  printf("~ BubbleSort ~ \n");
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
  printf("~ SelectionSort ~ \n");
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

void heapSort(int* array) {
  printf("~ HeapSort ~ \n");
  int n = size;
  int i = n / 2, parent, child, t;
  while(1) {
    if (i > 0) {
        i--;
        t = array[i];
    } else {
        n--;
        if (n <= 0) return;
        t = array[n];
        array[n] = array[0];
    }
    parent = i;
    child = i * 2 + 1;
    while (child < n) {
        if ((child + 1 < n)  &&  (array[child + 1] > array[child]))
            child++;
        if (array[child] > t) {
            array[parent] = array[child];
            parent = child;
            child = parent * 2 + 1;
        } else {
            break;
        }
    }
    array[parent] = t;
  }
}

void quicksort(int* array, int low, int high) {
  int pivot, i, j, aux;
  if (low < high) {
    pivot = low;
    i = low;
    j = high;
    while (i < j) {
      // increment i until you get a number greater than the pivot element
      while (array[i] <= array[pivot] && i <= high) i++;

      // decrement j till you get a number less than the pivot element
      while (array[j] > array[pivot] && j >= low)
        j--;
      // if i < j swap the elements
      if (i < j) {
        aux = array[i];
        array[i] = array[j];
        array[j] = aux;
      }
    }

    // when i >= j, it means the j-th position is the correct position of the pivot element, hence swap the pivot element with the
    // element in the j-th position
    aux = array[j];
    array[j] = array[pivot];
    array[pivot] = aux;

    // Repeat quicksort for the two sub-arrays, one to the left of j and one to the right of j
    quicksort(array, low, j - 1);
    quicksort(array, j + 1, high);
  }
}

int main () {
  int* arr = generateArray();
  printArray(arr);

  // heapSort(arr);
  quicksort(arr, 0, size - 1);
  printArray(arr);
  
}
