#include <stdio.h>
#include <stdlib.h>

#ifndef max
    #define max(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
    #define min(a, b) ((a) < (b) ? (a) : (b))
#endif

int BLOCK_SIZE = 256;

int randomInt() {
  return rand() % 200;
}

int** createMatrix(int rows, int cols) {
  int** mat = (int**)malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) mat[i] = (int*)malloc(cols * sizeof(int));
  return mat;
}

int main(int argc, char** argv) {
  int m, n, p, q, c, d, k, x, y, z, sum = 0;
  int MATRIX_N = atoi(argv[1]);

  // m, n => number of rows/columns for First matrix
  m = MATRIX_N;
  n = MATRIX_N;

  // p, q => number of rows/columns for Second matrix
  p = MATRIX_N;
  q = MATRIX_N;

  int** first = createMatrix(m, n);
  int** second = createMatrix(p, q);
  int** multiply = createMatrix(m, q);

  // Populating First matrix
  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      first[c][d] = randomInt();

  if (n != p)
    printf("The multiplication isn't possible.\n");
  else {
    // Initializing results matrix with zeroes
    for (c = 0; c < m; c++)
      for (d = 0; d < q; d++)
        multiply[c][d] = 0;

    // Populating Second matrix
    for (c = 0; c < p; c++)
      for (d = 0; d < q; d++)
        second[c][d] = randomInt();

// J - x
// K = y
// i = c
// j = d
// k = k
    for (x = 0; x < (MATRIX_N); x += BLOCK_SIZE)
      for (y = 0; y < (MATRIX_N); y += BLOCK_SIZE)
          for (c = 0; c < MATRIX_N; c++)
            for (d = x; d < min(x + BLOCK_SIZE, MATRIX_N); d++) {
              for (k = y; k < min(y + BLOCK_SIZE, MATRIX_N); k++) {
                multiply[c][d] += first[c][k] * second[k][d];
              }
            }
  }

  // Prints the resulting matrix (Uncomment)
  // for (c = 0; c < m; c++)
    // for (d = 0; d < q; d++)
      // printf("%d\t", multiply[c][d]);

  printf("Done.");

  return 0;
}
