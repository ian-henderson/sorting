#include "sorting.hpp"
#include "utils.hpp"
#include <utility> // std::swap

// https://en.wikipedia.org/wiki/Heapsort
// Worst-case performance: O(n*log(n))
// Best-case performance:  O(n*log(n)) (distinct keys) or O(n) (equal keys)
// Average performance:    O(n*log(n))
// Worst-case complexity:  O(n) total O(1) auxillary
void heap_sort(int array[], const int heap_size)
{
    // build heap (rearrange array)
    for (int root = heap_size / 2 - 1; root >= 0; root--)
        heapify(array, heap_size, root);

    // one by one, extract the element from the heap
    for (int i = heap_size - 1; i > 0; i--)
    {
        // move current root to end
        std::swap(array[0], array[i]);

        // call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

void heapify(int array[], const int heap_size, const int root)
{
    const int left = 2 * root + 1;
    const int right = 2 * root + 2;
    int largest = root;

    // if left child is larger than root
    if (left < heap_size && array[left] > array[largest]) largest = left;

    // if right child is larger than largest so far
    if (right < heap_size && array[right] > array[largest]) largest = right;

    // if largest is not root
    if (largest != root)
    {
        std::swap(array[root], array[largest]);

        // recursively heapify the affected sub-tree
        heapify(array, heap_size, largest);
    }
}

// https://en.wikipedia.org/wiki/Insertion_sort
// Worst case:                  O(n^2) comparisons and swaps
// Best case:                   O(n) comparisons and O(1) swaps
// Average performance:         O(n^2) comparisons and swaps
// Worst-case space complexity: O(n) total, O(1) auxillary
void insertion_sort(int array[], const int length)
{
    for (int i = 1; i < length; i++)
    {
        const int key = array[i];
        int j = i;

        while (j > 0 && array[j - 1] > key)
        {
            array[j] = array[j - 1];
            j--;
        }

        array[j] = key;
    }
}

void merge(int array[], const int left, const int mid, const int right)
{
    const int sub_array_one = mid - left + 1;
    const int sub_array_two = right - mid;

    int *left_array = new int[sub_array_one];
    int *right_array = new int[sub_array_two];

    // copy data to temp arrays
    for (int i = 0; i < sub_array_one; i++) left_array[i] = array[left + i];

    for (int i = 0; i < sub_array_two; i++) right_array[i] = array[mid + 1 + i];

    int index_of_subarray_one = 0;
    int index_of_subarray_two = 0;
    int index_of_merged_array = left;

    // merge the temp arrays back into array[left..right]
    while (index_of_subarray_one < sub_array_one &&
           index_of_subarray_two < sub_array_two)
    {
        if (left_array[index_of_subarray_one] <=
            right_array[index_of_subarray_two])
        {
            array[index_of_merged_array] = left_array[index_of_subarray_one];
            index_of_subarray_one++;
        }
        else
        {
            array[index_of_merged_array] = right_array[index_of_subarray_two];
            index_of_subarray_two++;
        }

        index_of_merged_array++;
    }

    // copy the remaining elements of left[] if there are any
    while (index_of_subarray_one < sub_array_one)
    {
        array[index_of_merged_array] = left_array[index_of_subarray_one];
        index_of_subarray_one++;
        index_of_merged_array++;
    }

    // copy the remaining elements of right[] if there are any
    while (index_of_subarray_two < sub_array_two)
    {
        array[index_of_merged_array] = right_array[index_of_subarray_two];
        index_of_subarray_two++;
        index_of_merged_array++;
    }

    delete[] left_array;
    delete[] right_array;
}

// https://en.wikipedia.org/wiki/Merge_sort
// Worst-case performance:      O(n*log(n))
// Best-case performance:       Omega(n*log(n))
// Average performance:         Theta(n*log(n))
// Worst-case space complexity: O(n) total with O(n) auxillary, O(1) auxillary
//                                  with linked lists
void merge_sort(int array[], const int length)
{
    merge_sort_r(array, 0, length - 1);
}

void merge_sort_r(int array[], const int begin, const int end)
{
    if (begin >= end) return;

    const int mid = begin + (end - begin) / 2;
    merge_sort_r(array, begin, mid);
    merge_sort_r(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// this function takes the last element as pivot, places the pivot element at
// its correct position in sorted array, and places all smaller to left of
// pivot and all greater elements to the right of pivot.
int partition(int array[], const int low, const int high)
{
    const int pivot = array[high];

    // index of smaller element and indicates the right position of pivot
    // found so far
    int i = low - 1;

    for (int j = low; j <= high; j++)
    {
        // if current element is smaller than the pivot
        if (array[j] < pivot)
        {
            i++;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[high]);

    return i + 1;
}

// https://en.wikipedia.org/wiki/Quicksort
// Worst-case performance:      O(n^2)
// Best-case performance:       O(n*log(n)) (simple partition),
//                                  O(n) (three-way partition and equal keys)
// Average performance:         O(n*log(n))
// Worst-case Space Complexity: O(n) auxillary (naive)
//                              O(log(n)) auxillary (Hoare 1962)
void quick_sort(int array[], const int length)
{
    quick_sort_r(array, 0, length - 1);
}

void quick_sort_r(int array[], const int low, const int high)
{
    if (low < high)
    {
        const int partition_index = partition(array, low, high);
        quick_sort_r(array, low, partition_index - 1);
        quick_sort_r(array, partition_index + 1, high);
    }
}
