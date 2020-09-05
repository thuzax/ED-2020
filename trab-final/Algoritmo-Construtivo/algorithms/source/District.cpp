
#include "../District.hpp"

District::District(int id) {
    this->id = id;
    this->balance_value = 0;
    this->num_vertices = 0;
}


void District::set_balance_value(double bal_val) {
    this->balance_value = bal_val;
}

void District::increase_num_vertices() {
    this->num_vertices++;
}


void District::decrease_num_vertices() {
    this->num_vertices--;
}


void District::add_vertex_to_district(int id_vertex) {
    vertices.push_back(id_vertex);
}

// Verify if a vertex is in the border district
bool District::is_border_of_district(int id_vertex) {
    if (is_in_vector(id_vertex, this->border)) {
        return true;
    }
    return false;
}

// Add the vertex id to the border vector
void District::add_to_border(int id_vertex) {
    if (this->is_border_of_district(id_vertex)) {
        return;
    }

    this->border.push_back(id_vertex);
}

// Remove the vertex id from the border vector
void District::remove_from_border(int id_vertex) {
    int pos = find_position_in_vector(id_vertex, this->border);
    if (pos == -1) {
        return;
    }

    this->border.erase(this->border.begin() + pos);
}

// Verify if a vertex is a candidate to enter in the district
bool District::is_candidate_of_district(int id_vertex) {
    if (is_in_vector(id_vertex, this->candidates)) {
        return true;
    }
    return false;
}

bool District::has_candidate() {
    if (this->candidates.size() > 0) {
        return true;
    }
    return false;
}

// Add the vertex id to the candidates vector
void District::add_to_candidates(int id_vertex) {
    if (this->is_candidate_of_district(id_vertex)) {
        return;
    }

    this->candidates.push_back(id_vertex);
}

// Add a list of vertices ids to the candidates vector
void District::add_to_candidates(vector<int> candidates_ids) {
    for (int i = 0; i < candidates_ids.size(); i++) {
        if (this->is_candidate_of_district(candidates_ids[i])) {
            candidates_ids.erase(candidates_ids.begin() + i);
            i--;
        }
    }
    
    for (int i = 0; i < candidates_ids.size(); i++) {
        this->candidates.push_back(candidates_ids[i]);
    }
}


// Remove the vertex id from the candidates vector
void District::remove_from_candidates(int id_vertex) {
    int pos = find_position_in_vector(id_vertex, this->candidates);
    if (pos == -1) {
        return;
    }

    this->candidates.erase(this->candidates.begin() + pos);
}


// TODO: adicionar atributos
double District::calculate_imbalance(double ideal_balance) {
    double variation = abs(this->get_balance() - ideal_balance)/ideal_balance;

    return variation;
}


double District::calculate_diameter(Vertex** graph_vertices) {
    int num_vertices = this->vertices.size();
    double max_distance = 0;

    for (int i = 0; i < num_vertices; i++) {
        int id_vertex_1 = this->vertices[i];
        double x_1 = graph_vertices[id_vertex_1]->get_coordinate_x();
        double y_1 = graph_vertices[id_vertex_1]->get_coordinate_y();
        

        for (int j = i+1; j < num_vertices; j++) {
            int id_vertex_2 = this->vertices[i];
            double x_2 = graph_vertices[id_vertex_2]->get_coordinate_x();
            double y_2 = graph_vertices[id_vertex_2]->get_coordinate_y();

            double distance = euclidian_distance(x_1, x_2, y_1, y_2);

            if (max_distance < distance) {
                max_distance = distance;
            }
        }
    }
    return max_distance;
}


// Get the id of the district
int District::get_id() {
    return this->id;
}

double District::get_balance() {
    return this->balance_value;
}


int District::get_num_vertices() {
    return this->num_vertices;
}

vector<int> District::get_candidates() {
    return this->candidates;
}

vector<int> District::get_border() {
    return this->border;
}


string District::get_string() {
    string text = "";
    text += "id distrito: " + to_string(this->id) + "\n";
    text += "borda: ";
    for (int i = 0; i < this->border.size(); i++) {
        text += to_string(this->border[i]) + " ";
    }
    
    text += "\n";

    text += "candidato: ";
    for (int i = 0; i < this->candidates.size(); i++) {
        text += to_string(this->candidates[i]) + " ";
    }

    text += "\n";

    text += "vertices: ";
    for (int i = 0; i < this->vertices.size(); i++) {
        text += to_string(this->vertices[i]) + " ";
    }
    
    return text;

}

