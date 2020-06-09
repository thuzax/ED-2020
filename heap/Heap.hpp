// Heap

#include <iostream>
#include <string>

using namespace std;

class Node {
    private:
        int id;
        double weight;

    public:
        Node(int id, double weight);

        void set_id(int id);
        void set_weight(double weight);
        int get_id();
        double get_weight();
};


class Heap {
    private:
        Node** nodes;
        bool ascending;

        int size;
        int max_size;

        bool verify_previous(Node* node, Node* previous);
        bool verify_next(Node* node, Node* next);

        bool heap_is_empty();
        bool heap_is_full();

        void correct_climbing(int pos);
        void correct_descending(int pos);

    public:
        Heap(int max_size, bool ascending = true);
        ~Heap();


        int father_pos(int child_pos);
        int left_pos(int father_pos);
        int right_pos(int father_pos);
        
        void add(int id, double weight);
        void set_id(int id, double weight);
        int remove();


        string get_string();    

};