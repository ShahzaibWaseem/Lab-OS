#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>
#include <pthread.h>
#include <time.h>

int s = 0;
int ga[100];

void *method1(void *args){
	for(int i = 0; i <= 25; i++)
		s += ga[i];
	printf("Sum No 1: %d\n", s);
}
void *method2(void *args){
	for(int i = 26; i <= 50; i++)
		s += ga[i];
	printf("Sum No 2: %d\n", s);
}
void *method3(void *args){
	for(int i = 51; i <= 75; i++)
		s += ga[i];
	printf("Sum No 3: %d\n", s);
}
void *method4(void *args){
	for(int i = 76; i <= 100; i++)
		s += ga[i];
	printf("Sum No 4: %d\n", s);
}

int main() {
	clock_t timer;
	int _local_sum = 0;
	srand(time(NULL));
	for(int i = 0; i < 100; i++){
		ga[i] = rand() % 10;
		_local_sum += ga[i];
	}
	pthread_t _th1; pthread_t _th3;
	pthread_t _th2; pthread_t _th4;
	timer = clock();
	pthread_create(&_th1, NULL, method1, (void *)&_th1);
	pthread_create(&_th2, NULL, method2, (void *)&_th2);
	pthread_create(&_th3, NULL, method3, (void *)&_th3);
	pthread_create(&_th4, NULL, method4, (void *)&_th4);
	timer = clock() - timer;

	double time_taken = ((double)timer)/CLOCKS_PER_SEC; // in seconds
	printf("\nTotal time Taken: %f secs\n", time_taken);
	pthread_exit(NULL);
	return 0;
}