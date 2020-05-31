

#include "../constructive_algorithm.hpp"


void construct_districts(Graph* graph, int num_districts, 
                                                District** districts) {

    for (int i = 0; i < num_districts; i++) {
        districts[i] = new District(i);
    }

    vector<int> districts_seeds = select_districts_seeds(graph, num_districts);

    for (int i = 0; i < num_districts; i++) {
        cout << districts_seeds[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < num_districts; i++) {
        assign_vertex_to_district(districts_seeds[i], districts[i], graph);
    }

    for (int i = 0; i < num_districts; i++) {
        cout << districts[i]->get_string() << endl;
    }

    cout << graph->get_vertices_string() << endl;

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