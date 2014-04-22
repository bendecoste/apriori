all: apriori.o transaction.o main.o
	gcc-4.9 -fopenmp apriori.o transaction.o main.o -o main

clean:
	rm -rf *.o main
