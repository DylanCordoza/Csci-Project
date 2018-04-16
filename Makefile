a.out: hash.o main.o hScore.h
    g++ -g -std=c++17 hash.o main.o

hash.o: hash.h hash.cc
    g++ -g -std=c++17 -c hash.cc

main.o: hash.h hScore.h main.cc
    g++ -g -std=c++17 -c main.cc

clean:
    rm -f a.out core *.o
