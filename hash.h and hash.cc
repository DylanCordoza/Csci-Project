//hash.h
#include <iostream>
#include <string>
#include <cctype>
#include <array>
using namespace std;

class Node {
    Node *next = nullptr;
    Node *prev = nullptr;
    string item;
    int amount = 0;
    public:
    Node(Node *new_next = nullptr, Node *new_prev = nullptr, string new_item, int new_amount = 0) {
        next = new_next;
        prev = new_prev;
        item = new_item;
        amount = new_amount;
    }
    void set_next(Node *new_next) { next = new_next; }
    void set_prev(Node *new_prev) { prev = new_prev; }
    void set_item(string new_item) { item = new_item; }
    void set_amount(int new_amount) { amount = new_amount; }
    Node *get_next() const { return next; }
    Node *get_prev() const { return prev; }
    string get_item() const { return item; }
    int get_amount() const { return amount; }
    bool operator<(const Node &rhs)
        return item < rhs.item;
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
    List table[50];
    public:
    void add(string item);
    string use(string item);
    void print() const;
};

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//hash.cc
#include "hash.h"
using namespace std;

List::void insert(string item) {
    Node new_node = new Node{nullptr, nullptr, item};
    if (size == 0) {
        head = new_node;
        tail = new_node;
    }
    else if (size == 1) {
        Node *temp = head;
        if (temp->item == item) {
            delete new_node;
            temp->amount++;
        }
        else if (new_node < temp) {
            head = new_node;
            head->set_next(temp);
        }
        else {
            tail = new_node;
            tail->set_prev(temp);
        }
    }
    else {
        Node *temp = head;
        while (temp) {
            if (temp->item == item) {
                delete new_node;
                temp->amount++;
                break;
            }
            else if (new_node < head) {
                head->prev = new_node;
                new_node->next = head;
                head = new_node;
                break;
            }
            else if (tail < new_node) {
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
                break;
            }
            else if (new_node < temp) {
                new_node->next = temp;
                new_node->prev = temp->prev;
                temp->prev->next = new_node;
                temp->prev = new_node;
                break;
            }
                temp = temp->next;
        }
    }
}

List::void remove(string item) {

}

List::string print_list() const {

}

Hash::void add(string item) {
    char letter = item.at(0);
    toupper(letter);
    int index = (letter - 65) % 26;
    table[index].insert(item);
}

Hash::void use(string item) {
    char letter = item.at(0);
    toupper(letter);
    int index = (letter - 65) % 26;
    table[index].remove(item);
}

Hash::void print() const {
    for(List l : table)
        cout << l.print_list();
}
