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
Sorting Algorithm Benchmarks (array length: 10000)

Bubble Sort
        Average Case:   0.273266 seconds
        Best Case:      2.0377e-05 seconds
        Worst Case:     0.232845 seconds

Heap Sort
        Average Case:   0.00267411 seconds
        Best Case:      3.093e-05 seconds
        Worst Case:     0.00211626 seconds

Insertion Sort
        Average Case:   0.0581824 seconds
        Best Case:      5.0297e-05 seconds
        Worst Case:     0.111723 seconds

Merge Sort
        Average Case:   0.00510136 seconds
        Best Case:      3.8686e-05 seconds
        Worst Case:     0.00413113 seconds

Quick Sort
        Average Case:   0.00155681 seconds
        Best Case:      4.5165e-05 seconds
        Worst Case:     0.157562 seconds

Selection Sort
        Average Case:   0.0862188 seconds
        Best Case:      2.2451e-05 seconds
        Worst Case:     0.0894028 seconds

Benchmarks ran asynchronously in 0.27299 seconds!
```
