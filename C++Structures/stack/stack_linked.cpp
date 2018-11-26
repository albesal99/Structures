//
// Created by Alberto on 11/15/2018.
//
#include <iostream>
#include "stack_linked.h"
using namespace std;

#define CAPACITY 10

class Stack {
    int capacity;
    struct Node *head;
    int num_items = 0;

private:
    struct Node {
        int data = data;
        struct Node *next;
    };

    struct Node* new_node(int data) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = nullptr;
        return new_node;
    }

public:
    Stack(int capacity = CAPACITY);

    void push(int);

    bool is_empty();
    bool is_full();
};

bool Stack::is_empty() {
    return head == nullptr;
}

bool Stack::is_full() {
    return num_items == capacity;
};

void Stack::push(int data) {
    if (is_full()) {
        throw out_of_range ("Stack is Full");
    }
    struct Node* node = new_node(data);
    if (is_empty()) {
        head = node;
        head->next = nullptr;
        num_items++;
    } else {
        node->next = head;
        head = node;
        num_items++;
    }
}
