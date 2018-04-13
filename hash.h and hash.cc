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
    Node(Node *new_next = nullptr, Node *new_prev = nullptr, string new_item, int new_amount = 0) {
        next = new_next;
        prev = new_prev;
        item = new_item;
        amount = new_amount;
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
#include <iomanip>
#include <sstream>
using namespace std;

void List::insert(string item) {
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

void List::remove(string item) {
    if (size == 0 || item < head.item || item > tail.item) return;
    Node *temp = head;
    while (temp) {
        if (item < temp.item) return;
        else if (temp.item == item) {
            if (temp->amount == 1) {
                if (size == 1) {
                    head = nullptr;
                    tail = nullptr;
                }
                else if (temp == head) {
                    head = temp->next;
                    head->prev = nullptr;
                }
                else if (temp == tail) {
                    tail = temp->prev;
                    tail->next = nullptr;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
            }
            temp->amount--;
            if (temp->amount == 0) {
                delete temp;
                size--;
            }
            return;
        }
        temp = temp->next;
    }
}

string List::print_list() const {
    Node *temp = head;
    ostringstream ss;
    if (!temp) {
        ss << "No items available.\n";
        return ss.str();
    }
    while (temp) {
        ss << temp->amount << " " << temp->item << endl;
        temp = temp->next;
    }
    return ss.str();
}

void Hash::add(string item) {
    char letter = item.at(0);
    toupper(letter);
    int index = (letter - 65) % 26;
    table[index].insert(item);
}

void Hash::use(string item) {
    char letter = item.at(0);
    toupper(letter);
    int index = (letter - 65) % 26;
    table[index].remove(item);
}

void Hash::print() const {
    for(List l : table)
        cout << l.print_list();
}
