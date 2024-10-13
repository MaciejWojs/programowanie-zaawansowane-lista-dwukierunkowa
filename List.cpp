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
