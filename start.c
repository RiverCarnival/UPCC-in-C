#include <stdio.h>
#include <upc_relaxed.h>

int  main ()
{
    for(int i = 0; i < 10000000; i++)
    {
        printf("\nOla mundo thred: %d/%d/ iteracao: %d\n", MYTHREAD, THREADS, i);

    }
    
    upc_barrier;

    return 0;
}