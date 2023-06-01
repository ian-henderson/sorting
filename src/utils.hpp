#ifndef UTILS_HPP
#define UTILS_HPP
#include <chrono>
#include <future>

struct SortTimes
{
    const char *sort_function_name;
    std::future<double> average_case_seconds_future;
    std::future<double> best_case_seconds_future;
    std::future<double> worst_case_seconds_future;
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

void populate_average_case_array(int array[], const int array_length);

void populate_best_case_array(int array[], const int array_length);

void populate_worst_case_array(int array[], const int array_length);

void print_array(int array[], const int length);

void print_sort_times(SortTimes &sort_times);

void print_title(const int array_length);

double run_sort_function(const char *sort_function_name,
                         void sort_function(int array[],
                                            const int array_length),
                         void populate_array(int array[],
                                             const int array_length),
                         const int array_length);

SortTimes run_sort_function_test_cases(
    const char *sort_function_name,
    void sort_function(int array[], const int array_length),
    const int array_length);

#endif
