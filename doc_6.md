This program demonstrates how to build the min and max heap. 

Building a heap from an unsorted array is done using the Heapify algorithm. Instead of inserting elements one by one (which is slower), we start from the last non-leaf node and work our way up to the root, "sinking" elements into their correct positions.For an array of size n, the last non-leaf node is always at index n/2 - 1.

Program Flow:
 1. The Array-to-Tree Mapping
 Even though we use a simple array, we treat it like a tree.
 i. For any element at index i: Left Child is at 2i + 1.
 ii. Right Child is at 2i + 2
 iii. Parent is at (i-1)/2

Why start at n/2 - 1?
We start at the first node that actually has children and work backward to the root (index 0). Leaf nodes already satisfy the heap property because there's nothing below them to compare.

**The "Heapify" Process**

1. Max-Heap: If a parent is smaller than its children, it "sinks" down, swapping with the largest child.

2. Min-Heap: If a parent is larger than its children, it "sinks" down, swapping with the smallest child.

3. After a swap, we check the new position to make sure the sub-tree below it is still valid.

Time Complexity: O(n)
Space Complexity: O(1)

Output:
Max-Heap array: 13 11 12 5 6 7 
Min-Heap array: 5 6 7 11 12 13 
 
