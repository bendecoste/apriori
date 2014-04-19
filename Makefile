all: apriori.o transaction.o main.o
	clang apriori.o transaction.o main.o -o main

clean:
	rm -rf *.o main
