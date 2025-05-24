#include <stdio.h>

// Function to rearrange array with only pointer arithmetic
void rearrangeEvenOdd(int *arr, int size) {
    int temp[size];
    int *write = temp;

    // First copy even elements
    for (int *read = arr; read < arr + size; read++) {
        if (*read % 2 == 0) {
            *write = *read;
            write++;
        }
    }

    // Then copy odd elements
    for (int *read = arr; read < arr + size; read++) {
        if (*read % 2 != 0) {
            *write = *read;
            write++;
        }
    }

    // Copy back to original array
    for (int i = 0; i < size; i++) {
        *(arr + i) = *(temp + i);
    }
}

int main() {
    int arr[] = {5, 2, 8, 1, 4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    for (int *p = arr; p < arr + size; p++)
        printf("%d ", *p);

    rearrangeEvenOdd(arr, size);

    printf("\nRearranged: ");
    for (int *p = arr; p < arr + size; p++)
        printf("%d ", *p);
        printf("\n");

    return 0;
}
