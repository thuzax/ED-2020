#include <iostream>

#include "algorithms/file_manager.hpp"

#include "algorithms/Vertex.hpp"
#include "algorithms/District.hpp"
#include "algorithms/AdjacencyMatrix.hpp"
#include "algorithms/AdjacencyList.hpp"
#include "algorithms/Graph.hpp"

using namespace std;


int main() {
    Graph* g = new Graph();

    int num_districts;

    read_rm_based("test_instances/tiny/teste_pra_teste.txt", g, &num_districts);

    cout << g->get_string() << endl;

    if (g->is_connected()) {
        cout << "GRAFO DE ENTRADA CONEXO" << endl;
    }

    delete g;
    return 0;
}