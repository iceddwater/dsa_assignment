//sorting

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global counters for stats
long long comparisons = 0;
long long swaps = 0;

void reset_stats() {
    comparisons = 0;
    swaps = 0;
}

// --- Sorting Algorithms ---

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            swaps++;
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            swaps++; // Treating shifts as swaps for reporting
        }
        if (j >= 0) comparisons++; // The check that failed the while loop
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// --- Utility Functions ---

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int N, choice;
    srand(time(0)); // Seed for randomness

    printf("Enter number of elements (N): ");
    scanf("%d", &N);

    int *arr = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) arr[i] = (rand() % 1000) + 1;

    printf("\nBefore Sorting:\n");
    printArray(arr, N);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\nSelection: ");
    scanf("%d", &choice);

    reset_stats();

    switch (choice) {
        case 1: bubbleSort(arr, N); break;
        case 2: selectionSort(arr, N); break;
        case 3: insertionSort(arr, N); break;
        case 4: mergeSort(arr, 0, N - 1); break;
        default: printf("Invalid choice!\n"); return 1;
    }

    printf("\nAfter Sorting:\n");
    printArray(arr, N);

    printf("\n--- Performance Stats ---\n");
    printf("Comparisons: %lld\n", comparisons);
    if (choice != 4) printf("Swaps/Shifts: %lld\n", swaps);
    else printf("Merge Sort uses auxiliary space, not traditional swaps.\n");

    free(arr);
    return 0;
}