

#include "../graph_common_functions.hpp"


int get_nearest_vertex_id(vector<int> vertices, vector<int> candidates,
                          Graph* graph) {

    int nearest_vertex = -1;
    double current_min_distance = 99999999;

    for (int i = 0; i < vertices.size(); i++) {
        int local_nearest = get_nearest_vertex_id(vertices[i], candidates, 
                                                  graph);
        if (local_nearest == -1) {
            continue;
        }
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

void assign_vertex_to_district(int id_vertex, District* 
                                district, Graph* graph) {
    
    graph->set_vertex_district_id(id_vertex, district->get_id());
    district->increase_num_vertices();
    // district->add_vertex_to_district(id_vertex);

    int num_neighbors_out = graph->get_num_neihgbors_out_of_district(id_vertex);
    if (num_neighbors_out > 1) {
        district->add_to_border(id_vertex);
        graph->set_vertex_num_neighbors_out(id_vertex, num_neighbors_out);
        vector<int> candidates = graph->get_candidates(id_vertex);
        district->add_to_candidates(candidates);
    }

    graph->remove_from_neighbors_out_count(id_vertex);

    double new_bal = recalculate_district_balance(district, graph);
    district->set_balance_value(new_bal);
}

double recalculate_district_balance(District* district, Graph* graph) {
    return district->get_num_vertices();
}

// função temporária
int remove_best_candidate_id(District* district, Graph* graph) {
    vector<int> candidates = district->get_candidates();
    vector<int> border = district->get_border();

    for (int i = 0; i < candidates.size(); i++) {
        if (graph->vertex_has_district(candidates[i])){
            candidates.erase(candidates.begin() + i);
            i--;
         }
    }

    int candidate_id = get_nearest_vertex_id(border, candidates, graph);

    district->remove_from_candidates(candidate_id);
    return candidate_id;
}
