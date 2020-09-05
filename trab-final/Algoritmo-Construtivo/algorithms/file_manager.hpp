// Read File describing graph

#include <iostream>
#include <string>
#include <fstream>

#include "Graph.hpp"
#include "District.hpp"
#include "Vertex.hpp"
#include "common_functions.hpp"

#ifndef FILE_MANAGER
#define FILE MANAGER 1


void read_rm_based(const char* file_name, Graph* graph, int* num_districts);

string parse_json(
    Graph* graph, 
    District** districts, 
    int num_districts, 
    bool connex_solution, 
    vector<double> imbalances, 
    double imbalance_tolerance,
    vector<double> diameters,
    double exec_time
);

void write_output_file(
    const char* file_name, 
    Graph* graph, 
    District** districts, 
    int num_districts,
    bool connex_solution, 
    vector<double> imbalances, 
    double imbalance_tolerance,
    vector<double> diameters,
    double exec_time
);

#endif