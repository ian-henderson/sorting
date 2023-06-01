#include "sorting.hpp"

#include <chrono>
#include <iostream>

int main(int argc, char *argv[])
{
    const int array_length = argc > 1 ? std::atoi(argv[1]) : 66666;

    const auto start = std::chrono::high_resolution_clock::now();

    print_title(array_length);

    sort_times_t heap_sort_times =
        run_sort_function_test_cases(heap_sort, array_length);

    sort_times_t insertion_sort_times =
        run_sort_function_test_cases(insertion_sort, array_length);

    sort_times_t merge_sort_times =
        run_sort_function_test_cases(merge_sort, array_length);

    sort_times_t quick_sort_times =
        run_sort_function_test_cases(quick_sort, array_length);

    print_sort_times("Heap Sort -> O(n*log(n))", &heap_sort_times);

    print_sort_times("Insertion Sort -> O(n^2)", &insertion_sort_times);

    print_sort_times("Merge Sort -> O(n*log(n))", &merge_sort_times);

    print_sort_times("Quick Sort -> O(n^2)", &quick_sort_times);

    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> diff = end - start;

    std::cout << "Benchmarks ran asynchronously in " << diff.count()
              << " seconds.\n";
}
