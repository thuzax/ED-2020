// Math formulas file

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;

#ifndef COMMON_FUNC
#define COMMON_FUNC 1

double euclidian_distance(double x1, double x2, double y1, double y2);

vector<int> generate_random_indices(int num_indices, int start, int end, bool* 
                                    banned);

int find_position_in_vector(int id, vector<int> vec);

int is_in_vector(int id, vector<int> vec);

string get_vector_string(vector<int> vec);


#endif