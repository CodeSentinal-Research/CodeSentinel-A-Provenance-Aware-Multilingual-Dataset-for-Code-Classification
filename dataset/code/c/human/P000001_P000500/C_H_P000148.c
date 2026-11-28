#include <stdio.h>

// Function to check if matrix is symmetric

int isSymmetric(int a[10][10], int rows, int cols) {

  if (rows != cols) // Symmetric only possible for square matrix

    return 0;

  for (int i = 0; i < rows; i++) {

    for (int j = 0; j < cols; j++) {

      if (a[i][j] != a[j][i])

        return 0; // Not symmetric
    }
  }

  return 1; // Symmetric
}

int main() {

  int a[10][10];

  int rows, cols;

  printf("Enter number of rows and columns: ");

  scanf("%d %d", &rows, &cols);

  printf("Enter elements of matrix:\n");

  for (int i = 0; i < rows; i++)

    for (int j = 0; j < cols; j++)

      scanf("%d", &a[i][j]);

  if (isSymmetric(a, rows, cols))

    printf("\nThe matrix is Symmetric.\n");

  else

    printf("\nThe matrix is NOT Symmetric.\n");

  return 0;
}
