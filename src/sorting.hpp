#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

struct sort_times_t
{
    double average_case_seconds;
    double best_case_seconds;
    double worst_case_seconds;
};

std::string get_sort_function_name(void sort_function(int array[], const int array_length));

void heap_sort(int array[], const int length);

void heapify(int array[], const int heap_size, const int node_index);

void insertion_sort(int array[], const int length);

void merge(int array[], const int left, const int mid, const int right);

void merge_sort(int array[], const int length);

void merge_sort_r(int array[], int const begin, int const end);

int partition(int array[], const int low, const int high);

void print_array(int array[], const int length);

void print_sort_times(const std::string &sort_function_name, sort_times_t sort_times);

void print_title(const int array_length);

void quick_sort(int array[], const int length);

void quick_sort_r(int array[], const int low, const int high);

double run_sort_function(void sort_function(int[], const int), int array[], const int length);

sort_times_t run_sort_function_test_cases(void sort_function(int array[], const int array_length),
                                          const int array_length);

#endif
