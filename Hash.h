//hash.h
#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <array>
using namespace std;

struct Node {
    Node *next = nullptr;
    Node *prev = nullptr;
    string item;
    int amount = 0;
    Node(Node *new_next = nullptr, Node *new_prev = nullptr, string new_item = "", int new_amount = 0) {
        next = new_next;
        prev = new_prev;
        item = new_item;
        amount = new_amount;
    }
    bool operator<(const Node &rhs) { //Compare two nodes to one another
        return item < rhs.item;
    }
};

class List {
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;
    public:
    void insert(string item);
    void remove(string item);
    string print_list() const;
};

class Hash {
    List table[26]; //Array of 26 linked lists
    public:
    void add(string item); //Insert a new item
    void use(string item); //Use an item
    void print() const; //Print the entire hash table
};
