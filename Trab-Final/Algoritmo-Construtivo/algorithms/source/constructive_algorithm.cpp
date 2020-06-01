

#include "../constructive_algorithm.hpp"


void construct_districts(Graph* graph, District** districts, 
                                                int num_districts) {

    for (int i = 0; i < num_districts; i++) {
        districts[i] = new District(i);
    }

    vector<int> districts_seeds = select_districts_seeds(graph, num_districts);

    for (int i = 0; i < num_districts; i++) {
        assign_vertex_to_district(districts_seeds[i], districts[i], graph);
    }

    expand_districts(graph, districts, num_districts);

}

void expand_districts(Graph* graph, District** districts, int num_districts) {
    Heap heap(num_districts);
    for (int i = 0; i < num_districts; i++) {
        heap.add(i, districts[i]->get_balance());
    }

    while (not heap.heap_is_empty()) {
        int id_district = heap.remove();
        District* district = districts[id_district];

        if (district->has_candidate()) {
            int candidate_id = remove_best_candidate_id(district, graph);
            if (candidate_id != -1) {
                assign_vertex_to_district(candidate_id, district, graph);
                heap.add(district->get_id(), district->get_balance());
            }
        }
    }
}


// select random seeds between a random pool
vector<int> select_districts_seeds(Graph* graph, int num_districts) {
    vector<int> districts_seeds;


    int num_vertices = graph->get_num_vertices();
    bool marked_vertices[num_vertices] = {false};

    // generate a array with one element and get it as the first vertex
    int first_vertex = generate_random_indices(1, 0, num_vertices-1, 
                                               marked_vertices)[0];
    
    districts_seeds.push_back(first_vertex);
    marked_vertices[first_vertex] = true;


    for (int i = 0; i < num_districts-1; i++) {

        vector<int> candidates = generate_random_indices(
                                                int(sqrt(num_vertices)), 
                                                0, num_vertices-1,
                                                marked_vertices
                                            );


        int nearest = get_nearest_vertex_id(districts_seeds, candidates, graph);
        districts_seeds.push_back(nearest);
        marked_vertices[nearest] = true;

    }

    return districts_seeds;
}