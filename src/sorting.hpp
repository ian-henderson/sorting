#ifndef SORTING_HPP
#define SORTING_HPP

void bubble_sort(int array[], const int array_length);

void heap_sort(int array[], const int array_length);

void heapify(int array[], const int heap_size, const int node_index);

void insertion_sort(int array[], const int array_length);

bool is_best_case_array(int array[], const int array_length);

void merge(int array[], const int left, const int mid, const int right);

void merge_sort(int array[], const int array_length);

void merge_sort_r(int array[], int const begin, int const end);

int partition(int array[], const int low, const int high);

void quick_sort(int array[], const int array_length);

void quick_sort_r(int array[], const int low, const int high);

void selection_sort(int array[], const int array_length);

#endif
