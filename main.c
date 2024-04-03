#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Dilraj Sooch Assignment 3
/*Starting from an empty project, you must:

Create two arrays of length 20,000 and insert the same random number into each index (i.e. the two arrays should be separate arrays but contain identical values).
Sort the first array using a bubble sort. Print the length of time it took to perform the sort.
Sort the second array using a heap sort. Print the length of time it took to perform the heap sort.
Print the time it took to perform each sort.
Insert a break point at the end of your code and during the presentation show the contents of the two arrays after they have been sorted using the debugger.
Note: This assignment depends on the speed of your computer's processor. If you find 20,000 is taking too long, you may shorten it. If it happens too quickly and you don't see a difference between the two runs, you may increase the length of the array. If you encounter a warning in Visual Studio about the array length, you can ignore it.

For the timing, you can use the following algorithm (or any timing code you wish):

#include <time.h>

…

clock_t startTime = clock();



//Sort happens here



clock_t endTime = clock();

double sortTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
 */

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// heap sort a subtree rooted with node i which is an index in arr[]
void heapify(int arr[], int n, int i) {
    int largest = i; // init largest as root
    int left = 2*i + 1;
    int right = 2*i + 2;

    // if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // if right child is larger than largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // iff largest is not root
    if (largest != i) {
        // swap arr[i] and arr[largest] using temp
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapsort the affected sub-tree
        heapify(arr, n, largest);
    }
}

// printing function for array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    const int size = 20000;
    int arr_bubble[size], arr_heap[size];
    clock_t startTime, endTime;
    double sortTime;

    // Generating random numbers and populating arrays using seed
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int random_num = rand() % 1000; // Random number between 0 and 999
        arr_bubble[i] = random_num; //putting same random number into each index
        arr_heap[i] = random_num;
    }

    //sorting array using bubble sort
    startTime = clock();
    bubbleSort(arr_bubble, size);
    endTime = clock();
    sortTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("Time taken for bubble sort: %lf seconds\n", sortTime);
    printf("Bubble sorted array: ");
    printArray(arr_bubble, size);

    //sorting array using heap sort
    startTime = clock();
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr_heap, size, i);
    for (int i = size - 1; i >= 0; i--) {
        int temp = arr_heap[0];
        arr_heap[0] = arr_heap[i];
        arr_heap[i] = temp;
        heapify(arr_heap, i, 0);
    }
    endTime = clock();
    sortTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("Time taken for heap sort: %lf seconds\n", sortTime);
    printf("Heap sorted array: ");
    printArray(arr_heap, size);



    return 0;
}
