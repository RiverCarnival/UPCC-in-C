#include <stdio.h>
#include <upc_relaxed.h>
#include <time.h>
#include <stdlib.h>
#define N 142858 * THREADS 

// upcc soma_vetores.c  -o soma -network=smp
// upcrun -n 6 soma

shared int v1[N], v2[N], soma[N];
shared long long int resultado = 0;

int main(void) {
    double time_spent = 0.0;
    clock_t begin = clock();
    srand(time(NULL));  
    int r = rand();
    shared int *p1, *p2, *s;
    p1 = v1; 
    p2 = v2;
    s = soma;
    upc_forall(unsigned i = 0; i < N; i++) {
        v1[i] = rand() % (10 * (MYTHREAD + 1));
        v2[i] = rand() % (10 * (MYTHREAD + 1));
    }
    upc_forall(unsigned i = 0; i < N; i++, p1++, p2++) {
        soma[i] = *p1 + *p2;
    }
    for (int i = 0; i < N; i++, s++) {
        resultado += *s;
    }
    upc_barrier;
    if (MYTHREAD == 0) {
        printf("\nO resultado da soma: %lld", resultado);
        clock_t end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\nTempo decorrido para a execução: %f segundos\n", time_spent);
    }
    return 0;
}
