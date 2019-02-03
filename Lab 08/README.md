# Lab 8: Synchronization

## Tasks
1. Your first task is to compile and run this code on your system. The issue is that we have no control over the order these numbers are printed on the console. For example, one sample run of the program produces:

	`$ ./a.out` 
	**2 4 6 8 1 3 5 7 9**

2. Your second and main task here is to modify the source code and use synchronization primitives available to you (semaphore/mutexes/condition variables) to produce the output in ascending order. For example, now the output should look like:

	`$ ./a.out`
	**1 2 3 4 5 6 7 8 9**