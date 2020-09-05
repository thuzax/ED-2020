

#include "../file_manager.hpp"

void read_rm_based(const char* file_name, Graph* graph, int* num_districts) {
    ifstream rm_file(file_name);

    int num_vertices;
    rm_file >> num_vertices;

    Vertex** vertices = new Vertex*[num_vertices];


    for (int i = 0; i < num_vertices; i++) {
        int id_vertex;
        double coord_x;
        double coord_y;
        rm_file >> id_vertex >> coord_x >> coord_y;
        
        double junk;

        rm_file >> junk;
        rm_file >> junk;
        rm_file >> junk;


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

string parse_json(
    Graph* graph, 
    District** districts, 
    int num_districts,
    bool connex_solution, 
    vector<double> imbalances, 
    double imbalance_tolerance,
    vector<double> diameters,
    double exec_time
) {
    string text = "";
    text += "{\n";
    text += "\t";

    text += "\"tempo_execucao\":";
    text += to_string(exec_time);
    
    text += ",\n";
    text += "\t";




    // escreve o status da solução em relação a conexidade
    text += "\"distritos_conexos\":";
    if (connex_solution) {
        text += "\"True\"";
    }
    else {
        text += "\"False\"";
    }
    
    text += ",\n";
    text += "\t";

    // escreve o status da solucao em relação ao balanceamento
    text += "\"solucao_balanceada\":";

    bool factivel = true;
    for (int i = 0; i < num_districts-1; i++) {
        if (imbalances[i] > imbalance_tolerance) {
            factivel = false;
        }
    }

    if (factivel) {
        text += "\"True\"";
    }
    else {
        text += "\"False\"";
    }
    

    text += ",\n";
    text += "\t";

    text += "\"solucao_diametro\":";
    double diametro_solucao = 0;
    for (int i = 0; i < num_districts-1; i++) {
        if (diameters[i] > diametro_solucao) {
            diametro_solucao = diameters[i];
        }
    }

    text += to_string(diametro_solucao);

    text += ",\n";
    text += "\t";

    text += "\"desbalanceamento_distritos\":";
    text += "{";
    
    for (int i = 0; i < num_districts-1; i++) {
        text += "\n";
        text += "\t\t";
        text += "\"";
        text += to_string(i);
        text += "\"";
        text += ":";
        text += to_string(imbalances[i]);
        text += ",";
    }
    
    text += "\n";
    text += "\t\t";
    text += "\"";
    text += to_string(num_districts-1);
    text += "\"";
    text += ":";
    text += to_string(imbalances[num_districts-1]);

    text += "\n";
    text += "\t";
    text += "}";

    text += ",\n";
    text += "\t";

    text += "\"diametro_distritos\":";
    text += "{";
    
    for (int i = 0; i < num_districts-1; i++) {
        text += "\n";
        text += "\t\t";
        text += "\"";
        text += to_string(i);
        text += "\"";
        text += ":";
        text += to_string(diameters[i]);
        text += ",";
    }
    
    text += "\n";
    text += "\t\t";
    text += "\"";
    text += to_string(num_districts-1);
    text += "\"";
    text += ":";
    text += to_string(diameters[num_districts-1]);

    text += "\n";
    text += "\t";
    text += "}";

    text += ",\n";
    text += "\t";

    text += "\"vertices\":";
    text += "{";
    
    int last_vertex_id = graph->get_num_vertices()-1;
    for (int i = 0; i < last_vertex_id; i++) {
        text += "\n";
        text += "\t\t";
        text += "\"";
        text += to_string(i);
        text += "\"";
        text += ":";
        text += to_string(graph->get_district_by_vertex(i));
        text += ",";
    }
    
    text += "\n";
    text += "\t\t";
    text += "\"";
    text += to_string(last_vertex_id);
    text += "\"";
    text += ":";
    text += to_string(graph->get_district_by_vertex(last_vertex_id));

    text += "\n";
    text += "\t";
    text += "}";

    text += "\n";
    text += "}";
    return text;
}




void write_output_file(
    const char* file_name, 
    Graph* graph, 
    District** districts, 
    int num_districts,
    bool connex_solution, 
    vector<double> imbalances, 
    double imbalance_tolerance,
    vector<double> diameters,
    double exec_time
) {

    string out_text = parse_json(
        graph, 
        districts, 
        num_districts,
        connex_solution, 
        imbalances, 
        imbalance_tolerance, 
        diameters,
        exec_time
    );

    ofstream output_file(file_name);
    output_file << out_text;
    output_file.close();

}