all: build-default \
	build-buggy17 build-fixed17 \
	build-buggy19 build-fixed19 \
	build-buggy23 build-fixed23

build-default:
	mpicc default.c -o /share/default

run-default: 
	mpirun /share/default

build-buggy17: 
	mpicc buggy17.c -o /share/buggy17

run-buggy17:
	mpirun /share/buggy17

build-fixed17:
	mpicc fixed17.c -o /share/fixed17

build-buggy19:
	mpic++ buggy19.cpp -o /share/buggy19

build-fixed19:
	mpic++ fixed19.cpp -o /share/fixed19

build-buggy23:
	mpic++ -lm buggy23.cpp -o /share/buggy23

build-fixed23:
	mpic++ -lm fixed23.cpp -o /share/fixed23
