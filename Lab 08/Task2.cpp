#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define FIRST_ODD_NUM 1
#define FIRST_EVEN_NUM 2
#define MAX 10

sem_t even_sem, odd_sem;

void *print_even_nums(void *param) {
	int even_num_to_print;
	for(even_num_to_print = FIRST_EVEN_NUM; even_num_to_print < MAX;) {
		sem_wait(&even_sem);
		printf("%d ", even_num_to_print);
		even_num_to_print += 2;
		sem_post(&odd_sem);
	}
	pthread_exit(0);
}

void *print_odd_nums(void *param) {
	int odd_num_to_print;
	for(odd_num_to_print = FIRST_ODD_NUM; odd_num_to_print < MAX;) {
		sem_wait(&odd_sem);
		printf("%d ", odd_num_to_print);
		odd_num_to_print += 2;
		sem_post(&even_sem);
	}
	pthread_exit(0);
}

int main(int argc, char *argv[]) {
	// Initializing both the Semophores
	sem_init(&even_sem, 0, 0);
	sem_init(&odd_sem, 0, 1);

	pthread_t even_thread;
	pthread_t odd_thread;
	pthread_create(&even_thread, NULL, print_even_nums, NULL);
	pthread_create(&odd_thread, NULL, print_odd_nums, NULL);
	pthread_join(even_thread, NULL);
	pthread_join(odd_thread, NULL);
	printf("\n");

	// Destorying Semophores
	sem_destroy(&odd_sem);
	sem_destroy(&even_sem);
}