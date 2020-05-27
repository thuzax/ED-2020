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
        srand(time(0));
        return;
    }
    // fixed seed
    srand(0);
}


int main() {
    Graph* graph = new Graph();

    int num_districts;

    read_rm_based("test_instances/tiny/teste_pra_teste.txt", graph, &num_districts);

    cout << graph->get_string() << endl;

    if (graph->is_connected()) {
        cout << "GRAFO DE ENTRADA CONEXO" << endl;
    }

    District** districts = new District*[num_districts];
    construct_districts(graph, num_districts, districts);


    for (int i = 0; i < num_districts; i++) {
        delete districts[i];
    }
    delete[] districts;

    delete graph;
    return 0;
}