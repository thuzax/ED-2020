// Graph Adjacency Matrix

#include <iostream>
#include <string>
using namespace std;


#ifndef ADJ_MATRIX
#define ADJ_MATRIX 1

class AdjacencyMatrix {
    private:
        int matrix_size;
        double** matrix;

    public:
        AdjacencyMatrix(int matrix_size);
        ~AdjacencyMatrix();

        void set_weight(int id_v1, int id_v2, double weight);
        
        double get_weight(int id_v1, int id_v2);

        bool are_neighbors(int id_v1, int id_v2);


        string get_string();
};

#endif