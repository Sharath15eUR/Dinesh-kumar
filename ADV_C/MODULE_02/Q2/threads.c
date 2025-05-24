#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

// Signal handler to catch SIGINT
void handle_sigint(int sig) {
    printf("\nSIGINT caught. Preventing termination. Use kill -9 to force stop.\n");
}

// Prime check function
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

// Thread A logic - returns sum of N primes
void sum_primes(int N) {
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    int count = 0, num = 2, sum = 0;
    while (count < N) {
        if (isPrime(num)) {
            sum += num;
            count++;
        }
        num++;
    }

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + 
                        (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Thread A: Sum = %d | Time: %.3f sec\n", sum, time_taken);
}

// Thread B logic
void* threadB_func(void* arg) {
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    for (int t = 0; t <= 100; t += 2) {
        printf("Thread 1 running\n");
        sleep(2);
    }

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + 
                        (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Thread B completed in %.3f sec\n", time_taken);
    return NULL;
}

// Thread C logic
void* threadC_func(void* arg) {
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    for (int t = 0; t <= 100; t += 3) {
        printf("Thread 2 running\n");
        sleep(3);
    }

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + 
                        (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Thread C completed in %.3f sec\n", time_taken);
    return NULL;
}

// Wrapper for threadA
void* threadA_func(void* arg) {
    int N = *(int*)arg;
    sum_primes(N);
    return NULL;
}

int main() {
    signal(SIGINT, handle_sigint);  // Register signal handler

    pthread_t t1, t2, t3;
    int N;

    printf("Enter N: ");
    scanf("%d", &N);

    pthread_create(&t1, NULL, threadA_func, &N);
    pthread_create(&t2, NULL, threadB_func, NULL);
    pthread_create(&t3, NULL, threadC_func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}
