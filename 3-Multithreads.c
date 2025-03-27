#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

typedef struct {
    int *array, start, end;
    long sum;
} ThreadData;

void *compute_sum(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    data->sum = 0;
    for (int i = data->start; i < data->end; i++) data->sum += data->array[i];
    return NULL;
}

int main() {
    int n;
    printf("Enter n (>1000): ");
    scanf("%d", &n);
    if (n <= 1000) return printf("n must be >1000\n"), 1;

    int *array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) array[i] = i + 1;

    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];
    int chunk = n / NUM_THREADS;

    long total_sum = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i] = (ThreadData){array, i * chunk, (i + 1 == NUM_THREADS) ? n : (i + 1) * chunk, 0};
        pthread_create(&threads[i], NULL, compute_sum, &threadData[i]);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_sum += threadData[i].sum;
    }
    
    printf("Total sum: %ld\n", total_sum);
    free(array);
    return 0;
}

