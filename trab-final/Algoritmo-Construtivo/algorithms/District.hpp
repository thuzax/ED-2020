
#include <iostream>
#include <string>
#include <vector>

#include "common_functions.hpp"

#include "Heap.hpp"
#include "Vertex.hpp"

using namespace std;


#ifndef DISTRICT
#define DISTRICT 1

class District {
    private:
        int id;
        int num_vertices;
        double balance_value;
        
        vector<int> vertices;
        vector<int> border;
        vector<int> candidates;
    public:
        District(int id);

        void set_balance_value(double bal_val);
        void increase_num_vertices();
        void decrease_num_vertices();
        void add_vertex_to_district(int id_vertex);
        void add_to_border(int id_vertex);
        void remove_from_border(int id_vertex);
        bool is_border_of_district(int id_vertex);

        void add_to_candidates(int id_vertex);
        void add_to_candidates(vector<int> id_vertex);
        void remove_from_candidates(int id_vertex);
        bool is_candidate_of_district(int id_vertex);
        bool has_candidate();

        double calculate_imbalance(double ideal_balance);
        double calculate_diameter(Vertex** graph_vertices);

        int get_id();
        double get_balance();
        int get_num_vertices();
        vector<int> get_candidates();
        vector<int> get_border();

        string get_string();
};

#endif