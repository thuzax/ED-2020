// Heap

#include <iostream>
#include <string>

using namespace std;

#ifndef HEAP
#define HEAP 1

class NodeHeap {
    private:
        int id;
        double weight;

    public:
        NodeHeap(int id, double weight);

        void set_id(int id);
        void set_weight(double weight);
        int get_id();
        double get_weight();
};


class Heap {
    private:
        NodeHeap** nodes;
        bool ascending;

        int size;
        int max_size;

        bool verify_previous(NodeHeap* node, NodeHeap* previous);
        bool verify_next(NodeHeap* node, NodeHeap* next);

        int father_pos(int child_pos);
        int left_pos(int father_pos);
        int right_pos(int father_pos);
        
        void correct_climbing(int pos);
        void correct_descending(int pos);

    public:
        Heap(int max_size, bool ascending = true);
        ~Heap();


        bool heap_is_full();
        bool heap_is_empty();
        
        void add(int id, double weight);
        void set_id(int id, double weight);
        int remove();


        string get_string();    

};

#endif