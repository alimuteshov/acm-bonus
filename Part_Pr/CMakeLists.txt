cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(PartPr)
 
include_directories(include)
 

set(SOURCES Part_Pr/findSets.cpp Part_Pr/isPartitionFeasible.cpp Part_Pr/printSets.cpp Part_Pr/PartitionProblem.cpp)
 
 
add_executable(PartPr ${SOURCES})