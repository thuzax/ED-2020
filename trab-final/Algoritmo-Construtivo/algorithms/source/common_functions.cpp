// Math formulas file


#include "../common_functions.hpp"

using namespace std;

double euclidian_distance(double x1, double y1, double x2, double y2) {
    double x = x1 - x2;
    double y = y1 - y2;
    return pow(pow(x, 2) + pow(y, 2), 1.0/2.0);
}


vector<int> generate_random_indices(int num_indices, int start, 
                                    int end, bool* banned) {

    vector<int> indices;
    int i = 0;
    while (i < num_indices) {
        int index = rand() % (end + 1 - start) + start;
        if (banned[index]) {
            continue;
        }
        if (count(indices.begin(), indices.end(), index) > 0) {
            continue;
        }
        indices.push_back(index);
        i++;
    }
    
    return indices;
}

// Find the position of a vertex: return -1 if nothing found
int find_position_in_vector(int id, vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == id) {
            return i;
        }
    }
    return -1;
}

// Verify if a id is in the vector
int is_in_vector(int id, vector<int> vec) {
    int pos = find_position_in_vector(id, vec);

    if (pos == -1) {
        return false;
    }

    return true;
}

string get_vector_string(vector<int> vec) {
    string text = "";
    for (int i = 0; i < vec.size(); i++) {
        text += to_string(vec[i]) + " ";
    }
    return text;
}