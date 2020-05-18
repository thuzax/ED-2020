// Vertex methods implementation

#include <iostream>
#include <string>
using namespace std;


#ifndef VERTEX
#define VERTEX 1

class Vertex {
    private:
        int id;                 // vertex identifier

        int id_district;        // identifier of the vertex's district

        double coordenate_x;
        double coordenate_y;

    public:
        Vertex(int id, double coordenate_x, double coordenate_y);

        void set_id_district(int id_district);

        int get_id();
        int get_id_district();
        double get_coordinate_x();
        double get_coordinate_y();

        string get_string();

};

#endif