#include <stdio.h>
#include <stdlib.h>

int randomInt() {
  return rand() % 200;
}
 
int main(int argc, char **argv) {
  int m, n, p, q, c, d, k, sum = 0;
  int first[10][10], second[10][10], multiply[10][10];
 
  // m, n => number of rows/columns for First matrix
  m = atoi(argv[1]);
  n = atoi(argv[1]);

  // p, q => number of rows/columns for Second matrix
  p = atoi(argv[1]);
  q = atoi(argv[1]);
 
  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      first[c][d] = randomInt();
 
  if (n != p)
    printf("The multiplication isn't possible.\n");
  else
  {
    printf("Enter elements of second matrix\n");
 
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
 
    printf("Product of the matrices:\n");
 
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++)
        printf("%d\t", multiply[c][d]);
 
      printf("\n");
    }
  }
 
  return 0;
}
