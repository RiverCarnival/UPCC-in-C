#include <stdio.h>
#include <upc_relaxed.h>
#define n 3*THREADS

shared int v[n];

int main (void)
{
  //  int v[3];

    upc_forall(unsigned i = MYTHREAD; i < n; i+=THREADS)
    {
      v[i] = MYTHREAD;
    }

    for(int i = 0; i < n; i++)
    {
      printf(" : %d", v[i]);
    }

    printf("\n");
    upc_barrier;
    
    return 0;
}