#include <stdio.h>
#include <stdlib.h>

int randomInt() {
  return rand() % 200;
}

int** createMatrix(int rows, int cols) {
  int **mat = (int **)malloc(rows * sizeof(int*));
  for(int i = 0; i < rows; i++) mat[i] = (int *)malloc(cols * sizeof(int));
  return mat;
}
 
int main(int argc, char **argv) {
  int m, n, p, q, c, d, k, sum = 0;
 
  // m, n => number of rows/columns for First matrix
  m = atoi(argv[1]);
  n = atoi(argv[1]);

  // p, q => number of rows/columns for Second matrix
  p = atoi(argv[1]);
  q = atoi(argv[1]);
 
  int** first = createMatrix(m, n);
  int** second = createMatrix(p, q);
  int** multiply = createMatrix(m, q);

  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      first[c][d] = randomInt();
 
  if (n != p)
    printf("The multiplication isn't possible.\n");
  else
  {
    for (c = 0; c < p; c++)
      for (d = 0; d < q; d++)
        second[c][d] = randomInt();
 
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++) {
        for (k = 0; k < p; k++) {
          sum = sum + first[c][k]*second[k][d];
        }
 
        multiply[c][d] = sum;
        sum = 0;
      }
    }
 
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++)
        printf("%d\t", multiply[c][d]);
 
      printf("\n");
    }
  }
 
  return 0;
}
