#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Function to check prime
int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

// Thread A: sum of first N primes
void* threadA(void* arg) {
    int N = *(int*)arg;
    int count = 0, num = 2, sum = 0;

    while (count < N) {
        if (isPrime(num)) {
            sum += num;
            count++;
        }
        num++;
    }

    printf("Thread A: Sum of first %d prime numbers is %d\n", N, sum);
    return NULL;
}

// Thread B: print every 2 seconds
void* threadB(void* arg) {
    for (int t = 0; t <= 100; t += 2) {
        printf("Thread 1 running\n");
        sleep(2);
    }
    return NULL;
}

// Thread C: print every 3 seconds
void* threadC(void* arg) {
    for (int t = 0; t <= 100; t += 3) {
        printf("Thread 2 running\n");
        sleep(3);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    int N;

    printf("Enter N: ");
    scanf("%d", &N);

    pthread_create(&t1, NULL, threadA, &N);
    pthread_create(&t2, NULL, threadB, NULL);
    pthread_create(&t3, NULL, threadC, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}
