#include "sorting.hpp" // heap_sort, insertion_sort, merge_sort, quick_sort
#include "utils.hpp"   // delete_test_arrays, print_title, run_sort_function_test_cases, SortTimes, TestArrays, Timer
#include <cstdlib>     // atoi, exit
#include <future>      // future_error
#include <iostream>    // cout, endl

int main(int argc, char *argv[])
{
    const int array_length = argc > 1 ? std::atoi(argv[1]) : 10000;

    print_title(array_length);

    // These arrays copied in worker threads so that every test uses the same
    // array. This is only useful for the average case "randomized" array.
    TestArrays *test_arrays = create_test_arrays(array_length);

    Timer timer;
    timer.start();

    SortTimes sort_times_array[] = {
        run_sort_function_test_cases("Bubble Sort", bubble_sort, test_arrays, array_length),
        run_sort_function_test_cases("Heap Sort", heap_sort, test_arrays, array_length),
        run_sort_function_test_cases("Insertion Sort", insertion_sort, test_arrays, array_length),
        run_sort_function_test_cases("Merge Sort", merge_sort, test_arrays, array_length),
        run_sort_function_test_cases("Quick Sort", quick_sort, test_arrays, array_length),
        run_sort_function_test_cases("Selection Sort", selection_sort, test_arrays, array_length)};

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
        std::cout << "Error: " << error.code() << " " << error.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }

    timer.stop();

    delete_test_arrays(test_arrays);

    for (SortTimes &sort_times : sort_times_array)
        print_sort_times(sort_times);

    std::cout << "Benchmarks ran asynchronously in " << timer.get_diff() << " seconds!" << std::endl;
}
