#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define N 10

int main(void) {
    int sum;
    int* a = calloc(N, sizeof(int));
  
    srand(time(NULL));
    
    printf("[");
    a[0] = rand() % 50;
    printf("%3d", a[0]);
    for (int i = 1; i < N; i++) {
        a[i] = rand() % 50;
        printf(", %3d", a[i]);
    }
    printf("]");
    printf("\n");

    int* min = &a[0];
    int* max = &a[0];

    for (int i = 0; i < N; i++) {
        if (a[i] < *min) min = a + i;
        if (a[i] > *max) max = a + i;
    }

    if(min > max) {
        int *tmp = min;
        min = max;
        max = tmp;
    }
  
    for (int *ptr = min + 1; ptr < max; ptr++) {    
        sum += *ptr;
    }

    printf("sum(i%ld, i%ld) = %3d", min - a, max - a, sum);

    printf("\n");
  
  return 0;
}