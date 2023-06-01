# sorting algorithm benchmarks

## requirements
- cmake
- make
- g++

## build
- run `./build.sh`
    - you may need to give executable permissions, eg `chmod +x build.sh`

## run
- run `./build/sorting-algorithm-benchmarks`
    - you can optionally pass in an int that determines how many elements the test arrays will contain, e.g. `./build/sorting-algorithm-benchmarks 500`

## sorting algorithms
- Heap Sort
- Insertion Sort
- Merge Sort
- Quick Sort

## sample output:

```
Sorting Algorithm Benchmarks (array length: 66666)

Heap Sort -> O(n*log(n))
        Average Case:   0.0206543 seconds
        Best Case:      0.0278411 seconds
        Worst Case:     0.0230177 seconds

Insertion Sort -> O(n^2)
        Average Case:   2.45533 seconds
        Best Case:      0.000396033 seconds
        Worst Case:     4.92439 seconds

Merge Sort -> O(n*log(n))
        Average Case:   0.0175542 seconds
        Best Case:      0.0122614 seconds
        Worst Case:     0.0125662 seconds

Quick Sort -> O(n^2)
        Average Case:   0.0159075 seconds
        Best Case:      18.7339 seconds
        Worst Case:     11.6302 seconds

Benchmarks ran asynchronously in 18.7358 seconds.
```
