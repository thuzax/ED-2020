

#include "../file_manager.hpp"

void read_rm_based(const char* file_name, Graph* graph, int* num_districts) {
    ifstream rm_file(file_name);

    int num_vertices;
    rm_file >> num_vertices;

    cout << "AQUI" << endl;

    Vertex** vertices = new Vertex*[num_vertices];

    for (int i = 0; i < num_vertices; i++) {
        int id_vertex;
        double coord_x;
        double coord_y;
        rm_file >> id_vertex >> coord_x >> coord_y;

        Vertex* v = new Vertex(id_vertex, coord_x, coord_y); 
        vertices[i] = v;
    }

    graph->set_num_vertices(num_vertices);
    graph->set_vertices(vertices);
    graph->create_structures();

    int num_edges;
    rm_file >> num_edges;
    for (int i = 0; i < num_edges; i++) {
        int id_v1;
        int id_v2;

        rm_file >> id_v1 >> id_v2;
        
        Vertex* v1 = vertices[id_v1];
        Vertex* v2 = vertices[id_v2];
        
        double x1 = v1->get_coordinate_x();
        double y1 = v1->get_coordinate_y();
        double x2 = v2->get_coordinate_x();
        double y2 = v2->get_coordinate_y();
        
        double distance = euclidian_distance(x1, y1, x2, y2); 
        graph->add_neighborhood(id_v1, id_v2, distance);
    }


    rm_file >> *num_districts;

}