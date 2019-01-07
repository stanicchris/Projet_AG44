GCC = g++
FLAGS = -g -Werror -Wall

all : main

main : main.cpp Graph.cpp Edge.cpp Vertex.cpp List.cpp MatrixI.cpp Heap.cpp
	$(GCC) $(FLAGS) -o main -cpp main.cpp Graph.cpp Edge.cpp Vertex.cpp List.cpp MatrixI.cpp Heap.cpp

#main.o : main.cpp
#	$(GCC) -o main.o -cpp main.cpp

#Graph.o : Graph.cpp
#	$(GCC) -o Graph.o -cpp Graph.cpp

#Edge.o : Edge.cpp
#	$(GCC) -o Edge.o -cpp Edge.cpp

#Vertex.o : Vertex.cpp
#	$(GCC) -o Vertex.o -cpp Vertex.cpp

#List.o : List.cpp
#	$(GCC) -o List.o -cpp List.cpp

#MatrixI.o : MatrixI.cpp
#	$(GCC) -o MatrixI.o -cpp MatrixI.cpp

#Heap.o : Heap.cpp
#	$(GCC) -o Heap.o -cpp Heap.cpp

clean :
	rm main output.txt