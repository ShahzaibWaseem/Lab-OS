# Lab 07: Programming Threads

## Tasks
In order to understand the concept of threads and role of synchronization primitives to ensure safe global variable access you are supposed to Write a program using pthreads, which calculates the sum of elements in a hard-coded integer array in parallel using 4 threads. The program must divide the work between 4 threads which run simultaneously. For simplicity, you can assume that the size of the array is 100. Note that the integer array must be declared as a global data structure.

1. Initially code your solution so that the sum of elements is maintained in a global shared variable.Each thread modifies the same shared variable as it sums up elements from the array. Use a suitable synchronization primitive to ensure safe access to the global variable.
2. Now modify your solution so that it does not require any synchronization primitives. An idea here is that each thread must first find its own local sum first, and later the main () function can use these local sums to determine the global sum for the entire array.

## Question
Q. Which approach do you think would run faster, and why?
Ans. The Unsynchronized version will run faster. In Synchronized Version The Threads will have to wait for other Threads to finish. So they are a bit slower. This trend is visible in the two code outputs above. In the second task it took 0.000527 seconds whereas in the first task (Synchronized Version) it took double the time, i.e. 0.001100 seconds.