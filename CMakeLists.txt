cmake_minimum_required(VERSION 3.24)
project(DA_Project1)

set(CMAKE_CXX_STANDARD 17)

add_executable(DA_Project1 main.cpp src/Menu.cpp src/Menu.h src/Station.cpp src/Station.h src/Segment.cpp src/Segment.h src/File.cpp src/File.h src/Network.cpp src/Network.h src/NetworkController.cpp src/NetworkController.h data_structures/Graph.cpp data_structures/Graph.h data_structures/Heap.cpp data_structures/Heap.h data_structures/UFDS.cpp data_structures/UFDS.h data_structures/VertexEdge.cpp data_structures/VertexEdge.h data_structures/MutablePriorityQueue.h)
