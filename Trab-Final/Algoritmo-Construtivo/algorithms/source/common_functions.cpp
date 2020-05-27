// Math formulas file


#include "../common_functions.hpp"

using namespace std;

double euclidian_distance(double x1, double y1, double x2, double y2) {
    double x = x1 - x2;
    double y = y1 - y2;
    return pow(pow(x, 2) + pow(y, 2), 1.0/2.0);
}


vector<int> generate_random_indices(int num_indices, int start, 
                                    int end, bool* banned) {

    vector<int> indices;
    int i = 0;
    while (i < num_indices) {
        int index = rand() % (end + 1 - start) + start;
        if (banned[index]) {
            continue;
        }
        if (count(indices.begin(), indices.end(), index) > 0) {
            continue;
        }
        indices.push_back(index);
        i++;
    }
    
    return indices;
}

int get_nearest_vertex_id(vector<int> vertices, vector<int> candidates,
                          Graph* graph) {

    int nearest_vertex = -1;
    double current_min_distance = 99999999;

    for (int i = 0; i < vertices.size(); i++) {
        int local_nearest = get_nearest_vertex_id(vertices[i], candidates, 
                                                  graph);
        double local_distance = graph->get_distance(i, local_nearest);
        if (local_distance < current_min_distance) {
            nearest_vertex = local_nearest;
            current_min_distance = local_distance;
        }
    }
    return nearest_vertex;
}

int get_nearest_vertex_id(int vertex, vector<int> candidates, Graph* graph) {
    int nearest_vertex = -1;
    double min_distance = 9999999;

    for (int i = 0; i < candidates.size(); i++) {
        double x1 = graph->get_coordenate_x(vertex);
        double y1 = graph->get_coordenate_y(vertex);

        double x2 = graph->get_coordenate_x(candidates[i]);
        double y2 = graph->get_coordenate_y(candidates[i]);
        
        double distance = euclidian_distance(x1, y1, x2, y2);   

        if (distance < min_distance) {
            nearest_vertex = candidates[i];
            min_distance = distance;
        }
    }
    return nearest_vertex;
}