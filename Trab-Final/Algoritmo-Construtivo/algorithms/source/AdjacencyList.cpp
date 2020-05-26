

#include "../AdjacencyList.hpp"


// ---------------------------- Node Structure ---------------------------------

// Set the id of the node
void Node::set_id_vertex(int id_vertex) {
    this->id_vertex = id_vertex;
}

// Add a vertex as neighbor of the node vertex
void Node::add_neighbor(int id_neighbor) {
    this->neighbors.push_back(id_neighbor);
}

// Get the node vertex id
int Node::get_id_vertex() {
    return this->id_vertex;
}

// Get all the neighbors of the vertex
vector<int> Node::get_neighbors() {
    vector<int> neighbors_copy(this->neighbors.size());

    for (int i = 0; i < (int) this->neighbors.size(); i++) {
        neighbors_copy[i] = this->neighbors[i];
    }

    return neighbors_copy;
}

// ---------------------------- Adjacency List ---------------------------------

// Initialize variables
AdjacencyList::AdjacencyList(int num_vertices) {
    this->num_vertices = num_vertices;

    this->nodes = new Node[this->num_vertices];

    for (int i = 0; i < this->num_vertices; i++) {
        this->nodes[i].set_id_vertex(i);
    }

}

// Destruct the node array
AdjacencyList::~AdjacencyList() {
    delete[] this->nodes;
}

// Add v2 as neighbor of v1
void AdjacencyList::add_neighbor(int id_v1, int id_v2) {
    this->nodes[id_v1].add_neighbor(id_v2);
}


// Return the list of neighbors
vector<int> AdjacencyList::get_neighbors(int id_vertex) {
    return this->nodes[id_vertex].get_neighbors();
}

// Return the adjacency list as string
string AdjacencyList::get_string() {
    string text = "";
    for (int i = 0; i < this->num_vertices; i++) {
        text += to_string(this->nodes[i].get_id_vertex()) + " -> ";
        vector<int> neighbors = this->nodes[i].get_neighbors();
        for (int j = 0; j < neighbors.size(); j++) {
            text += to_string(neighbors[j]) + " ";
        }
        text += "\n";
    }
    return text;
}
