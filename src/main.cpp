#include "sorting.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
    // keep default to 16000 until recursive functions are optimized.
    // Windows has a very small default stack.
    const int array_length = argc > 1 ? std::atoi(argv[1]) : 16000;

    print_title(array_length);

    SortTimes sort_times_array[] = {
        run_sort_function_test_cases("Heap Sort", heap_sort, array_length),
        run_sort_function_test_cases("Insertion Sort", insertion_sort,
                                     array_length),
        run_sort_function_test_cases("Merge Sort", merge_sort, array_length),
        run_sort_function_test_cases("Quick Sort", quick_sort, array_length)};

    Timer timer;
    timer.start();

    try
    {
        for (SortTimes &sort_times : sort_times_array)
        {
            sort_times.average_case_seconds_future.wait();
            sort_times.best_case_seconds_future.wait();
            sort_times.worst_case_seconds_future.wait();
        }
    }
    catch (std::future_error &error)
    {
        std::cout << "Error: " << error.code() << " " << error.what()
                  << std::endl;
        std::exit(EXIT_FAILURE);
    }

    timer.stop();

    for (SortTimes &sort_times : sort_times_array) print_sort_times(sort_times);

    std::cout << "Benchmarks ran asynchronously in " << timer.get_diff()
              << " seconds!" << std::endl;
}
