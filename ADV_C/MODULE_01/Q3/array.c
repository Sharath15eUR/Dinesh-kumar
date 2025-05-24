#include <stdio.h>

int searchMatrix(int matrix[][100], int n, int key) {
    int row = 0, col = n - 1;

    while (row < n && col >= 0) {
        if (matrix[row][col] == key)
            return 1;  // Key found
        else if (matrix[row][col] > key)
            col--;  // Move left
        else
            row++;  // Move down
    }

    return 0;  // Key not found
}

int main() {
    int matrix[100][100], n, key;

    printf("Enter size of matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter elements (sorted by row and column):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    if (searchMatrix(matrix, n, key))
        printf("Key %d found in matrix.\n", key);
    else
        printf("Key %d not found in matrix.\n", key);

    return 0;
}
