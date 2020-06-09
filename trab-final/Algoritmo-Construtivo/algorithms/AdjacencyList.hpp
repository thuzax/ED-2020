// Graph Adjacency List 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef ADJ_LIST
#define ADJ_LIST 1


class Node {
    private:
        int id_vertex;
        vector<int> neighbors;

    public:
        void set_id_vertex(int id_vertex);
        int get_id_vertex();
        void add_neighbor(int id_neighbor);
        vector<int> get_neighbors();

};


class AdjacencyList {
    private:
        int num_vertices;
        Node* nodes;

    public:
        AdjacencyList(int num_vertices);
        ~AdjacencyList();

        void add_neighbor(int id_v1, int id_v2);
        vector<int> get_neighbors(int id_vertex);

        
        string get_string();
};

#endif