#include "utils.hpp"
#include "sorting.hpp"
#include <algorithm> // copy
#include <chrono>    // high_resolution_clock
#include <cstdlib>   // exit, free, malloc
#include <future>    // async, launch::async
#include <iostream>  // cout, endl

double Timer::get_diff()
{
    return m_diff.count();
}

void Timer::start()
{
    m_start = std::chrono::high_resolution_clock::now();
}

void Timer::stop()
{
    m_end = std::chrono::high_resolution_clock::now();
    m_diff = m_end - m_start;
}

TestArrays *create_test_arrays(const int array_length)
{
    TestArrays *test_arrays = (TestArrays *)std::malloc(sizeof(TestArrays));

    test_arrays->average_case_array = (int *)std::malloc(sizeof(int) * array_length);

    test_arrays->best_case_array = (int *)std::malloc(sizeof(int) * array_length);

    test_arrays->worst_case_array = (int *)std::malloc(sizeof(int) * array_length);

    for (int i = 0; i < array_length; i++)
    {
        test_arrays->average_case_array[i] = std::rand();
        test_arrays->best_case_array[i] = i;
        test_arrays->worst_case_array[i] = array_length - i;
    }

    return test_arrays;
}

void delete_test_arrays(TestArrays *test_arrays)
{
    std::free(test_arrays->average_case_array);
    std::free(test_arrays->best_case_array);
    std::free(test_arrays->worst_case_array);
    std::free(test_arrays);
}

void print_array(int array[], const int length)
{
    std::cout << "[ ";

    for (int i = 0; i < length; i++)
    {
        std::cout << array[i];
        if (i < (length - 1))
            std::cout << ", ";
    }

    std::cout << " ]\n";
}

void print_sort_times(SortTimes &sort_times)
{
    std::cout << sort_times.sort_function_name << "\n"
              << "\tAverage Case:\t" << sort_times.average_case_seconds_future.get() << " seconds\n"
              << "\tBest Case:\t" << sort_times.best_case_seconds_future.get() << " seconds\n"
              << "\tWorst Case:\t" << sort_times.worst_case_seconds_future.get() << " seconds\n\n";
}

void print_title(const int array_length)
{
    std::cout << "Sorting Algorithm Benchmarks (array length: " << array_length << ")\n\n";
}

double run_sort_function(const char *sort_function_name, void sort_function(int array[], const int array_length),
                         int test_array[], const int array_length)
{
    int *test_array_copy = (int *)std::malloc(sizeof(int) * array_length);
    if (!test_array_copy)
    {
        std::cout << "Error: system was unable to allocate memory while running " << sort_function_name << ". Exiting."
                  << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::copy(&test_array[0], &test_array[array_length], test_array_copy);
    Timer timer;
    timer.start();
    sort_function(test_array_copy, array_length);
    timer.stop();
    std::free(test_array_copy);

    return timer.get_diff();
}

SortTimes run_sort_function_test_cases(const char *sort_function_name,
                                       void sort_function(int array[], const int array_length), TestArrays *test_arrays,
                                       const int array_length)
{
    SortTimes sort_times{sort_function_name,
                         std::async(std::launch::async, run_sort_function, sort_function_name, sort_function,
                                    test_arrays->average_case_array, array_length),
                         std::async(std::launch::async, run_sort_function, sort_function_name, sort_function,
                                    test_arrays->best_case_array, array_length),
                         std::async(std::launch::async, run_sort_function, sort_function_name, sort_function,
                                    test_arrays->worst_case_array, array_length)};

    return sort_times;
}
