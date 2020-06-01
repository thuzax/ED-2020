// algorithm used in constructve phase

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "graph_common_functions.hpp"
#include "common_functions.hpp"

#include "Graph.hpp"
#include "District.hpp"
#include "Heap.hpp"

using namespace std;

#ifndef CONSTR_ALG
#define CONSTR_ALG 1


void construct_districts(Graph* graph, District** districts, int num_districts);

void expand_districts(Graph* graph, District** districts, int num_districts); 


vector<int> select_districts_seeds(Graph* graph, int num_districts);

#endif