

#include "../AdjacencyMatrix.hpp"


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

AdjacencyMatrix::~AdjacencyMatrix() {
    // destruct matrix
    for (int i = 0; i < this->matrix_size; i++) {
        delete[] this->matrix[i];
    }
    delete[] matrix;
}


void AdjacencyMatrix::set_weight(int id_v1, int id_v2, double weight) {
    this->matrix[id_v1][id_v2] = weight;
}

double AdjacencyMatrix::get_weight(int id_v1, int id_v2) {
    return this->matrix[id_v1][id_v2];
}


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