#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <future>
#include <string>

struct sort_times_t
{
    std::future<double> average_case_seconds_future;
    std::future<double> best_case_seconds_future;
    std::future<double> worst_case_seconds_future;
};

int *create_average_case_array_function(int array[], const int array_length);

int *create_best_case_array_function(int array[], const int array_length);

int *create_worst_case_array_function(int array[], const int array_length);

std::string get_sort_function_name(void sort_function(int array[],
                                                      const int array_length));

void heap_sort(int array[], const int length);

void heapify(int array[], const int heap_size, const int node_index);

void insertion_sort(int array[], const int length);

void merge(int array[], const int left, const int mid, const int right);

void merge_sort(int array[], const int length);

void merge_sort_r(int array[], int const begin, int const end);

int partition(int array[], const int low, const int high);

void print_array(int array[], const int length);

void print_sort_times(const std::string &sort_function_name,
                      sort_times_t *sort_times);

void print_title(const int array_length);

void quick_sort(int array[], const int length);

void quick_sort_r(int array[], const int low, const int high);

double run_sort_function(void sort_function(int array[],
                                            const int array_length),
                         int *create_array_function(int array[],
                                                    const int array_length),
                         const int array_length);

sort_times_t run_sort_function_test_cases(
    void sort_function(int array[], const int array_length),
    const int array_length);

#endif
