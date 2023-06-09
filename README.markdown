# sorting algorithm benchmarks

## requirements
- cmake
- make
- g++ or clang++

## build
- run `./build.sh`
    - you may need to give executable permissions, eg `chmod +x build.sh`

## run
- run `./build/sorting-algorithm-benchmarks`
    - you can optionally pass in an int that determines how many elements the test arrays will contain, e.g. `./build/sorting-algorithm-benchmarks 500`

## sorting algorithms
- Bubble Sort
- Heap Sort<sup>*</sup>
- Insertion Sort
- Merge Sort<sup>*</sup>
- Quick Sort<sup>*</sup>
- Selection Sort<sup>*</sup>

<sup>*</sup> Optimized to run in linear time when array is already sorted

## sample output:

```
Sorting Algorithm Benchmarks (array length: 50000)

Bubble Sort
        Average Case:   10.0354 seconds
        Best Case:      0.000159829 seconds
        Worst Case:     10.8071 seconds

Heap Sort
        Average Case:   0.0210165 seconds
        Best Case:      0.000162154 seconds
        Worst Case:     0.0170977 seconds

Insertion Sort
        Average Case:   1.39794 seconds
        Best Case:      0.000277225 seconds
        Worst Case:     2.79942 seconds

Merge Sort
        Average Case:   0.0150752 seconds
        Best Case:      0.000150299 seconds
        Worst Case:     0.00987526 seconds

Quick Sort
        Average Case:   0.0124028 seconds
        Best Case:      0.000162998 seconds
        Worst Case:     7.02918 seconds

Selection Sort
        Average Case:   2.51368 seconds
        Best Case:      0.000131708 seconds
        Worst Case:     2.41217 seconds

Benchmarks ran asynchronously in 10.8084 seconds!
```
