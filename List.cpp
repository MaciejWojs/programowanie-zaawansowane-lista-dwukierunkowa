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

void List::insert_at(int value, int index) {
    std::cout << "counter: " << counter << '\n';
    if (index < 0) {
        std::cout << "Index cant be negative";
        exit(0);
    } else if (index == 0) {
        push_front(value);
    } else if (index == counter) {
        push_back(value);
    } else {
        if (index > counter) {
            std::cout << "Can't insert value at this index: " << index << '\n';
            return;
        }

        Node* current = head;
        for (int i = 0; i <= index - 1; i++) {
            current = current->next;
        }

        // std::cout << "current: " << current->value << " at index: " << index << '\n';
        Node* temp = current;
        Node* temp_prev = current->prev;

        current = new Node(value);
        temp_prev->next = current;
        current->prev = temp_prev;
        current->next = temp;


        ++counter;
    }
}