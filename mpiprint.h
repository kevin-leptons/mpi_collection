#ifndef MPIPRINT_H
#define MPIPRINT_H

#include <unistd.h>

char* get_mpiname()
{
	static char name_store[MPI_MAX_PROCESSOR_NAME];
	static char* name = NULL;

	if (name == NULL)
	{
		int name_length;

		if (MPI_Get_processor_name(name_store, &name_length) != 0)
		{
			printf("MPI_Get_processor_name\n");
			exit(EXIT_FAILURE);
		}

		name = name_store;
	}

	return name;
}

pid_t get_pid()
{
	static pid_t pid = 0;

	if (pid == 0)
	{
		pid = getpid();
	}

	return pid;
}

#define std_printf printf
#undef printf

#if __STDC_VERSION__ < 199901L
#define printf(format, ...) \
	std_printf("[%s/%i] ", get_mpiname(), get_pid()); \
	std_printf(format, ##__VA_ARGS__);
#else
#define printf(format, ...) \
	std_printf("[%s/%i] ", get_mpiname(), get_pid()); \
	std_printf(format __VA_OPT__(,) __VA_ARGS__);
#endif

#endif
