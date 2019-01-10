GCC = g++
FLAGS = -g -Wall

all : main

main : main.cpp Graph.cpp Edge.cpp Vertex.cpp
	$(GCC) $(FLAGS) -o main -cpp main.cpp Graph.cpp Edge.cpp Vertex.cpp

make compute :
	valgrind ./main

clear :
	if [ -e main ];then rm main;fi;
	if [ -e output.txt ];then rm output.txt;fi;
