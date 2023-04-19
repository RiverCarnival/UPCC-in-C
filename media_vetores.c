#include <stdio.h>
#include <upc_relaxed.h>
#include <time.h>
#include <stdlib.h>
#define n 125000 * THREADS

shared int v1[n], v2[n], soma[n];
shared long long int resultado = 0;

int main (void)
{
  double time_spent = 0.0;
  
  clock_t begin = clock();
  srand(time(NULL));  
  int r = rand();
  long long int media;
  shared int *p1, *p2, *s;
  p1 = v1; 
  p2 = v2;
  s = soma;

  upc_forall(unsigned i = 0; i < n; i++)
  {
    v1[i] = rand() % (10 * (MYTHREAD + 1));
    v2[i] = rand() % (10 * (MYTHREAD + 1));

  }
 
  upc_forall(unsigned i = 0; i < n; i++, p1++, p2++)
  {
    soma[i] = *p1 + *p2;
  }

  int i = 0;
  for(i = 0; i < n; i++, s++)
  {
    resultado += *s;
  }

  upc_barrier;
  media += resultado/i;

  if(MYTHREAD == 0)
  {
    printf("\nO resultado da media: %lld", media);
   clock_t end = clock();
   time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   printf("\nTempo decorrido para a execução: %f segundos\n", time_spent);
  }
  
  return 0;
}