// Graph Structure

#include <iostream>
#include <string>
using namespace std;

#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "Vertex.hpp"

#include "common_functions.hpp"

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
        void set_vertex_district_id(int id_vertex, int id_district);
        void set_vertex_num_neighbors_out(int id_vertex, int num_neighbors);

        void add_neighborhood(int id_v1, int id_v2, double distance);

        bool are_neighbors(int id_v1, int id_v2);
        bool are_from_same_district(int id_v1, int id_v2);
        bool vertex_has_district(int id_vertex);


        vector<int> get_candidates(int id_vertex);
        void add_to_neighbors_out_count(int id_vertex);
        void remove_from_neighbors_out_count(int id_vertex);
        
        int get_num_neihgbors_out_of_district(int id_vertex);
        double get_distance(int id_v1, int id_v2);
        double get_coordenate_x(int id_vertex);
        double get_coordenate_y(int id_vertex);
        int get_num_vertices();
        int get_district_by_vertex(int id_vertex);
        Vertex** get_vertices();
        
        string get_string();
        string get_vertex_string(int id_vertex);
        string get_vertices_string();


        // Verification functions
        bool is_connected();
        bool is_connected(int id_district);

};

#endif