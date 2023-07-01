#include <iostream>
#include <vector>
#include <algorithm>


// Function to swap two elements
template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

/**
 * Partition the array using the Median-of-Three pivot selection.
 *
 * This function takes an input array and partitions it into two parts such that all elements
 * less than or equal to the pivot are on the left side of the pivot, and all elements greater
 * than the pivot are on the right side of the pivot.
 *
 * The Median-of-Three pivot selection is used to find the pivot. It takes the elements at the
 * low, mid, and high indices and sorts them in ascending order, choosing the middle element as
 * the pivot. This approach helps to reduce the chances of worst-case behavior in QuickSort
 * and improves the algorithm's performance on partially sorted arrays.
 *
 * @tparam T The type of elements in the array.
 * @param arr The input vector that needs to be partitioned.
 * @param low The starting index of the subarray to partition.
 * @param high The ending index of the subarray to partition.
 * @return The index of the pivot element after partitioning.
 */
template<typename T>
int partition_Median_Of_Three(std::vector<T>& arr, int low, int high) {
    // Median-of-three pivot selection
    // Find the index of the middle element
    int mid = low + (high - low) / 2;

    // Sort the low, middle, and high elements of the partition
    if (arr[high] < arr[low]) {
        std::swap(arr[low], arr[high]);
    }
    if (arr[mid] < arr[low]) {
        std::swap(arr[low], arr[mid]);
    }
    if (arr[high] < arr[mid]) {
        std::swap(arr[mid], arr[high]);
    }

    // Hoare partition scheme
    // Choose the pivot as the middle element after sorting
    T pivot = arr[mid];

    // Initialize two pointers to partition the array
    int i = low - 1, j = high + 1;
    while (true) {
        // Move the left pointer to the right until it points to an element
        // that is greater than or equal to the pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Move the right pointer to the left until it points to an element
        // that is less than or equal to the pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // If the pointers have crossed, the partition is complete
        if (i >= j) {
            return j;
        }

        // Otherwise, swap the elements at the two pointers and continue
        std::swap(arr[i], arr[j]);
    }
}

/**
 * Implement QuickSort using Median-of-Three pivot selection.
 *
 * QuickSort is an efficient, comparison-based sorting algorithm that follows the
 * divide-and-conquer approach. It divides the input array into smaller subarrays,
 * sorts them recursively, and then combines them to produce the final sorted array.
 *
 * The Median-of-Three pivot selection is used here for better performance. It selects
 * the pivot as the median of three elements (low, mid, high) to reduce the chances of
 * worst-case behavior in QuickSort. The algorithm sorts the elements in-place.
 *
 * @tparam T The type of elements in the array.
 * @param arr The input vector that needs to be sorted.
 * @param low The starting index of the subarray to be sorted.
 * @param high The ending index of the subarray to be sorted.
 */
template<typename T>
void quickSort_Median_Of_Three(std::vector<T>& arr, int low, int high) {
    // Recursively sort the array using the Hoare partition scheme and
    // median-of-three pivot selection
    if (low < high) {
        int p = partition_Median_Of_Three(arr, low, high);
        quickSort_Median_Of_Three(arr, low, p);
        quickSort_Median_Of_Three(arr, p + 1, high);
    }
}



/**
 * Partition the array and return the pivot index.
 *
 * @param arr The vector to be partitioned.
 * @param low The starting index of the partition.
 * @param high The ending index of the partition.
 * @return The index of the pivot element after partitioning.
 */
template <typename T>
int partition(std::vector<T>& arr, int low, int high)
{
    T pivot = arr[high]; // Choose the last element as the pivot
    int smallerElementIndex = low - 1; // Index of the smaller element

    for (std::size_t currentElementIndex = low; currentElementIndex < high; ++currentElementIndex)
    {
        // If the current element is smaller than or equal to the pivot
        if (arr[currentElementIndex] <= pivot)
        {
            ++smallerElementIndex;
            swap(arr[smallerElementIndex], arr[currentElementIndex]); // Swap arr[smallerElementIndex] and arr[currentElementIndex]
        }
    }

    swap(arr[smallerElementIndex + 1], arr[high]); // Swap the pivot element with the element at (smallerElementIndex + 1)
    return (smallerElementIndex + 1); // Return the pivot index
}

/**
 * Implement QuickSort algorithm to sort the array.
 *
 * @param arr The vector to be sorted.
 * @param low The starting index of the subarray to be sorted.
 * @param high The ending index of the subarray to be sorted.
 */
template <typename T>
void quickSort(std::vector<T>& arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high); // Partition the array

        // Recursively call quickSort for the two sub-arrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}



// Function to print the elements of the array
template <typename T>
void printArray(const std::vector<T>& arr)
{
    for (const T& element : arr)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


/**
 * Merge Sort:
 * Merge sort is an efficient sorting algorithm that follows the divide-and-conquer approach.
 * It divides the input array into smaller sub-arrays, sorts them iteratively,
 * and then merges the sorted sub-arrays to produce the final sorted array.
 */

/**
 * Merge two sorted subarrays.
 *
 * @param container The vector to be sorted.
 * @param left The starting index of the first subarray.
 * @param mid The ending index of the first subarray and the starting index of the second subarray.
 * @param right The ending index of the second subarray.
 */
template <typename T>
void merge(std::vector<T>& container, std::size_t left, std::size_t mid, std::size_t right) {

    // Create temporary container of size 'container'
    std::size_t containerSize = container.size();
    std::vector<T> help_container(containerSize);

    // Merge the elements from the two subarrays
    std::size_t i = left;
    std::size_t j = mid + 1;
    std::size_t k = left;

    while (i <= mid && j <= right) {
        if (container[i] <= container[j]) {
            help_container[k] = container[i];
            i++;
        } else {
            help_container[k] = container[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements from the left subarray, if any
    while (i <= mid) {
        help_container[k] = container[i];
        i++;
        k++;
    }

    // Copy the remaining elements from the right subarray, if any
    while (j <= right) {
        help_container[k] = container[j];
        j++;
        k++;
    }

    // Copy the merged elements back to the original container
    for (std::size_t pos = left; pos <= right; ++pos) {
        container[pos] = help_container[pos];
    }
}

/**
 * Iterative implementation of merge sort.
 *
 * @param container The vector to be sorted.
 */
template <typename T>
void mergeSort(std::vector<T>& container) {
    std::size_t containerSize = container.size();

    // Perform merge sort for subarray sizes of 1, 2, 4, 8, ...
    for (std::size_t currSize = 1; currSize <= containerSize - 1; currSize = 2 * currSize) {
        for (std::size_t leftStart = 0; leftStart <= containerSize - currSize; leftStart += 2 * currSize) {
            std::size_t mid = std::min(leftStart + currSize - 1, containerSize - 1);
            std::size_t rightEnd = std::min(leftStart + 2 * currSize - 1, containerSize - 1);

            // Merge the sub-arrays from leftStart to mid and mid+1 to rightEnd
            merge(container, leftStart, mid, rightEnd);
        }
    }
}

/**
 * Sorts the given array using the Heap Sort algorithm.
 *
 * Heap Sort is an in-place comparison-based sorting algorithm that works by dividing the input into a sorted and an unsorted region.
 * It first builds a max heap from the array and then repeatedly extracts the maximum element from the heap, swapping it with the last unsorted element,
 * and decreasing the size of the heap. This process is repeated until the array is sorted.
 *
 * @tparam T       The type of elements in the array.
 * @param arr      The array to be sorted.
 */

// Function to maintain the max heap property for a given node
template <typename T>
void maxHeapify(std::vector<T>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Function to perform heap sort on the given array
template <typename T>
void heapSort(std::vector<T>& arr) {
    int n = arr.size();

    // Build max heap by calling maxHeapify on non-leaf nodes
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extract elements from the heap in sorted order
    for (int i = n - 1; i > 0; i--) {
        // Swap the root (maximum element) with the last element
        swap(arr[0], arr[i]);

        // Reduce the heap size and maintain the max heap property
        maxHeapify(arr, i, 0);
    }
}
/**

    @brief Sorts the elements in the range [first, last) using the heap sort algorithm.
    This function uses the C++ standard library functions std::make_heap and std::sort_heap
    to build a max heap from the range of elements and then sort them in ascending order using the heap.

    @tparam RandomIt The type of the iterators representing the range.
    @param first An iterator pointing to the first element of the range.
    @param last An iterator pointing one past the last element of the range.
*/
template <typename RandomIt>
void heapSort(RandomIt first, RandomIt last) {
    std::make_heap(first, last); // Build a max heap from the range of elements
    std::sort_heap(first, last); // Sort the elements in ascending order using the heap
}

/**
 * Bubble Sort:
 * Bubble Sort is a simple and inefficient sorting algorithm.
 * It repeatedly compares adjacent elements and swaps them if they are in the wrong order.
 * This process is repeated until the entire list is sorted.
 * Although it is not the most efficient sorting algorithm, it is easy to understand and implement.
 *
 * In the implementation below, I have added an improvement that allows the algorithm to break out of the loop
 * if no swaps are made during a pass. This improvement helps to optimize the algorithm by terminating early
 * when the data is already sorted, reducing unnecessary iterations.
 */

/**
 * Perform bubble sort on a vector.
 *
 * @param arr The vector to be sorted.
 */
template <typename T>
void bubbleSort(std::vector<T>& arr) {
    bool flag;
    for (std::size_t i = 0; i < arr.size() - 1; ++i) {
        flag = false;
        for (std::size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag) { // Improvement: break if data is already sorted.
            break;
        }
    }
}

/**
 * Insertion Sort:
 * Insertion Sort builds the final sorted array one element at a time.
 * It takes each element and inserts it into its correct position within the already sorted part of the array.
 */

/**
 * Perform insertion sort on a vector.
 *
 * @param arr The vector to be sorted.
 */
template<typename T>
void insertionSort(std::vector<T>& arr) {
    for (std::size_t i = 1; i < arr.size(); ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

/**
 * Selection Sort:
 * Selection Sort divides the array into two parts: the sorted part and the unsorted part.
 * It repeatedly selects the smallest (or largest) element from the unsorted part and swaps it
 * with the leftmost element of the unsorted part. Selection sort is not adaptive nor is it stable.
 */

/**
 * Perform selection sort on a vector.
 *
 * @param arr The vector to be sorted.
 */
template<typename T>
void selectionSort(std::vector<T>& arr) {
    for (std::size_t i = 0; i < arr.size() - 1; ++i) {
        int minIndex = i;
        // Find the index of the smallest element in the unsorted part
        for (std::size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the smallest element with the element at position i
        std::swap(arr[i], arr[minIndex]);
    }
}


int main() {
    std::vector<int> unsorted = {5, 2, 9, 1, 7, 0, 1, 2, 3, 1, -2};
    std::vector<std::string> names = {"Mona", "Aman", "Hamed", "Adam", "Benjamin", "Karim", "Maryam"};

    // Test BubbleSort
    std::vector<int> arr1 = unsorted;
    bubbleSort(arr1);
    std::cout << "\nBubbleSort: \n";
    printArray(arr1);

    // Test InsertionSort
    std::vector<int> arr2 = unsorted;
    insertionSort(arr2);
    std::cout << "\nInsertionSort: \n";
    printArray(arr2);

    // Test SelectionSort
    std::vector<int> arr3 = unsorted;
    selectionSort(arr3);
    std::cout << "\nSelectionSort: \n";
    printArray(arr3);

    // Test MergeSort
    std::vector<int> arr4 = unsorted;
    mergeSort(arr4);
    std::cout << "\nMergeSort: \n";
    printArray(arr4);

    // Test HeapSort
    std::vector<int> arr5 = unsorted;
    heapSort(arr5);
    std::cout << "\nHeapSort: \n";
    printArray(arr5);

    // Test HeapSort build in functions
    // Function uses the C++ standard library functions std::make_heap and std::sort_heap
    heapSort(names.begin(), names.end());
    std::cout << "\nHeapSort STL std::make_heap and std::sort_heap: \n";
    printArray(names);
    // Test QuickSort
    std::vector<int> arr6 = unsorted;
    quickSort(arr6, 0, arr6.size() - 1);
    std::cout << "\nQuickSort: \n";
    printArray(arr6);

    // Test QuickSort Median of Three
    std::vector<int> arr7 = unsorted;
    quickSort_Median_Of_Three(arr7, 0, arr7.size() - 1);
    std::cout << "\nQuickSort Median of Three: \n";
    printArray(arr7);

    return 0;
}
