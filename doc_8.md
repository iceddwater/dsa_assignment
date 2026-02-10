**Sorting**

**Program Flow**
 1. BreakdownRandomization: We use srand(time(0)) and rand() % 1000 which ensures that every time we run the code, we get a fresh set of numbers.
 2. The Switch-Case: Based on the input, the program routes the array to the specific algorithm.
 3. Performance Counters:
 i. Comparisons: Incremented every time we use an if or while to compare two values.
 ii. Swaps: Incremented when values are moved. 
 Note: Merge Sort doesn't "swap"—it copies to a temporary array—so a swap count isn't traditionally applicable there.
 iii. Memory Management: We use malloc because N is decided at runtime which prevents stack overflow for large values of N.




**Output:**
Enter number of elements (N): 4

Before Sorting:
123 893 318 307

Choose Sorting Algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Selection: 2 

After Sorting:
123 307 318 893

--- Performance Stats ---
Comparisons: 6
Swaps/Shifts: 1