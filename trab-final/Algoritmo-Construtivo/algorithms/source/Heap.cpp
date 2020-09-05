
#include "../Heap.hpp"


// ------------------------------NodeHeap functions-----------------------------
NodeHeap::NodeHeap(int id, double weight) {
    this->id = id;
    this->weight = weight;
}

void NodeHeap::set_id(int id) {
    this->id = id;
}

void NodeHeap::set_weight(double weight) {
    this->weight = weight;
}

int NodeHeap::get_id() {
    return this->id;
}

double NodeHeap::get_weight() {
    return this->weight;
}

//-------------------------------Heap functions---------------------------------

Heap::Heap(int max_size, bool ascending) {
    this->max_size = max_size;
    this->ascending = ascending;

    this->nodes = new NodeHeap*[this->max_size];
    this->size = 0;

}

Heap::~Heap() {
    for (int i = 0; i < size; i++) {
        delete this->nodes[i];
    }
    delete[] this->nodes;
}

bool Heap::verify_previous(NodeHeap* node, NodeHeap* previous) {
    if (this->ascending) {
        return (node->get_weight() >= previous->get_weight());
    }
    else {
        return (node->get_weight() <= previous->get_weight());
    }
}

bool Heap::verify_next(NodeHeap* node, NodeHeap* next) {
    if (this->ascending) {
        return (node->get_weight() >= next->get_weight());
    }
    else {
        return (node->get_weight() <= next->get_weight());
    }
}

bool Heap::heap_is_empty() {
    if (this->size == 0) {
        return true;
    }

    return false;
}

bool Heap::heap_is_full() {
    if (this->size >= max_size) {
        return true;
    }

    return false;
}

int Heap::father_pos(int child_pos) {
    return ((child_pos - 1) / 2);
}

int Heap::left_pos(int father_pos) {
    return (2 * father_pos + 2);
}

int Heap::right_pos(int father_pos) {
    return (2* father_pos + 1);
}

void Heap::correct_climbing(int pos) {
    NodeHeap* node = this->nodes[pos];
    int p_father = this->father_pos(pos);
    NodeHeap* father = this->nodes[p_father];
    if (not verify_previous(node, father)) {
        this->nodes[p_father] = node;
        this->nodes[pos] = father;
        return correct_climbing(p_father);
    }

    return;
}

void Heap::add(int id, double weight) {
    if (this->heap_is_full()) {
        cout << "Heap cheia" << endl;
        return;
    }
    NodeHeap* novo = new NodeHeap(id, weight);
    this->nodes[this->size] = novo;
    this->size++;

    correct_climbing(this->size-1);

}

void Heap::correct_descending(int pos) {
    NodeHeap* father = this->nodes[pos];
    int left_pos = this->left_pos(pos);
    NodeHeap* left = nullptr;
    if (left_pos < this->size) {
        left = this->nodes[left_pos];
    }


    int right_pos = this->right_pos(pos);
    NodeHeap* right = nullptr;
    if (right_pos < this->size) {
        right = this->nodes[right_pos];
    }


    int child_pos = left_pos;
    if (left == nullptr or this->verify_previous(left, right)) {
        child_pos = right_pos;
    }

    NodeHeap* child = nullptr;
    if (child_pos < this->size){
        child = this->nodes[child_pos];
    }

    if (child == nullptr or this->verify_previous(child, father)) {
        return;
    }

    this->nodes[pos] = child;
    this->nodes[child_pos] = father;
    this->correct_descending(child_pos);
}

int Heap::remove() {
    if (this->size < 1) {
        cout << "ERRO" << endl;
        return -1;
    }
    NodeHeap* node = this->nodes[0];
    int returned_id = node->get_id();
    this->size--;
    this->nodes[0] = this->nodes[this->size];
    this->nodes[this->size] = nullptr;
    delete node;
    this->correct_descending(0);
    return returned_id;
}

string Heap::get_string() {
    string text = "";
    for(int i = 0; i < this->size; i++) {
        text += "(" + to_string(this->nodes[i]->get_id()) + ", ";
        text += to_string(this->nodes[i]->get_weight()) + ") ";
    }
    return text;
}

