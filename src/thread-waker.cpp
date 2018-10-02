#include <stdio.h>
#include <iostream>
#include <thread>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <mutex>
#include <semaphore.h>
#include <fcntl.h>
using namespace std;

sem_t *semaphore;



int main() {
	unsigned short numThreads = 1;

	semaphore = sem_open("threads", O_CREAT, S_IRWXO | S_IRWXU, 0);
	while(numThreads != 0){
		cout << "Enter the number of threads to wake(0 to exit): ";
		cin >> numThreads;




		for(int i = 0; i < numThreads; i++){
			sem_post(semaphore);
		}

	}
	sem_close(semaphore);

	sem_destroy(semaphore);
	return 0;
}
