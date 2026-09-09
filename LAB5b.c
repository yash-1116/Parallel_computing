//For multiple process
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size;
    int number;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (size < 2)
    {
        if (rank == 0)
            printf("Please run with at least 2 processes.\n");

        MPI_Finalize();
        return 0;
    }
    int next = (rank + 1) % size;
    int previous = (rank - 1 + size) % size;
    number = rank + 10;
    MPI_Send(&number, 1, MPI_INT, next, 0, MPI_COMM_WORLD);
    printf("Process %d sent %d to Process %d\n",
           rank, number, next);
    MPI_Recv(&number, 1, MPI_INT, previous, 0,
             MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process %d received %d from Process %d\n",
           rank, number, previous);
    MPI_Finalize();
    return 0;
}
