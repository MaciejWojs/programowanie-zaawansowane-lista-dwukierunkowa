#include "List.hpp"

List::Node::Node(int a) : value(a), prev(nullptr), next(nullptr) {}
List::Node::Node(int a, Node* b) : value(a), prev(b), next(nullptr) {}
std::ostream& operator<<(std::ostream& stream, const List::Node* node) {
    stream << node->value;
    return stream;
}

List::List() : head(nullptr), tail(nullptr), counter(0) {}

List::~List() {
}

void List::push_back(int i) {
    if (head == nullptr) {
        head = new Node(i);
        tail = head;
    } else {
        tail->next = new Node(i, tail);
        tail = tail->next;
    }

    ++counter;
}

void List::push_front(int i) {
    if (head == nullptr) {
        head = new Node(i);
        tail = head;
    } else {
        // tail->next = new Node(i, tail);
        // tail = tail->next;
        Node* temp = head;
        head->prev = new Node(i);
        head = head->prev;
        head->next = temp;
    }

    ++counter;
}