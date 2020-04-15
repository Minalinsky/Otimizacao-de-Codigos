#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  // Reding the matrix size
  int matrixSize = atoi(argv[1]);
  for(int i = 1; i <= matrixSize; i++) {
    for (int j = 1; j <= matrixSize; j += 5) {
      printf("i: %d, j: %d\n", i, j);
      printf("i: %d, j: %d\n", i, j + 1);
      printf("i: %d, j: %d\n", i, j + 2);
      printf("i: %d, j: %d\n", i, j + 3);
      printf("i: %d, j: %d\n", i, j + 4);
    }
  }
}
