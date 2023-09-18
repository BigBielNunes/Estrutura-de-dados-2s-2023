#include "bubble_sort.h"

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(char **arr, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
