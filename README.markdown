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

Merge Sort -> O(n*log(n))
        Average Case:   0.0125277 seconds
        Best Case:      0.00679441 seconds
        Worst Case:     0.00690654 seconds

Heap Sort -> O(n*log(n))
        Average Case:   0.021811 seconds
        Best Case:      0.0172573 seconds
        Worst Case:     0.0169674 seconds

Insertion Sort -> O(n^2)
        Average Case:   2.43668 seconds
        Best Case:      0.000192168 seconds
        Worst Case:     4.84465 seconds

Quick Sort -> O(n^2)
        Average Case:   0.0130386 seconds
        Best Case:      18.6444 seconds
        Worst Case:     11.8423 seconds

Benchmarks ran asynchronously in 30.5285 seconds.
```
