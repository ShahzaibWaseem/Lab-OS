# Lab 02: Locks and Pthreads

## Task 1
Study the lock_init, lock_acquire and lock_release() functions in Pintos' synch.c file. Clearly describe how each of these functions work. Note that this includes explanations of sema_up() and sema_down(), functions that are called within lock_acquire() and lock_release(). Also, identify places in the Pintos codebase where these functions are used. Finally, mention what shared
variables these locks are protecting.

## Task 2
Thread programming in Linux is often done using the POSIX Threads (pthreads) library. Introduce yourself to the library by going through the following tutorial:

http://www.yolinux.com/TUTORIALS/LinuxTutorialPosixThreads.html#SYNCHRONIZATION

Compile and run the sample code on the tutorial related to thread creation, thread joining and mutually exclusive locks (mutexes). In your writeup, explain what the sample code does and how you compiled and ran it.