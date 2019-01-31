#include <stdio.h>
#include <pthread.h>
#include <cstdlib>
#include <time.h>

#define array_size 100
#define threads_c 4

float ga[array_size];
int global_index = 0;
int sum = 0;
pthread_mutex_t _sum_mutex;

void *slave(void *argv){
	int *tid = (int *) argv;
	int li, ls = 0;
	do{
		pthread_mutex_lock(&_sum_mutex);
		li = global_index;
		global_index++;
		pthread_mutex_unlock(&_sum_mutex);
		if (li <array_size)
			ls += *(ga + li);
	}while(li <array_size);
	pthread_mutex_lock(&_sum_mutex);
	sum += ls;
	printf("Working of Thread # %d at Sum %d\n", *tid, sum);
	pthread_mutex_unlock(&_sum_mutex);
	return 0;
}

int main(){
	clock_t timer;
	int ls_main_ = 0;
	srand(time(NULL));
	pthread_t threadArr[threads_c]; // creating 4 threads.
	pthread_mutex_init(&_sum_mutex, NULL);
	for (int i = 0; i <array_size; i++){
		ga[i] = rand() % 10;
		ls_main_ += ga[i];
	}
	timer = clock();
	for (int i = 0; i < threads_c; i++)
		pthread_create(&threadArr[i], NULL, slave, (void *)&threadArr[i]);
	for (int i = 0; i < threads_c; i++)
		pthread_join(threadArr[i], NULL);
	timer = clock() - timer;
	double timer_taken = ((double)timer)/CLOCKS_PER_SEC; // in seconds
	printf("The Global Sum: %d\n", sum);
	printf("The Local Sum: %d\n", ls_main_);
	printf("Total time: %f secs\n", timer_taken);
	pthread_mutex_destroy(&_sum_mutex);
	pthread_exit (NULL);
	return 0;
}