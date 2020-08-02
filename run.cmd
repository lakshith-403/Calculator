g++ -c arts/arts.cpp -o bin/arts.o
g++ -c util/errorCheck.cpp -o bin/errorCheck.o
g++ -c solvers/solver.cpp -o bin/solver.o
g++ -c main.cpp -o bin/main.o
g++ bin/arts.o bin/errorCheck.o bin/solver.o bin/main.o -o runner.o
runner.o