#ifndef UTILS_HPP
#define UTILS_HPP
#include <chrono> // duration, high_resolution_clock, time_point
#include <future> // future

struct SortTimes
{
    const char *sort_function_name;
    std::future<double> average_case_seconds_future;
    std::future<double> best_case_seconds_future;
    std::future<double> worst_case_seconds_future;
};

struct TestArrays
{
    int *average_case_array;
    int *best_case_array;
    int *worst_case_array;
};

class Timer
{
  public:
    double get_diff();
    void start();
    void stop();

  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_end;
    std::chrono::duration<double> m_diff;
};

TestArrays *create_test_arrays(const int array_length);

void delete_test_arrays(TestArrays *test_arrays);

void print_array(int array[], const int length);

void print_sort_times(SortTimes &sort_times);

void print_title(const int array_length);

double run_sort_function(const char *sort_function_name,
                         void sort_function(int array[],
                                            const int array_length),
                         int *test_array, const int array_length);

SortTimes run_sort_function_test_cases(
    const char *sort_function_name,
    void sort_function(int array[], const int array_length),
    TestArrays *test_arrays, const int array_length);

#endif
