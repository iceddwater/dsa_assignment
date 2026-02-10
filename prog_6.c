//Min and max heap
#include <stdio.h>

// Helper to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Logic to sink a node down to maintain Max-Heap property
void maxHeapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

// Logic to sink a node down to maintain Min-Heap property
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(data) / sizeof(data[0]);

    // Build Max Heap
    int maxData[n];
    for(int i=0; i<n; i++) maxData[i] = data[i]; // Copy original data
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(maxData, n, i);
    }
    printf("Max-Heap array: ");
    printArray(maxData, n);

    // Build Min Heap
    int minData[n];
    for(int i=0; i<n; i++) minData[i] = data[i]; // Copy original data
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(minData, n, i);
    }
    printf("Min-Heap array: ");
    printArray(minData, n);

    return 0;
} 
 
