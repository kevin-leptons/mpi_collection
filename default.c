#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mpi.h"
#include "mpiprint.h"

int main (int argc, char **argv)
{
	int num_proc;
	int rank;
	int i = 0;
	int count_down = 20;

	if (argc > 1)
	{
		int attempt_parse_arg = atoi(argv[1]);
		if (0 < attempt_parse_arg) count_down = attempt_parse_arg;
	}

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &num_proc);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (0 == rank)
	{
		printf("So we got %d processes and...\n", num_proc);
	}

	printf("...I'm number %d\n", rank);

	for (i = count_down; i > 0; --i)
	{
		printf("%d: Blip...\n", rank);
		sleep(1);
	}

	printf("Oh he dead\n");

	MPI_Finalize();

	return EXIT_SUCCESS;
}
