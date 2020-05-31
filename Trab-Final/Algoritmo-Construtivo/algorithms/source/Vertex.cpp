
#include "../Vertex.hpp"

Vertex::Vertex(int id, double coordenate_x, double coordenate_y) {
    this->id = id;
    this->coordenate_x = coordenate_x;
    this->coordenate_y = coordenate_y;
    this->id_district = -1;
    this->num_neighbors_out_district = 0;
}

void Vertex::set_id_district(int id_district) {
    this->id_district = id_district;
}

void Vertex::set_vertex_num_neighbors_out(int num_neighbors_out_district) {
    this->num_neighbors_out_district = num_neighbors_out_district;
}


void Vertex::increase_num_neighbors_out_district() {
    this->num_neighbors_out_district++;
}


void Vertex::decrease_num_neighbors_out_district() {
    this->num_neighbors_out_district--;
}


bool Vertex::is_border() {
    if (this->num_neighbors_out_district > 0) {
        return true;
    }
    return false;
}



int Vertex::get_id() {
    return this->id;
}

int Vertex::get_id_district() {
    return this->id_district;
}

double Vertex::get_coordinate_x() {
    return this->coordenate_x;
}

double Vertex::get_coordinate_y() {
    return this->coordenate_y;
}

string Vertex::get_string() {
    string text = "";
    text += "id vértice: " + to_string(this->id) + "\n";
    text += "id distrito: " + to_string(this->id_district) + "\n";
    text += "coordenadas: \n";
    text += "    x: " + to_string(this->coordenate_x) + "\n";
    text += "    y: " + to_string(this->coordenate_y);
    return text;
}