cmake_minimum_required(VERSION 3.10)
project(VirtualWorld)

set(CMAKE_CXX_STANDARD 11)
find_package(Curses REQUIRED)
include_directories(.)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(VirtualWorld main.cpp Map.cpp Map.h PriorityQueue.cpp PriorityQueue.h MapExceptions.cpp MapExceptions.h QueueExceptions.cpp QueueExceptions.h Organism.cpp Organism.h World.cpp World.h WorldExceptions.cpp WorldExceptions.h OrganismExceptions.cpp OrganismExceptions.h Plant.cpp Plant.h Sheep.cpp Sheep.h Wolf.cpp Wolf.h Fox.cpp Fox.h Turtle.cpp Turtle.h Antelope.cpp Antelope.h Grass.cpp Grass.h Dandelion.cpp Dandelion.h Guarana.cpp Guarana.h Belladonna.cpp Belladonna.h SosnowskyiHodweed.cpp SosnowskyiHodweed.h Animal.cpp Animal.h "Global Function.cpp" GlobalFunctions.h Human.cpp Human.h)
target_link_libraries(VirtualWorld ${CURSES_LIBRARIES})