#include <iostream>

#include "algorithms/Vertex.hpp"
#include "algorithms/District.hpp"
#include "algorithms/AdjacencyMatrix.hpp"
#include "algorithms/AdjacencyList.hpp"

using namespace std;

int main() {
    Vertex v = Vertex(1, 1, 1);
    cout << v.get_string() << endl;

    District d = District(1);
    cout << d.get_string() << endl;

    v.set_id_district(d.get_id());
    cout << v.get_string() << endl;

    AdjacencyMatrix adj_matrix(5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; (j < i); j++) {
            if ((i+j >= 2) and (i-3*j < 0)) {
                continue;
            }
            adj_matrix.set_weight(i, j, (i+j+1));
            adj_matrix.set_weight(j, i, (i+j+1));
        }
    }
    cout << adj_matrix.get_string() << endl;
    cout << adj_matrix.get_weight(0, 1) << endl;

    int vertices[5];

    for (int i = 0; i < 5; i++) {
        vertices[i] = i;
    }

    AdjacencyList adj_list(vertices, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; (j < i); j++) {
            if ((i+j >= 2) and (i-3*j < 0)) {
                continue;
            }
            adj_list.add_neighbor(i, j);
            adj_list.add_neighbor(j, i);
        }
    }

    cout << adj_list.get_string() << endl;


    return 0;
}