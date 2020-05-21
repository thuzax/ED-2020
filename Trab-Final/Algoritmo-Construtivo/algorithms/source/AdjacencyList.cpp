

#include "../AdjacencyList.hpp"


void Node::set_id_vertex(int id_vertex) {
    this->id_vertex = id_vertex;
}


void Node::add_neighbor(int id_neighbor) {
    this->neighbors.push_back(id_neighbor);
}


int Node::get_id_vertex() {
    return this->id_vertex;
}

vector<int> Node::get_neighbors() {
    vector<int> neighbors_copy(this->neighbors.size());

    for (int i = 0; i < (int) this->neighbors.size(); i++) {
        neighbors_copy[i] = this->neighbors[i];
    }

    return neighbors_copy;
}

// ---------------------------- Adjacency List ---------------------------------

AdjacencyList::AdjacencyList(int* vertices, int num_vertices) {
    this->num_vertices = num_vertices;

    this->nodes = new Node[this->num_vertices];

    for (int i = 0; i < this->num_vertices; i++) {
        this->nodes[i].set_id_vertex(vertices[i]);
    }

}


AdjacencyList::~AdjacencyList() {
    delete[] this->nodes;
}

// Add v2 as neighbor of v1
void AdjacencyList::add_neighbor(int id_v1, int id_v2) {
    this->nodes[id_v1].add_neighbor(id_v2);
}


// return the list of neighbors
vector<int> AdjacencyList::get_neighbors(int id_vertex) {
    return this->nodes[id_vertex].get_neighbors();
}


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