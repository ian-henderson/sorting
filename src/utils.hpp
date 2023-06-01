#ifndef UTILS_HPP
#define UTILS_HPP
#include <chrono>
#include <future>

struct sort_times_t
{
    std::future<double> average_case_seconds_future;
    std::future<double> best_case_seconds_future;
    std::future<double> worst_case_seconds_future;
};

class Timer
{
  public:
    Timer();
    double get_diff();
    bool is_running();
    void start();
    double stop();

  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_end;
    std::chrono::duration<double> m_diff;
    bool m_running;
};

const char *get_sort_function_name(void sort_function(int array[],
                                                      const int array_length));

void populate_average_case_array(int array[], const int array_length);

void populate_best_case_array(int array[], const int array_length);

void populate_worst_case_array(int array[], const int array_length);

void print_array(int array[], const int length);

void print_sort_times(const char *sort_function_name, sort_times_t *sort_times);

void print_title(const int array_length);

double run_sort_function(void sort_function(int array[],
                                            const int array_length),
                         void populate_array(int array[],
                                             const int array_length),
                         const int array_length);

sort_times_t run_sort_function_test_cases(
    void sort_function(int array[], const int array_length),
    const int array_length);

#endif
