#include <iostream>
#include <time.h>

#include "algorithms/file_manager.hpp"
#include "algorithms/constructive_algorithm.hpp"

#include "algorithms/Vertex.hpp"
#include "algorithms/District.hpp"
#include "algorithms/AdjacencyMatrix.hpp"
#include "algorithms/AdjacencyList.hpp"
#include "algorithms/Graph.hpp"
#include "algorithms/graph_common_functions.hpp"

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


int main(int argc, char** argv) {

    clock_t start = clock();


    if (argc < 3) {
        string saida = "";
        saida += "Modo de execução incorreto.";
        saida += "Utilize o formato abaixo: \n\n";
        saida += "\t";
        saida += "./constr-distr.app <arquivo-entrada> <arquivo-saida>";
        cout << saida << endl;
        exit(0);
    }
    
    // TODO: Arrumar a tolerancia do balanceamento
    double imbalance_tolerance = 0.1;

    char* input_file_name = argv[1];
    char* output_file_name = argv[2];

    initialize_random();
    Graph* graph = new Graph();

    int num_districts;

    read_rm_based(input_file_name, graph, &num_districts);

    if (not graph->is_connected()) {
        cerr << "GRAFO DE ENTRADA DESCONEXO" << endl;
        cout << graph->get_string() << endl;
        exit(1);
    }

    District** districts = new District*[num_districts];
    
    double ideal_balance = calculate_ideal_balance(
        districts, 
        num_districts, 
        graph
    );
    
    // TODO: função obj + recompute balance
    // TODO: função obj + recompute balance
    // TODO: função obj + recompute balance
    // TODO: função obj + recompute balance
    // TODO: função obj + recompute balance
    // TODO: função obj + recompute balance
    // TODO: função obj + recompute balance
    // TODO: função obj + recompute balance
    // TODO: função obj + recompute balance
    construct_districts(graph, districts, num_districts);

    bool connex_solution = true;

    for (int i = 0; i < num_districts; i++) {
        if (not graph->is_connected(i)) {
            connex_solution = false;
        }
    }

    vector<double> imbalances = calculate_imbalances(
        districts,
        num_districts, 
        ideal_balance
    );

    vector<double> diameters = calculate_diameters(
        districts, 
        num_districts, 
        graph
    );

    clock_t end = clock();

    double exec_time = double(end - start) / CLOCKS_PER_SEC;

    write_output_file(
        output_file_name, 
        graph, 
        districts, 
        num_districts, 
        connex_solution, 
        imbalances, 
        imbalance_tolerance, 
        diameters,
        exec_time
    );

    // for (int i = 0; i < num_districts; i++) {
    //     cout << districts[i]->get_string() << endl;
    // }



    for (int i = 0; i < num_districts; i++) {
        delete districts[i];
    }
    delete[] districts;

    delete graph;
    return 0;
}