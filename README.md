# Sorting-Algorithms
This repository contains implementations of various sorting algorithms in C++. The sorting algorithms included are:

- Bubble Sort
- Insertion Sort
- Selection Sort
- Merge Sort
- Heap Sort
- Quick Sort
- Quick Sort with Median of Three pivot selection

These algorithms are fundamental in computer science and are commonly taught in introductory courses.
Each algorithm has been implemented with clear comments and documentation to aid understanding.

## Algorithms

- **Bubble Sort**: Bubble Sort is a simple and inefficient sorting algorithm that repeatedly compares adjacent elements and swaps them if they are in the wrong order.
- It continues this process until the entire list is sorted.

- **Insertion Sort**: Insertion Sort builds the final sorted array one element at a time.
- It takes each element and inserts it into its correct position within the already sorted part of the array.

- **Selection Sort**: Selection Sort divides the array into two parts: the sorted part and the unsorted part.
- It repeatedly selects the smallest (or largest) element from the unsorted part and swaps it with the leftmost element of the unsorted part.

- **Merge Sort**: Merge Sort is an efficient sorting algorithm that follows the divide-and-conquer approach.
- It divides the input array into smaller sub-arrays, sorts them iteratively, and then merges the sorted sub-arrays to produce the final sorted array.

- **Heap Sort**: Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure.
- It builds a max-heap (or min-heap) from the input array and repeatedly extracts the maximum (or minimum) element to obtain a sorted array.

- **Quick Sort**: Quick Sort is a divide-and-conquer sorting algorithm that works by selecting a pivot element and partitioning the array around the pivot.
- It recursively applies the same process to the sub-arrays until the entire array is sorted.

- **Quick Sort with Median of Three**: This variation of Quick Sort improves the pivot selection by using the Median-of-Three method.
- It chooses the pivot as the median of the first, middle, and last elements in the array, which helps to reduce the chances of choosing a bad pivot and improve the algorithm's performance.

## Sources

- Wikipedia: [Sorting Algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
- GeeksforGeeks: [Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)
- Books:
  - "Introduction to Algorithms" by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein
  - "Algorithms" by Robert Sedgewick and Kevin Wayne

Feel free to explore the code and use it as a reference for learning and implementing sorting algorithms in your own projects.


