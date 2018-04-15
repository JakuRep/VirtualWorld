cmake_minimum_required(VERSION 3.10)
project(VirtualWorld)

set(CMAKE_CXX_STANDARD 11)

add_executable(VirtualWorld main.cpp Map.cpp Map.h PriorityQueue.cpp PriorityQueue.h MapExceptions.cpp MapExceptions.h QueueExceptions.cpp QueueExceptions.h Organism.cpp Organism.h World.cpp World.h WorldExceptions.cpp WorldExceptions.h OrganismExceptions.cpp OrganismExceptions.h)