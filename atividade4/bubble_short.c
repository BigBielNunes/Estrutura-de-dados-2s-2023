#include "bubble_sort.h"

void bubble_sort(int arr[], int n) {
    int temp;
    int swapped;

    do {
        swapped = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                // Troca os elementos arr[i-1] e arr[i]
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}
