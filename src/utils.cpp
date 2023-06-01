#include "utils.hpp"
#include "sorting.hpp"
#include <chrono>
#include <cstdlib>
#include <future>
#include <iostream>

Timer::Timer() : m_running{false}
{
}

void Timer::start()
{
    m_running = true;
    m_start = std::chrono::high_resolution_clock::now();
}

double Timer::stop()
{
    m_running = false;
    m_end = std::chrono::high_resolution_clock::now();
    m_diff = m_end - m_start;
    return m_diff.count();
}

double Timer::get_diff()
{
    if (m_running)
    {
        std::chrono::time_point<std::chrono::high_resolution_clock> now =
            std::chrono::high_resolution_clock::now();
        return (now - m_start).count();
    }

    return m_diff.count();
}

bool Timer::is_running()
{
    return m_running;
}

const char *get_sort_function_name(void sort_function(int array[],
                                                      const int array_length))
{
    if (&(*sort_function) == &(*heap_sort)) return "Heap Sort";

    if (&(*sort_function) == &(*insertion_sort)) return "Insertion Sort";

    if (&(*sort_function) == &(*merge_sort)) return "Merge Sort";

    if (&(*sort_function) == &(*quick_sort)) return "Quick Sort";

    return "";
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

void print_sort_times(const char *sort_function_name, sort_times_t *sort_times)
{
    try
    {
        sort_times->average_case_seconds_future.wait();
        sort_times->best_case_seconds_future.wait();
        sort_times->worst_case_seconds_future.wait();
    }
    catch (std::future_error &error)
    {
        std::cout << "Error:" << error.code() << "\n\t" << error.what()
                  << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::cout << sort_function_name << "\n"
              << "\tAverage Case:\t"
              << sort_times->average_case_seconds_future.get() << " seconds\n"
              << "\tBest Case:\t" << sort_times->best_case_seconds_future.get()
              << " seconds\n"
              << "\tWorst Case:\t"
              << sort_times->worst_case_seconds_future.get() << " seconds\n\n";
}

void print_title(const int array_length)
{
    std::cout << "Sorting Algorithm Benchmarks (array length: " << array_length
              << ")\n\n";
}

double run_sort_function(void sort_function(int array[],
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
            << get_sort_function_name(sort_function) << ". Exiting."
            << std::endl;
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

sort_times_t run_sort_function_test_cases(
    void sort_function(int array[], const int array_length),
    const int array_length)
{
    sort_times_t sort_times{
        std::async(std::launch::async, run_sort_function, sort_function,
                   populate_average_case_array, array_length),
        std::async(std::launch::async, run_sort_function, sort_function,
                   populate_best_case_array, array_length),
        std::async(std::launch::async, run_sort_function, sort_function,
                   populate_worst_case_array, array_length)};

    return sort_times;
}
