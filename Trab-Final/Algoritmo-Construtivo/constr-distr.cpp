#include <iostream>
#include <time.h>

#include "algorithms/file_manager.hpp"
#include "algorithms/constructive_algorithm.hpp"

#include "algorithms/Vertex.hpp"
#include "algorithms/District.hpp"
#include "algorithms/AdjacencyMatrix.hpp"
#include "algorithms/AdjacencyList.hpp"
#include "algorithms/Graph.hpp"

using namespace std;

// If seed < 0, then it's used random seed
void initialize_random(int seed = -1) {
    // random seed
    if (seed == -1) {
        srand(time(nullptr));
        return;
    }
    // fixed seed
    srand(seed);
}


int main() {
    initialize_random();
    Graph* graph = new Graph();

    int num_districts;

    read_rm_based("test_instances/tiny/teste_pra_teste.txt", graph, &num_districts);

    cout << graph->get_string() << endl;

    if (graph->is_connected()) {
        cout << "GRAFO DE ENTRADA CONEXO" << endl;
    }

    District** districts = new District*[num_districts];
    construct_districts(graph, districts, num_districts);


    cout << "---------------------------------------------------------" << endl;
    cout << graph->get_vertices_string() << endl;

    for (int i = 0; i < num_districts; i++) {
        cout << graph->is_connected(i) << " " << districts[i]->get_balance();
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < num_districts; i++) {
        delete districts[i];
    }
    delete[] districts;

    delete graph;
    return 0;
}