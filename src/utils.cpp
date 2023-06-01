#include "utils.hpp"
#include "sorting.hpp"
#include <chrono>
#include <cstdlib>
#include <future>
#include <iostream>

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

void populate_average_case_array(int array[], const int array_length)
{
    for (int i = 0; i < array_length; i++) array[i] = std::rand();
}

void populate_best_case_array(int array[], const int array_length)
{
    for (int i = 0; i < array_length; i++) array[i] = i;
}

void populate_worst_case_array(int array[], const int array_length)
{
    for (int i = 0; i < array_length; i++) array[i] = array_length - i;
}

void print_array(int array[], const int length)
{
    std::cout << "[ ";

    for (int i = 0; i < length; i++)
    {
        std::cout << array[i];
        if (i < (length - 1)) std::cout << ", ";
    }

    std::cout << " ]\n";
}

void print_sort_times(SortTimes &sort_times)
{
    std::cout << sort_times.sort_function_name << "\n"
              << "\tAverage Case:\t"
              << sort_times.average_case_seconds_future.get() << " seconds\n"
              << "\tBest Case:\t" << sort_times.best_case_seconds_future.get()
              << " seconds\n"
              << "\tWorst Case:\t" << sort_times.worst_case_seconds_future.get()
              << " seconds\n\n";
}

void print_title(const int array_length)
{
    std::cout << "Sorting Algorithm Benchmarks (array length: " << array_length
              << ")\n\n";
}

double run_sort_function(const char *sort_function_name,
                         void sort_function(int array[],
                                            const int array_length),
                         void populate_array(int array[],
                                             const int array_length),
                         const int array_length)
{
    int *array = (int *)std::malloc(sizeof(int) * array_length);
    if (!array)
    {
        std::cout
            << "Error: system was unable to allocate memory while running "
            << sort_function_name << ". Exiting." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    populate_array(array, array_length);
    Timer timer;
    timer.start();
    sort_function(array, array_length);
    timer.stop();
    std::free(array);

    return timer.get_diff();
}

SortTimes run_sort_function_test_cases(
    const char *sort_function_name,
    void sort_function(int array[], const int array_length),
    const int array_length)
{
    SortTimes sort_times{
        sort_function_name,
        std::async(std::launch::async, run_sort_function, sort_function_name,
                   sort_function, populate_average_case_array, array_length),
        std::async(std::launch::async, run_sort_function, sort_function_name,
                   sort_function, populate_best_case_array, array_length),
        std::async(std::launch::async, run_sort_function, sort_function_name,
                   sort_function, populate_worst_case_array, array_length)};

    return sort_times;
}
