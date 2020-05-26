
#include <iostream>
#include <string>
using namespace std;


#ifndef DISTRICT
#define DISTRICT 1

class District {
    private:
        int id;
    public:
        District(int id);

        int get_id();

        string get_string();
};

#endif