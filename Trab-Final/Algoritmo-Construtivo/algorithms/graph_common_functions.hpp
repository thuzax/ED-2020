// Math formulas file

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "Graph.hpp"
#include "Vertex.hpp"
#include "District.hpp"


using namespace std;

#ifndef GRAPH_COMMON_FUNC
#define GRAPH_COMMON_FUNC 1


int get_nearest_vertex_id(vector<int> district_seeds, vector<int> candidates, 
                          Graph* graph);

int get_nearest_vertex_id(int district_seeds, vector<int> candidates, 
                          Graph* graph);

void assign_vertex_to_district(int id_vertex, District* district, Graph* graph);

double recalculate_district_balance(District* district, Graph* graph);

int remove_best_candidate_id(District* district, Graph* graph);

#endif