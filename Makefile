all: apriori.o transaction.o
	clang apriori.o transaction.o -o apriori

clean:
	rm -rf *.o apriori
