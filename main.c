#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include <pthread.h>
#include "functions.h"

#define NUM_THREADS 32

void delay(int milisec)
{
#if defined(_WIN32) || defined(_WIN64)
    Sleep(milisec);
#else
    usleep(milisec * 1000);
#endif
}

pthread_t threads[NUM_THREADS];

void *thread_func(void *arg)
{
    int thread_id = *(int *)arg;
    printf("\n-------------------------\n");

    printf("Thread %d\n", thread_id);
    int a[25] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    int b[25] = {6, 7, 8, 9, 10, 6, 7, 8, 9, 10, 6, 7, 8, 9, 10, 6, 7, 8, 9, 10, 6, 7, 8, 9, 10};
    printf("Sum of arrays is: %d\n", sumArrays(a, b, 25));
    printf("-------------------------\n");
    // delay(1000);
}

int main(int argc, char **argv)
{
    int i, executionTimes = 2, counter = 0;

    for (int j = 0; j < executionTimes; j++)
    {
        for (i = 0; i < NUM_THREADS; i++)
        {
            pthread_create(&threads[i], NULL, thread_func, &i);
        }
        for (i = 0; i < NUM_THREADS; i++)
        {
            pthread_join(threads[i], NULL);
            counter++;
        }

    }

    printf("Execution times: %d\n", counter);

    return 0;
}