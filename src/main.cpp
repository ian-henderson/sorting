#include "sorting.hpp"
#include "utils.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    // keep default to 16000 until recursive functions are optimized.
    // Windows has a very small stack.
    const int array_length = argc > 1 ? std::atoi(argv[1]) : 16000;

    print_title(array_length);

    Timer timer;
    timer.start();

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

    timer.stop();

    std::cout << "Benchmarks ran asynchronously in " << timer.get_diff()
              << " seconds.\n";
}
