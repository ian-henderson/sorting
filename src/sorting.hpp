#ifndef SORTING_HPP
#define SORTING_HPP

void heap_sort(int array[], const int length);

void heapify(int array[], const int heap_size, const int node_index);

void insertion_sort(int array[], const int length);

void merge(int array[], const int left, const int mid, const int right);

void merge_sort(int array[], const int length);

void merge_sort_r(int array[], int const begin, int const end);

int partition(int array[], const int low, const int high);

void quick_sort(int array[], const int length);

void quick_sort_r(int array[], const int low, const int high);

#endif
