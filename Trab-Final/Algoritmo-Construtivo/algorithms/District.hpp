
#include <iostream>
#include <string>
using namespace std;

#include "Vertex.hpp"

class District {
    private:
        int id;
    public:
        District(int id);

        int get_id();

        string get_string();
};