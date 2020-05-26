// Graph Structure

#include <iostream>
#include <string>
using namespace std;

#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "Vertex.hpp"

#ifndef GRAPH
#define GRAPH 1

class Graph {
    private:
        int num_vertices;
        Vertex** vertices;
        AdjacencyList* adj_list;
        AdjacencyMatrix* adj_matrix;

    public:
        Graph();
        ~Graph();

        void create_structures();
        void set_num_vertices(int num_vertices);
        void set_vertices(Vertex** vertices);

        void add_neighborhood(int id_v1, int id_v2, double distance);

        bool are_neighbors(int id_v1, int id_v2);


        string get_string();

        // Verification functions
        bool is_connected();

};

#endif