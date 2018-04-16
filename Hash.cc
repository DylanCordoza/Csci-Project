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
    else if (size == 1) { //If there is only one element in the list...
        Node *temp = head;
        if (temp->item == item) { //If the item is already there
            delete new_node; //Remove the node that was declared
            temp->amount++; //Increment how many available
        }
        else if (new_node < temp) { //Insert before the one element
            head = new_node;
            head->set_next(temp);
        }
        else { //Insert after the one element
            tail = new_node;
            tail->set_prev(temp);
        }
    }
    else { //More than one element in the list
        Node *temp = head;
        while (temp) {
            if (temp->item == item) { //If the item is already there
                delete new_node; //Remove the node that was declared
                temp->amount++; //Increment how many available
                break;
            }
            else if (new_node < head) { //If the node belongs before the head
                head->prev = new_node;
                new_node->next = head;
                head = new_node;
                break;
            }
            else if (tail < new_node) { //If the node belongs after the tail
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
                break;
            }
            else if (new_node < temp) { //If the node belongs before the current node
                new_node->next = temp;
                new_node->prev = temp->prev;
                temp->prev->next = new_node;
                temp->prev = new_node;
                break;
            }
                temp = temp->next; //Otherwise, move to the next node
        }
    }
}

void List::remove(string item) {
    //Return if the list is empty, or the item would be before the head or after the tail
    if (size == 0 || item < head.item || item > tail.item) return;
    Node *temp = head;
    while (temp) {
        if (item < temp.item) return; //Return if the item belongs before the current node
        else if (temp.item == item) { //If there is a match...
            if (temp->amount == 1) { //If there is only one...
                if (size == 1) { //If it is the only item...
                    head = nullptr;
                    tail = nullptr;
                }
                else if (temp == head) { //If the item is at the head...
                    head = temp->next;
                    head->prev = nullptr;
                }
                else if (temp == tail) { //If the item is at the tail...
                    tail = temp->prev;
                    tail->next = nullptr;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
            }
            temp->amount--; //Decrement the amount available
            if (temp->amount == 0) { //If the amount is now 0...
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
    while (temp) {
        ss << temp->amount << " " << temp->item << endl;
        temp = temp->next;
    }
    return ss.str(); //Returns blank if the list is empty
}

void Hash::add(string item) {
    char letter = item.at(0); //Grabs the first character in the item
    toupper(letter); //Capitalize the letter
    int index = (letter - 65) % 26; //Determine which slot the item belongs in, A-Z
    table[index].insert(item); //Insert the item into the appropriate linked list
}

void Hash::use(string item) {
    char letter = item.at(0); //Grabs the first character in the item
    toupper(letter); //Capitalize the letter
    int index = (letter - 65) % 26; //Determine which slot the item is in, A-Z
    table[index].remove(item); //Remove the item by searching the appropriate linked list
}

void Hash::print() const {
    for(List l : table) //Print each linked list in the hash table
        cout << l.print_list();
}
