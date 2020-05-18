#include <iostream>

#include "algorithms/Vertex.hpp"
#include "algorithms/District.hpp"
#include "algorithms/AdjacencyMatrix.hpp"

using namespace std;

int main() {
    Vertex v = Vertex(1, 1, 1);
    cout << v.get_string() << endl;

    District d = District(1);
    cout << d.get_string() << endl;

    v.set_id_district(d.get_id());
    cout << v.get_string() << endl;

    AdjacencyMatrix adj_matrix = AdjacencyMatrix(5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; (j != i and j < 5); j++) {
            adj_matrix.set_weight(i, j, (i+j+1)/7.0);
            adj_matrix.set_weight(j, i, (i+j+1)/3.0);
        }
    }
    cout << adj_matrix.get_string() << endl;
    cout << adj_matrix.get_weight(0, 1) << endl;


    return 0;
}