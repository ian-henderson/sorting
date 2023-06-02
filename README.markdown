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
- Heap Sort<sup>*</sup>
- Insertion Sort
- Merge Sort<sup>*</sup>
- Quick Sort<sup>*</sup>
- Selection Sort<sup>*</sup>

<sup>*</sup> Optimized to run in linear time when array is already sorted

## sample output:

```
Sorting Algorithm Benchmarks (array length: 100000)

Heap Sort
        Average Case:   0.0539358 seconds
        Best Case:      0.00041238 seconds
        Worst Case:     0.0439888 seconds

Insertion Sort
        Average Case:   6.64866 seconds
        Best Case:      0.000598618 seconds
        Worst Case:     13.3408 seconds

Merge Sort
        Average Case:   0.0419816 seconds
        Best Case:      0.000513726 seconds
        Worst Case:     0.0282265 seconds

Quick Sort
        Average Case:   0.0364708 seconds
        Best Case:      0.000489395 seconds
        Worst Case:     29.1918 seconds

Selection Sort
        Average Case:   12.0801 seconds
        Best Case:      0.000482336 seconds
        Worst Case:     11.6385 seconds

Benchmarks ran asynchronously in 29.1936 seconds!
```
