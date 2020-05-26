
#include "../District.hpp"

District::District(int id) {
    this->id = id;
}


int District::get_id() {
    return this->id;
}


string District::get_string() {
    string text = "";
    text += "id distrito: " + to_string(this->id);
    
    return text;

}

