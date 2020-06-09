

#include "../AdjacencyMatrix.hpp"

// Initialize matrix values
AdjacencyMatrix::AdjacencyMatrix(int matrix_size) {
    this->matrix_size = matrix_size;

    // construct matrix
    this->matrix = new double*[this->matrix_size];
    for (int i = 0; i < this->matrix_size; i++) {
        this->matrix[i] = new double[this->matrix_size];
        
        // set 0 to all edges
        for (int j = 0; j < this->matrix_size; j++) {
            this->matrix[i][j] = 0;
        }
    }
}

// Destruct Matrix
AdjacencyMatrix::~AdjacencyMatrix() {
    // destruct matrix
    for (int i = 0; i < this->matrix_size; i++) {
        delete[] this->matrix[i];
    }
    delete[] matrix;
}

// Set the edge weight --> if weight is != the vertices are neighbors
void AdjacencyMatrix::set_weight(int id_v1, int id_v2, double weight) {
    this->matrix[id_v1][id_v2] = weight;
}

// Get the weight of the edge
double AdjacencyMatrix::get_weight(int id_v1, int id_v2) {
    return this->matrix[id_v1][id_v2];
}

// Verify if two vertices are neighbors
bool AdjacencyMatrix::are_neighbors(int id_v1, int id_v2) {
    if (this->matrix[id_v1][id_v2] == 0) {
        return false;
    }
    return true;
}

// Return the adjacency matrix as string
string AdjacencyMatrix::get_string() {
    string text = "";
    text += "Matrix: \n";
    for (int i = 0; i < this->matrix_size; i++) {
        text += "| ";
        for (int j = 0; j < this->matrix_size; j++) {
            text += to_string(this->matrix[i][j]) + " ";
        }
        text += " |";
        text += "\n";
    }
    
    return text;
}

