all: a1

a1: main.o Category.o Tester.o Price.o User.o Listing.o CuMarket.o 
	g++ -o a1 main.o Category.o Tester.o Price.o User.o Listing.o CuMarket.o

main.o: main.cc CuMarket.h Tester.h
	g++ -c main.cc

Category.o: Category.cc Category.h
	g++ -c Category.cc

Tester.o: Tester.cc Tester.h
	g++ -c Tester.cc

Price.o: Price.cc Price.h 
	g++ -c Price.cc

User.o: User.cc User.h 
	g++ -c User.cc

Listing.o: Listing.cc Listing.h Category.h Price.h
	g++ -c Listing.cc

CuMarket.o: CuMarket.cc CuMarket.h User.h
	g++ -c CuMarket.cc

clean:
	rm -f *.o a1 a.out