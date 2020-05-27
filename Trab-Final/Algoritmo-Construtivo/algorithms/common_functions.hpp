// Math formulas file

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "Graph.hpp"

using namespace std;

#ifndef COMMON_FUNC
#define COMMON_FUNC 1

double euclidian_distance(double x1, double x2, double y1, double y2);

vector<int> generate_random_indices(int num_indices, int start, int end, bool* 
                                    banned);

int get_nearest_vertex_id(vector<int> district_seeds, vector<int> candidates, 
                          Graph* graph);

int get_nearest_vertex_id(int district_seeds, vector<int> candidates, 
                          Graph* graph);


#endif