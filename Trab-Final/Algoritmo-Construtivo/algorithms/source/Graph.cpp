

#include "../Graph.hpp"

// Initialize all variables
Graph::Graph() {
    this->num_vertices = 0;
    this->vertices = nullptr;
    this->adj_list = nullptr;
    this->adj_matrix = nullptr;
}

// Destruct structures and the vertices
Graph::~Graph() {
    delete this->adj_list;
    delete this->adj_matrix;
    for (int i = 0; i < this->num_vertices; i++) {
        delete this->vertices[i];
    }

    delete[] this->vertices;
}

// Create the adjacency list and matrix
void Graph::create_structures() {
    this->adj_list = new AdjacencyList(this->num_vertices);
    this->adj_matrix = new AdjacencyMatrix(this->num_vertices);
}

// Set the number of vertices of the graph
void Graph::set_num_vertices(int num_vertices) {
    this->num_vertices = num_vertices;
}

// Set the vertices list
void Graph::set_vertices(Vertex** vertices) {
    this->vertices = vertices;
}

// Set vertex as a border
void Graph::set_vertex_num_neighbors_out(int id_vertex, int num_neighbors) {
    this->vertices[id_vertex]->set_vertex_num_neighbors_out(num_neighbors);
}

// Add v1 as neighbor of v2 and v2 as neighbor of v1
void Graph::add_neighborhood(int id_v1, int id_v2, double distance) {
    this->adj_list->add_neighbor(id_v1, id_v2);
    this->adj_matrix->set_weight(id_v1, id_v2, distance);

    // To make undirected graph remove the next lines 
    this->adj_list->add_neighbor(id_v2, id_v1);
    this->adj_matrix->set_weight(id_v2, id_v1, distance);
}

// Verify if two vertices are neighbors
bool Graph::are_neighbors(int id_v1, int id_v2) {
    return adj_matrix->are_neighbors(id_v1, id_v2);
}

vector<int> Graph::get_candidates(int id_vertex) {
    vector<int> candidates;
    vector<int> neighbors = this->adj_list->get_neighbors(id_vertex);
    
    Vertex* vertex = this->vertices[id_vertex];
    for (int i = 0; i < neighbors.size(); i++) {
        Vertex* neighbor = this->vertices[neighbors[i]];
        if (vertex->get_id_district() != neighbor->get_id_district()) {
            candidates.push_back(neighbors[i]);
        }
    }

    return candidates;
}


// Neighbors of same district will have the number of vertices out of the district increased
void Graph::add_to_neighbors_out_count(int id_vertex) {
    vector<int> neighbors = this->adj_list->get_neighbors(id_vertex);
    
    Vertex* vertex = this->vertices[id_vertex];
    for (int i = 0; i < neighbors.size(); i++) {
        Vertex* neighbor = this->vertices[neighbors[i]];
        if (vertex->get_id_district() == neighbor->get_id_district()) {
            neighbor->increase_num_neighbors_out_district();
        }
    }
}


void Graph::remove_from_neighbors_out_count(int id_vertex) {
    vector<int> neighbors = this->adj_list->get_neighbors(id_vertex);
    
    Vertex* vertex = this->vertices[id_vertex];
    for (int i = 0; i < neighbors.size(); i++) {
        Vertex* neighbor = this->vertices[neighbors[i]];
        if (vertex->get_id_district() == neighbor->get_id_district()) {
            neighbor->decrease_num_neighbors_out_district();
        }
    }
}


// Verify if a vertex has a neighbor which isn't from the same district
int Graph::get_num_neihgbors_out_of_district(int id_vertex) {
    vector<int> neighbors = this->adj_list->get_neighbors(id_vertex);

    Vertex* vertex = this->vertices[id_vertex];

    int num_neighbors = 0;

    for (int i = 0; i < neighbors.size(); i++) {
        Vertex* neighbor = this->vertices[neighbors[i]];
        if (vertex->get_id_district() != neighbor->get_id_district()) {
            num_neighbors++;
        }
    }
    return num_neighbors;
}


// Set the id of the district in the vertex
void Graph::set_vertex_district_id(int id_vertex, int id_district) {
    Vertex* vertex = this->vertices[id_vertex];
    if (vertex->get_id_district() != -1) {
        this->add_to_neighbors_out_count(id_vertex);
    }
    this->vertices[id_vertex]->set_id_district(id_district);
}

// Get the weight in adj matrix
double Graph::get_distance(int id_v1, int id_v2) {
    return this->adj_matrix->get_weight(id_v1, id_v2);
}

// Return the coord x from vertex with the input id
double Graph::get_coordenate_x(int id_vertex) {
    return this->vertices[id_vertex]->get_coordinate_x();
}

// Return the coord y from vertex with the input id
double Graph::get_coordenate_y(int id_vertex) {
    return this->vertices[id_vertex]->get_coordinate_y();
}

// Return the number of vertices in graph
int Graph::get_num_vertices() {
    return this->num_vertices;
}

// Get the structures as strings
string Graph::get_string() {
    string text = "";
    text += "---------------- Adj List -------------------\n";
    text += this->adj_list->get_string() + "\n";
    text += "--------------- Adj Matri -------------------\n";
    text += this->adj_matrix->get_string() + "\n";

    return text;

}


string Graph::get_vertices_string() {
    string text = "";
    for (int i = 0; i < num_vertices; i++) {
        text += this->vertices[i]->get_string() + "\n";
    }

    return text;

}


// -------------------------- Verification Functions ---------------------------




bool Graph::is_connected() {
    // discovered vertices
    bool* discovered = new bool[this->num_vertices];
    // number of subgraphs
    int count = 0;

    for (int i = 0; i < this->num_vertices; i++) {
        // if discovered, means that it is in a previous subgraph
        if (discovered[i]) {
            continue;
        }

        
        // otherwise it is the first discovered vertex of a subgraph
        count += 1;

        // vertex stack
        vector<int> stack;
        
        // add vertex to stack
        stack.push_back(i);

        // while stack is not empty
        while (stack.size() > 0) {
            int v = stack.back();
            stack.pop_back();

            // if vertex already discovered, search next one
            if (discovered[v]) {
                continue;
            }

            // otherwise, mark and add neighbors to search
            discovered[v] = true;
            vector<int> neighbors = this->adj_list->get_neighbors(v);
            stack.insert(stack.end(), neighbors.begin(), neighbors.end());

        }

    }

    delete[] discovered;

    // se count == 1, grafo é conexo, se count == 2, conjunto V == {}
    if (count < 2) {
        return true;
    }
    // caso contrário é um grafo desconexo
    return false;

}