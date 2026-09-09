/*openmp program that divides the iterations into chunks containing 2 iterations, respectively. its input should be
number of iterations and its output should be which iterations of parallelized for loop are being executed by which thread*/
#include<stdio.h>
#include<omp.h>
int main()
{
    int num_iterations;
    printf("Enter the number of iterations");
    scanf("%d", &num_iterations);
    #pragma omp parallel 
    {
        #pragma omp for schedule(static,2)
        for(int i=0;i<num_iterations;i++)
        {
            printf("Thread %d is executing iteration %d\n", omp_get_thread_num(), i);
        }
    }
    return 0;
}
