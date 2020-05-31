
#include <iostream>
#include <string>
#include <vector>

#include "common_functions.hpp"

using namespace std;


#ifndef DISTRICT
#define DISTRICT 1

class District {
    private:
        int id;
        // vector<int> vertices;
        vector<int> border;
        vector<int> candidates;
    public:
        District(int id);

        // void add_vertex_to_district(int id_vertex);
        void add_to_border(int id_vertex);
        void remove_from_border(int id_vertex);
        bool is_border_of_district(int id_vertex);

        void add_to_candidates(int id_vertex);
        void add_to_candidates(vector<int> id_vertex);
        void remove_from_candidates(int id_vertex);
        bool is_candidate_of_district(int id_vertex);

        int get_id();

        string get_string();
};

#endif