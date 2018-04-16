//queue.h
#pragma once
#include <iostream>
#include <room.h>
using namespace std;

class Node {
    Node *next = nullptr;
    Node *prev = nullptr;
    Room r; //Information for whichever room is being stored
    public:
    Node(Node *new_next = nullptr, Node *new_prev = nullptr; Room new_r) {
        next = new_next;
        prev = new_prev;
        r = new_r;
    }
    void set_next(Node *new_next) { next = new_next; }
    void set_prev(Node *new_prev) { prev = new_prev; }
    void set_r(Room new_r) { r = new_r; }
    Node *get_next() const { return next; }
    Node *get_prev() const { return prev; }
    Room get_r() const { return r; }
};

class Queue {
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;
    public:
    List() {} //Default constructor
    ~List() { //Destructor
        while (head) {
            Node *temp = head;
            head = head->get_next();
            delete temp;
        }
    }
    int get_size() const { return size; }
    Room top() const { return head->get_r(); } //Return the current room
    void pop(); //Proceed to the next room
    void push(Room new_room); //Add rooms to the queue
};
