GCC = g++

all : main

main : main.o Graph.o Edge.o Vertex.o List.o MatrixI.o Heap.o
	$(GCC) -o main main.o Graph.o Edge.o Vertex.o List.o MatrixI.o Heap.o

main.o : main.cpp Graph.h Edge.h Vertex.h List.h MatrixI.h Heap.h
	$(GCC) -o main.o -c main.cpp

Graph.o : Graph.cpp
	$(GCC) -o Graph.o -c Graph.cpp

Edge.o : Edge.cpp
	$(GCC) -o Edge.o -c Edge.cpp

Vertex.o : Vertex.cpp
	$(GCC) -o Vertex.o -c Vertex.cpp

List.o : List.cpp
	$(GCC) -o List.o -c List.cpp

MatrixI.o : MatrixI.cpp
	$(GCC) -o MatrixI.o -c MatrixI.cpp

Heap.o : Heap.cpp
	$(GCC) -o Heap.o -c Heap.cpp

clean :
	rm *.o

cleanall : clean
	rm main
