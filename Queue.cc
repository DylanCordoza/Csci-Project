//queue.cc
#include "queue.h"
using namespace std;

void Queue::pop() {
    Node *temp = head;
    if (size == 0) return;
    else if (size == 1) {
        head = nullptr;
        tail = nullptr;
        delete temp;
    }
    else {
        head = temp->get_next();
        head->set_prev(nullptr);
        delete temp;
    }
    size--;
    return;
}

void Queue::push(Room new_room) {
    Node *bottom = new Node{nullptr, tail, new_room}; //Insert to the bottom of the list
    if (size == 0) head = bottom;
    else tail->set_next(bottom);
    tail = bottom;
    size++;
}
